#ifndef BLOCK_H
#define BLOCK_H
#include <GL/gl.h>
#include "textureLoader.h"

class Block
{
    public:
        Block();
        virtual ~Block();

        virtual void draw() const = 0;

        void drawBlock();
        void initBlock(GLuint);
        void blockTexture(char*);
        void placeBlock(float,float,float);

        GLuint tex;
        textureLoader *tLoad = new textureLoader();

        float x,y,scale;

    protected:

    private:
};

#endif // BLOCK_H
