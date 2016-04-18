//
//  Light.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#include "Light.h"
#include "Constants.h"

//default constructor
Light::Light(void)
{}


//copy constructor
Light::Light(const Light& ls)
{}


//operator
Light&
Light::operator= (const Light& rhs) {
    
    if (this == &rhs)
        return (*this);
    
    return (*this);
}


//destructor
Light::~Light(void) {}


//L function (return the radiance)
RGBColor
Light::L(ShadeRec& s) {
    return (black);
}
