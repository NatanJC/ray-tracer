//
//  ThinLens.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin on 12/8/15.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __ThinLens__
#define __ThinLens__

#include <stdio.h>
#include "Camera.h"
#include "Sampler.h"

class ThinLens: public Camera {
public:
    ThinLens();
    
    ThinLens(const ThinLens& tl);
    
    virtual Camera*
    clone(void) const;
    
    ThinLens&
    operator= (const ThinLens& tls);
    
    virtual
    ~ThinLens();
    
    void
    set_sampler(Sampler* sp);
    
    Vector3D
    ray_direction(const Point2D& pixel_point, const Point2D& lens_point) const;
    
    virtual void
    render_scene(const World& w);
    
private:
    
    float lens_radius; //lens radius
    float d; //view plane distance
    float f; //focal plane distance
    float zoom; //zoom factor
    Sampler* sampler_ptr; //sampler object
};

#endif /* __ThinLens__ */
