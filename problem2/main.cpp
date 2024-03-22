#include "ComplexNr.h"
#include<iostream>

void display_mandelbrot(int width, int height, int max_its)
// this function computes and displays the mandelbrot sequence 
{
	const float x_start = -3.0f;
	const float x_fin = 1.0f;
	const float y_start = -1.0f;
	const float y_fin = 1.0f;
	double dx = (x_fin - x_start) / (width - 1);
	double dy = (y_fin - y_start) / (height - 1);
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			ComplexNr c0;
			c0.set_real_imag(0, 0);// create complex number z = 0 + 0i

			ComplexNr c;
			c.set_real_imag(x_start + x * dx, (y_start + y * dy));// create complex number c = x_start+ x*dx + (y_start+y*dy)i
			int iteration = 0;
			// while |z| < 2 and we haven't reach max_its
			while (magnitude(c0) < 2 && iteration < max_its) {
				c0 = c0 * c0 + c;// apply the rule: z = z*z + c
				iteration++;
			}
			// characters represented colored, using ASCI code representation
			if (iteration == max_its) {
				std::cout << "\033[34m*";
			}
			else {
				std::cout << "\033[32m-";
			}
		}
		std::cout << endl;
	}
}

void personalized_mandelbrot(int* its) {
	display_mandelbrot(100, 25, *its);// personalized mandelbrot representation, using a pointer to an input number
}

int main(void) {

	//allocate an integer value dynamically so as to read a value for the personalized_mandelbrot(nr_iterations) function
	int* nr_iterations = new int;
	cout << "Enter number of interations for Mandelbrot representation:" << endl;
	std::cin >> *nr_iterations;
	personalized_mandelbrot(nr_iterations);
	// Using ComplexNr class to perform different operations with complex numbers
	{
		// variables stocked in the stack
		ComplexNr c1;
		ComplexNr c2;
		ComplexNr c3;
		ComplexNr c4;

		// use the parametrized constructor to define a complex number
		c1.set_real_imag(1, -1);
		c2.set_real_imag(0, 42);
		c3.set_real_imag(1, 1);

		//using the << overloaded operator
		std::cout << "c1 complex number is: " << c1 << std::endl;
		std::cout << "c2 complex number is: " << c2 << std::endl;
		std::cout << "c3 complex number is: " << c3 << std::endl;

		//using the getter functions 
		std::cout << "The real part of c1 is: " << c1.get_real() << std::endl;
		std::cout << "The imaginary part of c1 is: " << c1.get_imag() << std::endl;

		//checking the != operator
		bool not_equal = (c1 != c2);
		std::cout << not_equal << std::endl;// we get 1, because c1(1-i) is different from c2(42*i)

		// checking the == operator
		bool equal2 = (c1 == c2);
		std::cout << equal2 << std::endl;// we get 0, because c1(1-i) is not equal to c2(42*i)

		// printing thr magnitude and the phase of the complex number c1
		std::cout << magnitude(c1) << std::endl;
		std::cout << phase(c1) << std::endl;

		std::cout << c1.get_display() << std::endl;
		std::cout << c1 << std::endl;
		c2.set_display("POLAR_FORM");
		std::cout << c2.get_display() << std::endl;
		std::cout << c1 << std::endl;

		// checking the addition, substraction and multiplication of c1 and c3 
		ComplexNr add3 = c1 + c3;
		add3.set_display("RECTANGULAR_FORM");
		std::cout << add3 << std::endl;

		ComplexNr substr = c1 - c3;
		substr.set_display("RECTANGULAR_FORM");
		std::cout << substr << std::endl;

		ComplexNr multipl = c1 * c3;
		multipl.set_display("RECTANGULAR_FORM");
		std::cout << multipl << std::endl;

		// reading a complex number with >> overloaded operator
		std::cout << "Read the real and the imaginary part of a complex number." << std::endl;
		std::cin >> c4;
		std::cout << c4 << std::endl;

		// scalar multiplication operator
		ComplexNr scalar_mult = 4 & c4;
		std::cout << scalar_mult << std::endl;

		// defining a complex number dynamically and freeing the memory, to avoid any memory leaks
		std::cout << "Dynamically allocated instance of the class:" << std::endl;
		ComplexNr* complexVariable = new ComplexNr(3.0, 4.0);
		std::cout << *complexVariable << std::endl;

		// multiplication between 2 complex number (c3 is allocated on the stack and complexVariable is on the heap)
		ComplexNr multipl2 = *complexVariable * c3;
		multipl.set_display("RECTANGULAR_FORM");
		std::cout << multipl2 << std::endl;


		delete complexVariable;

	}
	return 0;
}