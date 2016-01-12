//
//  SingleSphere.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __SingleSphere__
#define __SingleSphere__

#include <iostream>
#include "Tracer.h"

class SingleSphere: public Tracer {
public:
    SingleSphere(void);
    
    SingleSphere(World* _worldPtr);
    
    virtual
    ~SingleSphere(void);
    
    virtual RGBColor
    trace_ray(const Ray& ray) const;
};

#endif /* __SingleSphere__ */
