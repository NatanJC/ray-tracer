//
//  GeometricObject.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//


#include "GeometricObject.h"
#include "Constants.h"
#include "Material.h"

//default constructor
GeometricObject::GeometricObject(void)
    : material_ptr(NULL)
{}


//constructor
GeometricObject::GeometricObject (const GeometricObject& object) {
    if (object.material_ptr)
        material_ptr = object.material_ptr->clone();
    else
        material_ptr = NULL;
}


//operator
GeometricObject&
GeometricObject::operator= (const GeometricObject& rhs) {
    if (this == &rhs)
        return (*this);
    
    if (material_ptr) {
        delete material_ptr;
        material_ptr = NULL;
    }
    
    if (rhs.material_ptr)
        material_ptr = rhs.material_ptr->clone();
    return (*this);
}


//destructor
GeometricObject::~GeometricObject (void) {
    if (material_ptr) {
        delete material_ptr;
        material_ptr = NULL;
    }
}


//set material function
void
GeometricObject::set_material(Material* mPtr) {
    material_ptr = mPtr;
}


