#ifndef QPUSHBUTTONCUSTOM_H
#define QPUSHBUTTONCUSTOM_H

#include <QObject>
#include <QPushButton>
#include <QWidget>

class QPushButtonCustom : public QPushButton
{
    Q_OBJECT
public:
    QPushButtonCustom(int index, QWidget *parent = Q_NULLPTR);

signals:
    void buttonClicked(int);

private slots:
    // Emits the new signal
    void handleClick();

private:
    // Numéro du QPushButton
    int _index;
};

#endif // QPUSHBUTTONCUSTOM_H
