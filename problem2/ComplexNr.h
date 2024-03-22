#include<iostream>
using namespace std;

class ComplexNr {
public:
	ComplexNr();
	ComplexNr(double preal, double pimag);
	~ComplexNr();

	double get_real() const;
	double get_imag() const;
	std::string get_display() const;

	void set_real_imag(double real,double imag);
	void set_display(std::string display);

	friend ostream& operator<<(ostream& os, const ComplexNr& cn);
	friend istream& operator>>(istream& is, ComplexNr& cn);

	friend bool operator==(const ComplexNr& c1, const ComplexNr& c2);
	friend bool operator!=(const ComplexNr& c1, const ComplexNr& c2);
	friend ComplexNr operator+(const ComplexNr& c1, const ComplexNr& c2);
	friend ComplexNr operator-(const ComplexNr& c1, const ComplexNr& c2);
	friend ComplexNr operator*(const ComplexNr& c1, const ComplexNr& c2);
	friend ComplexNr operator&(double scalar, const ComplexNr& c);

	friend double magnitude(const ComplexNr& c1);
	friend double phase(const ComplexNr& c1);
	//friend std::string toString(const ComplexNr& c1);

private:
	double real;
	double imag;
	static std::string display_type;
};
