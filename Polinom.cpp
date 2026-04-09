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
        delete monom;
        if (l->GetMonomData()->GetKoeff() == 0) {
            list.Remove(l);
        }
    }
    else {
        Link* linkk = new Link(monom);
        list.Insert(linkk);
    }
}

Polinom Polinom::operator+(Polinom& p) const
{
    Polinom result;
    Link* dummy1 = list.GetDummy();
    Link* curr = list.GetHead();
    while (curr != dummy1) {
        Monom* m = curr->GetMonomData();
        Monom* newMonom = new Monom(m->GetKoeff(), m->GetSvertka());
        result.AddMonom(newMonom);
        curr = curr->GetNextLink();
    }
    Link* dummy2 = p.list.GetDummy();
    curr = p.list.GetHead();
    while (curr != dummy2) {
        Monom* m = curr->GetMonomData();
        Monom* newMonom = new Monom(m->GetKoeff(), m->GetSvertka());
        result.AddMonom(newMonom);
        curr = curr->GetNextLink();
    }
    return result;
}

Polinom::Polinom(const Polinom& other) : list(other.list) {}

Polinom Polinom::AddBySvertka(const Polinom& other) const
{
    Polinom result;
    Link* dummy1 = list.GetDummy();
    Link* curr1 = list.GetHead();
    while (curr1 != dummy1) {
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
    Link* dummy = p.list.GetDummy();
    Link* curr = p.list.GetHead();
    bool first = true;
    bool printed = false;
    while (curr != dummy) {
        Monom* m = curr->GetMonomData();
        int coeff = m->GetKoeff();
        if (coeff != 0) {
            int absCoeff = (coeff < 0) ? -coeff : coeff;
            int svertka = m->GetSvertka();
            int degX = svertka / 100;
            int degY = (svertka / 10) % 10;
            int degZ = svertka % 10;
            bool hasVars = (degX != 0 || degY != 0 || degZ != 0);
            if (!first) {
                out << (coeff > 0 ? " + " : " - ");
            }
            else if (coeff < 0) {
                out << "-";
            }
            if (absCoeff != 1 || !hasVars) {
                out << absCoeff;
            }
            if (degX != 0) out << "x^" << degX;
            if (degY != 0) out << "y^" << degY;
            if (degZ != 0) out << "z^" << degZ;
            first = false;
            printed = true;
        }
        curr = curr->GetNextLink();
    }
    if (!printed) {
        out << "0";
    }
    return out;
}
