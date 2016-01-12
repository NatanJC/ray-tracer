// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

#ifndef __POINT_2D__
#define __POINT_2D__

class Point2D {
public:
    
    float	x, y;
				
public:
    
    Point2D (void);										// default constructor
    Point2D (const float arg);							// constructor
    Point2D (const float x1, const float y1);			// constructor
    Point2D (const Point2D& p); 						// copy constructor
    ~Point2D (void) {}									// destructor
    
    Point2D& 											// assignment operator
    operator= (const Point2D& rhs);
    
    Point2D												// multiplication on right by scalar
    operator* (const float a);
};


// scales the point by the float a

inline Point2D
Point2D::operator* (const float a) {
    return (Point2D(a * x, a * y));
}


#endif


