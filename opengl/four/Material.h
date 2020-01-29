#ifndef MATERIAL_H
#define MATERIAL_H

#include <cassert>
#include <vecmath.h>

#include "Ray.h"
#include "Hit.h"

class Material
{
public:

    Material( const Vector3f& d_color )
    {
        diffuseColor = d_color;
    }

    virtual ~Material()
    {

    }

    virtual Vector3f getDiffuseColor() const = 0;

    virtual Vector3f Shade( const Ray& ray, const Hit& hit,
            const Vector3f& dirToLight, const Vector3f& lightColor ) const = 0;

protected:

    Vector3f diffuseColor;
     
};

#endif // MATERIAL_H
