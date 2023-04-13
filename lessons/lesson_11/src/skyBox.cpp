#include "skyBox.h"

skyBox::skyBox()
{
    //ctor

    rotateX = 0.0;
    rotateY = 0.0;
    rotateZ = 0.0;

    scale.x = scale.y = scale.z = 100.0;

    zoom = 0.0;
    posX = 0.0;
    posY = 0.0;
}

skyBox::~skyBox()
{
    //dtor
}

void skyBox::initSkyBox()
{

    glGenTextures(6,tex);
    sTex->loadTexture("images/front.jpg", tex[0]);
    sTex->loadTexture("images/back.jpg", tex[1]);
    sTex->loadTexture("images/top.jpg", tex[2]);
    sTex->loadTexture("images/bottom.jpg", tex[3]);
    sTex->loadTexture("images/left.jpg", tex[4]);
    sTex->loadTexture("images/right.jpg", tex[5]);
}

void skyBox::drawSkyBox()
{

 glPushMatrix();
 glDisable(GL_LIGHTING);
 glColor3f(1.0,1.0,1.0);
 //glClearColor(1.0,1.0,1.0,1.0);
 glScalef(scale.x, scale.y, scale.z);
 glTranslated(posX,posY,zoom);
 glRotated(rotateX,1,0,0);
 glRotated(rotateY,0,1,0);
 glRotated(rotateZ,0,0,1);

 glBindTexture(GL_TEXTURE_2D, tex[0]);
 glBegin(GL_QUADS);
 glNormal3f(0.0f, 0.0f, 1.0f); // Normal Front Face
 glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f); // Bottom Left Of The Texture and Quad
 glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f); // Bottom Right Of The Texture and Quad
 glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -1.0f, 1.0f); // Top Right Of The Texture and Quad
 glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f); // Top Left Of The Texture and Quad
 glEnd();

  glBindTexture(GL_TEXTURE_2D, tex[1]);
  glBegin(GL_QUADS);
 glNormal3f(0.0f, 0.0f, -1.0f); // Normal Back Face
 glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f); // Bottom Right Of The Texture and Quad
 glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // Top Right Of The Texture and Quad
 glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f); // Top Left Of The Texture and Quad
 glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, 1.0f, -1.0f); // Bottom Left Of The Texture and Quad
 glEnd();

  glBindTexture(GL_TEXTURE_2D, tex[2]);
  glBegin(GL_QUADS);
 glNormal3f(0.0f, 1.0f, 0.0f); // Normals Top Face
 glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f); // Top Left Of The Texture and Quad
 glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f); // Bottom Left Of The Texture and Quad
 glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f); // Bottom Right Of The Texture and Quad
 glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f); // Top Right Of The Texture and Quad
 glEnd();

  glBindTexture(GL_TEXTURE_2D, tex[3]);
  glBegin(GL_QUADS);
 glNormal3f(0.0f, -1.0f, 0.0f); // Bottom Face
 glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f); // Top Right Of The Texture and Quad
 glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, 1.0f); // Top Left Of The Texture and Quad
 glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f); // Bottom Left Of The Texture and Quad
 glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom Right Of The Texture and Quad
 glEnd();

  glBindTexture(GL_TEXTURE_2D, tex[4]);
  glBegin(GL_QUADS);
 glNormal3f(1.0f, 0.0f, 0.0f); // Right face
 glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, -1.0f); // Bottom Right Of The Texture and Quad
 glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f); // Top Right Of The Texture and Quad
 glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, 1.0f); // Top Left Of The Texture and Quad
 glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f); // Bottom Left Of The Texture and Quad
 glEnd();

  glBindTexture(GL_TEXTURE_2D, tex[5]);
 glBegin(GL_QUADS);
 glNormal3f(-1.0f, 0.0f, 0.0f); // Left Face
 glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, -1.0f); // Bottom Left Of The Texture and Quad
 glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f); // Bottom Right Of The Texture and Quad
 glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f); // Top Right Of The Texture and Quad
 glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f); // Top Left Of The Texture and Quad
 glEnd();
 glEnable(GL_LIGHTING);
 glPopMatrix();

}
