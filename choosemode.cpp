#include "choosemode.h"
#include <QCloseEvent>
#include <QCoreApplication>

ChooseMode::ChooseMode(QWidget *parent) : QDialog(parent)
{
    botButton = new QPushButton("Jouer contre le Bot", this);
    playerButton = new QPushButton("Jouer contre un autre joueur", this);

    setWindowTitle("Puissance 4 !");
    setFixedSize(300, 150); // Empêcher le redimensionnement de la fenêtre

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(botButton);
    layout->addWidget(playerButton);

    connect(botButton, &QPushButton::clicked, this, &ChooseMode::onBotClicked);
    connect(playerButton, &QPushButton::clicked, this, &ChooseMode::onPlayerClicked);
}

void ChooseMode::onBotClicked()
{
    emit modeSelected(true);
    accept();
}

void ChooseMode::onPlayerClicked()
{
    emit modeSelected(false);
    accept();
}

void ChooseMode::closeEvent(QCloseEvent *event)
{
    QCoreApplication::quit();
    _exit(0);
}
