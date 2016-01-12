//
//  ThinLens.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#include "ThinLens.h"
#include "Ray.h"
#include "ViewPlane.h"

//default constructor
ThinLens::ThinLens(void)
    :	Camera(),
        lens_radius(1.0),
        d(500),
        f(75.0),
        zoom(1.0),
        sampler_ptr(NULL)
{}


//constructor
ThinLens::ThinLens(const ThinLens& tl)
    :	Camera(tl),
        lens_radius(tl.lens_radius),
        d(tl.d),
        f(tl.f),
        zoom(tl.zoom)
{
    // need to do a deep copy of the sampler
    if(tl.sampler_ptr != NULL) {
        sampler_ptr = tl.sampler_ptr->clone();
    }
}

//clone
Camera*
ThinLens::clone(void) const {
    return (new ThinLens(*this));
}



//operator
ThinLens&
ThinLens::operator= (const ThinLens& tls) {
    if (this == &tls)
        return (*this);
    
    Camera::operator= (tls);
    
    d 		= tls.d;
    zoom	= tls.zoom;
    
    return (*this);
}


//destructor
ThinLens::~ThinLens(void) {}

void ThinLens::set_sampler(Sampler *sp) {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = NULL;
    }
    
    sampler_ptr = sp;
    sampler_ptr -> map_samples_to_unit_disk();
    
}

//ray direction function
Vector3D ThinLens::ray_direction(const Point2D &pixel_point, const Point2D &lens_point) const {
    Point2D p;
    p.x = pixel_point.x * f / d;
    p.y = pixel_point.y * f / d;
    
    Vector3D dir = (p.x - lens_point.x) * u + (p.y - lens_point.y) * v - f * w;
    dir.normalize();
    return Vector3D();
}

//render scene function
void ThinLens::render_scene(const World& w) {
    RGBColor L;
    Ray ray;
    ViewPlane vp(w.vp);
    int depth = 0;
    
    Point2D sp;
    Point2D pp;
    Point2D dp;
    Point2D lp;
    
    vp.s /= zoom;
    
    for (int r = 0; r < vp.vres - 1; r++)
        for (int c = 0; c < vp.hres - 1; c++) {
            L = black;
            
            for (int n = 0; n < vp.num_samples; n++) {
                sp = vp.sampler_ptr->sample_unit_disk();
                pp.x = vp.s * (c-vp.hres/2.0+sp.x);
                pp.y = vp.s * (r-vp.vres/2.0+sp.y);
                
                dp = sampler_ptr->sample_unit_disk();
                lp = dp * lens_radius;
                
                ray.o = eye + lp.x * u + lp.y * v;
                ray.d = ray_direction(pp, lp);
                L += w.tracer_ptr->trace_ray(ray, depth);
            }
            
            L /= vp.num_samples;
            L *= exposure_time;
            w.display_pixel(r, c, L);
        }
}
