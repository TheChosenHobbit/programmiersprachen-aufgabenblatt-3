#ifndef CIRCLE_HPP
#define CIRCLE_HPP

struct Point2D
{
	float x, y;
};

struct Color
{
	float r, g, b;
};


class Circle
{
public:
	Circle();
	Circle(Point2D const& ctr, float r, Color const& clr);

	Color getColor() const;
	Point2D getPoint2D() const;
	float getRadius() const;

	void setColor (Color const& clr);
	void setPoint2D (Point2D const& ctr);
	void setRadius (float r);

	float circumference() const;

private:
	Point2D center_;
	float radius_;
	Color color_;
};

bool operator<(Circle const& c1, Circle const& c2);
bool operator>(Circle const& c1, Circle const& c2);
bool operator==(Circle const& c1, Circle const& c2);



#endif