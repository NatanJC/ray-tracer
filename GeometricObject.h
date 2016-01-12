//
//  GeometricObject.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __GeometricObject__
#define __GeometricObject__

#include <iostream>
#include "Ray.h"
#include "ShadeRec.h"

class GeometricObject {
    public:
        GeometricObject(void);
    
        GeometricObject(const GeometricObject& object);
    
        virtual GeometricObject*
        clone(void) const = 0;
    
        virtual
        ~GeometricObject (void);
    
        virtual bool
        hit(const Ray& ray, double& t, ShadeRec& s) const = 0;
    
        //color
        void
        set_color(const RGBColor& c);
				
        void
        set_color(const float r, const float g, const float b);
    
        RGBColor
        get_color(void);
    
    protected:
        RGBColor color;
    
        GeometricObject&
        operator = (const GeometricObject& rhs);
};

//set color
inline void
GeometricObject::set_color(const RGBColor& c) {
    color = c;
}

//set color
inline void
GeometricObject::set_color(const float r, const float g, const float b) {
    color.r = r;
    color.b = b;
    color.g = g;
}

//get color
inline RGBColor
GeometricObject::get_color(void) {
    return (color);
}

#endif /* defined(__GeometricObject__) */

