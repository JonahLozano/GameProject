#ifndef PLAYER_H
#define PLAYER_H
#include <GL/gl.h>

#include <textureLoader.h>
#include <commons.h>
#include <sounds.h>

class player
{
    public:
        player();
        virtual ~player();

        vec3 scaleSize; //width. height, length, 3 values
        vec3 verts[4]; //four corners of quad, 12 values
        enum acts{IDLE,WALKR,WALKL,JUMP,ATTACK,DIE}; //0, 1, 2, 3, 4, 5

        float runSpeed;
        float jumpSpeed;

        acts actionTrigger;

        void drawPlayer();
        void playerInit(char*, int, int); //player initialization
        void actions(acts, sounds*);

        int hFrames; //horizontal num of frames
        int vFrames; //vertical num of frames

        vec3 pPos;

        float xMax, yMax, xMin, yMin; //values that help us get a frame
        GLuint tex;
        textureLoader *tLoad = new textureLoader();

        char playerDir; //to find out where the player is heading


    protected:

    private:
};

#endif // PLAYER_H
