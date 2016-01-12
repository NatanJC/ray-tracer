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

MultipleObjects::MultipleObjects(void)
    :   Tracer()
{}

MultipleObjects::MultipleObjects(World* w_ptr)
    :   Tracer(w_ptr)
{}

MultipleObjects::~MultipleObjects(void){}
RGBColor
MultipleObjects::trace_ray(const Ray &ray) const {
    ShadeRec sr(world_ptr->hit_objects(ray));
    
    if (sr.hit_an_object)
        return (sr.color);
    else
        return (world_ptr->background_color);
}
