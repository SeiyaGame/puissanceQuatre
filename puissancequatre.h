#ifndef PUISSANCEQUATRE_H
#define PUISSANCEQUATRE_H

#include <QMainWindow>
#include <QList>
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QVector>
#include <QPushButton>
#include <QString>
#include <QtGlobal>
#include <QMessageBox>
#include <QRandomGenerator>

#include "qpushbuttoncustom.h"

namespace Ui
{
    class PuissanceQuatre;
}

class PuissanceQuatre : public QMainWindow
{
    Q_OBJECT

public:
    explicit PuissanceQuatre(QWidget *parent = 0);
    ~PuissanceQuatre();

    void disableAllButton();
    void enableAllButton();

    int randomButton();

    void addScore(int nbButton, bool player);

    void checkWin(int row, int col, QString player);

    bool checkRow(int row, QString player);
    bool checkCol(int row, int col, QString player);
    bool checkRightDiagonale(int row, int col, QString player);
    bool checkLeftDiagonale(int row, int col, QString player);

private slots:
    void on_pushButton(int);
    //    void play();

private:
    Ui::PuissanceQuatre *ui;

    bool _win = false;

    static const int _ROW = 6;
    static const int _COL = 7;

    // Tableau 2D de QLabel
    QLabel *_gridGameQlabel[_ROW][_COL];

    // Tableau 2D de scores, same size with gridGameQlabel
    QString _scores[_ROW][_COL] = {{""}};

    // Tableau avec nos boutons
    QPushButtonCustom *_gridQPushButton[_COL];
};

#endif // PUISSANCEQUATRE_H
