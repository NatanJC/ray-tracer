//
//  Plane.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
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
        Plane(const Plane& plane);
    
        virtual Plane*
        clone(void) const;
    
        Plane&
        operator= (const Plane& rhs);
    
        virtual
        ~Plane(void);
    
        virtual bool
        hit(const Ray& ray, double& t, ShadeRec& s) const;
    
    private:
        Point3D point;
        Normal normal;
    
    static const  double kEpsilon;
};

#endif /* __Plane__ */