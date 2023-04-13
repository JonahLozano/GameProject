#ifndef ENMS_H
#define ENMS_H

#include <GL/gl.h>

#include <textureLoader.h>
#include <commons.h>
#include <time.h>

class enms
{
    public:
        enms();
        virtual ~enms();

        void drawEnemy();
        void placeEnemy(vec3); //x, y, z, pos of enemy placement
        void initEnemy(GLuint, int, int); //enemy initialization with image file name and hframes and vframes
        void enemyTexture(char*);

        enum acts{IDLE,WALKR,WALKL,ROLLR,ROLLL,JUMP,ATTACK,DIE}; //0, 1, 2, 3, 4, 5

        void actions();
        acts action;

        int hFrames; //horizontal num of frames
        int vFrames; //vertical num of frames

        vec3 ePos; //position of the enemy
        vec2 eSize; //
        vec2 eSpeed; //move speed, x and y direction

        vec3 eRot; //x, y, z rotation
        clock_t startTime;

        float xMax, yMax, xMin, yMin; //values that help us get a frame, for the texture
        GLuint tex; //
        textureLoader *tLoad = new textureLoader();

        float theta; //angle of enemy roll
        float velocity; //speed of enemy roll
        float t; //t is time on projectiles


    protected:

    private:
};

#endif // ENMS_H
