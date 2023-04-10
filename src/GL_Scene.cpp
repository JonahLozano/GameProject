#include "../include/GL_Scene.h"
#include "../include/GL_Light.h"
#include "../include/player.h"
#include "../include/enms.h"
#include "../include/checkCollision.h"
#include "../include/sounds.h"
#include "../include/levelLoader.h"

Model *myFirstModel = new Model();
Inputs *KbMs = new Inputs();
parallax *prLx = new parallax();
parallax *prLx2 = new parallax();
parallax *prLx3 = new parallax();
player *ply = new player();
checkCollision *hit = new checkCollision();
sounds *snds = new sounds();
levelLoader *lvlLoad = new levelLoader();

// enms *en = new enms();
enms en[4];

GL_Scene::GL_Scene()
{
    //ctor
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);

    zoom = 1.0f;
}

GL_Scene::~GL_Scene()
{
    //dtor
}
int GL_Scene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // glColor3f(1.0,0.0,0.0);

    // TEAPOT
//    glPushMatrix();
//        // glutSolidTeapot(1.5f);
//        // make your own player class & Model model into a class instead of global
//        glScaled(0.25,0.25,0.25);
//        glTranslatef(0,0,-8.0f);
//        myFirstModel->drawModel();
//    glPopMatrix();


    // PARALAX
    glPushMatrix();
        glScaled(3.333,3.333,1);
        prLx->drawSquare(screenWidth,screenHeight);
        // prLx->scroll(true,"x",0.0025);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0.0f,-2,0.0f);
        glScaled(3.333,1.111,1);
        prLx2->drawSquare(screenWidth,screenHeight);
    glPopMatrix();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(0.0f,-3,0.0f);
        glScaled(3.333,1.111,1);
        prLx3->drawSquare(screenWidth,screenHeight);
    glPopMatrix();

            // LEVEL
    lvlLoad->drawLevel();

    // PLAYER
    glPushMatrix();
        ply->drawPlayer();
    glPopMatrix();

    // ENEMY
    glPushMatrix();
        for(int i = 0; i < 4; i++)
        {
            // check if enemy is colliding with player
            // if player is moving right then check for collisions for objects to the right
//            cout << "pPos: " << "{ " << ply->pPos.x << "," << ply->pPos.y << " }" << endl;
//            cout << "ePos: " << "{ " << en[i].ePos.x << "," << en[i].ePos.y << " }" << endl;
            if(ply->actionTrigger == ply->WALKRIGHT && ply->pPos.x < en[i].ePos.x)
            {

                if(hit->isRadialCollision(ply->pPos.x, en[i].ePos.x, ply->pPos.y, en[i].ePos.y,0.1,0.11))
                {
                    en[i].action = en[i].ROLLRIGHT;
                }
            }
            else if(ply->actionTrigger == ply->WALKLEFT && ply->pPos.x < en[i].ePos.x)
            {
                if(hit->isRadialCollision(ply->pPos.x, en[i].ePos.x, ply->pPos.y, en[i].ePos.y,0.1,0.11))
                {
                    en[i].action = en[i].ROLLLEFT;
                }
            }
            else
            {
                if(en[i].ePos.x > 2.0)
                {
                    en[i].action = en[i].WALKLEFT;
                    // en[i].eSpeed.x = -0.1;
                }else if(en[i].ePos.x < -2.0)
                {
                    en[i].action = en[i].WALKRIGHT;
                    // en[i].eSpeed.x = 0.1;
                }
            }

            en[i].drawEnemy();
        }
    glPopMatrix();




    return true;
}

int GL_Scene::GLinit()
{
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.0f,0.0f,0.0f,0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GL_Light Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);

    myFirstModel->modelInit("images/ny1.jpg");
    prLx->initParallax("images/para.jpg");
    prLx2->initParallax("images/floor2.png");
    prLx3->initParallax("images/floor.png");
    // ply->playerInit("images/sprite.png",1,8);
    ply->playerInit("images/eg-1.png",4,6);


    en[0].enemyTexture("images/mon.png");

    for(int i = 0; i < 4; i++)
    {
        en[i].initEnemy(en[0].tex,2,7);
        en[i].placeEnemy(vec3{(float)rand()/(float)(RAND_MAX)*5-2.5,0.0,-1.0});
        en[i].eSize.x = en[i].eSize.y = 1.0f/10.0f;
        en[i].scale = zoom;
    }


    snds->initSound();
    snds->playMusic("sounds/nycatmus.mp3");

    lvlLoad->loadCSV("levels/test2.csv");

    for (const auto& row : lvlLoad->levelData) {
            for (const auto& block : row) {
                 block->draw();
            }
            cout << endl;
        }

    lvlLoad->setScale(zoom);
    ply->setScale(zoom);
    // enemy->setScale(1.0f);



    // KbMs->mdl = myFirstModel; // copy model to mdl

    return true;
}

void GL_Scene::GLReSize(GLsizei width, GLsizei height)
{
    screenWidth = width;
    screenHeight = height;

    float ratio = (float)width/(float)height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,ratio,0.1,1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int GL_Scene::winMsg(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    KbMs->wParam = wParam;

    switch(uMsg){
    case WM_KEYDOWN:
        KbMs->keyPressed(myFirstModel);
        KbMs->keyEnv(prLx,0.005);
        KbMs->keyEnv(prLx2,0.01);
        KbMs->keyEnv(prLx3,0.02);
        KbMs->keyMap(lvlLoad,0.2f,0.0f);
        KbMs->keyPlayer(ply,snds);
        break;
    case WM_KEYUP:
        ply->actions(ply->IDLE, snds);
        KbMs->mouseBtnUp();
        break;
    case WM_LBUTTONDOWN:
        KbMs->mouseBtnDwn(myFirstModel,LOWORD(lParam),HIWORD(lParam));
        break;
    case WM_RBUTTONDOWN:
        KbMs->mouseBtnDwn(myFirstModel,LOWORD(lParam),HIWORD(lParam));
        break;
    case WM_MBUTTONDOWN:
        break;

    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
        KbMs->mouseBtnUp();
        break;

    case WM_MOUSEMOVE:
        KbMs->mouseMove(myFirstModel,LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_MOUSEWHEEL:
        KbMs->mouseWheel(myFirstModel,(double)GET_WHEEL_DELTA_WPARAM(wParam));

        zoom += ((double)GET_WHEEL_DELTA_WPARAM(wParam))/12000;

        for(int i = 0; i < 4; i++) en[i].scale = zoom;
        lvlLoad->setScale(zoom);
        ply->setScale(zoom);
        break;

    case WM_MOUSELEAVE:
        break;
    }
}
