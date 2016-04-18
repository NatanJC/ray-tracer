//
//  SingleSphere.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//


#include "SingleSphere.h"
#include "World.h"
#include "ShadeRec.h"


SingleSphere::SingleSphere(void)
    :   Tracer()
{}

//constructor

SingleSphere::SingleSphere(World* _worldPtr)
    :   Tracer(_worldPtr)
{}


//destructor
SingleSphere::~SingleSphere(void)
{}

//trace ray function
RGBColor SingleSphere::trace_ray(const Ray& ray) const {
    ShadeRec sr(*world_ptr);
    double t;
    
    if(world_ptr->sphere.hit(ray, t, sr))
        return (red);
    else
        return (black);
}