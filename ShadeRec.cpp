//
//  ShadeRec.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#include "ShadeRec.h"
#include "World.h"

//constructor
ShadeRec::ShadeRec(World& wr)
    :   hit_an_object(false),
        local_hit_point(),
        normal(),
        color(black),
        t(0.0),
        w(wr)

{}

//destructor
ShadeRec::~ShadeRec(void)
{}