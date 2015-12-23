//
//  RGBColor.cpp
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 11/5/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#include <math.h>
#include "RGBColor.h"

//default constructor
RGBColor::RGBColor(void)
    : r(0.0), g(0.0), b(0.0)
    {}


//constructor
RGBColor::RGBColor(float c)
    : r(c), g(c), b(c)
    {}


//constructor
RGBColor::RGBColor(float _r, float _g, float _b)
    : r(_r), g(_g), b(_b)
    {}


//copy constructor
RGBColor::RGBColor(const RGBColor& c)
    : r(c.r), g(c.g), b(c.b)
    {}


//destructor
RGBColor::~RGBColor(void)
{}


//assignment operator
RGBColor&
RGBColor::operator= (const RGBColor& rhs) {
	if (this == &rhs)
		return (*this);
    
	r = rhs.r; g = rhs.g; b = rhs.b;
    
	return (*this);
}


// -------------------------------------------------------- powc
// raise each component to the specified power
// used for color filtering in Chapter 28

RGBColor
RGBColor::powc(float p) const {
	return (RGBColor(pow(r, p), pow(g, p), pow(b, p)));
}

