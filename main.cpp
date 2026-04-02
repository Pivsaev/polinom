#include <iostream>
#include "Monom.h"
#include "Link.h"
#include "LIst.h"
#include "Polinom.h"
const int n = 4;

int main() {
	Monom* m1 = new Monom(5, 123);
	Monom* m2 = new Monom(4, 8);
	Monom* m3 = new Monom(1, 14);
	Monom* m4 = new Monom(10, 666);
	/*std::cout << "Наши мономы их " << n << ':' << std::endl;
	Link* l1 = new Link(m1);
	Link* l2 = new Link(m2);
	Link* l3 = new Link(m3);
	Link* l4 = new Link(m4);
	std::cout << "l1: " << *l1 << std::endl << "l2: " << *l2 << std::endl << "l3: " << *l3 << std::endl << "l4: " << *l4 << std::endl;
	std::cout << "Образуем из l1 и l2 список list1, а из l3 и l4 список list2" << std::endl;
	List list1, list2;
	list1.Insert(l1);
	list1.Insert(l2);
	list2.Insert(l3);
	list2.Insert(l4);
	std::cout << "list1:  " << list1 << std::endl << "list2:  " << list2 << std::endl;*/
	std::cout << "Создадим два полинома. p1=m1+m2; p2=m3+m4" << std::endl;
	Polinom p1, p2, res;
	p1.AddMonom(m1);
	p1.AddMonom(m2);
	p2.AddMonom(m3);
	p2.AddMonom(m4);
	std::cout << "p1 = " << p1 << std::endl << "p2 = " << p2 << std::endl;
	std::cout << "Обычное сложение{res = p1+p2}" << std::endl;
	res = p1 + p2;
	std::cout << "p1+p2 = " << res << std::endl;
	res = p1.AddBySvertka(p2);
	std::cout << "Сложение по свертке: " << res;
}
Monom* m1 = new Monom(5, 123);
Monom* m2 = new Monom(-5, 123);

Monom* m3 = new Monom(5, 123);
Monom* m4 = new Monom(-4, 8);
