//
//  Jittered.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Jittered__
#define __Jittered__

#include <stdio.h>
#include "Sampler.h"

class Jittered: public Sampler {
    public:
        Jittered(void);
    
        Jittered(const int num_samples);
    
        Jittered(const int num_samples, const int m);
    
        Jittered(const Jittered& u);
    
        Jittered&
        operator= (const Jittered& rhs);
    
        virtual Jittered*
        clone(void) const;
    
        virtual
        ~Jittered(void);
    
    private:
    
        virtual void
        generate_samples(void);
};
#endif /* __Jittered__ */
