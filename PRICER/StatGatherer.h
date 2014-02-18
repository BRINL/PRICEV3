
#include <QVector>
#include "Option.h"

#ifndef STATGATHERER_H
#define STATGATHERER_H

class StatGatherer
{
public:
    StatGatherer(Option& MonOption, int taille, double fin);
    virtual QVector<double> SimuCoursB() ;
    virtual QVector<double> Axis() ;
    virtual QVector<double> GPO() ;
    virtual QVector<double> GPOT() ;
private :
    int m_taille ;
    double m_fin;
    Option& m_MonOption;
};

#endif // STATGATHERER_H

