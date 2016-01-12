//
//  Pinhole.h
//  wx-barebonesTracing
//
//  Created by Natan Chawalitcheewin.
//  Copyright © 2015 Natan Chawalitcheewin. All rights reserved.
//

#ifndef __Pinhole__
#define __Pinhole__

#include "Camera.h"
#include "Point2D.h"
#include "World.h"    // we can #include "World.h" here


class Pinhole: public Camera {
	public:
	
		Pinhole();   							

		Pinhole(const Pinhole& ph);	
		
		virtual Camera*						
		clone(void) const;			

		Pinhole& 							
		operator= (const Pinhole& rhs);	
		
		virtual
		~Pinhole();   						
			
		void
		set_view_distance(const float vpd);
		
		void
		set_zoom(const float zoom_factor);
		
		Vector3D								
		get_direction(const Point2D& p) const;
		
		virtual void 												
		render_scene(const World& w);
		
	private:
			
		float d; 
		float zoom;
		
};




//set view distance
inline void
Pinhole::set_view_distance(float _d) {
	d = _d;
}	


//set zoom
inline void
Pinhole::set_zoom(float zoom_factor) {
	zoom = zoom_factor;
}	

#endif /* __Pinhole__ */

