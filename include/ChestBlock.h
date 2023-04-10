#ifndef CHESTBLOCK_H
#define CHESTBLOCK_H
#include "commons.h"

class ChestBlock : public Block
{
    public:
        ChestBlock();
        virtual ~ChestBlock();

        void draw() const override;

    protected:

    private:
};

#endif // CHESTBLOCK_H
