#include "MC.h"
#include <QVector>
#include "Option.h"
using namespace std;

MC::MC() : i(0)
{   
}


//Methode de Monte Carlo avec Arrêt par nombre de chermins
QVector <double> MC::PrixA(unsigned long NumberOfPaths, Option& Option)
{
    QVector <double> PrixAV(NumberOfPaths);
    double runningSum(0);
    unsigned long i(0);
    while (i<NumberOfPaths-1)
 {
     i+=1;
     runningSum+=0.5*(Option.getPayOff(Option)[0]+Option.getPayOff(Option)[1]);
     PrixAV[i]=(runningSum/i)*exp(-Option.getExpiry()*Option.getr());
 }
    return PrixAV;
 }


//Methode de monte Carlo avec arrêt par le nombre de seconde(s) ecoulee(s)
double MC::PrixT(int secondes, Option& Option)
{
    time_t tbegin,tend;
    unsigned long k=0;
    double texec=0.;
    double runningSum(0);
    tbegin=time(NULL);              // Date du debut
    while (texec<secondes)
    {
        tend=time(NULL);                // Date de fin
        k+=1;
        runningSum+=0.5*(Option.getPayOff(Option)[0]+Option.getPayOff(Option)[1]);
        texec=difftime(tend,tbegin); // tend-tbegin (resultat en secondes)
    }
    double resultat=(runningSum/k)*exp(-Option.getExpiry()*Option.getr());
    return resultat;
}

// MonteCarlo avec arrêt par Standard Error:
double MC::PrixSE(int secondes, Option& Option)
{
    unsigned long k=0;
    double runningSum(0);
    double runningSumCarre(0);
    double VarianceEmpirique(100);
    double resultatSansEscompte(0);
    double resultat(0);
    double resultataucarre(0);
    while ((secondes<VarianceEmpirique) || (k<10) )
    {
        k+=1;
        double VAR=Option.getPayOff(Option)[1];
        runningSum+=VAR;
        runningSumCarre+=VAR*VAR;
        if (k==1) {
            runningSum+=Option.getPayOff(Option)[1];
            runningSumCarre+=Option.getPayOff(Option)[1]*Option.getPayOff(Option)[1];
            k=2;
     }

        resultatSansEscompte=(runningSum/k);
        resultataucarre=(runningSumCarre/k);
        VarianceEmpirique=sqrt((resultataucarre-resultatSansEscompte*resultatSansEscompte)/k);
  }
    resultat=resultatSansEscompte*exp(-Option.getExpiry()*Option.getr());
        return resultat;
}

// Arret avec la convexite: quand une valeur supplementaire n'apporte plus d'information, on arrêt la boucle.
// Ne fonctionne pas, donc pas implémenté: il y a des moments où le monte Carlo

double MC::PrixCV(double secondes, Option& Option)
{
    unsigned long k(1);
        double runningSum(0);
        double resultat(0);
        double resultatancien(100);
     // Date du debut
    while (fabs(resultat-resultatancien)>secondes)
    {
        resultatancien=(runningSum/k)*exp(-Option.getExpiry()*Option.getr());
        runningSum+=0.5*(Option.getPayOff(Option)[0]+Option.getPayOff(Option)[1]);
        resultat=(runningSum/k)*exp(-Option.getExpiry()*Option.getr());
           k+=1;
    }

    return resultat;
}

double MC::PrixAc(unsigned long NumberOfPaths, Option& Simu, double Spot, double Expiry, double r, double sigma)
{
    double runningSum(0);
    for(int i=1;i<NumberOfPaths;i++)
    {
        runningSum+=Simu.getPayOffg(Simu, Spot, Expiry, r, sigma);
    }
    double mean = runningSum/NumberOfPaths;
    double resultat=mean*exp(-(Expiry*r));
    return resultat;
}

