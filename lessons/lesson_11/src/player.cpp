#include "player.h"

player::player()
{
    //ctor
    verts[0].x = -0.5;
    verts[0].y = -0.5;
    verts[0].z = -1.0;

    verts[1].x = 0.5;
    verts[1].y = -0.5;
    verts[1].z = -1.0;


    verts[2].x = 0.5;
    verts[2].y = 0.5;
    verts[2].z = -1.0;


    verts[3].x = -0.5;
    verts[3].y = 0.5;
    verts[3].z = -1.0;

    runSpeed = 0.0;
    jumpSpeed = 0.0;

    actionTrigger = IDLE;
    playerDir = 'R';

    pPos.x = 0.0;
    pPos.y = -0.5;
    pPos.z = -2.0;

}

player::~player()
{
    //dtor
}

void player::drawPlayer()
{

    tLoad->binder(tex);

    glTranslated(pPos.x, pPos.y, pPos.z);
    glBegin(GL_QUADS);

    glTexCoord2f(xMin, yMax);
    glVertex3f(verts[0].x, verts[0].y, verts[0].z);

     glTexCoord2f(xMax, yMax);
    glVertex3f(verts[1].x, verts[1].y, verts[1].z);


     glTexCoord2f(xMax, yMin);
    glVertex3f(verts[2].x, verts[2].y, verts[2].z);


     glTexCoord2f(xMin, yMin);
    glVertex3f(verts[3].x, verts[3].y, verts[3].z);

    glEnd();

}

void player::playerInit(char* fileName, int hFrm, int vFrm)
{



    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    vFrames = vFrm;
    hFrames = hFrm;

    xMax = 1.0/(float)hFrames;
    //xMax = 1.0/(float)vFrames;
    xMin = 0.0;
    yMax = 1.0/(float)vFrames;
    //yMax = 1.0/(float)hFrames;
    yMin = 0.0;
    tLoad->loadTexture(fileName, tex);



}

void player::actions(acts action, sounds* _snds)
{

    float temp;
    float temp2;

    switch(action){

        case IDLE:

            if(playerDir == 'R'){
                xMax = 1.0/(float)hFrames;
                xMin = 0.0;
                yMax = 1.0/(float)vFrames;
                yMin = 0.0;

            }else if(playerDir == 'L'){


                xMin = 1.0/(float)hFrames;
                xMax = 0.0;
                yMax = 1.0/(float)vFrames;
                yMin = 0.0;
            }

            actionTrigger = IDLE;
            break;


        case WALKR:

            _snds->playSound("sounds/p.mp3");
            if(playerDir != 'R'){
                float tmp;
                tmp = xMax;
                xMax = xMin;
                xMin = tmp;
                playerDir = 'R';


            }

            xMin +=1.0/(float)hFrames;
            xMax +=1.0/(float)hFrames;

            if(xMax > 1.0){
                xMax = 1.0/(float)hFrames;
                xMin = 0.0;

                yMax += 1.0/(float)vFrames;
                yMin += 1.0/(float)vFrames;


            }

            actionTrigger = WALKR;
            break;

        case WALKL:


            _snds->playSound("sounds/p.mp3");
            if(playerDir != 'L'){
                float tmp;
                tmp = xMax;
                xMax = xMin;
                xMin = tmp;
                playerDir = 'L';

            }

            xMin +=1.0/(float)hFrames;
            xMax +=1.0/(float)hFrames;

            if(xMin > 1.0){
                xMin = 1.0/(float)hFrames;
                xMax = 0.0;

                 yMin += 1.0/(float)vFrames;
                 yMax += 1.0/(float)vFrames;
            }
            actionTrigger = WALKL;
            break;

    }

}
