//
//  World.cpp
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 11/5/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#include <math.h>
#include "Maths.h"
#include "wxraytracer.h" //wxwidgets (window management)
#include "Constants.h"
#include "World.h"

#include "vector3D.h"
#include "Jittered.h"
#include "Point3D.h"
#include "Point2D.h"
#include "Normal.h"
#include "Ray.h"
#include "SingleSphere.h"
#include "MultipleObjects.h"
#include "Pinhole.h"
#include "Camera.h"


using namespace std;

World::World(void)
:   background_color(black),
tracer_ptr(NULL)
{}

World::~World(void) {
    if(tracer_ptr) {
        delete tracer_ptr;
        tracer_ptr = NULL;
    }
}

//build functions
void World::build(void) {
    vp.set_hres(200);
    vp.set_vres(200);
    vp.set_pixel_size(1.0);
    vp.set_samples(83);
    
    Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(300, 400, 500);
    pinhole_ptr->set_lookat(0, 0 , -50);
    pinhole_ptr->set_view_distance(400); //set d
    pinhole_ptr->compute_uvw();
    set_camera(pinhole_ptr);
    
    
    background_color = black;
    tracer_ptr = new SingleSphere(this);
    
    sphere.set_center(0.0);
    sphere.set_radius(85.0);
}

//render scene function
void
World::render_scene(void) const {
    
    RGBColor	pixel_color;
    Ray			ray;
    int 		hres 	= vp.hres;
    int 		vres 	= vp.vres;
    float		s		= vp.s;
    float		zw		= 100.0;				// hardwired in
    
    ray.d = Vector3D(0, 0, -1);
    
    for (int r = 0; r < vres; r++)			// up
        for (int c = 0; c <= hres; c++) {	// across
            ray.o = Point3D(s * (c - hres / 2.0 + 0.5), s * (r - vres / 2.0 + 0.5), zw);
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(r, c, pixel_color);
        }	
}

/*
//render scene function -- sample
void World::render_perspective(void) const {
    RGBColor pixel_color;
    Ray ray;
    double zw = 100.0; //hard wire in
    //int n = (int)sqrt((float)vp.num_samples);
    Point2D sp; //sample point in [0, 1] x [0, 1]
    Point2D pp; //sample point on pixel
    
    ray.d = Vector3D(0, 0, -1);

    for (int r = 0; r < vp.vres; r++) //up
        for (int c = 0; c <= vp.hres; c++) { //across
            pixel_color = black;
            
            for (int j = 0; j < vp.num_samples; j++) {
                sp = vp.sampler_ptr->sample_unit_square();
                pp.x = vp.s * (c - 0.5 * vp.hres + rand_float());
                pp.y = vp.s * (r - 0.5 * vp.vres + rand_float());
                ray.o = Point3D(pp.x, pp.y, zw);
                pixel_color += tracer_ptr->trace_ray(ray);
                
            }
            pixel_color /= vp.num_samples; //acerage the colors
            display_pixel(r, c, pixel_color);
        }

    
}
 
*/

//render scene in perspective function
void World::render_perspective(void) const {
    RGBColor pixel_color;
    Ray ray;
    float eye = 5.0;
    float d = 140.0;
    
    ray.o = Point3D(0.0, 0.0, eye);
    
    for (int r = 0; r < vp.vres; r++) //up
        for (int c = 0; c <= vp.hres; c++) { //across
            ray.d = Vector3D(vp.s * (c - 0.5 * (vp.hres - 1.0)),
                             vp.s * (r - 0.5 * (vp.vres - 1.0)), -d);
            ray.d.normalize();
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(r, c, pixel_color);
            
        }
    
}

// ------------------------------------------------------------------ clamp

RGBColor
World::max_to_one(const RGBColor& c) const  {
    float max_value = max(c.r, max(c.g, c.b));
    
    if (max_value > 1.0)
        return (c / max_value);
    else
        return (c);
}


// ------------------------------------------------------------------ clamp_to_color
// Set color to red if any component is greater than one

RGBColor
World::clamp_to_color(const RGBColor& raw_color) const {
    RGBColor c(raw_color);
    
    if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0) {
        c.r = 1.0; c.g = 0.0; c.b = 0.0;
    }
    
    return (c);
}

//display pixel
void World::display_pixel(const int row, const int column, const RGBColor &raw_color) const{
    RGBColor mapped_color;
    
    if (vp.show_out_of_gamut)
        mapped_color = clamp_to_color(raw_color);
    else
        mapped_color = max_to_one(raw_color);
    
    if (vp.gamma != 1.0)
        mapped_color = mapped_color.powc(vp.inv_gamma);
    
    
    //have to start from max y coordinate to convert to screen coordinates
    int x = column;
    int y = vp.vres - row - 1;
    
    paintArea->setPixel(x, y, (int)(mapped_color.r * 255),
                        (int)(mapped_color.g * 255),
                        (int)(mapped_color.b * 255));
}

ShadeRec
World::hit_objects(const Ray& ray) {
    
    ShadeRec	sr(*this);
    double		t;
    Normal normal;
    Point3D local_hit_point;
    float		tmin 			= kHugeValue;
    unsigned long 		num_objects 	= objects.size();
    
    for (int j = 0; j < num_objects; j++)
        if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
            sr.hit_an_object	= true;
            tmin 				= t;
            sr.hit_point 		= ray.o + t * ray.d;
            normal 				= sr.normal;
            local_hit_point	 	= sr.local_hit_point;
        }
    
    if(sr.hit_an_object) {
        sr.t = tmin;
        sr.normal = normal;
        sr.local_hit_point = local_hit_point;
    }
    
    return(sr);   
}
