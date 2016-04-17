//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "../Header/Point.h"

Point::Point(int x, int y)
{
	setPoint(x, y);
}

void Point::setPoint(int newX, int newY)
{
	_x = newX;
	_y = newY;
}

Point Point::add(const Point otherP)
{
	Point _p;
	_p._x = _x + otherP._x;
	_p._y = _y + otherP._y;
	return _p;
}

Point Point::subtract(const Point otherP)
{
	Point _p;
	_p._x = _x - otherP._x;
	_p._y = _y - otherP._y;
	return _p;
}