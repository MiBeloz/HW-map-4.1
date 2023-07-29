#include <iostream>

#include "classes/shape.h"
#include "classes/transform.h"


int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tРефакторинг\n\n" << std::endl;

	Shape sh1{ Point(1,2), Point(1,2) };

	system("pause > nul");
	return 0;
}