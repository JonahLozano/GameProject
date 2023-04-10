#include "../include/sounds.h"
#include "../include/commons.h"

sounds::sounds()
{
    //ctor
}

sounds::~sounds()
{
    //dtor
    engine->drop();
}
void sounds::playMusic(char* File)
{
    engine->play2D(File, true, false);
}

void sounds::playSound(char* File)
{
    if(!engine->isCurrentlyPlaying(File))
        engine->play2D(File,false, false);
}

void sounds::pauseSound(char*)
{

}

int sounds::initSound()
{
    if(!engine) cout << "The Sound Engine did not start" << endl;
}
