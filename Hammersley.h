//
//  Hammersley.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Hammersley__
#define __Hammersley__

#include "Sampler.h"

class Hammersley: public Sampler {
	public:
		
		Hammersley(void);							
		
		Hammersley(const int num);					

		Hammersley(const Hammersley& r);			

		Hammersley& 
		operator= (const Hammersley& rhs);			

		virtual Hammersley*							
		clone(void) const;

		virtual
		~Hammersley(void);
		
		double 
		phi(int j);
		
	private:
		
		virtual void
		generate_samples(void);
};

#endif /* __Hammersley__ */

