#pragma once

#include "shape.h"


class transform {
public:
	transform(const Shape& sh) : shape(sh) {}
	Shape shift(const int m, const int n, const int k);
	Shape scaleX(const int a);
	Shape scaleY(const int d);
	Shape scaleZ(const int e);
	Shape scale(const int s);

private:
	Shape shape;

	void scaleXYZ(const int a, const int d, const int e);
};

//#pragma once
//#include"shape.h"
//class transform
//{
//public:
//	transform(const Shape& sh);
//	Shape shift(int m, int n, int k);
//	Shape scaleX(int a);
//	Shape scaleY(int d);
//	Shape scaleZ(int e);
//	Shape scale(int s);
//
//private:
//	Shape shape;
//};
