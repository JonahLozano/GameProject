#ifndef ENEMYBLOCK_H
#define ENEMYBLOCK_H
#include "commons.h"

class EnemyBlock : public Block
{
    public:
        EnemyBlock();
        virtual ~EnemyBlock();

        void draw() const override;

    protected:

    private:
};

#endif // ENEMYBLOCK_H
