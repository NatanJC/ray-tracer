//
//  Sampler.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin on 12/6/15.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Sampler__
#define __Sampler__

#include <stdio.h>
#include <vector>
#include <math.h>

#include "Point2D.h"
#include "Point3D.h"
#include "Maths.h"

using namespace std;

class Sampler {
    public:
        Sampler(void);
    
        Sampler(const int num);
    
        Sampler(const int num, const int num_sets);
    
        Sampler(const Sampler& s);
    
        Sampler&
        operator= (const Sampler& rhs);
    
        virtual Sampler*
        clone(void) const = 0;
    
        virtual
        ~Sampler(void);
    
        void
        set_num_sets(const int np);
    
        virtual void
        generate_samples(void) = 0;
    
        int
        get_num_samples(void);
    
        void
        shuffle_x_coordinates(void);
    
        void
        shuffle_y_coordinates(void);
    
        void
        setup_shuffled_indices(void);
    
        void
        map_samples_to_unit_disk(void);
    
        void
        map_samples_to_hemisphere(const float p);
    
        void
        map_samples_to_sphere(void);
    
        Point2D
        sample_unit_square(void);
    
        Point2D
        sample_unit_disk(void);
    
        Point3D
        sample_hemisphere(void);
    
        Point3D
        sample_sphere(void);
    
    protected:
    
        int num_samples;
        int num_sets;
        vector<Point2D> samples;
        vector<int> shuffled_indices;
        vector<Point2D> disk_samples;
        vector<Point3D> hemisphere_samples;
        vector<Point3D> sphere_samples;
        unsigned long count;
        int jump;
};

#endif /* __Sampler__ */
