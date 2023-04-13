#ifndef COMMONS_H
#define COMMONS_H

#include <SNDS/irrKlang.h>
using namespace irrklang;


#include<iostream>
#include<string.h>
using namespace std;



#include<math.h>
#include<time.h>
#define GRAVITY 9.81
#define PI 3.14159

typedef struct{


    float x;
    float y;
    float z;



}vec3;


typedef struct{


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
