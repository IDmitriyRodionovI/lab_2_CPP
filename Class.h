#include <iostream>
#include <string>




class CassiniLine {

	double focus1_x;
	double focus1_y;

	double focus2_x;
	double focus2_y;

	double x;
	double y;

	double a;
	double c;

public:
	CassiniLine(double x_inp, double y_inp, double c_inp) {
		focus1_x = -c_inp;
		focus1_y = 0;

		focus2_x = c_inp;
		focus2_y = 0;

		x = x_inp;
		y = y_inp;

		a = sqrt(((x - focus1_x) * (x - focus1_x)) + y * y) * sqrt(((x - focus2_x) * (x - focus2_x)) + y * y);
		c = abs(focus1_x);
	}

	int find_shape_form() {




		if ((sqrt(a) == 0) && (c != 0)) {
			return 1;
		}
		else if ((sqrt(a) > 0) && (sqrt(a) < c)) {
			return 2;
		}
		else if (sqrt(a) == c) {
			return 3;
		}
		else if ((c < sqrt(a)) && (sqrt(a) < c * sqrt(2))) {
			return 4;
		}
		else if (sqrt(a) > c * sqrt(2)) {
			return 5;
		}
		else if ((c == 0) && (sqrt(a) != 0)) {
			return 6;
		}
		else {
			return 0;
		}
	}


	void print_form(int find) {
		if (find == 1) {
			std::cout << "this line represents 2 points" << std::endl;
		}
		else if (find == 2) {
			std::cout << "this line represents 2 ovals" << std::endl;
		}
		else if (find == 3) {
			std::cout << "this line represents a Bernoulli lemniscate " << std::endl;
		}
		else if (find == 4) {
			std::cout << "this line represents a curve with a concave web " << std::endl;
		}
		else if (find == 5) {
			std::cout << "this line represents a oval" << std::endl;
		}
		else if (find == 6) {
			std::cout << "this line represents a circle" << std::endl;
		}
		else {
			std::cout << "it is impossible to determine the type, it may not be a Cassini line " << std::endl;
		}
	}

	double find_distance() {

		int answer;
		if ((x * x + y * y) * (x * x + y * y) - (2 * c * c * (x * x - y * y)) == (a * a) - (c * c * c * c)) {
			answer = 1;
		}

		if (answer == 1) {
			double distance = sqrt(x * x + y * y);
			return distance;
		}
		else {
			return -1;
		}
	}


	void equation() {

		// Cassini line equation is: (x^2 + y^2)^2 - 2c^2(x^2 - y^2) = a^4 - c^4



		double first_param = 2 * c * c;
		double second_param = (a * a) - (c * c * c * c);

		std::string line;
		line.append("Cassini line equation is: (x^2 + y^2)^2 - ");
		line.append(std::to_string(first_param));
		line.append("(x^2 - y^2) = ");
		line.append(std::to_string(second_param));
		char* arr = new char[line.size() + 1];
		for (int i = 0; i < line.size(); i++) {
			arr[i] = line[i];
		}

		for (int i = 0; i < line.size(); i++) {
			std::cout << arr[i];
		}
		std::cout << std::endl;
	}


	double find_radius() {

		double x_rad = sqrt(c * c + a);
		double radius = x_rad - focus2_x;
		return radius;
	}

	void find_inflection_points() {
		double x1, y1, x2, y2;

		if (sqrt(a) == c) {
			std::cout << "it's Bernoulli lemniscate. inflection point is (0,0)" << std::endl;
		}
		else if ((c < sqrt(a)) && (sqrt(a) < c * sqrt(2))) {
			y1 = sqrt((focus2_x * focus2_x * focus2_x * focus2_x) - (a * a - c * c * c * c) + 2 * c * c * focus2_x * focus2_x) / (2 * c);
			y2 = -sqrt((focus2_x * focus2_x * focus2_x * focus2_x) - (a * a - c * c * c * c) + 2 * c * c * focus2_x * focus2_x) / (2 * c);
			x1 = sqrt(focus2_x * focus2_x - y1 * y1);
			x2 = -sqrt(focus2_x * focus2_x - y1 * y1);

			std::cout << "inflection points" << std::endl;
			std::cout << "(" << x1 << "," << y1 << ")" << std::endl;
			std::cout << "(" << x1 << "," << y2 << ")" << std::endl;
			std::cout << "(" << x2 << "," << y1 << ")" << std::endl;
			std::cout << "(" << x2 << "," << y2 << ")" << std::endl;

		}
		else {
			std::cout << "your line has not any inflection points" << std::endl;
		}

	}



};
