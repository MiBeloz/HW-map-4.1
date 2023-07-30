#pragma once

#include "shape.h"


class transform {
public:
	transform(const Shape& sh) : shape(sh) {}
	Shape shift(int m, int n, int k);
	Shape scaleX(int a);
	Shape scaleY(int d);
	Shape scaleZ(int e);
	Shape scale(int s);

private:
	Shape shape;
};

