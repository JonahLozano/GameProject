//#include<commons.h>
#include "GLScene.h"
#include <GLLight.h>
#include <Model.h>
#include<Inputs.h>
#include <parallax.h>
#include <player.h>
#include <enms.h>
#include <checkCollision.h>
#include <sounds.h>
#include<Fonts.h>
#include<skyBox.h>


Model *myFirstModel = new Model();
Inputs *KbMs = new Inputs();
parallax *prLX = new parallax();
player *ply = new player();
checkCollision *hit = new checkCollision();
sounds* snds = new sounds();
Fonts* F = new Fonts();
skyBox* box = new skyBox();

enms en[20];

parallax *middlePrlx = new parallax();
parallax *forePrlx = new parallax();

GLScene::GLScene()
{
    //ctor
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth  = GetSystemMetrics(SM_CXSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}

int GLScene::drawScene()
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();

   //glColor3f(1.0,0.0,0.0);   // R, G,B



   /*
   glPushMatrix();
   myFirstModel->drawModel();
   glPopMatrix();
   */


   /*
   glPushMatrix();
   glScaled(3.33,3.33,1.0);
   prLX->drawSquare(screenWidth,screenHeight);
   glPopMatrix();


   glPushMatrix();
   glScaled(3.33,3.33,1.0);
   middlePrlx->drawSquare(screenWidth,screenHeight);
   glPopMatrix();

   glPushMatrix();
   glScaled(3.33,3.33,1.0);
   forePrlx->drawSquare(screenWidth,screenHeight);
   glPopMatrix();
   */

   //glPushMatrix();
   box->drawSkyBox();
   //glPopMatrix();

   glPushMatrix();
   ply->drawPlayer();
   glPopMatrix();

   glPushMatrix();


   for(int i = 0; i < 20; i++){

    //collision is determined by the player's current action and direction
    //if player is IDLE then no collision
    //only checking for collision with enemies that are in front of the player

    if(ply->actionTrigger == ply->WALKR && ply->pPos.x < en[i].ePos.x)
        if(hit->isRadialCollision(ply->pPos.x, en[i].ePos.x, ply->pPos.y, en[i].ePos.y,0.1, 0.11 )){
            en[i].action = en[i].ROLLR;
            //cout << "hit" << endl;
            //en[i].eSpeed.x = 0.1;
            //en[i].action = en[i].WALKR;
            //en[i].eSpeed.x = 0.2;
        }


    if(ply->actionTrigger == ply->WALKL && ply->pPos.x < en[i].ePos.x){
        if(hit->isRadialCollision(ply->pPos.x, en[i].ePos.x, ply->pPos.y, en[i].ePos.y,0.1, 0.11 )){
            en[i].action = en[i].ROLLL;
            //cout << "hit" << endl;
            //en[i].eSpeed.x = 0.1;
            //en[i].action = en[i].WALKR;
            //en[i].eSpeed.x = 0.2;
        }




    }else{




    if(en[i].ePos.x < -2.0){
        //en[i].actions(en[i].WALKL);
        //en[i].ePos.x += en[i].eSpeed.x;
        en[i].action = en[i].WALKR;
        //en[i].eSpeed.x = 0.1;
    }else if(en[i].ePos.x > 2.0){
        //en[i].actions(en[i].WALKR);
        //en[i].ePos.x -= en[i].eSpeed.x;
        en[i].action = en[i].WALKL;
        //en[i].eSpeed.x = -0.1;
    }

    }
    en[i].drawEnemy();

   }
   glPopMatrix();




   for(int i = 0; i < F->cCnt; i++){

        glPushMatrix();
        glTranslatef(F->pos.x+i/14.0, F->pos.y, F->zoom);
        F->drawFonts(i);
        glPopMatrix();

   }





    return true;
}

int GLScene::GLinit()
{
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.0f,0.0f,0.0f,0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);

    myFirstModel->modelInit("images/flower.jpeg");
    box->initSkyBox();
    //prLX->initParallax("images/background.png");
    ply->playerInit("images/player.png", 12, 3);
    en[0].enemyTexture("images/mon.png"); //to avoid loading same image for all enemies

    middlePrlx->initParallax("images/fg1.png");
    forePrlx->initParallax("images/fg2.png");

    for(int i = 0; i < 20; i++){
        en[i].initEnemy(en[0].tex, 7, 2); //load enemies
        en[i].placeEnemy(vec3{(float)rand()/(float)(RAND_MAX) * 5 -2.5, -0.5, -2.5}); //random placement
        en[i].eSize.x = en[i].eSize.y = (float)(rand()%12)/35.0; //random sizes
    }

    snds->initSound();
    snds->playMusic("sounds/ms.mp3");

    F->initFonts("images/font.png");
    F->buildFonts("abBA");
    return true;
}
void GLScene::GLReSize(GLsizei width, GLsizei height)
{
    screenWidth= width;
    screenHeight = height;
    float ratio = (float)width/(float)height;
    glViewport(0,0, width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,ratio,0.1,1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int GLScene::winMsg(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    KbMs->wParam = wParam;

    switch(uMsg)
    {
    case WM_KEYDOWN:

        KbMs->keyPressed(myFirstModel);
        KbMs->keyPressed(box);
        KbMs->keyEnv(prLX, 0.001);
        KbMs->keyEnv(middlePrlx, 0.002);
        KbMs->keyEnv(forePrlx, 0.005);
        KbMs->keyPlayer(ply, snds);

        break;

    case WM_KEYUP:
        KbMs ->keyUp();
        ply->actions(ply->IDLE, snds);

        break;

    case WM_LBUTTONDOWN:

        KbMs->mouseBtnDwn(myFirstModel, LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_RBUTTONDOWN:
        KbMs->mouseBtnDwn(myFirstModel, LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_MBUTTONDOWN:
        KbMs->mouseBtnDwn(myFirstModel, LOWORD(lParam),HIWORD(lParam));
        break;

    case    WM_LBUTTONUP:
    case    WM_RBUTTONUP:
    case    WM_MBUTTONUP:

             KbMs ->mouseBtnUp();
            break;

    case WM_MOUSEMOVE:
        KbMs->mouseMove(myFirstModel, LOWORD(lParam),HIWORD(lParam));
        KbMs->mouseMove(box, LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_MOUSEWHEEL:
        KbMs->mouseWheel(myFirstModel,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;
    }

}
