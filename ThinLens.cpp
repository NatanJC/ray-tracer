//
//  ThinLens.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin on 12/8/15.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#include "ThinLens.h"

// ----------------------------------------------------------------------------- default constructor

ThinLens::ThinLens(void)
:	Camera(),
d(500),
zoom(1.0)
{}


// ----------------------------------------------------------------------------- copy constructor

ThinLens::ThinLens(const ThinLens& tl)
: 	Camera(tl),
d(tl.d),
zoom(tl.zoom)
{}


// ----------------------------------------------------------------------------- clone

Camera*
ThinLens::clone(void) const {
    return (new ThinLens(*this));
}



// ----------------------------------------------------------------------------- assignment operator

ThinLens&
ThinLens::operator= (const ThinLens& tls) {
    if (this == &tls)
        return (*this);
    
    Camera::operator= (tls);
    
    d 		= tls.d;
    zoom	= tls.zoom;
    
    return (*this);
}


// ----------------------------------------------------------------------------- destructor

ThinLens::~ThinLens(void) {}

void ThinLens::set_sampler(Sampler *sp) {
    
}

Vector3D ThinLens::ray_direction(const Point2D &pixel_point, const Point2D &lens_point) const {
    return Vector3D();
}

void ThinLens::render_scene(const World &w) {
    
}
