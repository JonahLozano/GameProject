#include "../include/enms.h"

enms::enms()
{
    //ctor

    ePos.x = 0.7f;
    ePos.y = -0.5f;
    ePos.z = -2.5f;

    eSize.x = 0.3f;
    eSize.y = 0.3f;

    eRota.x = eRota.y = eRota.z = 0.0f;
    eSpeed.x = 0.1f;
    eSpeed.y = 0.1f;
    action = WALKLEFT;

    theta = 35 * PI / 180.0;
    velocity = 35;
    t = 0;

    startTime = clock();

    scale = 1.0f;
}

enms::~enms()
{
    //dtor
}
void enms::drawEnemy()
{
    tLoad->binder(tex);
    glPushMatrix();
        glTranslated(ePos.x,ePos.y,ePos.z);
        glRotatef(eRota.x,1.0f,0.0,0.0f);
        glRotatef(eRota.y,0.0f,1.0,0.0f);
        glRotatef(eRota.z,0.0f,0.0,1.0f);
        glScalef(eSize.x * scale,eSize.y * scale,1.0f);

        glBegin(GL_QUADS);
            glTexCoord2f(xMin,yMin);
            glVertex3f(1.0,1.0,0.0);

            glTexCoord2f(xMax,yMin);
            glVertex3f(-1.0,1.0,0.0);

            glTexCoord2f(xMax,yMax);
            glVertex3f(-1.0,-1.0,0.0);

            glTexCoord2f(xMin,yMax);
            glVertex3f(1.0,-1.0,0.0);
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
    tLoad->loadTexture(fileName,tex);
}


void enms::initEnemy(GLuint tex, int vfrm, int hfrm)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    vFrames = vfrm;
    hFrames = hfrm;

    xMax = 1.0/hFrames;
    xMin = 0.0;
    yMax = 1.0/vFrames;
    yMin = 0.0;

    this->tex = tex;
}

void enms::actions()
{
    switch(action)
    {
    case WALKRIGHT:
        if(clock() - startTime > 60)
        {
            xMax += 1.0/(float)hFrames;
            xMin += 1.0/(float)hFrames;

            eRota.z = 0.0f;
            ePos.y = 0.0f;

            yMax = 1.0;
            yMin = 1.0/(float)vFrames;
            ePos.x +=eSpeed.x;

            startTime = clock();
        }
        break;

    case WALKLEFT:
        if(clock() - startTime > 60)
        {
            xMax -= 1.0/(float)hFrames;
            xMin -= 1.0/(float)hFrames;

            eRota.z = 0.0f;
            ePos.y = 0.0f;

            yMax = 1.0/(float)vFrames;
            yMin = 0.0;
            ePos.x -=eSpeed.x;

            startTime = clock();
        }
        break;

    case ATTACK:
        break;

    case DIE:
        break;

    case IDLE:
        if(clock() - startTime > 60)
        {
            // std::cout << "LEFT" << std::endl;
            xMax += 1.0/(float)hFrames;
            xMin += 1.0/(float)hFrames;
        }
        break;

    case JUMP:
        break;

    case ROLLLEFT:
        if(clock() - startTime > 60)
        {
            xMax += 1.0/(float)hFrames;
            xMin += 1.0/(float)hFrames;

            yMax = 1.0;
            yMin = 1.0/(float)vFrames;

            eRota.z += (float)(rand()/(float)(RAND_MAX))*100;

            ePos.x -= velocity * t * cos(theta) / 1200.0;
            ePos.y += (velocity * t * sin(theta) - 0.5 * GRAVITY * t * t) / 700;


            if(ePos.y >= -0.5f)
            {
                t += 0.2;
            }
            else
            {
                t = 0;
                ePos.y = -0.5;
            }

            // ePos.x -= abs(eSpeed.x)*2;

             startTime = clock();
        }
        break;

    case ROLLRIGHT:
//        if(clock() - startTime > 60)
//        {
//            xMax += 1.0/(float)hFrames;
//            xMin += 1.0/(float)hFrames;
//
//            yMax = 1.0;
//            yMin = 1.0/(float)vFrames;
//
//            eRota.z += (float)(rand()/(float)(RAND_MAX))*100;
//            ePos.x += 0.07;
//
//             startTime = clock();
//        }
        if(clock() - startTime > 60)
        {
            xMax += 1.0/(float)hFrames;
            xMin += 1.0/(float)hFrames;

            yMax = 1.0;
            yMin = 1.0/(float)vFrames;

            eRota.z += (float)(rand()/(float)(RAND_MAX))*100;

            ePos.x += velocity * t * cos(theta) / 1200.0;
            ePos.y += (velocity * t * sin(theta) - 0.5 * GRAVITY * t * t) / 700;


            if(ePos.y >= -0.5f)
            {
                t += 0.2;
            }
            else
            {
                t = 0;
                ePos.y = -0.5;
            }

            // ePos.x -= abs(eSpeed.x)*2;

             startTime = clock();
        }
        break;

    default:
        break;
    }
}

void enms::setScale(float newScale)
{
    scale = newScale;
}
