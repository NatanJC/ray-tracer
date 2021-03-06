//
//  PerfectSpecular.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __PerfectSpecular__
#define __PerfectSpecular__

#include <stdio.h>
#include "BRDF.h"
#include "Normal.h"
#include "Constants.h"

class PerfectSpecular: public BRDF {
public:
    PerfectSpecular(void);
    
    PerfectSpecular(const PerfectSpecular& mirror);
    
    ~PerfectSpecular(void);
    
    virtual PerfectSpecular*
    clone(void) const;
    
    PerfectSpecular&
    operator= (const PerfectSpecular& rhs);
    
    void
    set_kr(const float k);
    
    void
    set_cr(const RGBColor& c);
    
    void
    set_cr(const float r, const float g, const float b);
    
    void
    set_cr(const float c);

    virtual RGBColor
    f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const;
    
    virtual RGBColor
    sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const;
    
    virtual RGBColor
    rho(const ShadeRec& sr, const Vector3D& wo) const;
    
private:
    
    float kr;
    RGBColor cr;
};


inline void
PerfectSpecular::set_kr(const float k) {
    kr = k;
}

inline void
PerfectSpecular::set_cr(const RGBColor& c) {
    cr = c;
}

inline void
PerfectSpecular::set_cr(const float r, const float g, const float b) {
    cr.r = r; cr.g = g; cr.b = b;
}

inline void
PerfectSpecular::set_cr(const float c) {
    cr.r = c; cr.g = c; cr.b = c;
}


#endif /* __PerfectSpecular__ */
