//
//  ShadeRec.h
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 10/6/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __ShadeRec__
#define __ShadeRec__
class World;

#include <iostream>
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "RGBColor.h"



class ShadeRec {
    public:
        bool hit_an_object; //did the ray hit an object?
        Point3D hit_point;			// world coordinates of intersection
        Point3D local_hit_point; //world coordinates of hit point
        Normal normal; //normal at hit point
        RGBColor color;//use in chapter 3 only
        float t;
        World& w;
    

        ShadeRec(World& wr); // constructor
        ShadeRec(const ShadeRec& sr); //copy constructor
        ~ShadeRec(void); //destructor
    
        ShadeRec& //assignment operator
        operator= (const ShadeRec& rhs);
    
};

#endif /* defined(__ShadeRec__) */
