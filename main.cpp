#include <iostream>

#include "classes/shape.h"
#include "classes/transform.h"


void print(const Shape& sh);

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tРефакторинг\n\n" << std::endl;

	Shape cube(5, 3, 8, 11, 7, 9);
	std::cout << "Созданный объект:" << std::endl;
	print(cube);

	transform tr_cube(cube);
	Shape cube_2(tr_cube.shift(7, 5, 9));
	std::cout << "Объект после трансформации 'shift':" << std::endl;
	print(cube_2);

	cube_2 = tr_cube.scaleX(7);
	std::cout << "Объект после трансформации 'scaleX':" << std::endl;
	print(cube_2);

	cube_2 = tr_cube.scaleY(3);
	std::cout << "Объект после трансформации 'scaleY':" << std::endl;
	print(cube_2);

	cube_2 = tr_cube.scaleZ(11);
	std::cout << "Объект после трансформации 'scaleZ':" << std::endl;
	print(cube_2);

	cube_2 = tr_cube.scale(2);
	std::cout << "Объект после трансформации 'scale':" << std::endl;
	print(cube_2);

	system("pause > nul");
	return 0;
}

void print(const Shape& sh) {
	std::cout << "\tТип: " << sh.getType() << std::endl;
	std::cout << "\tПлощадь: " << sh.getArea() << std::endl;
	std::cout << "\tОбъём: " << sh.getVolume() << std::endl;
	std::cout << std::endl << "---------------------" << std::endl;
}
