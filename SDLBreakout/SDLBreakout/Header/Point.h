
#ifndef POINT_H
#define POINT_H


// Represents a point. This class is probably unused
class Point
{
public:
	Point(int = 0, int = 0);
	void setPoint(int newX, int newY);
	Point add(const Point p);
	Point subtract(const Point p);

private:
	int _x;
	int _y;
};

#endif // !POINT_H
