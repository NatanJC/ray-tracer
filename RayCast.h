//
//  RayCast.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __RayCast__
#define __RayCast__

#include <stdio.h>
#include "Tracer.h"

class RayCast: public Tracer {
    
    public:
        RayCast(void);
    
        RayCast(World* _worldPtr);
    
        virtual
        ~RayCast(void);
    
        virtual RGBColor
        trace_ray(const Ray& ray) const;
    
        virtual RGBColor
        trace_ray(const Ray ray, const int depth) const;
};

#endif /* __RayCast__ */
