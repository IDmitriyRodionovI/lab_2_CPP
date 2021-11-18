#include <iostream>
#include <string>


namespace MyFuncs {
	void show_commands() {
		std::cout << "press 1 to find distance from point to center" << std::endl;
		std::cout << "press 2 to determine the shape of the Cassini line" << std::endl;
		std::cout << "press 3 to return the equation of the Cassini line" << std::endl;
		std::cout << "press 4 to find curvature radius" << std::endl;
		std::cout << "press 5 to find inflection points" << std::endl;
		std::cout << "press 0 to finish work " << std::endl;
	}

	bool getDouble(double* insert) {

		double cntrl;
		std::cin >> cntrl;
		while (std::cin.fail()) {
			if (std::cin.eof()) {
				return 0;
			}
			std::cout << "wrong input, try again " << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> cntrl;
		}
		*insert = cntrl;
		return 1;
	}
	void getCoords(double* x, double* y, double* c) {
		std::cout << "input coordinates of your point" << std::endl;
		std::cout << "input X coordinate" << std::endl;
		if (getDouble(x) == 0) {
			return;
		}
		std::cout << "input Y coordinate" << std::endl;
		if (getDouble(y) == 0) {
			return;
		}
		std::cout << "input distence from center to focus" << std::endl;
		if (getDouble(c) == 0) {
			return;
		}
	}

}

