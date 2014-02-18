#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QVector>
#include "qcustomplot.h"
#include "PayOff.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void SetupPlotSimuB();
  void SetupPlotSimuL();
  void SetupPlotPayOffB();
  void SetupPlotPayOffL();
  void SetupPrices();
  void Greeksc();

public slots:
  void AddSimuL();
  void AddSimuB();
  double edStrike();
  double edSpot();
  double edExpiry();
  double edVol();
  double edr();
  double edlambda();
  double edm();
  double edvega2();
  bool edMCStop();
  bool edPOC();
  unsigned long  edNumberOfPaths();
  int edt();
  void update2();
  void update3();
  void update4();
  void CleanB();
  void CleanL();
  void VarP();
  void Volimp();



private:
  Ui::MainWindow *ui;
  int prec;

protected :
  double Spot;
  double Strike;
  double Expiry;
  double Vol;
  double r;
  double lambda;
  double m;
  double vega2;
  int TypeOption;
  int StopMCType;
  unsigned long NumberOfPaths;
  int secondes;
  PayOff* PO;
};

#endif // MAINWINDOW_H
