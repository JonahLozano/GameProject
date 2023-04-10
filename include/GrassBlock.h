#ifndef GRASSBLOCK_H
#define GRASSBLOCK_H
#include "commons.h"

class GrassBlock : public Block
{
    public:
        GrassBlock();
        virtual ~GrassBlock();

        void draw() const override;

    protected:

    private:
};

#endif // GRASSBLOCK_H
