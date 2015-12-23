//
//  ShadeRec.cpp
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 10/6/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#include "ShadeRec.h"
#include "World.h"

ShadeRec::ShadeRec(World& wr) //constructor
    :   hit_an_object(false),
        local_hit_point(),
        normal(),
        color(black),
        t(0.0),
        w(wr)

{}


ShadeRec::~ShadeRec(void) {}