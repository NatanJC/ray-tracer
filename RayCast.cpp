//
//  RayCast.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#include "RayCast.h"
#include "ShadeRec.h"
#include "World.h"
#include "Material.h"

//constructor
RayCast::RayCast(void)
:   Tracer()
{}


//copy constructor
RayCast::RayCast(World* _worldPtr)
:   Tracer(_worldPtr)
{}


//destructor
RayCast::~RayCast(void)
{}

//trace ray
RGBColor
RayCast::trace_ray(const Ray& ray) const {
    ShadeRec sr(world_ptr->hit_objects(ray));
    
    if (sr.hit_an_object) {
        sr.ray = ray;
        //use for specular shading
        return (sr.material_ptr->shade(sr));
    }
    else
        return (world_ptr->background_color);
}

//trace ray with depth (simulate reflection + transparency)
RGBColor
RayCast::trace_ray(const Ray ray, const int depth) const {
    ShadeRec sr (world_ptr->hit_objects(ray)); //copy constructor
    
    if (sr.hit_an_object) {
        sr.ray = ray;
        //use for specular reflection
        return (sr.material_ptr->shade(sr));
    }
    
    else
        return (world_ptr->background_color);
}