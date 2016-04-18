//
//  PerfectSpecular.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#include "PerfectSpecular.h"

//default
PerfectSpecular::PerfectSpecular(void)
    :	BRDF(),
        kr(0.0),
        cr(1.0)
{}

//copy constructor
PerfectSpecular::PerfectSpecular(const PerfectSpecular& mirror)
    :   BRDF(mirror),
        kr(mirror.kr),
        cr(mirror.cr)
{}

//destructor
PerfectSpecular::~PerfectSpecular(void) {}


//clone
PerfectSpecular*
PerfectSpecular::clone(void) const {
    return (new PerfectSpecular(*this));
}

//operator
PerfectSpecular&
PerfectSpecular::operator= (const PerfectSpecular& rhs) {
    
    if (this == &rhs)
        return (*this);
    
    BRDF::operator= (rhs);
    
    kr = rhs.kr;
    cr = rhs.cr;
    
    return (*this);
}

//f
RGBColor
PerfectSpecular::f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const {
    return (black);
}

//sample_f
RGBColor
PerfectSpecular::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const {
    
    float ndotwo = sr.normal * wo;
    wi = -wo + 2.0 * sr.normal * ndotwo;
    
    return (kr * cr / fabs(sr.normal * wi));
}

//rho
RGBColor
PerfectSpecular::rho(const ShadeRec& sr, const Vector3D& wo) const {
    return (black);
}