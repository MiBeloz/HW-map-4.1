#include <iostream>

#include "classes/shape.h"
#include "classes/transform.h"


int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tРефакторинг\n\n" << std::endl;

	Shape o(2, 3, 4, 6, shape_type::line);

	system("pause > nul");
	return 0;
}