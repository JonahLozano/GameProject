#ifndef SOUNDS_H
#define SOUNDS_H
#include<commons.h>


class sounds
{
    public:
        sounds();
        virtual ~sounds();

        //ISoundEngine* engine = createIrrKlangDevice();
        ISoundEngine* engine = createIrrKlangDevice();

        void playMusic(char* );
        void playSound(char* );
        void pauseSound(char* );
        int initSound();

    protected:

    private:
};

#endif // SOUNDS_H
