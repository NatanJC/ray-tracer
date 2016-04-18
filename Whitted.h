//
//  Whitted.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Whitted__
#define __Whitted__

#include "Tracer.h"

class Whitted: public Tracer {
public:
    Whitted(void);
    
    Whitted(World* _worldPtr);
    
    virtual
    ~Whitted(void);
    
    virtual RGBColor
    trace_ray(const Ray ray, const int depth) const;
};

#endif /* __Whitted__ */
