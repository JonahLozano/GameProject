#include "enms.h"

enms::enms()
{
    //ctor
    ePos.x =  0.7;
    ePos.y = -0.5;
    ePos.z = -2.5;

    eSize.x = 0.3;
    eSize.y = 0.3;

    eRot.x = eRot.y = eRot.z = 0.0;

    eSpeed.x = -0.05;
    eSpeed.y = 0.0;
    action = WALKL;

    theta = 30 * PI/180.0;
    velocity = 35;
    t = 0;
    startTime = clock();
}

enms::~enms()
{
    //dtor
}

void enms::drawEnemy()
{

    tLoad->binder(tex);
    glPushMatrix();


        glTranslated(ePos.x, ePos.y, ePos.z);
        glRotatef(eRot.x, 1.0, 0.0, 0.0);  //about x-axis
        glRotatef(eRot.y, 0.0, 1.0, 0.0);  //about y-axis
        glRotatef(eRot.z, 0.0, 0.0, 1.0);  //about z-axis
        glScalef(eSize.x, eSize.y, 1.0); //2d, so eSize.z = 1.0

        glBegin(GL_POLYGON);
            glTexCoord2f(xMin, yMin);
            glVertex3f(1.0, 1.0, 0.0);

            glTexCoord2f(xMax, yMin);
            glVertex3f(-1.0, 1.0, 0.0);

            glTexCoord2f(xMax, yMax);
            glVertex3f(-1.0, -1.0, 0.0);

            glTexCoord2f(xMin, yMax);
            glVertex3f(1.0, -1.0, 0.0);


        glEnd();

    actions();
    glPopMatrix();

}

void enms::placeEnemy(vec3 p)
{

    ePos.x = p.x;
    ePos.y = p.y;
    ePos.z = p.z;

}

void enms::enemyTexture(char* fileName)
{
    tLoad->loadTexture(fileName, tex);

}


void enms::initEnemy(GLuint tex, int hFrm, int vFrm)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    vFrames = vFrm;
    hFrames = hFrm;

    xMax = 1.0/(float)hFrames;
    xMin = 0.0;
    yMax = 1.0/(float)vFrames;
    yMin = 0.0;

    this->tex = tex;

}

void enms::actions()
{

    switch(action){


    case IDLE:

        if(clock() - startTime > 60){
            xMin += 1.0/(float)hFrames;
            xMax += 1.0/(float)hFrames;
        }


        break;

    case WALKR:

        if(clock() - startTime > 60){

            xMin += 1.0/(float)hFrames;
            xMax += 1.0/(float)hFrames;



            yMax = 1.0;
            yMin = 1.0/(float)vFrames;
            ePos.y = -0.5;
            eRot.z = 0.0;
             ePos.x -=eSpeed.x;
            startTime = clock();

        }

        break;

    case WALKL:
         if(clock() - startTime > 60){

            xMin += 1.0/(float)hFrames;
            xMax += 1.0/(float)hFrames;

            yMax = 1.0/(float)vFrames;
            yMin = 0.0;

            ePos.y = -0.5;
            eRot.z = 0.0;
            ePos.x +=eSpeed.x;


            startTime = clock();

        }

        break;


    case ROLLR:

        if(clock() - startTime > 60){


            xMin += 1.0/(float)hFrames;
            xMax += 1.0/(float)hFrames;

            yMax = 1.0;
            yMin = 1.0/(float)vFrames;

            eRot.z += (float)(rand()/(float)(RAND_MAX)) * 100;

            ePos.x += 0.07; //check for out of bounds
            startTime = clock();
        }


        break;

    case ROLLL:

          if(clock() - startTime > 60){

            xMin += 1.0/(float)hFrames;
            xMax += 1.0/(float)hFrames;

            yMax = 1.0;
            yMin = 1.0/(float)vFrames;

            eRot.z += (float)(rand()/(float)(RAND_MAX)) * 100;

            //first bounce
            ePos.x -= (velocity * t * cos(theta)) / 1200.0;
            ePos.y += (velocity * t * sin(theta) - 0.5 * GRAVITY * t * t) /700.0;

            if(ePos.y >= -0.5)t+=0.2;
            else{t=0;ePos.y = -0.5;}
            startTime = clock();


        }

        break;

    }

}
