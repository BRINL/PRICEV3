#ifndef Option_H
#define Option_H

#include <iostream>
#include "PayOff.h"
#include <ctime>
#include <cmath>
#include <QVector>

/*
CLASSE MERE : Option
Les différentes méthodes de cette classe sont les différentes méthodes d'arrêt du Option
*/

class Option
{
    public :
    Option();
    virtual QVector <double> operator()(double Spot) const=0;
    virtual double getSpot() const;
    virtual double getExpiry() const;
    virtual double getr() const;
    virtual double getStrike() const;
    virtual double getSigma() const;
    virtual double Simu(double Spot, double Expiry, double r, double sigma) const;
    virtual QVector <double> getPayOff(Option& Option) const ;
    virtual double getPayOffg(Option& Option, double Spot, double Expiry, double r, double sigma) const ;
    virtual double getPayOffgT(double Spot) const ;

    protected :
};


/*
 CLASSE MERE : Option
Permet de simuler le cours avec la méthode B&S
 */

class OptionB : public Option
{
    public :
            OptionB(double Strike, double Expiry, double Spot, double Vol, double r, PayOff& thePayOff);
            virtual QVector <double> operator()(double Spot) const;
            virtual double Simu(double Spot, double Expiry, double r, double sigma) const;
            virtual double getSpot() const ;
            virtual double getExpiry() const ;
            virtual double getr() const ;
            virtual double getStrike() const ;
            virtual double getSigma() const ;
            virtual QVector <double> getPayOff(Option& Option) const ;
            virtual double getPayOffg(Option& Option, double Spot, double Expiry, double r, double sigma) const ;
            virtual double getPayOffgT(double Spot) const ;
    ~OptionB();

    protected :
    double m_Strike;
    double m_Expiry;
    double m_Spot;
    double m_Vol;
    double m_r;
    int m_TypeOption;
    double variance ;
    double Rootvariance;
    double demivar;
    double m_movedSpot;
    double thisSpotB;
    PayOff& m_thePayOff;

};

/*
 CLASSE MERE : Option
 Permet de simuler le cours avec la méthode Levy
 */


class OptionL : public Option
{
    public :
    OptionL(double Strike, double Expiry, double Spot, double Vol, double r, double lambda, double m, double vega2, PayOff& thePayOff);
    virtual QVector <double> operator()(double Spot) const;
    virtual double getSpot() const ;
    virtual double getExpiry() const ;
    virtual double getr() const ;
    virtual double getStrike() const ;
        virtual double getSigma() const ;
    virtual QVector <double> getPayOff(Option& Option) const ;
        virtual double getPayOffg(Option& Option, double Spot, double Expiry, double r, double sigma) const ;
    virtual double Simu(double Spot, double Expiry, double r, double sigma) const;
        virtual double getPayOffgT(double Spot) const ;


    protected :

    double m_Strike;
    double m_Expiry;
    double m_Spot;
    double m_Vol;
    double m_r;
    int m_TypeOption;
    double m_lambda;
    double m_m;
    double m_vega2;
    double variance ;
    double Rootvariance;
    double demivar;
    double m_movedSpot;
    double thisSpotL;
    PayOff& m_thePayOff;
};


#endif // Option_H
