#ifndef MODEL_H
#define MODEL_H

#include <windows.h>
#include <GL/glut.h>
#include "textureLoader.h"

class Model
{
    public:
        Model();
        virtual ~Model();

        void drawModel();
        void modelInit(char *fileName);

        float x_rotate,y_rotate,z_rotate;
        float zoom;
        float x_pos,y_pos;

        GLuint tex;
        textureLoader *tLoad = new textureLoader();

    protected:

    private:
};

#endif // MODEL_H
