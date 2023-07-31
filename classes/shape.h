#pragma once

#include <cmath>
#include <memory>


class Point final {
public:
	friend class Shape;
	explicit Point() {};
	explicit Point(const int _x, const int _y, const int _z = 0) : x(_x), y(_y), z(_z) {}

private:
	int x = 0, y = 0, z = 0;
};

class Shape final {
public:
	class ShapeType {
	public:
		virtual int getType() const = 0;
		virtual double getArea(const int a, const int b, const int c, double height, double radius) const = 0;
		virtual double getVolume(const int a, const int b, const int c, double height, double radius) const = 0;
		virtual ~ShapeType() {}
	};

	class Line final : public ShapeType {
	public:
		int getType() const override;
		double getArea(const int a, const int b, const int c, double height, double radius) const  override;
		double getVolume(const int a, const int b, const int c, double height, double radius) const  override;
	};

	class Sqr final : public ShapeType {
	public:
		int getType() const  override;
		double getArea(const int a, const int b, const int c, double height, double radius) const  override;
		double getVolume(const int a, const int b, const int c, double height, double radius) const  override;
	};

	class Cube final : public ShapeType {
	public:
		int getType() const  override;
		double getArea(const int a, const int b, const int c, double height, double radius) const  override;
		double getVolume(const int a, const int b, const int c, double height, double radius) const  override;
	};

	class Circle final : public ShapeType {
	public:
		int getType() const  override;
		double getArea(const int a, const int b, const int c, double height, double radius) const  override;
		double getVolume(const int a, const int b, const int c, double height, double radius) const  override;
	};

	class Cylinder final : public ShapeType {
	public:
		int getType() const  override;
		double getArea(const int a, const int b, const int c, double height, double radius) const  override;
		double getVolume(const int a, const int b, const int c, double height, double radius) const  override;
	};

	enum class type {
		line = 0,
		sqr = 1,
		cube = 2,
		circle = 3,
		cylinder = 4
	};
	
	explicit Shape(int _x1, int _y1, int _x2, int _y2, type _sh_t = type::line);
	explicit Shape(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2);
	explicit Shape(int _x1, int _y1, double R, double H = 0);

	void setPoint(Point _point_1, Point _point_2 = Point());

	int get_x1() const { return m_point_1.x; }
	int get_y1() const { return m_point_1.y; }
	int get_z1() const { return m_point_1.z; }
	int get_x2() const { return m_point_2.x; }
	int get_y2() const { return m_point_2.y; }
	int get_z2() const { return m_point_2.z; }

	int getType() const;
	double getArea() const;
	double getVolume() const;

private:
	Point m_point_1, m_point_2;
	std::shared_ptr<ShapeType> m_type;
	int m_side_a = 0;
	int m_side_b = 0;
	int m_side_c = 0;
	double m_height = 0;
	double m_radius = 0;
};


//#pragma once
//#include<string>
//class Shape
//{
//public:
//	static const int line = 0;
//	static const int sqr = 1;
//	static const int cube = 2;
//	static const int circle = 3;
//	static const int cylinder = 4;
//	Shape() = default;
//	Shape(int type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);
//	Shape(int type, int _x1, int _y1, double R, double H);
//	int getType() { return type; }
//
//	int type;
//	int x1 = 0, y1 = 0, z1 = 0,
//		x2 = 0, y2 = 0, z2 = 0,
//		x3 = 0, y3 = 0, z3 = 0,
//		x4 = 0, y4 = 0, z4 = 0,
//		x5 = 0, y5 = 0, z5 = 0,
//		x6 = 0, y6 = 0, z6 = 0,
//		x7 = 0, y7 = 0, z7 = 0,
//		x8 = 0, y8 = 0, z8 = 0;
//	double volume;
//	double square;
//	double height;
//	double radius;
//};
