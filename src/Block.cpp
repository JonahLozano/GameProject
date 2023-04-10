#include "Block.h"

Block::Block()
{
    //ctor

    x = 0;
    y = 0;
    scale = 0.01f;
}

Block::~Block()
{
    //dtor
}

void Block::drawBlock()
{
    tLoad->binder(tex);
    glPushMatrix();
        // glTranslatef(-scalething*10,scalething*10,1.0f);
        // glTranslatef(x,y,-1.0f);

        glScalef(scale,scale,1.0f);
        // glTranslatef(-x,-y,-1.0f);

        glTranslatef(x,y,-1.0f);

        glBegin(GL_QUADS);
            glTexCoord2f(0,0);
            glVertex3f(1.0,1.0,0.0);

            glTexCoord2f(1,0);
            glVertex3f(-1.0,1.0,0.0);

            glTexCoord2f(1,1);
            glVertex3f(-1.0,-1.0,0.0);

            glTexCoord2f(0,1);
            glVertex3f(1.0,-1.0,0.0);
        glEnd();

    glPopMatrix();
}

void Block::initBlock(GLuint)
{
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
//
//    this->tex = tex;
}

void Block::blockTexture(char* fileName)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    tLoad->loadTexture(fileName,tex);
}

void Block::placeBlock(float x, float y, float scale)
{
    this->x = x;
    this->y = y;
    this->scale = scale;
}
