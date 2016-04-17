//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

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
