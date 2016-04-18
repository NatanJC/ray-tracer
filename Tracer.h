//
//  Tracer.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
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
        Tracer(void);
    
        Tracer(World*w_ptr);
    
        ~Tracer(void);
    
        virtual RGBColor
        trace_ray(const Ray& ray) const;
    
        virtual RGBColor
        trace_ray(const Ray ray, const int depth) const;
    
    protected:
        World* world_ptr;
};

#endif /* __Tracer__ */
