#ifndef GL_LIGHT_H
#define GL_LIGHT_H

#include "GL_Scene.h"

#include <GL/gl.h>


class GL_Light:GL_Scene
{
    public:
        GL_Light(GLenum Light);
        virtual ~GL_Light();

        GLfloat light_ambient[4]  = { 0.0f, 0.0f, 0.0f, 1.0f };
        GLfloat light_diffuse[4]  = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat light_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat light_position[4] = { 2.0f, 5.0f, 5.0f, 0.0f };

        GLfloat mat_ambient[4]    = { 0.7f, 0.7f, 0.7f, 1.0f };
        GLfloat mat_diffuse[4]    = { 0.8f, 0.8f, 0.8f, 1.0f };
        GLfloat mat_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat high_shininess[1] = { 100.0f };

        void setLight(GLenum);

    protected:

    private:
};

#endif // GL_LIGHT_H
