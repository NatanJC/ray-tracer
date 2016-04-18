//
//  Ambient.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Ambient__
#define __Ambient__

#include <stdio.h>
#include "Light.h"

class Ambient: public Light{
    public:
    
        Ambient(void);
    
        Ambient (const Ambient& a);
    
        virtual Light*
        clone(void) const;
    
        Ambient&
        operator = (const Ambient& rhs);
    
        ~Ambient(void);
    
        void
        scale_radiance(const float b);
    
        virtual Vector3D
        get_direction(ShadeRec& sr);
    
        virtual RGBColor
        L(ShadeRec& sr);
    
        void
        set_color(const float c);
    
        void
        set_color(const RGBColor& c);
    
        void
        set_color(const float r, const float g, const float b);
    
    private:
        float ls;
        RGBColor color;
};

inline void
Ambient::scale_radiance(const float b) {
    ls = b;
}

inline void
Ambient::set_color(const float c) {
    color.r = c; color.g = c; color.b = c;
}


#endif /* __Ambient__ */
