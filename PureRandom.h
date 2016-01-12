//
//  PureRandom.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.

#ifndef __PureRandom__
#define __PureRandom__

#include "Sampler.h"

class PureRandom: public Sampler {
	public:
		
		PureRandom(void);							
		
		PureRandom(const int num);					

		PureRandom(const PureRandom& r);				

		PureRandom& 
		operator= (const PureRandom& rhs);			

		virtual PureRandom*							
		clone(void) const;			

		virtual
		~PureRandom(void);
		
	private:
		
		virtual void
		generate_samples(void);
};

#endif /* __PureRandom__ */

