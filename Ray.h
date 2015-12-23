//
//  Ray.h
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 9/28/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

//#ifndef ray_tracing_Ray_h
//#define ray_tracing_Ray_h

#ifndef __RAY__
#define __RAY__

#include <iostream>
#include "Point3D.h"
class Ray {
    public:
    
        Point3D o;  //origin
        Vector3D d; //direction
    
        Ray(void);  //default constructor
    
        Ray(const Point3D& origin, const Vector3D& dir); //constructor
    
        Ray(const Ray& ray);    //copy constructor
    
        Ray&        //assignment operator
        operator= (const Ray& rhs);
    
        ~Ray(void); //destructor
};

#endif
