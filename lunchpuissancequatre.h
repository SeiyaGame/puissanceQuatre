#ifndef LUNCHPUISSANCEQUATRE_H
#define LUNCHPUISSANCEQUATRE_H

#include "puissancequatre.h"
#include <QObject>

class LunchPuissanceQuatre : public QObject
{
    Q_OBJECT

public:
    LunchPuissanceQuatre();

private slots:
    void play();

private:
    PuissanceQuatre *puissanceQuatre;
};

#endif // LUNCHPUISSANCEQUATRE_H
