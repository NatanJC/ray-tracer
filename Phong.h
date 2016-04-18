//
//  Phong.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Phong__
#define __Phong__

#include <stdio.h>
#include "Material.h"
#include "Lambertian.h"
#include "GlossySpecular.h"


class Phong: public Material {
public:
    Phong(void);
    
    Phong(const Phong& m);
    
    virtual RGBColor
    shade(ShadeRec& sr);
    
    virtual RGBColor
    get_Le(ShadeRec& sr) const;
    
    virtual Material*
    clone(void) const;
    
    Phong&
    operator= (const Phong& rhs);
    
    ~Phong(void);
    
    void
    set_ka(const float k);
    
    void
    set_kd(const float k);
    
    void
    set_ks(const float ks);
    
    void
    set_cd(const RGBColor c);
    
    void
    set_cd(const float r, const float g, const float b);
    
    void
    set_cd(const float c);
    
    void
    set_cs(const RGBColor c);
    
    void
    set_cs(const float r, const float g, const float b);
    
    void
    set_cs(const float c);
    
    void
    set_exp(const float _e);
    
protected:
    
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;
    GlossySpecular* specular_brdf;
};

inline void
Phong::set_ka(const float ka) {
    ambient_brdf->set_kd(ka);
}

inline void
Phong::set_kd(const float kd) {
    diffuse_brdf->set_kd(kd);
}

inline void
Phong::set_ks(const float ks) {
    specular_brdf->set_ks(ks);
}

inline void
Phong::set_cd(const RGBColor c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
    specular_brdf->set_cs(c);
}

inline void
Phong::set_cd(const float r, const float g, const float b) {
    ambient_brdf->set_cd(r, g, b);
    diffuse_brdf->set_cd(r, g, b);
    specular_brdf->set_cs(r, g, b);
}

inline void
Phong::set_cd(const float c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
    specular_brdf->set_cs(c);
}

inline void
Phong::set_cs(const RGBColor c) {
    specular_brdf->set_cs(c);
}

inline void
Phong::set_cs(const float r, const float g, const float b) {
    specular_brdf->set_cs(r, g, b);
}

inline void
Phong::set_cs(const float c) {
    specular_brdf->set_cs(c);
}


inline void
Phong::set_exp(const float _e) {
    specular_brdf->set_exp(_e);
}

#endif /* __Phong__ */
