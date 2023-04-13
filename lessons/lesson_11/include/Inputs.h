#ifndef INPUTS_H
#define INPUTS_H
#include<windows.h>
#include <Model.h>
#include <parallax.h>
#include <player.h>
#include <sounds.h>
#include<skyBox.h>

class Inputs
{
    public:
        Inputs();
        virtual ~Inputs();

        void keyPressed(Model *);
        void keyPressed(skyBox *);
        void keyPlayer(player *, sounds*);
        void keyUp();

        void mouseBtnDwn(Model *, double, double);
        void mouseBtnUp();
        void mouseWheel(Model *,double);
        void mouseMove(Model *,double, double);
        void mouseMove(skyBox*, double, double);

        void keyEnv(parallax*, float);

        WPARAM wParam;

        double prev_Mx;
        double prev_My;

        bool Mouse_translate =false;
        bool Mouse_Rotate =false;

      //  Model *mdl=new Model();

    protected:

    private:
};

#endif // INPUTS_H
