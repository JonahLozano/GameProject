#ifndef CLOUDBLOCK_H
#define CLOUDBLOCK_H
#include "commons.h"

class CloudBlock : public Block
{
    public:
        CloudBlock();
        virtual ~CloudBlock();

        void draw() const override;

    protected:

    private:
};

#endif // CLOUDBLOCK_H
