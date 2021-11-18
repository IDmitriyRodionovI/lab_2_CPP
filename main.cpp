#include <iostream>
#include <string>


#include "Class.h"
#include "MyFuncs.h"




int main() {
	
	int command, answer;
	double distance, radius , x=0, y=0, c=0;
	
	MyFuncs::getCoords(&x, &y, &c);
	CassiniLine line(x, y, c);

	while (1) {
		std::cout << std::endl;
		std::cout << "choose what you want to do" << std::endl;
		MyFuncs::show_commands();
		std::cin >> command;
		switch (command)
		{
		case 1:
			distance = line.find_distance();
			if (distance == -1) {
				std::cout << "this point doesn't belong to Cassini Line" << std::endl;
			}
			else {
				std::cout << " distence from (" << x << "," << y << ") to center is " << distance << std::endl;
			}
			break;
		case 2:
			answer = line.find_shape_form();
			line.print_form(answer);
			break;
		case 3:
			//std::cout << "not ready yet" << std::endl;
			line.equation();
			break;
		case 4:
			radius = line.find_radius();
			std::cout << "radius of your line is " << radius << std::endl;
			break;
		case 5:
			line.find_inflection_points();
		case 0:
			std::cout << "shutdown..." << std::endl;
			return 0;
		default:
			std::cout << "incorrect command!!!!!!!!!!!!!!" << std::endl;
			break;
		}
	}
	return 0;
}

