#include "Polinom.h"

Polinom::Polinom():list(){}

Polinom::~Polinom()
{
}

Polinom& Polinom::operator=(const Polinom& p) 
{
	if (this != &p) {
		list = p.list;
	}
	return *this;
}

void Polinom::AddMonom(Monom* monom)
{
	Link* l = list.FindBySvertka(monom->GetSvertka());
	if (l != nullptr) {
		l->GetMonomData()->AddKoeff(monom->GetKoeff());
	}
	else {
		Link* linkk = new Link(monom);
		list.Insert(linkk);
	}
}

Polinom Polinom::operator+(Polinom& p) const
{
    Polinom result;
    Link* curr = list.GetHead();
    while (curr != nullptr) {
        Monom* m = curr->GetMonomData();
        Monom* newMonom = new Monom(m->GetKoeff(), m->GetSvertka());
        result.AddMonom(newMonom);
        curr = curr->GetNextLink();
    }
    curr = p.list.GetHead();
    while (curr != nullptr) {
        Monom* m = curr->GetMonomData();
        Monom* newMonom = new Monom(m->GetKoeff(), m->GetSvertka());
        result.AddMonom(newMonom);
        curr = curr->GetNextLink();
    }
    return result;;
}

Polinom::Polinom(const Polinom& other) : list(other.list) {}

Polinom Polinom::AddBySvertka(const Polinom& other) const
{
    Polinom result;
    Link* curr1 = list.GetHead();
    while (curr1 != nullptr) {
        Monom* m1 = curr1->GetMonomData();
        int svertka1 = m1->GetSvertka();
        Link* found = other.list.FindBySvertka(svertka1);
        if (found != nullptr) {
            Monom* m2 = found->GetMonomData();
            int sumKoeff = m1->GetKoeff() + m2->GetKoeff();
            if (sumKoeff != 0) {
                Monom* newMonom = new Monom(sumKoeff, svertka1);
                result.AddMonom(newMonom);
            }
        }

        curr1 = curr1->GetNextLink();
    }

    return result;
}

std::ostream& operator<<(std::ostream& out, const Polinom& p)
{
    if (p.list.IsEmpty()) {
        out << "0";
        return out;
    }
    Link* curr = p.list.GetHead();
    bool first = true;
    while (curr) {
        Monom* m = curr->GetMonomData();
        int coeff = m->GetKoeff();
        if (coeff != 0) {
            if (first) {
                if (coeff < 0) out << "-";
                out << *m;
                first = false;
            }
            else {
                if (coeff > 0) out << " + ";
                else out << " - ";
                out << *m;
            }
        }
        curr = curr->GetNextLink();
    }
    return out;
}
