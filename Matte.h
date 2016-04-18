//
//  Matte.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2016 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Matte__
#define __Matte__

#include "Material.h"
#include "Lambertian.h"


class Matte: public Material {	
	
    public:
			
		Matte(void);											

		Matte(const Matte& m);
		
		virtual Material*										
		clone(void) const;									

		Matte& 
		operator= (const Matte& rhs);							

		~Matte(void);											
		
		void 													
		set_ka(const float k);
		
		void 													
		set_kd(const float k);
		
		void													
		set_cd(const RGBColor c);
		
		void													
		set_cd(const float r, const float g, const float b);
		
		void																						
		set_cd(const float c);
				
		virtual RGBColor										
		shade(ShadeRec& sr);
		
	private:
		
		Lambertian* ambient_brdf;
		Lambertian* diffuse_brdf;
};


//set ka
inline void								
Matte::set_ka(const float ka) {
	ambient_brdf->set_kd(ka);
}


//set kd
inline void								
Matte::set_kd (const float kd) {
	diffuse_brdf->set_kd(kd);
}


//set cd
inline void												
Matte::set_cd(const RGBColor c) {
	ambient_brdf->set_cd(c);
	diffuse_brdf->set_cd(c);
}


//set cd
inline void													
Matte::set_cd(const float r, const float g, const float b) {
	ambient_brdf->set_cd(r, g, b);
	diffuse_brdf->set_cd(r, g, b);
}

//set cd
inline void													
Matte::set_cd(const float c) {
	ambient_brdf->set_cd(c);
	diffuse_brdf->set_cd(c);
}

#endif /* __Matte__ */


