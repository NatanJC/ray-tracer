//
//  Sphere.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Sphere__
#define __Sphere__

#include <iostream>
#include "GeometricObject.h"
#include "Plane.h"
#include "ShadeRec.h"


class Sphere: public GeometricObject {
    
    public:
    
        Sphere(void);
    
        Sphere(Point3D center, double r);
    
        Sphere(const Sphere& sphere);
    
        virtual Sphere*
        clone(void) const;
    
        virtual
        ~Sphere(void);
    
        Sphere&
        operator= (const Sphere& sphere);
    
        void
        set_center(const Point3D& c);
    
        void
        set_center(const double x, const double y, const double z);
    
        void
        set_radius(const double r);
    
        virtual bool
        hit(const Ray& ray, double& t, ShadeRec& s) const;
    
    private:
	
        Point3D center;
        double radius;
    
        static const double kEpsilon;
};

//set center function
inline void
Sphere::set_center(const Point3D& c) {
	center = c;
}

//set center function
inline void
Sphere::set_center(const double x, const double y, const double z) {
	center.x = x;
	center.y = y;
	center.z = z;
}

//set radius function
inline void
Sphere::set_radius(const double r) {
	radius = r;
}

#endif /* __Sphere__ */
