//
//  MulitJittered.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#include "MultiJittered.h"

//default constructor
MultiJittered::MultiJittered(void)
    :   Sampler()
{}


//constructor
MultiJittered::MultiJittered(const int num_samples)
    :   Sampler(num_samples) {
    generate_samples();
}


//constructor
MultiJittered::MultiJittered(const int num_samples, const int m)
    :   Sampler(num_samples, m) {
    generate_samples();
}


//copy constructor
MultiJittered::MultiJittered(const MultiJittered& mjs)
    :   Sampler(mjs) {
    generate_samples();
}

//operator
MultiJittered&
MultiJittered::operator= (const MultiJittered& rhs)	{
    if (this == &rhs)
        return (*this);
    
    Sampler::operator=(rhs);
    
    return (*this);
}

//clone
MultiJittered*
MultiJittered::clone(void) const {
    return (new MultiJittered(*this));
}

//destructor
MultiJittered::~MultiJittered(void) {}

//generate samples function
void
MultiJittered::generate_samples(void) {
    
    int n = (int)sqrt((float)num_samples);
    float subcell_width = 1.0 / ((float) num_samples);
    
    Point2D fill_point;
    for (int j = 0; j < num_samples * num_sets; j++)
        samples.push_back(fill_point);
    
    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                samples[i * n + j + p * num_samples].x = (i * n + j) * subcell_width + rand_float(0, subcell_width);
                samples[i * n + j + p * num_samples].y = (j * n + i) * subcell_width + rand_float(0, subcell_width);
            }
    
    // shuffle x coordinates
    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int k = rand_int(j, n - 1);
                float t = samples[i * n + j + p * num_samples].x;
                samples[i * n + j + p * num_samples].x = samples[i * n + k + p * num_samples].x;
                samples[i * n + k + p * num_samples].x = t;
            }
    
    // shuffle y coordinates
    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int k = rand_int(j, n - 1);
                float t = samples[j * n + i + p * num_samples].y;
                samples[j * n + i + p * num_samples].y = samples[k * n + i + p * num_samples].y;
                samples[k * n + i + p * num_samples].y = t;
            }
}