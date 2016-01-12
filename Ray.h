// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

#ifndef __RAY__
#define __RAY__

#include <iostream>
#include "Point3D.h"
class Ray {
    public:
    
        Point3D o;  //origin
        Vector3D d; //direction
    
        Ray(void);  //default constructor
    
        Ray(const Point3D& origin, const Vector3D& dir); //constructor
    
        Ray(const Ray& ray);    //copy constructor
    
        Ray&        //assignment operator
        operator= (const Ray& rhs);
    
        ~Ray(void); //destructor
};

#endif
