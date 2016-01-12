//
//  Lambertian.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//


#include "Lambertian.h"
#include "Constants.h"

//default constructor
Lambertian::Lambertian(void)
    :   BRDF(),
        kd(0.0),
        cd(0.0)
{}

//constructor
Lambertian::Lambertian(const Lambertian& lamb)
    :   BRDF(lamb),
        kd(lamb.kd),
        cd(lamb.cd)
{}

//clone
Lambertian*
Lambertian::clone(void) const {
    return (new Lambertian(*this));
}


//operator
Lambertian&
Lambertian::operator= (const Lambertian& rhs) {
    if (this == &rhs)
        return (*this);
    
    BRDF::operator= (rhs);
    
    kd = rhs.kd;
    cd = rhs.cd;
    
    return (*this);
}

//destructor
Lambertian::~Lambertian(void){}

//f function
RGBColor
Lambertian::f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const {
    return (kd * cd * invPI);
}

//sample f
//chapter 26 (return still have to be changed)
RGBColor
Lambertian::sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const {
    return (black);
}


//rho
RGBColor
Lambertian::rho(const ShadeRec& sr, const Vector3D& wo) const {
    return (kd * cd);
}
