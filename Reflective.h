//
//  Reflective.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Reflective__
#define __Reflective__

#include <stdio.h>

#include "Phong.h"
#include "PerfectSpecular.h"

class Reflective: public Phong {
public:
    
    Reflective(void);
    
    Reflective(const Reflective& rm);
    
    Reflective&
    operator= (const Reflective& rhs);
    
    virtual Reflective*
    clone(void) const;
    
    ~Reflective(void);
    
    void
    set_kr(const float k);
				
    void
    set_cr(const RGBColor& c);
    
    void
    set_cr(const float r, const float g, const float b);
    
    void
    set_cr(const float c);
    
    virtual RGBColor
    shade(ShadeRec& s);
    
private:
    
    PerfectSpecular* reflective_brdf;
};


inline void
Reflective::set_kr(const float k) {
    reflective_brdf->set_kr(k);
}

inline void
Reflective::set_cr(const RGBColor& c) {
    reflective_brdf->set_cr(c);
    
}

inline void
Reflective::set_cr(const float r, const float g, const float b) {
    reflective_brdf->set_cr(r, g, b);
}

inline void
Reflective::set_cr(const float c) {
    reflective_brdf->set_cr(c);
}


#endif /* __Reflective__ */
