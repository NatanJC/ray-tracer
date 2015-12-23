//
//  Tracer.h
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 11/5/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Tracer__
#define __Tracer__

#include <iostream>
#include "Constants.h"
#include "Ray.h"
#include "RGBColor.h"

class World;

class Tracer {
    public:
        Tracer(void); //constructor
    
        Tracer(World*w_ptr); //constructor
    
        ~Tracer(void); //destructor
    
        virtual RGBColor
        trace_ray(const Ray& ray) const; //trace ray
    
        virtual RGBColor
        trace_ray(const Ray ray, const int depth) const; //trace ray
    
    protected:
        World* world_ptr;
};

#endif /* defined(__Tracer__) */
