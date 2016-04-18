//
//  Material.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//


#ifndef __Material__
#define __Material__

#include "World.h"
#include "RGBColor.h"
#include "ShadeRec.h"

class Material {
    
public:
    
    Material(void);
    
    Material(const Material& material);
    
    virtual Material*
    clone(void) const = 0;
    
    virtual
    ~Material(void);
    
    virtual RGBColor
    shade(ShadeRec& sr);
    
    virtual RGBColor
    area_light_shade(ShadeRec& sr);
    
    virtual RGBColor
    path_shade(ShadeRec& sr);
    
protected:
    
    Material&
    operator= (const Material& rhs);
};

#endif /* __Material__*/
