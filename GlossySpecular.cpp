//
//  GlossySpecular.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#include "GlossySpecular.h"

//constructor
GlossySpecular::GlossySpecular(void)
    : 	ks(0.0),
        cs(1.0),
        sampler_ptr(NULL)
{}


//copy
GlossySpecular::GlossySpecular(const GlossySpecular& gloss)
    :	BRDF(gloss),
        ks(gloss.ks),
        cs(gloss.cs),
        exp(gloss.exp)
{
    if(gloss.sampler_ptr != NULL)
    {
        sampler_ptr = gloss.sampler_ptr->clone();
    }
}


//clone
GlossySpecular*
GlossySpecular::clone(void) const {
    return (new GlossySpecular(*this));
}


//operator
GlossySpecular&
GlossySpecular::operator= (const GlossySpecular& rhs) {
    
    if (this == &rhs)
        return (*this);
    
    BRDF::operator= (rhs);
    
    ks = rhs.ks;
    cs = rhs.cs;
    exp = rhs.exp;
    
    // need to do a deep copy of the sampler
    if(rhs.sampler_ptr != NULL) {
        sampler_ptr = rhs.sampler_ptr->clone();
    }
    
    return (*this);
}

//destructor
GlossySpecular::~GlossySpecular(void) {}

//set_sampler
void
GlossySpecular::set_sampler(Sampler* sp, const float exp) {
    
    sampler_ptr = sp;
    sampler_ptr->map_samples_to_hemisphere(exp);
}


//f
RGBColor
GlossySpecular::f(const ShadeRec &sr, const Vector3D& wi, const Vector3D& wo) const {
    RGBColor L;
    float ndotwi = sr.normal * wi;
    Vector3D r(-wi + 2.0 * sr.normal * ndotwi);
    float rdotwo = r * wo;
    
    if (rdotwo > 0.0) {
        L = ks * pow(rdotwo, exp);
    }
    return (L);
}


//sample_f
RGBColor
GlossySpecular::sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const {
    
    float ndotwo = sr.normal * wo;
    Vector3D r = -wo + 2.0 * sr.normal * ndotwo;	// direction of mirror reflection
    
    Vector3D w = r;
    Vector3D u = Vector3D(0.00424, 1, 0.00764) ^ w;
    u.normalize();
    Vector3D v = u ^ w;
    
    Point3D sp = sampler_ptr->sample_hemisphere();
    wi = sp.x * u + sp.y * v + sp.z * w;			// reflected ray direction
    
    if (sr.normal * wi < 0.0) 						// reflected ray is below tangent plane
        wi = -sp.x * u - sp.y * v + sp.z * w;
    
    float phong_lobe = pow((float)(r * wi), (float)exp);
    
    return (ks * cs * phong_lobe);
}


//rho -- return black
RGBColor
GlossySpecular::rho(const ShadeRec& sr, const Vector3D& wo) const {
    return (black);
}
