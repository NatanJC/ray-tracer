//
//  Tracer.cpp
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 11/5/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#include "World.h"
#include "Tracer.h"

//default constructor
Tracer::Tracer(void)
: world_ptr(NULL) {}

//constructor
Tracer::Tracer(World*w_ptr)
: world_ptr(w_ptr) {}

//destructor
Tracer::~Tracer(void) {
    if (world_ptr)
        world_ptr = NULL;
}

//trace ray function
RGBColor
Tracer::trace_ray(const Ray& ray) const{
    return (black);
}

//trace ray function with depth
RGBColor
Tracer::trace_ray(const Ray ray, const int depth) const {
    return (black);
}