//
//  Phong.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#include "Phong.h"

//default
Phong::Phong (void)
    :	Material(),
        ambient_brdf(new Lambertian),
        diffuse_brdf(new Lambertian),
        specular_brdf(new GlossySpecular)
{}

//constrictor
Phong::Phong(const Phong& m)
: 	Material(m)
{
    if(m.ambient_brdf)
        ambient_brdf = m.ambient_brdf->clone();
    else  ambient_brdf = NULL;
    
    if(m.diffuse_brdf)
        diffuse_brdf = m.diffuse_brdf->clone();
    else  diffuse_brdf = NULL;
    
    if(m.specular_brdf)
        specular_brdf = m.specular_brdf->clone();
    else  specular_brdf = NULL;
}

Material*
Phong::clone(void) const {
    return (new Phong(*this));
}


//operator
Phong&
Phong::operator= (const Phong& rhs) {
    
    if (this == &rhs)
        return (*this);
    
    Material::operator=(rhs);
    
    if (ambient_brdf) {
        delete ambient_brdf;
        ambient_brdf = NULL;
    }
    
    if (rhs.ambient_brdf)
        ambient_brdf = rhs.ambient_brdf->clone();
    
    if (diffuse_brdf) {
        delete diffuse_brdf;
        diffuse_brdf = NULL;
    }
    
    if (rhs.diffuse_brdf)
        diffuse_brdf = rhs.diffuse_brdf->clone();
    
    if (specular_brdf) {
        delete specular_brdf;
        specular_brdf = NULL;
    }
    
    if (rhs.specular_brdf)
        specular_brdf = rhs.specular_brdf->clone();
    
    return (*this);
}


//destructor
Phong::~Phong(void) {
    
    if (ambient_brdf) {
        delete ambient_brdf;
        ambient_brdf = NULL;
    }
    
    if (diffuse_brdf) {
        delete diffuse_brdf;
        diffuse_brdf = NULL;
    }
    
    if (specular_brdf) {
        delete specular_brdf;
        specular_brdf = NULL;
    }
}


//shade
RGBColor
Phong::shade(ShadeRec& sr) {
    
    Vector3D wo = -sr.ray.d;
    RGBColor L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
    int num_lights = sr.w.lights.size();
    
    for (int j = 0; j < num_lights; j++) {
        Vector3D wi = sr.w.lights[j]->get_direction(sr);
        float ndotwi = sr.normal * wi;
        
        if (ndotwi > 0.0) {
            L += (diffuse_brdf->f(sr, wo, wi) + specular_brdf->f(sr, wo, wi)) * sr.w.lights[j]->L(sr) * ndotwi;
        }
    }
    
    return (L);
}

//get_Le
RGBColor
Phong::get_Le(ShadeRec& sr) const{
    return (black);
}

