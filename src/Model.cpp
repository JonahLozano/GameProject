#include "../include/Model.h"

Model::Model()
{
    //ctor
    x_rotate = 0;
    y_rotate = 0;
    z_rotate = 0;

    zoom = -3.0f;

    x_pos = 0.0f;
    y_pos = 0.0f;
}

Model::~Model()
{
    //dtor
}
void Model::drawModel()
{
    tLoad->binder(tex);
    glTranslated(x_pos,y_pos,zoom);
    glRotated(x_rotate,1,0,0);
    glRotated(y_rotate,0,1,0);
    glRotated(z_rotate,0,0,1);

    glutSolidTeapot(1.5f);
}

void Model::modelInit(char *fileName)
{
    // glEnable(GL_COLOR_MATERIAL);
    tLoad->loadTexture(fileName, tex);
}
