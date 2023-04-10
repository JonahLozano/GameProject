#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include <SOIL.h>
#include <GL/gl.h>
#include <iostream>


class textureLoader
{
    public:
        textureLoader();                    // Constructor
        virtual ~textureLoader();           // Destructor

        void loadTexture(char *, GLuint&);  // Image loader
        unsigned char* image;               // Image binder

        int width,height;                   // Image data
        void binder(GLuint);                // Image dimensions

        // GLuint test;


    protected:

    private:
};

#endif // TEXTURELOADER_H
