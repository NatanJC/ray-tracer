//
//  NRooks.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin on 12/6/15.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//


#ifndef __NRooks__
#define __NRooks__

#include "Sampler.h"

class NRooks: public Sampler {
	public:
		
		NRooks(void);									
		
		NRooks(const int num_samples);					
		
		NRooks(const int num_samples, const int m);	

		NRooks(const NRooks& nr);					

		NRooks& 
		operator= (const NRooks& rhs);				

		virtual NRooks*								
		clone(void) const;			

		virtual
		~NRooks(void);
		
	private:
		
		virtual void									
		generate_samples(void);						
};

#endif /* __NRooks__ */

