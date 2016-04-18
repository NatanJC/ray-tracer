//
//  MultipleObjects.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#include "MultipleObjects.h"
#include "RGBColor.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "World.h"

//default constructor
MultipleObjects::MultipleObjects(void)
    :   Tracer()
{}

//constructor
MultipleObjects::MultipleObjects(World* w_ptr)
    :   Tracer(w_ptr)
{}

//destructor
MultipleObjects::~MultipleObjects(void){}

//trace ray
RGBColor
MultipleObjects::trace_ray(const Ray &ray) const {
    ShadeRec sr(world_ptr->hit_objects(ray));
    
    if (sr.hit_an_object)
        return (sr.color);
    else
        return (world_ptr->background_color);
}
