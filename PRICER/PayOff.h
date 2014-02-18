#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{
    public :
    PayOff();
    virtual double operator()(double Spot) const=0;
private :
    int i;
};


class PayOffCall : public PayOff
{
    public :
        PayOffCall(double Strike);
        virtual double operator()(double Spot) const;
    private :
        double m_Strike;
};


class PayOffPut : public PayOff
{
    public :
        PayOffPut(double Strike);
        virtual double operator()(double Spot) const;
    private :
    double m_Strike;
  };
#endif // PAYOFF_H
