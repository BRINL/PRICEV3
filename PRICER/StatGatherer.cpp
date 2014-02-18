#include "Option.h"
#include "StatGatherer.h"
#include "MC.h"
#include <QVector>



StatGatherer::StatGatherer(Option& MonOption, int taille, double fin) : m_taille(taille), m_fin(fin), m_MonOption(MonOption)
{
}


QVector<double> StatGatherer :: SimuCoursB()
{
    QVector<double> StatG(m_taille);
    double pas=m_fin/m_taille;
    double rec=m_MonOption.Simu(m_MonOption.getSpot(), pas, m_MonOption.getr(), m_MonOption.getSigma());
    double axe(0);
    for (int i=0;i<m_taille;++i)
    {
        axe+=pas;
        rec=m_MonOption.Simu(rec, pas, m_MonOption.getr(), m_MonOption.getSigma());
        StatG[i]=rec;
    }
    return StatG;
}

QVector<double> StatGatherer :: Axis()
{
    QVector<double> Axis(m_taille);
    double pas=m_fin/m_taille;
    double axe(0);
    for (int i=0;i<m_taille;++i)
    {
        Axis[i]=axe;
        axe+=pas;
    }
    return Axis;
}

QVector<double> StatGatherer :: GPO()
{
    QVector<double> GPO(m_taille);
    MC maMC;
    double pas=m_fin/m_taille;
    double axe(0);
    for (int i=0;i<m_taille;++i)
    {
        axe+=pas;
        GPO[i]=maMC.PrixAc(10000,m_MonOption,axe, m_MonOption.getExpiry(), m_MonOption.getr(), m_MonOption.getSigma());
    }
    return GPO;
}

QVector<double> StatGatherer :: GPOT()
{
    QVector<double> GPO(m_taille);
    double pas=m_fin/m_taille;
    double axe(0);
    for (int i=0;i<m_taille;++i)
    {
        GPO[i]=m_MonOption.getPayOffgT(axe);
        axe+=pas;
    }
    return GPO;
}
