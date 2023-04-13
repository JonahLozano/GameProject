#include "Fonts.h"
#include<commons.h>

Fonts::Fonts()
{
    //ctor
    cCnt = 0;
    rotation.x = rotation.y = rotation.z = 0;

    pos.x = 1.5;
    pos.y = 0.0;
    pos.z = 0.0;

    zoom = -2.5;

}

Fonts::~Fonts()
{
    //dtor
}

void Fonts::initFonts(char* fileName)
{

    tLoad->loadTexture(fileName, tex);

}

void Fonts::buildFonts(char* str)
{
    for(int i = 0; i < strlen(str); i++){

        switch(str[i]){

        case 'a':
            C[cCnt].xMin = 0;
            C[cCnt].xMax = 1.0/13.0;

            C[cCnt].yMin = 3.0/10.0;
            C[cCnt].yMax = 4.0/10.0;

            break;

        case 'b':

             C[cCnt].xMin = 1.0/13.0;
            C[cCnt].xMax = 2.0/13.0;

            C[cCnt].yMin = 3.0/10.0;
            C[cCnt].yMax = 4.0/10.0;

            break;
        case 'B':
            C[cCnt].xMin = 1.0/13.0;
            C[cCnt].xMax = 2.0/13.0;

            C[cCnt].yMin = 0.0;
            C[cCnt].yMax = 1.0/10.0;
            break;

        case 'A':
            C[cCnt].xMin = 0;
            C[cCnt].xMax = 1.0/13.0;

            C[cCnt].yMin = 0;
            C[cCnt].yMax = 1.0/10.0;

            break;

        }

        cCnt++;

    }

}

void Fonts::drawFonts(int i)
{

    tLoad->binder(tex);

    glPushMatrix();
    //glTranslated(pos.x,pos.y,zoom);
    glRotated(rotation.x,1,0,0);
    glRotated(rotation.y,0,1,0);
    glRotated(rotation.z,0,0,1);

   glBegin(GL_QUADS);
       //glTexCoord2f(C[i].xMin,1.0);
       glTexCoord2f(C[i].xMin,C[i].yMax);
       glVertex3f(0,0,0);

       //glTexCoord2f(C[i].xMax,1.0);
       glTexCoord2f(C[i].xMax,C[i].yMax);
       glVertex3f(1.0/13.0, 0,0);

       //glTexCoord2f(C[i].xMax,0.0);
       glTexCoord2f(C[i].xMax,C[i].yMin);
       glVertex3f(1.0/13.0, 1.0/10.0,0);

       //glTexCoord2f(C[i].xMin,0.0);
       glTexCoord2f(C[i].xMin,C[i].yMin);
       glVertex3f(0,1.0/10.0,0);

    glEnd();

    glPopMatrix();

}
