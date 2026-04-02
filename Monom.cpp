#include "Monom.h"

std::ostream& operator<<(std::ostream& out, const Monom& monom)
{
    out << monom.koeff << "x^" << monom.svertka/100 << "y^"<< (monom.svertka/10)%10 << "z^"<< monom.svertka%10;
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
