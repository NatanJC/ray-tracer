//
//  Lambertian.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Lambertian__
#define __Lambertian__

#include <stdio.h>
#include "BRDF.h"

class Lambertian: public BRDF {
    public:
    
        Lambertian(void);
    
        Lambertian(const Lambertian& lamb);
    
        virtual Lambertian*
        clone(void) const;
    
        Lambertian&
        operator= (const Lambertian& rhs);
    
        virtual
        ~Lambertian(void);

    
        //access functions for kd and cd
        //kd = diffuse reflection coefficient
        //cd = diffuse color
    
        void
        set_ka(const float ka);
				
        void
        set_kd(const float kd);
    
        void
        set_cd(const RGBColor& c);
    
        void
        set_cd(const float r, const float g, const float b);
    
        void
        set_cd(const float c);
    
    
        //f, sample f, and rho functions
        virtual RGBColor
        f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const;
    
        virtual RGBColor
        sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const;
    
        virtual RGBColor
        rho(const ShadeRec& sr, const Vector3D& wo) const;

    private:
    
        float kd;
        RGBColor cd;
};

inline void
Lambertian::set_ka(const float k) {
    kd = k;
}

inline void
Lambertian::set_kd(const float k) {
    kd = k;
}

inline void
Lambertian::set_cd(const RGBColor& c) {
    cd = c;
}

inline void
Lambertian::set_cd(const float r, const float g, const float b) {
    cd.r = r; cd.g = g; cd.b = b;
}

inline void
Lambertian::set_cd(const float c) {
    cd.r = c; cd.g = c; cd.b = c;
}

#endif /* __Lambertian__ */
