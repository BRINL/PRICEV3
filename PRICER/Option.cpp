#include "Option.h"
#include "PayOff.h"
#include "Genealeatoire.h"
#include <cstdlib>
#include <cmath>
#include "FunVect.h"

using namespace std;

// Constructeur mère

Option::Option() {};

// Accesseurs Spot, Expiry, r //

double Option::getSpot() const
{
    return 0;
}

double Option::getStrike() const
{
    return 0;
}
double Option::getExpiry() const
{
    return 0;
}

QVector <double> Option::getPayOff(Option& Option) const
{
    QVector<double> A(2);
    return A;
}

double Option::getPayOffg(Option& Option, double Spot, double Expiry, double r, double sigma) const
{
    return 0;
}

double Option::getPayOffgT(double Spot) const
{
    return 0;
}


double Option::getr() const
{
    return 0;
}

double Option::getSigma() const
{
    return 0;
}

// Méthode virtuelle pure ??? (vérifier la dénomination)//

double Option::Simu(double Spot, double Expiry, double r, double sigma) const
{
    return 0;
}

////////////////////////////////// CLASSE FILLE 1 : OBJET "BROWNIEN"  //////////////////////////////////////
// Classe pour simuler le cours dans le cas du modèle Black-Scholes-Merton //


OptionB ::OptionB(double Strike, double Expiry, double Spot, double Vol, double r, PayOff& thePayOff) :  m_Strike(Strike), m_Expiry(Expiry), m_Spot(Spot), m_Vol(Vol), m_r(r), variance(m_Vol*m_Vol*m_Expiry), Rootvariance(sqrt(variance)), demivar(-0.5*variance), m_movedSpot(m_Spot*exp(m_r*m_Expiry+demivar)), thisSpotB(1), m_thePayOff(thePayOff)
{
}

OptionB::~OptionB()
{
}


QVector <double> OptionB::operator()(double Spot) const
{
    QVector <double> SpotTB(2);
    Random loi;
    SpotTB[0]=m_movedSpot*exp(Rootvariance*loi.GNormale());
    SpotTB[1]=m_movedSpot*exp(-Rootvariance*loi.GNormale());
    return SpotTB;
}


// Une version avec choix Spot et Expiry pour tracer les graphes, plus long car les calculs sont répétés dans chaque boucle de la MC //

double OptionB::Simu(double Spot, double Expiry, double r, double sigma) const
{
    double varianceSB(sigma*sigma*Expiry);
    double RootvarianceSB(sqrt(varianceSB));
    double demivarSB(-0.5*varianceSB);
    double movedSpot(Spot*exp(r*Expiry+demivarSB));
    Random loi;
    double SimuBr = movedSpot*exp(RootvarianceSB*loi.GNormale());
    return SimuBr;
}

// Accesseurs Spot, Expiry, r //

double OptionB::getSpot() const
{
    return m_Spot;
}

double OptionB::getExpiry() const
{
    return m_Expiry;
}

double OptionB::getr() const
{
    return m_r;
}

double OptionB::getSigma() const
{
    return m_Vol;
}

double OptionB::getStrike() const
{
    return m_Strike;
}

QVector <double> OptionB::getPayOff(Option& Option) const
{
    return FVect(Option(m_Spot), m_thePayOff);
}

double OptionB::getPayOffg(Option& Option, double Spot, double Expiry, double r, double sigma) const
{
    return m_thePayOff(Option.Simu(Spot, Expiry, r, sigma));
}

double OptionB::getPayOffgT(double Spot) const
{
    return m_thePayOff(Spot);
}



////////////////////////////////// CLASSE FILLE 2 : OBJET "LEVY"  //////////////////////////////////////
// Classe pour simuler le cours dans le cas du modèle de Levy //

OptionL ::OptionL(double Strike, double Expiry, double Spot, double Vol, double r, double lambda, double m, double vega2, PayOff& thePayOff) :  m_Strike(Strike), m_Expiry(Expiry), m_Spot(Spot), m_Vol(Vol), m_r(r), m_lambda(lambda), m_m(m), m_vega2(vega2), variance(m_Vol*m_Vol*m_Expiry), Rootvariance(sqrt(variance)), m_movedSpot(m_Spot*exp(m_r*m_Expiry+demivar)), demivar(-0.5*variance), thisSpotL(1), m_thePayOff(thePayOff)
{
}

QVector <double> OptionL::operator()(double Spot) const
{
    double T(1);
    Random loi;
    int N=loi.GPoisson(m_lambda*m_Expiry);
    QVector <double> SpotTL(2);
    if (N>1)
    {
    for (int i=1; i<N; i++)
    {
        T=T*(loi.GLogNormale(m_m, m_vega2));
    }
    SpotTL[0]=m_movedSpot*exp(Rootvariance*loi.GNormale())*T;
    SpotTL[1]=m_movedSpot*exp(-Rootvariance*loi.GNormale())*T;
    }

    return SpotTL;
}

double OptionL::Simu(double Spot, double Expiry, double r, double sigma) const
{
    double varianceSL(sigma*sigma*Expiry);
    double RootvarianceSL(sqrt(varianceSL));
    double demivarSL(-0.5*varianceSL);
    double movedSpot(Spot*exp(r*Expiry+demivarSL));
    Random loi;
    double SimuTL = movedSpot*exp(RootvarianceSL*loi.GNormale());
    double T(1);
    int N=loi.GPoisson(m_lambda*Expiry);
    if (N>1)
    for (int i=1;i<N;i++)
        T=T*(loi.GLogNormale(m_m, m_vega2));
        SimuTL=movedSpot*exp(RootvarianceSL*loi.GNormale())*T;
    return SimuTL;
}

// Accesseurs Spot, Expiry, r //

double OptionL::getSpot() const
{
    return m_Spot;
}

double OptionL::getExpiry() const
{
    return m_Expiry;
}

double OptionL::getr() const
{
    return m_r;
}

double OptionL::getSigma() const
{
    return m_Vol;
}

double OptionL::getStrike() const
{
    return m_Strike;
}

QVector <double> OptionL::getPayOff(Option& Option) const
{
    return FVect(Option(m_Spot), m_thePayOff);
}

double OptionL::getPayOffg(Option& Option, double Spot, double Expiry, double r, double sigma) const
{
    return m_thePayOff(Option.Simu(Spot, Expiry, r, sigma));
}

double OptionL::getPayOffgT(double Spot) const
{
    return m_thePayOff(Spot);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
