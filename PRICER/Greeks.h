#ifndef GREEKS_H
#define GREEKS_H
#include "Option.h"

class Greeks
{
public:
Greeks();
};

class Deltac : public Greeks
{
public :
    Deltac(Option &MonOption, unsigned long prec);
    virtual double operator()(double Spot) const;
private :
    Option& m_Option;
    unsigned long m_prec;
};

class Thetac : public Greeks
{
public :
    Thetac(Option &MonOption, unsigned long prec);
    virtual double operator()(double Spot) const;
private :
    Option& m_Option;
    unsigned long m_prec;
};

class Vegac : public Greeks
{
public :
    Vegac(Option &MonOption, unsigned long prec);
    virtual double operator()(double Spot) const;
private :
    Option& m_Option;
    unsigned long m_prec;
};

class Rhoc : public Greeks
{
public :
    Rhoc(Option &MonOption, unsigned long prec);
    virtual double operator()(double Spot) const;
private :
    Option& m_Option;
    unsigned long m_prec;
};


#endif // GREEKS_H
