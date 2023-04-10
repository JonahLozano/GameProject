#ifndef COMMONS_H
#define COMMONS_H

#include <math.h>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <SNDS/irrklang.h>
using namespace std;
using namespace irrklang;

#include "Block.h"
#include "AirBlock.h"
#include "GrassBlock.h"
#include "BoundaryBlock.h"
#include "ChestBlock.h"
#include "CloudBlock.h"
#include "EnemyBlock.h"
#include "FinishBlock.h"
#include "SpawnBlock.h"

#define GRAVITY 9.81
#define PI 3.14159

typedef struct
{
    float x;
    float y;
    float z;
}vec3;

typedef struct
{
    float x;
    float y;
}vec2;

class commons
{
    public:
        commons();
        virtual ~commons();

    protected:

    private:
};

#endif // COMMONS_H
