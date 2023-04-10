#ifndef BOUNDARYBLOCK_H
#define BOUNDARYBLOCK_H
#include "commons.h"

class BoundaryBlock : public Block
{
    public:
        BoundaryBlock();
        virtual ~BoundaryBlock();

        void draw() const override;

    protected:

    private:
};

#endif // BOUNDARYBLOCK_H
