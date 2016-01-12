//
//  GeometricObject.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//


#include "GeometricObject.h"
#include "Constants.h"

//default constructor
GeometricObject::GeometricObject(void)
    : color(black)
{}


//constructor
GeometricObject::GeometricObject (const GeometricObject& object)
    : color(object.color)
{}


//operator
GeometricObject&
GeometricObject::operator= (const GeometricObject& rhs) {
    if (this == &rhs)
        return (*this);
    color = rhs.color;
    
    return (*this);
}


//destructor
GeometricObject::~GeometricObject (void)
{}
