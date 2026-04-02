#pragma once
#include <iostream>
class Monom {
	int koeff;
	int svertka;
public:
	Monom(int _koeff, int _svertka);
	friend std::ostream& operator<<(std::ostream& out, const Monom& monom);
	int GetKoeff();
	int GetSvertka();
	void AddKoeff(int _koeff);
};
