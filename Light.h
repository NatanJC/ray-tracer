//
//  Light.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Light__
#define __Light__

#include <stdio.h>
#include "Vector3D.h"
#include "ShadeRec.h"

class Light {
    public:
    
        Light(void);
    
        Light(const Light& ls);
    
        Light&
        operator= (const Light& rhs);
    
        ~Light(void);
    
        virtual Vector3D
        get_direction(ShadeRec& sr) = 0;
    
        virtual RGBColor
        L(ShadeRec& sr) = 0;
};

#endif /* __Light__ */
