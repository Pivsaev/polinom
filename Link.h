#pragma once
#include <iostream>
#include "Monom.h"

class Link {
protected:
	Monom* curMonomData;
	Link* nextLink;
public:
	Link(Monom* m, Link* n);
	Link(Monom* m);
	void SetNextLink(Link* Data);
	void SetMonom(Monom* _m);
	Link* GetNextLink();
	Monom* GetMonomData();
	bool IsLast();
	~Link();
	friend std::ostream& operator<<(std::ostream& out, const Link& link);
};
