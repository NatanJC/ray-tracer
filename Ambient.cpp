//
//  Ambient.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#include "Ambient.h"

//default constrcutor = white light
Ambient::Ambient(void)
    :   Light(),
        ls(1.0),
        color(1.0)
{}

//copy constructor
Ambient::Ambient(const Ambient& a)
    : 	Light(a),
        ls(a.ls),
        color(a.color)
{}

//clone
Light*
Ambient::clone(void)const {
    return (new Ambient(*this));
}

//operation
Ambient&
Ambient::operator = (const Ambient& rhs) {
    if (this == &rhs)
        return (*this);
    
    Light::operator= (rhs);
    
    ls = rhs.ls;
    color = rhs.color;
    
    return (*this);
}

//destructor
Ambient::~Ambient(void)
{}

//get direction
Vector3D
Ambient::get_direction(ShadeRec &sr){
    return (Vector3D(0.0));
}

//L function
RGBColor
Ambient::L(ShadeRec &sr){
    return (ls * color);
}