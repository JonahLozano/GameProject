#ifndef FINISHBLOCK_H
#define FINISHBLOCK_H
#include "commons.h"

class FinishBlock : public Block
{
    public:
        FinishBlock();
        virtual ~FinishBlock();

        void draw() const override;

    protected:

    private:
};

#endif // FINISHBLOCK_H
