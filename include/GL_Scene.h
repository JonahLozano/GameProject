#ifndef GL_SCENE_H
#define GL_SCENE_H

#include <windows.h>
#include <iostream>
#include <string.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "Model.h"
#include "Inputs.h"
#include "parallax.h"

using namespace std;

class GL_Scene
{
    public:
        GL_Scene();
        virtual ~GL_Scene();
        int drawScene(); // main renderer
        int GLinit(); // initalization of the scene
        void GLReSize(GLsizei,GLsizei); // callback function for resize

        int winMsg(HWND,UINT,WPARAM,LPARAM);

        int screenWidth, screenHeight;

        double zoom;

    protected:

    private:
};

#endif // GL_SCENE_H
