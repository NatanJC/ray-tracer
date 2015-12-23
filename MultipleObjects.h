//
//  MultipleObjects.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin on 12/5/15.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __MultipleObjects__
#define __MultipleObjects__

#include <stdio.h>
#include "Tracer.h"

class MultipleObjects: public Tracer {
public:
    
    MultipleObjects(void);
    
    MultipleObjects(World* _worldptr);
    
    virtual
    ~MultipleObjects(void);
    
    virtual RGBColor
    trace_ray(const Ray& ray) const;
};

#endif /* __MultipleObjects__ */
