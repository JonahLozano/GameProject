#ifndef CHECKCOLLISION_H
#define CHECKCOLLISION_H
#include<commons.h>

class checkCollision
{
    public:
        checkCollision();
        virtual ~checkCollision();

    bool isLinearCollision(float , float );
    bool isRadialCollision(float , float , float , float , float, float);
    bool isSphereCollision(vec3 , vec3 );
    bool isQuadCollision(vec2 , vec2 );

    protected:

    private:
};

#endif // CHECKCOLLISION_H
