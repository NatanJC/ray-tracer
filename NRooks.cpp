//
//  NRooks.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin on 12/6/15.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#include "NRooks.h"

//default constructor
NRooks::NRooks(void)							
	: Sampler()
{}


//constructor
NRooks::NRooks(const int num_samples)
	: 	Sampler(num_samples) {
	generate_samples();
}


//constructor
NRooks::NRooks(const int num_samples, const int m)
	: 	Sampler(num_samples, m) {
	generate_samples();
}


//copy constructor
NRooks::NRooks(const NRooks& nr)			
	: Sampler(nr) {
	generate_samples();
}

//operator
NRooks& 
NRooks::operator= (const NRooks& rhs) {
	if (this == &rhs)
		return (*this);
		
	Sampler::operator=(rhs);

	return (*this);
}

//clone
NRooks*										
NRooks::clone(void) const {
	return (new NRooks(*this));
}

//destructor
NRooks::~NRooks(void) {}


//generatesamples
void
NRooks::generate_samples(void) {	
	for (int p = 0; p < num_sets; p++)          			
		for (int j = 0; j < num_samples; j++) {
			Point2D sp((j + rand_float()) / num_samples, (j + rand_float()) / num_samples);
			samples.push_back(sp);
		}		
	shuffle_x_coordinates();
	shuffle_y_coordinates();
}


	

