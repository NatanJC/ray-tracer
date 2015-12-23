//
//  GeometricObject.cpp
//  ray tracing
//
//  Created by Natan Chawalitcheewin
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//


#include "GeometricObject.h"

//default constructor
GeometricObject::GeometricObject(void)
{}


//copy constructor
GeometricObject::GeometricObject (const GeometricObject& object)
{}


//assignment operator
GeometricObject&
GeometricObject::operator= (const GeometricObject& rhs) {
    if (this == &rhs)
        return (*this);
    
    return (*this);
}


//destructor
GeometricObject::~GeometricObject (void)
{}
