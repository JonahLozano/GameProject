#ifndef FONTS_H
#define FONTS_H

#include<commons.h>
#include<textureLoader.h>

typedef struct{

    char letter;
    float xMin, xMax, yMin, yMax;
    float offset;
    vec3 fontSize;

}charSet;

class Fonts
{
    public:
        Fonts();
        virtual ~Fonts();
        void initFonts(char*);
        void buildFonts(char*);

        void drawFonts(int);

        charSet C[1024];

        vec3 rotation;
        vec3 pos;
        float zoom;

        int cCnt; //character counter
        GLuint tex; //texture handler

        textureLoader *tLoad = new textureLoader();


    protected:

    private:
};

#endif // FONTS_H
