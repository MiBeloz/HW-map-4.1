#pragma once

#include <cmath>
#include <vector>
#include <initializer_list>
#include <stdexcept>


enum class shape_type {
	line,
	sqr,
	cube,
	circle,
	cylinder
};

class Shape {
public:
	/*static const int line = 0;
	static const int sqr = 1;
	static const int cube = 2;
	static const int circle = 3;
	static const int cylinder = 4;
	Shape() = default;
	Shape(int type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);
	Shape(int type, int _x1, int _y1, double R, double H);
	int getType() { return type; }

	int type;
	int x1 = 0, y1 = 0, z1 = 0,
		x2 = 0, y2 = 0, z2 = 0,
		x3 = 0, y3 = 0, z3 = 0,
		x4 = 0, y4 = 0, z4 = 0,
		x5 = 0, y5 = 0, z5 = 0,
		x6 = 0, y6 = 0, z6 = 0,
		x7 = 0, y7 = 0, z7 = 0,
		x8 = 0, y8 = 0, z8 = 0;
	double volume;
	double square;
	double height;
	double radius;*/

	struct Point final {
		explicit Point(const int _x, const int _y, const int _z = 0) : m_x(_x), m_y(_y), m_z(_z) {}
		int m_x, m_y, m_z;
	};

	//explicit Shape() = default;
	explicit Shape(int _x1, int _y1, int _x2, int _y2, shape_type _sh_t = shape_type::line);
	explicit Shape(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3);
	explicit Shape(int _x1, int _y1, double R, double H = 0);
	virtual ~Shape() {};

protected:
	std::vector<Point> m_point;
	//double m_area;
	//double m_volume;
	double m_height = 0;
	double m_radius = 0;

private:
	shape_type m_type;

	virtual double getArea();
};

class Line final : public Shape {
	double getArea() override;
};

class Sqr final : public Shape {
	double getArea() override;
};

class Cube final : public Shape {
	double getArea() override;
};

class Circle final : public Shape {
	double getArea() override;
};

class Cylinder final : public Shape {
	double getArea() override;
};
