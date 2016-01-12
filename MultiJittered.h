//
//  MulitJittered.hpp
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __MulitJittered__
#define __MulitJittered__

#include <stdio.h>
#include "Sampler.h"

class MultiJittered: public Sampler {
    public:
        MultiJittered(void);
    
        MultiJittered(const int num_samples);
    
        MultiJittered(const int num_samples, const int m);
    
        MultiJittered(const MultiJittered& mjs);
    
        MultiJittered&
        operator= (const MultiJittered& rhs);
    
        virtual MultiJittered*
        clone(void) const;
    
        virtual
        ~MultiJittered(void);
    
    private:
    
        virtual void
        generate_samples(void);		
};

#endif /* __MulitJittered__ */
