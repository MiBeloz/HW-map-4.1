#define _USE_MATH_DEFINES

#include "shape.h"

//Shape::Shape(int _type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8) {
//	type = _type;
//
//	// заполн¤ем координаты фигуры
//	switch (type) {
//	case line: 
//		x1 = _x1; y1 = _y1;
//		x2 = _x2; y2 = _y2;
//		break;
//	case sqr:
//		x1 = _x1; y1 = _y1;
//		x2 = _x2; y2 = _y2;
//		x3 = _x3; y3 = _y3;
//		x4 = _x4; y4 = _y4;
//		break;
//	case cube:
//		x1 = _x1; y1 = _y1; z1 = _z1;
//		x2 = _x2; y2 = _y2; z2 = _z2;
//		x3 = _x3; y3 = _y3; z3 = _z3;
//		x4 = _x4; y4 = _y4; z4 = _z4;
//		x5 = _x5; y5 = _y5; z5 = _z5;
//		x6 = _x6; y6 = _y6; z6 = _z6; 
//		x7 = _x7; y7 = _y7; z7 = _z7;
//		x8 = _x8; y8 = _y8; z8 = _z8;
//		break;
//	default:
//		break;
//	}
//	
//	// стороны фигуры
//	int a = abs(x1 - x2);
//	int b = abs(y1 - y2);
//	int c = abs(z1 - z2);
//
//	// считаем площадь фигуры
//	switch (type) {
//	case line:
//		square = 0;
//		break;
//	case sqr:
//		square = a * b;
//		break;
//	case cube:
//		square = 2 * a * b + 2 * a * c + 2 * b * c;
//		break;
//	default:
//		break;
//	}
//
//	// считаем объем фигуры
//	switch (type) {
//	case line:
//		volume = 0;
//		break;
//	case sqr:
//		volume = 0;
//		break;
//	case cube:
//		volume = a * b * c;
//		break;
//	default:
//		break;
//	}
//
//}

Shape::Shape(std::initializer_list<Point> _point) {
	verifyArguments(_point);

	for (auto i = _point.begin(); i != _point.end(); ++i) {
		m_point.emplace_back(i);
	}

	setType();
	setArea();
}

//Shape::Shape(int type, int _x1, int _y1, double R, double H)
//{
//	// заполн¤ем координаты фигуры
//	switch (type) {
//	case circle:
//		x1 = _x1; y1 = _y1;
//		radius = R;
//		break;
//	case cylinder:
//		x1 = _x1; y1 = _y1;
//		radius = R;
//		height = H;
//		break;
//	default:
//		break;
//	}
//
//	// считаем площадь фигуры
//	switch (type) {
//	case circle:
//		square = M_PI * R * R;
//		break;
//	case cylinder:
//		square = M_PI * R * R + 2 * R * height;
//		break;
//	default:
//		break;
//	}
//
//	// считаем объем фигуры
//	switch (type) {
//	case circle:
//		volume = 0;
//		break;
//	case cylinder:
//		volume = M_PI * R * R * height;
//		break;
//	default:
//		break;
//	}
//}

void Shape::verifyArguments(const std::initializer_list<Point>& in_list) const {
	if (in_list.size() < 2) {
		throw std::invalid_argument("Слишком мало аргументов!");
	}
	else if ((in_list.size() > 2 && in_list.size()) < 4 || (in_list.size() > 4 && in_list.size() < 8)) {
		throw std::invalid_argument("Неккоректное число аргументов!");
	}
	else if (in_list.size() > 8) {
		throw std::invalid_argument("Слишком много аргументов!");
	}
}

void Shape::setType() {
	if (m_point.size() == 2) {
		m_type = shape_type::line;
	}
	else if (m_point.size() == 4) {
		m_type = shape_type::sqr;
	}
	else if (m_point.size() == 8) {
		m_type = shape_type::cube;
	}
}

void Shape::setArea() {
	m_square = 0;
}

void Sqr::setArea() {
	int a = abs(m_point[0].m_x - m_point[1].m_x);
	int b = abs(m_point[0].m_y - m_point[1].m_y);
	m_square = a * b;
}

void Cube::setArea() {
	int a = abs(m_point[0].m_x - m_point[1].m_x);
	int b = abs(m_point[0].m_y - m_point[1].m_y);
	int c = abs(m_point[0].m_z - m_point[1].m_z);
	m_square = 2 * a * b + 2 * a * c + 2 * b * c;
}

void Circle::setArea() {
	m_square = M_PI * m_radius * m_radius;
}

void Cylinder::setArea() {
	m_square = M_PI * m_radius * m_radius + 2 * m_radius * m_height;
}
