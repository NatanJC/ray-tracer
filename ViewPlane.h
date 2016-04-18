//
//  ViewPlane.h
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 11/5/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __ViewPlane__
#define __ViewPlane__

#include <iostream>
#include "Sampler.h"
#include "Regular.h"
#include "MultiJittered.h"

class ViewPlane {
    public:
        int hres; //horizontal image resolution
        int vres; //vertical image resolution
        float s; //pixel size
        float gamma; //monitor gamma factor
        float inv_gamma; //one over gamma
        int num_samples; // number of samples per pixel
        int max_depth; // max number of reflected bounce rays
    
        Sampler* sampler_ptr;
    
    
        ViewPlane();   								// default Constructor
    
        ViewPlane(const ViewPlane& vp);				// copy constructor
    
        ViewPlane& operator= (const ViewPlane& rhs);		// assignment operator
    
        ~ViewPlane();
    
        void
        set_hres(const int h_res);
    
        void
        set_vres(const int v_res);
    
        void
        set_pixel_size(const float size);
    
        void
        set_gamma(const float g);
    
        bool
        show_out_of_gamut;			// display red if RGBColor out of gamut
    
        void
        set_samples(const int n);
    
        void
        set_sampler(Sampler* sp);
    
        void
        set_max_depth(int depth);
    
    
};

inline void
ViewPlane::set_hres(const int h_res) {
	hres = h_res;
}

inline void
ViewPlane::set_vres(const int v_res) {
	vres = v_res;
}

inline void
ViewPlane::set_pixel_size(const float size) {
    s = size;
}

inline void
ViewPlane::set_gamma(const float g) {
	gamma = g;
	inv_gamma = 1.0 / gamma;
}

inline void
ViewPlane::set_max_depth(int depth) {
    max_depth = depth;
}


#endif /* defined(__ViewPlane__) */
