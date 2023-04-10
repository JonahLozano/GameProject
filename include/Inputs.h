#ifndef INPUTS_H
#define INPUTS_H
#include <windows.h>
#include "Model.h"
#include "parallax.h"
#include "player.h"
// #include "commons.h"
#include "levelLoader.h"
#include "GL_Scene.h"

class Inputs
{
    public:
        Inputs();
        virtual ~Inputs();

        void keyPressed(Model *);
        void keyPlayer(player *, sounds*);
        void keyUp();

        void mouseBtnDwn(Model *,double,double);
        void mouseBtnUp();
        void mouseWheel(Model *,double);
        void mouseMove(Model *,double,double);
        void keyEnv(parallax *,float);
        void keyMap(levelLoader *,float,float);

        WPARAM wParam;

        double prev_Mx;
        double prev_My;

        bool Mouse_Translate = false;
        bool Mouse_Rotate = false;

        // Model *mdl=new Model();

    protected:

    private:
};

#endif // INPUTS_H
