//
//  GeometricObject.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __GeometricObject__
#define __GeometricObject__

class Material;

#include <iostream>
#include "Point3D.h"
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
    
        void
        set_color(const RGBColor& c);
				
        void
        set_color(const float r, const float g, const float b);
    
        RGBColor
        get_color(void);

        Material*
        get_material(void) const;
    
        virtual void
        set_material(Material* mPtr);
    
    protected:
        RGBColor color;
    
        mutable Material*
        material_ptr;
    
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

inline Material*
GeometricObject::get_material(void) const {
    return (material_ptr);
}

#endif /* defined(__GeometricObject__) */

