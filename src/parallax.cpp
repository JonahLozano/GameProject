#include "../include/parallax.h"

parallax::parallax()
{
    //ctor
    xMin = 0.0;
    xMax = 1.0;

    yMin = 0.0;
    yMax = 1.0;

    startTime = clock();

}

parallax::~parallax()
{
    //dtor
}

void parallax::drawSquare(float width, float height)
{
    glColor3f(1.0f,1.0f,1.0f);
    bTex->binder(tex);

    float thing = -8.0f;

    glBegin(GL_POLYGON);
        glTexCoord2f(xMin,yMin);
        glVertex3f(-1.0f*width/height, 1.0f, thing);

        glTexCoord2f(xMax,yMin);
        glVertex3f(width/height, 1.0f, thing);

        glTexCoord2f(xMax,yMax);
        glVertex3f(width/height, -1.0f, thing);

        glTexCoord2f(xMin,yMax);
        glVertex3f(-1.0f*width/height, -1.0f, thing);


    glEnd();
}

void parallax::initParallax(char *fileName)
{
    bTex->loadTexture(fileName, tex);
}

void parallax::scroll(bool scrll, std::string dir, float speed)
{
    if(scrll)
    {
        if(clock() - startTime > 15)
        {
            if(dir == "x"){xMin += speed;xMax += speed;}
            else if(dir == "-x"){xMin -= speed;xMax -= speed;}
            else if(dir == "y"){yMin += speed;yMax += speed;}
            else if(dir == "-y"){yMin -= speed;yMax -= speed;}

            startTime = clock();
        }
    }
}
