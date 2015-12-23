//
//  Plane.h
//  ray tracing
//
//  Created by Natan Chawalitcheewin on 10/6/15.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Plane__
#define __Plane__

#include <iostream>
#include "GeometricObject.h"
#include "Normal.h"

class GeometricObject;

class Plane: public GeometricObject {
    public:
        Plane(void);
        Plane(const Point3D &p, const Normal& n);
        Plane(const Plane& plane); 									// copy constructor
    
        virtual Plane* 												// virtual copy constructor
        clone(void) const;
    
        Plane& 														// assignment operator
        operator= (const Plane& rhs);
    
        virtual														// destructor
        ~Plane(void);
    
        virtual bool
        hit(const Ray& ray, double& t, ShadeRec& s) const;
    
    private:
        Point3D point; //point through which plane passes
        Normal normal;  //normal to the plane
    
    static const  double kEpsilon; //see chapter 16
};

#endif /* defined(__Plane__) */