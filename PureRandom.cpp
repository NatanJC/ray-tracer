//
//  PureRandom.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.

#include "PureRandom.h"

//default constructor
PureRandom::PureRandom(void)							
	:   Sampler()
{}


//constructor
PureRandom::PureRandom(const int num)
	:   Sampler(num) {
	generate_samples();
}


//constructor
PureRandom::PureRandom(const PureRandom& r)			
	:   Sampler(r) {
	generate_samples();
}

//assignment operator
PureRandom& 
PureRandom::operator= (const PureRandom& rhs) {
	if (this == &rhs)
		return (*this);
		
	Sampler::operator=(rhs);

	return (*this);
}

//clone
PureRandom*										
PureRandom::clone(void) const {
	return (new PureRandom(*this));
}

//destructor
PureRandom::~PureRandom(void) {}


//generate samples function
void
PureRandom::generate_samples(void) {
	for (int p = 0; p < num_sets; p++)         
		for (int q = 0; q < num_samples; q++)
			samples.push_back(Point2D(rand_float(), rand_float()));
}


