//
//  World.h
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 11/5/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __World__
#define __World__

#include <iostream>
#include <vector>
#include <fstream>
#include "viewPlane.h"
#include "RGBColor.h"
#include "Sphere.h"
#include "Tracer.h"
#include "Ray.h"
#include "GeometricObject.h"
#include "Camera.h"

using namespace std;

class RenderThread; 	//part of skeleton - wxRaytracer.h

class World {
    public:
    
        RenderThread* 				paintArea; 	//connection to skeleton - wxRaytracer.h
    
        ViewPlane vp;
        RGBColor background_color;
        Sphere sphere;
        Tracer* tracer_ptr;
        Camera*	camera_ptr;
        vector<GeometricObject*> objects;
    
        World(void);
        ~World(void);
    
        void
        build(void);
    
        void
        render_scene(void) const;
    
        void
        render_perspective(void) const;
    
        void
        display_pixel(const int row, const int column, const RGBColor& pixel_color) const;
    
        void
        add_object(GeometricObject* object_ptr);
    
        RGBColor
        max_to_one(const RGBColor& c) const;
    
        RGBColor
        clamp_to_color(const RGBColor& c) const;
    
        ShadeRec
        hit_objects(const Ray& ray);
    
        void
        set_camera(Camera* c_ptr);
    

};

inline void
World::add_object(GeometricObject* object_ptr){
    objects.push_back(object_ptr);
}

inline void
World::set_camera(Camera* c_ptr) {
    camera_ptr = c_ptr;
}

#endif /* defined(__World__) */
