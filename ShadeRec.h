//
//  ShadeRec.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __ShadeRec__
#define __ShadeRec__

class World;
class Material;

#include <vector>
#include <iostream>
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "RGBColor.h"

class ShadeRec {
public:
    
    bool hit_an_object;
    Material* material_ptr;
    Point3D hit_point;
    Point3D local_hit_point;
    Normal normal;
    Ray ray;
    int depth;
    Vector3D dir;
    float t;
    World& w;
    RGBColor color;
    
    ShadeRec(World& wr);
    ShadeRec(const ShadeRec& sr);
};

#endif /* defined(__ShadeRec__) */
