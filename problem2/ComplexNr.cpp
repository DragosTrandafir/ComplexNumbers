#include "ComplexNr.h"
#include<iostream>
#include<cmath>
std::string ComplexNr::display_type="RECTANGULAR_FORM";
ComplexNr::ComplexNr() {
	this->real = 0;
	this->imag = 0;
}

ComplexNr::ComplexNr(double preal, double pimag) :real{ preal }, imag{ pimag } {

}

ComplexNr::~ComplexNr() {
	//destructor;
}

double ComplexNr::get_real() const {
	return real;
}
double ComplexNr::get_imag() const {
	return imag;
}
std::string ComplexNr::get_display() const {
	return display_type;
}

double magnitude(const ComplexNr& c1) {
	return sqrt(c1.real* c1.real + c1.imag * c1.imag);
}
double phase(const ComplexNr& c1) {
	return atan2(c1.imag, c1.real);
}




//parametrized constructors

void ComplexNr::set_real_imag(double real,double imag) {
	this->real = real;
	this->imag = imag;
}
void ComplexNr::set_display(std::string display) {
	display_type = display;
}


//operators
istream& operator>>(istream& is, ComplexNr& cn) {
	is >> cn.real >> cn.imag;
	return is;
}
ostream& operator<<(ostream& os, const ComplexNr& cn) {
	if(cn.display_type=="RECTANGULAR_FORM")
		if(cn.imag>=0)
			os << cn.real << "+" << cn.imag << "*i" << std::endl;
		else
			os << cn.real << cn.imag << "*i" << std::endl;
	else
			os << magnitude(cn)<<"*(cos" << acos(phase(cn)) << "+" << "i*(sin" << asin(phase(cn))<<"))" << std::endl;

	return os;
}
bool operator==(const ComplexNr& c1, const ComplexNr& c2) {
	return (c1.real == c2.real && c1.imag == c2.imag);
}
bool operator!=(const ComplexNr& c1, const ComplexNr& c2) {
	return !(c1.real == c2.real && c1.imag == c2.imag);
}
// addition, substr, mult
ComplexNr operator+(const ComplexNr& c1, const ComplexNr& c2) {
	return ComplexNr{ c1.real + c2.real,c1.imag + c2.imag };
}
ComplexNr operator-(const ComplexNr& c1, const ComplexNr& c2) {
	return ComplexNr{ c1.real - c2.real,c1.imag - c2.imag };
}
ComplexNr operator*(const ComplexNr& c1, const ComplexNr& c2) {
	return ComplexNr{ c1.real*c2.real- c1.imag * c2.imag,c1.real* c2.imag+ c2.real* c1.imag };
}
ComplexNr operator&(double scalar, const ComplexNr& c) {
	return ComplexNr{scalar* c.real , scalar * c.imag };
}