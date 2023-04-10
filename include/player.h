#ifndef PLAYER_H
#define PLAYER_H
#include <GL/gl.h>
#include "textureLoader.h"
#include "commons.h"
#include "sounds.h"

class player
{
    public:
        player();
        virtual ~player();

        vec3 scaleSize();
        vec3 verts[4];

        enum acts{IDLE,WALKLEFT,WALKRIGHT,JUMP,ATTACK,DIE};

        char playerDir; // to find out where the player heading

        float runSpeed;
        float jumpSpeed;
        acts actionTrigger;

        void drawPlayer();
        void playerInit(char *,int,int);
        void actions(acts,sounds*);

        int hFrames; // horizontal frames
        int vFrames; // vertical frames

        vec3 pPos;

        float xMax,yMax,xMin,yMin;

        GLuint tex;
        textureLoader *tLoad = new textureLoader();

        float scale;
        void setScale(float);

    protected:

    private:
};

#endif // PLAYER_H
