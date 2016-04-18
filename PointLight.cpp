//
//  PointLight.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//
#include "PointLight.h"
#include "World.h"

//default constructor
PointLight::PointLight (void)
    :	Light(),
        ls(1.0),
        color(1.0),
        location()
{}


//copy constructor
PointLight::PointLight (const PointLight& a)
    :	Light(a),
        ls(a.ls),
        color(a.color),
        location(a.location)
{}


//clone
Light*
PointLight::clone(void) const {
    return (new PointLight(*this));
}


//operator
PointLight&
PointLight::operator = (const PointLight& rhs) {
    if (this == &rhs)
        return (*this);
    
    Light::operator = (rhs);
    
    ls = rhs.ls;
    color = rhs.color;
    location = rhs.location;
    
    return (*this);
}


//destructor
PointLight::~PointLight (void)
{}


//get direction
Vector3D
PointLight::get_direction(ShadeRec& sr) {
    return ((location - sr.hit_point).hat());
}


//L function
RGBColor
PointLight::L(ShadeRec& sr) {
    return (ls * color);
}


