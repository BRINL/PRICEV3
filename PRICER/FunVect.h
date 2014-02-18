#ifndef FUNVECT_H
#define FUNVECT_H

#include "PayOff.h"
#include <QVector>
using namespace  std;


template<class PayOff>
QVector <double> FVect(QVector<double> A, PayOff& F)
{
QVector <double> B(A.size(),0);
for (int i(0);i<A.size();i++)
{
    B[i]=F(A[i]);
}
return B;
}



#endif // FUNVECT_H
