//
//  Vector.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

// This class can be used by moving game_objects to calculate the direction in which the object is moving towards

#ifndef Vector_hpp
#define Vector_hpp
#include <math.h>

namespace Breakout {
    
    class Vector{
    public:
        Vector();
        Vector(const double x, const double y);
        ~Vector();

        double get_x()const{return _x;};
        double get_y()const{return _y;};

        void set_x(const double x){_x = x;};
        void set_y(const double y){_y = y;};

        double length() const;
        void normalize();
		Vector multiply(double scalar)const;
		Vector operator*(double scalar)const;
        
    private:
        double _x;
        double _y;
    };
}

#endif /* Vector_hpp */
