#include "Link.h"

Link::Link(Monom* m, Link* n) :curMonomData(m), nextLink(n) {}

Link::Link(Monom* m):curMonomData(m), nextLink(nullptr)
{
}

void Link::SetNextLink(Link* Data)
{
	nextLink = Data;
}

void Link::SetMonom(Monom* _m)
{
	curMonomData = _m;
}

Link* Link::GetNextLink()
{
	return nextLink;
}

Monom* Link::GetMonomData()
{
	return curMonomData;
}

bool Link::IsLast()
{
	return nextLink==nullptr;
}

Link::~Link()
{
	delete curMonomData;
}

std::ostream& operator<<(std::ostream& out, const Link& link)
{
	if (link.curMonomData != nullptr) {
		out << *link.curMonomData;
	}
	return out;
}
