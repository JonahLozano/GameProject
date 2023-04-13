#ifndef SKYBOX_H
#define SKYBOX_H

#include<commons.h>
#include<textureLoader.h>

class skyBox
{
    public:
        skyBox();
        virtual ~skyBox();

        void initSkyBox(); //initialize skybox
        void drawSkyBox(); //draw skybox n scene

        textureLoader *sTex = new textureLoader(); //texture loader

        GLuint tex[6]; //need 6 texture handlers for skybox

        float rotateX;
        float rotateY;
        float rotateZ;

        float zoom;
        float posX;
        float posY;

        vec3 scale;

    protected:

    private:
};

#endif // SKYBOX_H
