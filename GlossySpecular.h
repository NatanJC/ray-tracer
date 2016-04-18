//
//  GlossySpecular.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __GlossySpecular__
#define __GlossySpecular__

#include "BRDF.h"

#include <stdio.h>

class GlossySpecular: public BRDF {
public:
    
    GlossySpecular(void);
    
    GlossySpecular(const GlossySpecular& gloss);
    
    virtual GlossySpecular*
    clone(void) const;
    
    GlossySpecular&
    operator= (const GlossySpecular& rhs);
    
    virtual
    ~GlossySpecular(void);
    
    //ks = specular reflection coefficient
    //exp = specular exponent
    //cs = specular color
    
    void
    set_ks(const float ks);
				
    void
    set_exp(const float _e);
    
    void
    set_cs(const RGBColor& c);
    
    void
    set_cs(const float r, const float g, const float b);
    
    void
    set_cs(const float c);
    
    virtual RGBColor
    f(const ShadeRec &sr, const Vector3D& wi, const Vector3D& wo) const;
    
    virtual RGBColor
    sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const;
    
    virtual RGBColor
    rho(const ShadeRec& sr, const Vector3D& wo) const;
    
    void
    set_sampler(Sampler* sp, const float exp);
    
private:
    
    float ks;
    float exp;
    RGBColor cs;
    Sampler* sampler_ptr;
};

inline void
GlossySpecular::set_ks(const float k) {
    ks = k;
}

inline void
GlossySpecular::set_exp(const float e) {
    exp = e;
}

inline void
GlossySpecular::set_cs(const RGBColor& c) {
    cs = c;
}

inline void
GlossySpecular::set_cs(const float r, const float g, const float b) {
    cs.r = r; cs.g = g; cs.b = b;
}

inline void
GlossySpecular::set_cs(const float c) {
    cs.r = c; cs.g = c; cs.b = c;
}


#endif /* __GlossySpecular__ */
