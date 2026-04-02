#pragma once
#include <iostream>
#include "Link.h"

class List {
protected:
	Link* head;
	Link* tail;
	int count;
public:
	List();
	~List();
	List& operator=(const List& other);
	void Insert(Link* newLink);
	friend std::ostream& operator<<(std::ostream& out, const List& list);
	Link* FindBySvertka(int _svertka) const;
	Link* GetHead() const;
	bool IsEmpty() const;
	void Remove(Link* linkToRemove);
	int GetCount() const;
};
