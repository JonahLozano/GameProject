#ifndef PARALLAX_H
#define PARALLAX_H
#include "textureLoader.h"
#include <time.h>

class parallax
{
    public:
        parallax();
        virtual ~parallax();

        void drawSquare(float,float);
        void initParallax(char*);
        void scroll(bool,std::string,float);

        double xMin,xMax,yMin,yMax;

        textureLoader *bTex = new textureLoader();

        clock_t startTime;

        GLuint tex;

    protected:

    private:
};

#endif // PARALLAX_H
