//
//  Vector.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Vector.hpp"

namespace Breakout {
    
    Vector::Vector(){
        set_x(.0);
        set_y(.0);
    }
    
    Vector::Vector(const double x, const double y){
        set_x(x);
        set_y(y);
    }
    
    Vector::~Vector(){
        
    }
    
    
    double Vector::length() const {
        return sqrt(_x*_x + _y*_y);
    }
    
    void Vector::normalize(){
        double x = _x/length();
        double y = _y/length();
        set_x(x);
        set_y(y);
    }

	Vector Vector::multiply(double scalar)const{
		Vector ret(_x * scalar, _y * scalar);
		return ret;
	}

	Vector Vector::operator*(double scalar)const {
		return multiply(scalar);
	}
}