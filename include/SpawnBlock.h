#ifndef SPAWNBLOCK_H
#define SPAWNBLOCK_H
#include "commons.h"

class SpawnBlock : public Block
{
    public:
        SpawnBlock();
        virtual ~SpawnBlock();

        void draw() const override;

    protected:

    private:
};

#endif // SPAWNBLOCK_H
