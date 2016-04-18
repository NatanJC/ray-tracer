//
//  ShadeRec.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#include "Constants.h"
#include "ShadeRec.h"

//constructor

ShadeRec::ShadeRec(World& wr)
    : 	hit_an_object(false),
        material_ptr(NULL),
        hit_point(),
        local_hit_point(),
        normal(),
        ray(),
        depth(0),
        dir(),
        t(0.0),
        w(wr)
{}


//copy constructor
ShadeRec::ShadeRec(const ShadeRec& sr)
    : 	hit_an_object(sr.hit_an_object),
        material_ptr(sr.material_ptr),
        hit_point(sr.hit_point),
        local_hit_point(sr.local_hit_point),
        normal(sr.normal),
        ray(sr.ray),
        depth(sr.depth),
        dir(sr.dir),
        t(sr.t),
        w(sr.w)
{}