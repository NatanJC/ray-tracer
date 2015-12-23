//
//  GeometricObject.h
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 10/6/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __GeometricObject__
#define __GeometricObject__

#include <iostream>
#include "Ray.h"
#include "ShadeRec.h"

class GeometricObject {
    public:
        GeometricObject(void);									// default constructor
    
        GeometricObject(const GeometricObject& object);			// copy constructor
    
        virtual GeometricObject*								// virtual copy constructor
        clone(void) const = 0;
    
        virtual 												// destructor
        ~GeometricObject (void);
    
        virtual bool
        hit(const Ray& ray, double& t, ShadeRec& s) const = 0;
    
        //set color function only required when there is no material assigned
        void
        set_color(const RGBColor& c);
				
        void
        set_color(const float r, const float g, const float b);
    
        RGBColor
        get_color(void);
    
    protected:
        RGBColor color; //only used in this chapter
    
        GeometricObject&						// assignment operator
        operator= (const GeometricObject& rhs);
};

// --------------------------------------------------------------------  set_color

inline void
GeometricObject::set_color(const RGBColor& c) {
    color = c;
}

// --------------------------------------------------------------------  set_color

inline void
GeometricObject::set_color(const float r, const float g, const float b) {
    color.r = r;
    color.b = b;
    color.g = g;
}

// --------------------------------------------------------------------  get_color

inline RGBColor
GeometricObject::get_color(void) {
    return (color);
}

#endif /* defined(__GeometricObject__) */

