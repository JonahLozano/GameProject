#include "sounds.h"

sounds::sounds()
{
    //ctor
}

sounds::~sounds()
{
    //dtor
    engine->drop();
}

void sounds::playMusic(char* fileName)
{
    engine->play2D(fileName, true); //true for running on loop
}

void sounds::playSound(char* fileName)
{
    if(!engine->isCurrentlyPlaying(fileName)){
        engine->play2D(fileName, false, false);
    }
}

void sounds::pauseSound(char* fileName)
{
    engine->play2D(fileName, true, false);
}

int sounds::initSound()
{

    if(!engine){

        cout << "The Sound Engine did not start\n";
        return 0;

    }

    return 1;

}
