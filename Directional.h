//
//  Directional.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Directional__
#define __Directional__

#include <stdio.h>

#include "Light.h"
#include "ShadeRec.h"

class Directional: public Light {
    
public:
    
    Directional(void);
    
    Directional(const Directional& dl);
    
    virtual Light*
    clone(void) const;
    
    Directional&
    operator= (const Directional& rhs);
    
    virtual
    ~Directional(void);
    
    void
    set_direction(Vector3D d);

    void
    set_direction(float dx, float dy, float dz);
    
    virtual Vector3D
    get_direction(ShadeRec& sr);
    
    virtual RGBColor
    L(ShadeRec& sr);
    
    void
    scale_radiance(const float b);
    
    //set color
    void
    set_color(const float c);
    
    void
    set_color(const RGBColor& c);
    
    void
    set_color(const float r, const float g, const float b);
    
private:
    
    float ls;
    RGBColor color;
    Vector3D dir;
};


inline void
Directional::scale_radiance(float b) {
    ls = b;
}

inline void
Directional::set_direction(Vector3D d) {
    dir = d;
    dir.normalize();
}

inline void
Directional::set_direction(float dx, float dy, float dz) {
    dir.x = dx; dir.y = dy; dir.z = dz;
    dir.normalize();
}

inline void
Directional::set_color(const float c) {
    color.r = c; color.g = c; color.b = c;
}

inline void
Directional::set_color(const RGBColor& c) {
    color = c;
}

inline void
Directional::set_color(const float r, const float g, const float b) {
    color.r = r; color.g = g; color.b = b;
}



#endif /* __Directional__ */
