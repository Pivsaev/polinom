#include "Monom.h"

std::ostream& operator<<(std::ostream& out, const Monom& monom)
{
    out << monom.koeff;
    if (monom.svertka / 100 == 1) {
        out << 'x';
    }
    else if (monom.svertka / 100 > 1) {
        out << "x^" << monom.svertka/100;
    }
    if ((monom.svertka / 10) % 10 == 1) {
        out << 'y';
    }
    else if ((monom.svertka / 10) % 10  > 1) {
        out << "y^" << (monom.svertka / 10) % 10 ;
    }
    if (monom.svertka % 10 == 1) {
        out << 'z';
    }
    else if (monom.svertka % 10 > 1) {
        out << "z^" << monom.svertka % 10;
    }
    return out;
}

Monom::Monom(int _koeff, int _svertka):koeff(_koeff), svertka(_svertka){}

int Monom::GetKoeff()
{
    return koeff;
}

int Monom::GetSvertka()
{
    return svertka;
}

void Monom::AddKoeff(int _koeff)
{
    koeff += _koeff;
}

