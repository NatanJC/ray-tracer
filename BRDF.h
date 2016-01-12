//
//  BRDF.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __BRDF__
#define __BRDF__

#include <stdio.h>
#include "RGBColor.h"
#include "ShadeRec.h"
#include "Vector3D.h"
#include "Sampler.h"

class BRDF {
    public:
    
        BRDF(void);
    
        BRDF (const BRDF& brdf);
    
        virtual BRDF*
        clone(void)const = 0;
    
        BRDF&
        operator= (const BRDF& rhs);
    
        virtual
        ~BRDF(void);
    
        virtual RGBColor
        f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const = 0;
    
        virtual RGBColor
        sample_f(const ShadeRec& sr, Vector3D& wi, const Vector3D& wo) const = 0;
    
        virtual RGBColor
        rho(const ShadeRec& sr, const Vector3D& wo) const = 0;
    
    protected:
    
        Sampler* sampler_ptr;
    
};

#endif /* __BRDF__ */
