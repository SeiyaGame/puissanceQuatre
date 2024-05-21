#include "qpushbuttoncustom.h"

QPushButtonCustom::QPushButtonCustom(int index, QWidget *parent)
    : QPushButton(parent), _index(index)
{
    connect(this, SIGNAL(clicked()), this, SLOT(handleClick()));
}

void QPushButtonCustom::handleClick()
{
    emit buttonClicked(_index);
}
