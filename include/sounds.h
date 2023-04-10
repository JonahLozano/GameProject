#ifndef SOUNDS_H
#define SOUNDS_H

#include "commons.h"

class sounds
{
    public:
        sounds();
        virtual ~sounds();

        ISoundEngine* engine = createIrrKlangDevice();

        void playMusic(char *); //
        void playSound(char *); // attack sound
        void pauseSound(char *);
        int initSound();

    protected:

    private:
};

#endif // SOUNDS_H
