//
//  PointLight.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __POINTLIGHT__
#define __POINTLIGHT__

#include "Light.h"
#include "ShadeRec.h"

class PointLight: public Light {
    
public:
    
    PointLight(void);
    
    PointLight(const PointLight& a);
    
    virtual Light*
    clone(void) const;
    
    PointLight&
    operator= (const PointLight& rhs);
    
    virtual
    ~PointLight(void);
    
    virtual Vector3D
    get_direction(ShadeRec& sr);
    
    virtual RGBColor
    L(ShadeRec& sr);
    
    void
    set_location(float x, float y, float z);
    
    void
    scale_radiance(float _r);

    
private:
    
    float ls;
    RGBColor color;
    Point3D location;
};

inline void
PointLight::set_location(float _x, float _y, float _z) {
    location.x = _x; location.y = _y; location.z = _z;
}

inline void
PointLight::scale_radiance(float _r) {
    ls *= _r;
}

#endif
