//
//  Camera.cpp
//  ray tracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright (c) 2015 Natan Chawalitcheewin. All rights reserved.

#include "Camera.h"


//default constructor
Camera::Camera(void)		
	:	eye(0, 0, 500),
		lookat(0),
		ra(0),
		up(0, 1, 0),
		u(1, 0, 0),
		v(0, 1, 0),
		w(0, 0, 1),
		exposure_time(1.0)
{}


//constructor
Camera::Camera(const Camera& c)   		
	: 	eye(c.eye),
		lookat(c.lookat),
		ra(c.ra),
		up(c.up),
		u(c.u),
		v(c.v),
		w(c.w),
		exposure_time(c.exposure_time)
{}


//operator
Camera& 
Camera::operator= (const Camera& rhs) {
	if (this == &rhs)
		return (*this);
	
	eye	= rhs.eye;
	lookat = rhs.lookat;
	ra = rhs.ra;
	up = rhs.up;
	u = rhs.u;
	v = rhs.v;
	w = rhs.w;
	exposure_time = rhs.exposure_time;

	return (*this);
}


//destructor
Camera::~Camera(void) {}


//compute uvw
void
Camera::compute_uvw(void) {
	w = eye - lookat;
	w.normalize();
	u = up ^ w; 
	u.normalize();
	v = w ^ u;
    
    //vertically down
	if (eye.x == lookat.x && eye.z == lookat.z && eye.y > lookat.y) {
		u = Vector3D(0, 0, 1);
		v = Vector3D(1, 0, 0);
		w = Vector3D(0, 1, 0);	
	}
	
    //vertically up
	if (eye.x == lookat.x && eye.z == lookat.z && eye.y < lookat.y) {
		u = Vector3D(1, 0, 0);
		v = Vector3D(0, 0, 1);
		w = Vector3D(0, -1, 0);
	}
}



