#ifndef LIGHT_H
#define LIGHT_H

#include <cfloat>
#include <Vector3f.h>

#include "Object3D.h"

class Light
{
public:

    Light();
    virtual ~Light();
    
    virtual void getIllumination( const Vector3f& p, Vector3f& dir, Vector3f& col, float& distanceToLight ) const = 0;

};


#endif // LIGHT_H
