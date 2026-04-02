#pragma once
#include <iostream>
#include "List.h"

class Polinom {
	List list;
public:
	Polinom();
	~Polinom();
	Polinom& operator=(const Polinom& p);
	void AddMonom(Monom* monom);
	friend std::ostream& operator<<(std::ostream& out, const Polinom& p);
	Polinom operator+(Polinom& p) const;
	Polinom(const Polinom& other);
	Polinom AddBySvertka(const Polinom& other) const;
};
