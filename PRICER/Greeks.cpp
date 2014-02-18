#include "Greeks.h"
#include "Option.h"
#include "MC.h"
#include "Deriv.h"

Greeks::Greeks()
{}

Deltac::Deltac(Option& MonOption, unsigned long prec) : m_Option(MonOption), m_prec(prec)
{
}

double Deltac::operator()(double Spot) const
{
    MC maMC;
    return maMC.PrixAc(m_prec,m_Option, Spot, m_Option.getExpiry(), m_Option.getr(), m_Option.getSigma()) ;
}

Thetac::Thetac(Option& MonOption, unsigned long prec) : m_Option(MonOption), m_prec(prec)
{
}

double Thetac::operator()(double Expiry) const
{
    MC maMC;
    return maMC.PrixAc(m_prec,m_Option, m_Option.getSpot(), Expiry, m_Option.getr(), m_Option.getSigma()) ;
}


Vegac::Vegac(Option& MonOption, unsigned long prec) : m_Option(MonOption), m_prec(prec)
{
}

double Vegac::operator()(double sigma) const
{
    MC maMC;
    return maMC.PrixAc(m_prec,m_Option, m_Option.getSpot(), m_Option.getExpiry(), m_Option.getr(), sigma) ;
}

Rhoc::Rhoc(Option& MonOption, unsigned long prec) : m_Option(MonOption), m_prec(prec)
{
}

double Rhoc::operator()(double r) const
{
    MC maMC;
    return maMC.PrixAc(m_prec,m_Option, m_Option.getSpot(), m_Option.getExpiry(), r, m_Option.getSigma()) ;
}
