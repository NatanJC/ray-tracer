//
//  Plane.cpp
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 10/6/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#include "Plane.h"
#include "ShadeRec.h"

const double Plane::kEpsilon = 0.001;

Plane::Plane(void) {
    
}

Plane::Plane(const Point3D &p, const Normal &n) {
    
}

// ---------------------------------------------------------------- copy constructor

Plane::Plane(const Plane& plane)
:	GeometricObject(plane),
    point(plane.point),
    normal(plane.normal)
{}


// ---------------------------------------------------------------- clone

Plane*
Plane::clone(void) const {
    return (new Plane(*this));
}


// ---------------------------------------------------------------- assignment operator

Plane&
Plane::operator= (const Plane& rhs)	{
    
    if (this == &rhs)
        return (*this);
    
    GeometricObject::operator= (rhs);
    
    point = rhs.point;
    normal = rhs.normal;
    
    return (*this);
}

//destructor
Plane::~Plane(void)
{}

//hit function
bool
Plane::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
    double t = (point - ray.o) * normal / (ray.d * normal);
    
    if(t > kEpsilon) {
        tmin = t;
        sr.normal = normal;
        sr.local_hit_point = ray.o +t * ray.d;
        
        return (true);
    }
    
    else
        return (false);
    
}

