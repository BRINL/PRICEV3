//  Genealeatoire.cpp


#include "Genealeatoire.h"
#include <cstdlib>
#include <cmath>
#include "math.h"
#include "time.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;


//Constructeur:
Random::Random() : i(0)
{};

//Classe mère:

double Random::uRand()
  {
     return (rand()/static_cast<double>(RAND_MAX));
 }


double Random::GNormale()
    {
            double result=0;
            for (unsigned long j=0; j < 12; j++)
            result += rand()/static_cast<double>(RAND_MAX);
            result -= 6.0;
            return result;

    }

double Random::GLogNormale(double m, double vega2)
{
      Random loi;
      double normal=sqrt(vega2)*loi.GNormale()+m;
      double lognormal=exp(normal);
      return lognormal;
}

        double Random::GPoisson(double lambda)
{
    double L=exp(-lambda);
    double p(1);
    int k(1);
    Random Uniforme;
    while (p>L)
    {
        p=p*Uniforme.uRand();
        k+=1;
    }
    return (k-1);
}

/*
////////////////////////////////// UNIFORME (0,1) //////////////////////////////////////

double uRand()
{
    return (rand()/static_cast<double>(RAND_MAX));
}

////////////////////////////////// LOI NORMALE (0,1)  //////////////////////////////////////
// Méthode employée ??? //

double gNormale()
{
    double result=0;
    for (unsigned long j=0; j < 12; j++)
        result += rand()/static_cast<double>(RAND_MAX);
    result -= 6.0;
    return result;
     }

////////////////////////////////// LOI LOGNORMALE (m, vega2)  //////////////////////////////////////

double gLogNormale(double m, double vega2)
{
    double normal=sqrt(vega2)*gNormale()+m;
    return exp(normal);
}

////////////////////////////////// LOI POISSON (lambda)  //////////////////////////////////////

// Méthode employée ??? //

int gPoisson(double lambda)
{
    double L=exp(-lambda);
    double p(1);
    int k(1);
    while (p>L)
    {
        p=p*uRand();
        k+=1;
    }
    return (k-1);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

*/
