//
//  Directional.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#include "Directional.h"

//constructor
Directional::Directional(void)
    : 	Light(),
        ls(1.0),
        color(1.0),
        dir(0, 1, 0)
{}

//copy
Directional::Directional(const Directional& dl)
    :   Light(dl),
        ls(dl.ls),
        color(dl.color),
        dir(dl.dir)
{}


//clone
Light*
Directional::clone(void) const {
    return (new Directional(*this));
}

//operator
Directional&
Directional::operator= (const Directional& rhs)
{
    if (this == &rhs)
        return (*this);
    
    Light::operator= (rhs);
    
    ls		= rhs.ls;
    color 	= rhs.color;
    dir 	= rhs.dir;
    
    return (*this);
}


//destructor
Directional::~Directional(void)
{}


//get direction
Vector3D
Directional::get_direction(ShadeRec &sr) {
    return dir;
}

//L
RGBColor
Directional::L(ShadeRec& s) {
    return (ls * color);
}





