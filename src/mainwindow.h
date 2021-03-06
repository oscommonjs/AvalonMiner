#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bfgconf.h"
#include "minerplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void saveConf(bfgConf *);
    void runProcess(bool, const QStringList &);
    void addPlotValue(const plotInfo &);

public slots:
    void confChanged(bfgConf *);
    void confSaved();
    void processStarted();
    void processFinished();
    void updateInfo(minerInfo);
    void rpcConnected();
    void serialReady(QStringList);

private:
    Ui::MainWindow *ui;
    bool processStatus; /* true for started, false for not running */
    MinerPlot *plot;
    QStringList serialPara;

private slots:
    void saveClicked();
    void runClicked();
};

#endif // MAINWINDOW_H
