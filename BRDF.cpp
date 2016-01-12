//
//  BRDF.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#include "BRDF.h"

//default constructor
BRDF::BRDF(void)
    :   sampler_ptr(NULL)
{}


//constructor
BRDF::BRDF (const BRDF& brdf) {
    if(brdf.sampler_ptr)
        sampler_ptr	= brdf.sampler_ptr->clone();
    else
        sampler_ptr = NULL;
}

//operator
BRDF&
BRDF::operator= (const BRDF& rhs) {
    if (this == &rhs)
        return (*this);
    
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = NULL;
    }
    
    if (rhs.sampler_ptr)
        sampler_ptr	= rhs.sampler_ptr->clone();
    
    return (*this);
}


//destructor
BRDF::~BRDF(void) {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = NULL;
    }
}

//f function
RGBColor
BRDF::f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const {
    return (black);
}

//sample f function
RGBColor
BRDF::sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const {
    return (black);
}

//rho
RGBColor
rho(const ShadeRec& sr, const Vector3D& wo) {
    return (black);
}