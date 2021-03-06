//
//  Hammersley.cpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//
#include "Hammersley.h"
#include "Maths.h"

//default constructor
Hammersley::Hammersley(void)							
	: 	Sampler()
{}


//constructor
Hammersley::Hammersley(const int num)
	: 	Sampler(num) {
	generate_samples();
}


//copy constructor
Hammersley::Hammersley(const Hammersley& h)			
	: 	Sampler(h) {
	generate_samples();
}

//operator
Hammersley& 
Hammersley::operator= (const Hammersley& rhs) {
	if (this == &rhs)
		return (*this);
		
	Sampler::operator=(rhs);

	return (*this);
}


//clone
Hammersley*										
Hammersley::clone(void) const {
	return (new Hammersley(*this));
}


//destructor
Hammersley::~Hammersley(void) {}


//phi value
double 
Hammersley::phi(int j) {
	double x = 0.0;
	double f = 0.5; 
	
	while (j) {
		x += f * (double) (j % 2);
		j /= 2;
		f *= 0.5; 
	}
	
	return (x);
}


//generate samples function
void
Hammersley::generate_samples(void) {
	for (int p = 0; p < num_sets; p++)		
		for (int j = 0; j < num_samples; j++) {
			Point2D pv((float) j / (float) num_samples, phi(j));
			samples.push_back(pv);
		}		
}


