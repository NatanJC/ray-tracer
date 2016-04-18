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

//utilities
#include "vector3D.h"
#include "Jittered.h"
#include "Point3D.h"
#include "Point2D.h"
#include "Normal.h"
#include "Ray.h"

//sample
#include "Jittered.h"

//tracer
#include "SingleSphere.h"
#include "MultipleObjects.h"
#include "RayCast.h"

//camera
#include "Pinhole.h"

//light
#include "Directional.h"
#include "PointLight.h"

//material
#include "Matte.h"
#include "Phong.h"


using namespace std;

World::World(void)
    :   camera_ptr(NULL),
        background_color(black),
        tracer_ptr(NULL),
        ambient_ptr(new Ambient)
{}

//destructor
World::~World(void) {
    
    if(tracer_ptr) {
        delete tracer_ptr;
        tracer_ptr = NULL;
    }
    
    if (ambient_ptr) {
        delete ambient_ptr;
        ambient_ptr = NULL;
    }
    
    if (camera_ptr) {
        delete camera_ptr;
        camera_ptr = NULL;
    }
    
    delete_objects();
    delete_lights();
}

//build function
void
World::build(void){
    int num_samples = 16;
    
    vp.set_hres(600);
    vp.set_vres(400);
    vp.set_samples(num_samples);
    
    tracer_ptr = new RayCast(this);
    
    Ambient* ambient_ptr = new Ambient;
    ambient_ptr->scale_radiance(0.5);
    set_ambient_light(ambient_ptr);
    
    float a = 0.75;
    background_color = RGBColor(0.0, 0.3 * a, 0.25 * a);  // torquise
    
    Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(7.5, 4, 10);
    pinhole_ptr->set_lookat(-1, 3.7, 0);
    pinhole_ptr->set_view_distance(340);
    pinhole_ptr->compute_uvw();
    set_camera(pinhole_ptr);
    
    Directional* light_ptr1 = new Directional;	// for Figure 15.8(a)
    light_ptr1->set_direction(15, 15, 2.5);
    light_ptr1->scale_radiance(2.0);
    add_light(light_ptr1);
    
    PointLight* light_ptr2 = new PointLight;	// for Figure 15.8(b)
    light_ptr2->set_location(15, 15, 2.5);
    light_ptr2->scale_radiance(2.0);
    add_light(light_ptr2);
    
    
    Phong* phong_ptr1 = new Phong;
    phong_ptr1->set_ka(0.25);
    phong_ptr1->set_kd(0.75);
    phong_ptr1->set_cd(0.75, 0.75, 0);  	// dark yellow
    phong_ptr1->set_ks(0.25);
    phong_ptr1->set_exp(50);
    
    Phong* phong_ptr2 = new Phong;
    phong_ptr2->set_ka(0.45);
    phong_ptr2->set_kd(0.75);
    phong_ptr2->set_cd(0.75, 0.25, 0);   	// orange
    phong_ptr2->set_ks(0.25);
    phong_ptr2->set_exp(500);
    
    Phong* phong_ptr3 = new Phong;
    phong_ptr3->set_ka(0.4);
    phong_ptr3->set_kd(0.75);
    phong_ptr3->set_cd(1, 0.5, 1);			// mauve
    phong_ptr3->set_ks(0.25);
    phong_ptr3->set_exp(4);
    
    Phong* phong_ptr4 = new Phong;
    phong_ptr4->set_ka(0.15);
    phong_ptr4->set_kd(0.5);
    phong_ptr4->set_cd(0.75, 1.0, 0.75);   	// light green
    phong_ptr4->set_ks(0.5);
    phong_ptr4->set_exp(3);
    
    Matte* matte_ptr5 = new Matte;
    matte_ptr5->set_ka(0.20);
    matte_ptr5->set_kd(0.97);
    matte_ptr5->set_cd(white);
    
    
    // spheres
    
    Sphere* sphere_ptr1 = new Sphere(Point3D(3.85, 2.3, -2.55), 2.3);
    sphere_ptr1->set_material(phong_ptr1);
    add_object(sphere_ptr1);
    
    Sphere* sphere_ptr2 = new Sphere(Point3D(-0.7, 1, 4.2), 2);
    sphere_ptr2->set_material(phong_ptr2);
    add_object(sphere_ptr2);
    
    // ground plane
    
    Plane* plane_ptr = new Plane(Point3D(0), Normal(0, 1, 0));
    plane_ptr->set_material(matte_ptr5);
    add_object(plane_ptr);
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
//render scene function -- random sampling
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
                //change rand_float() to (q+0.5)/n for regular sampling
                pp.y = vp.s * (r - 0.5 * vp.vres + rand_float());
                //change rand_float() to (p+0.5)/n for regular sampling
                ray.o = Point3D(pp.x, pp.y, zw);
                pixel_color += tracer_ptr->trace_ray(ray);
                
            }
            pixel_color /= vp.num_samples; //acerage the colors
            display_pixel(r, c, pixel_color);
        }

    
}
 
*/

//render scene in perspective function
//would have to switch this with render_scene
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

//clamp
RGBColor
World::max_to_one(const RGBColor& c) const  {
    float max_value = max(c.r, max(c.g, c.b));
    
    if (max_value > 1.0)
        return (c / max_value);
    else
        return (c);
}


//clamp_to_color
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

//hit object function
ShadeRec
World::hit_objects(const Ray& ray) {
    ShadeRec sr(*this);
    double t;
    Normal normal;
    Point3D local_hit_point;
    float tmin = kHugeValue;
    int num_objects = objects.size();
    
    for (int j = 0; j < num_objects; j++)
        if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
            sr.hit_an_object = true;
            tmin = t;
            sr.material_ptr = objects[j]->get_material();
            sr.hit_point = ray.o + t * ray.d;
            normal = sr.normal;
            local_hit_point = sr.local_hit_point;
        }
    
    if(sr.hit_an_object) {
        sr.t = tmin;
        sr.normal = normal;
        sr.local_hit_point = local_hit_point;
    }
    
    return(sr);   
}

//hit bare bones objects
/*
ShadeRec
World::hit_objects(const Ray& ray) {
    ShadeRec sr(*this);
    double t;
    double tmin = kHugeValue;
    int num_objects = objects.size();
    
    for (int j=0; j < num_objects; j++)
        if (objects[j] -> hit(ray, t, sr) && (t<tmin)) {
            sr.hit_an_object = true;
            tmin = t;
            sr.color = objects[j]->get_color();
        }
    return (sr);
}
*/
//delete objects
void
World::delete_objects(void) {
    
    int num_objects = objects.size();
    
    for (int j = 0; j < num_objects; j++) {
        delete objects[j];
        objects[j] = NULL;
    }
    
    objects.erase (objects.begin(), objects.end());
}

//delete lights
void
World::delete_lights(void) {
    
    int num_lights = lights.size();
    
    for (int j = 0; j < num_lights; j++) {
        delete lights[j];
        lights[j] = NULL;
    }
    
    lights.erase (lights.begin(), lights.end());
}
