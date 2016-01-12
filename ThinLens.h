//
//  ThinLens.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __ThinLens__
#define __ThinLens__

#include <stdio.h>
#include "Camera.h"
#include "Sampler.h"
#include "World.h"

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
    
        float lens_radius;
        float d;
        float f;
        float zoom;
        Sampler* sampler_ptr;
};

#endif /* __ThinLens__ */
