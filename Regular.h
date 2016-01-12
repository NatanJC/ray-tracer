//
//  Regular.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin on 12/6/15.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Regular__
#define __Regular__

#include <stdio.h>

#include "Sampler.h"

class Regular: public Sampler {
    public:
        Regular(void);
    
        Regular(const int num);
    
        Regular(const Regular& u);
    
        Regular&
        operator= (const Regular& rhs);
    
        virtual Regular*
        clone(void) const;
    
        virtual
        ~Regular(void);
    
        virtual void
        generate_samples(void);
};

#endif /* __Regular__ */
