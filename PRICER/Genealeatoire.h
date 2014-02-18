#ifndef GENEALEATOIRE_H
#define GENEALEATOIRE_H

class Random
{
public:
    Random();
    double uRand();
    double GNormale();
    double GLogNormale(double m, double vega2);
    double GPoisson (double lambda);
private:
 int i;
};


/*double uRand();
double gNormale();
int gPoisson(double lambda);
double gLogNormale(double m, double vega2);
*/
#endif // GENEALEATOIRE_H
