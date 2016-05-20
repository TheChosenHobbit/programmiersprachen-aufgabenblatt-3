#include "circle.hpp"
#include <cmath>
#include <math.h>



Circle::Circle():
center_{1,1},
radius_{1.0},
color_{0,0,0}{}

Circle::Circle(Point2D const& ctr, float r, Color const& clr):
center_{ctr},
radius_{r},
color_{clr}{}

Color Circle::getColor() const
{
	return color_;
}

Point2D Circle::getPoint2D() const
{
	return center_;
}

float Circle::getRadius() const
{
	return radius_;
}


void Circle::setColor (Color const& clr)
{
	color_ = clr;
}

void Circle::setPoint2D (Point2D const& ctr)
{
	center_ = ctr;
}

void Circle::setRadius(float r)
{
	radius_ = r;
}

float Circle::circumference() const
{
	return 2*M_PI*radius_;
}

bool operator<(Circle const& c1, Circle const& c2) 
{
	return c1.getRadius() < c2.getRadius();

}
bool operator>(Circle const& c1, Circle const& c2)
{
	return c1.getRadius() > c2.getRadius();
}

bool operator==(Circle const& c1, Circle const& c2)
{
	return c1.getRadius() == c2.getRadius();
}