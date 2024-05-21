#include "puissancequatre.h"
#include "ui_puissancequatre.h"
#include <QDebug>

PuissanceQuatre::PuissanceQuatre(QWidget *parent) : QMainWindow(parent), ui(new Ui::PuissanceQuatre)
{

    ui->setupUi(this);

    setWindowTitle("Puissance 4 !");
    setFixedSize(780, 675); // On fixe la taille max de la fenetre

    ui->mainQlabel->setStyleSheet("background-color: #3232FF;");

    // Initialisation de notre grille ( QLabel )
    for (int i = 0; i < _ROW; ++i)
    {
        for (int j = 0; j < _COL; ++j)
        {
            _gridGameQlabel[i][j] = new QLabel();
            ui->gridQlabel->addWidget(_gridGameQlabel[i][j], i, j);
            _gridGameQlabel[i][j]->setStyleSheet("background-color: #FFFFFF; border-radius: 40%;");
        }
    }

    // Initialisation des boutons
    for (int i = 0; i < _COL; ++i)
    {
        _gridQPushButton[i] = new QPushButtonCustom(i);

        // DOC: https://doc.qt.io/qt-5/qcursor.html
        _gridQPushButton[i]->setCursor(Qt::ClosedHandCursor);
        ui->gridButton->addWidget(_gridQPushButton[i]);

        connect(_gridQPushButton[i], SIGNAL(buttonClicked(int)), this, SLOT(on_pushButton(int)));
    }

    ui->event->setText("A vous de jouer !!");
}

void PuissanceQuatre::on_pushButton(int btnCol)
{
    addScore(btnCol, true); // PLAYER
    if (!_win)
    {
        int rdm = randomButton();
        addScore(rdm, false); // BOT

    }
}

void PuissanceQuatre::disableAllButton()
{
    for (int i = 0; i < _COL; i++)
    {
        _gridQPushButton[i]->setDisabled(true);
    }
}

int PuissanceQuatre::randomButton()
{
    int random;
    do
    {
        random = QRandomGenerator::global()->generate() % _COL;
    } while (!_gridQPushButton[random]->isEnabled());

    return random;
}

void PuissanceQuatre::addScore(int nbButton, bool player)
{
    for (int i = _ROW - 1; i >= 0; i--)
    {
        if (_scores[i][nbButton] == "")
        {
            if (player)
            {
                _scores[i][nbButton] = "player";
                _gridGameQlabel[i][nbButton]->setStyleSheet("background-color: #FEFE00; border-radius: 40%;");
                checkWin(i, nbButton, "player");
            }
            else
            {
                _scores[i][nbButton] = "bot";
                _gridGameQlabel[i][nbButton]->setStyleSheet("background-color: #FE0009; border-radius: 40%;");
                checkWin(i, nbButton, "bot");
            }

            if (i == 0)
            {
                _gridQPushButton[nbButton]->setDisabled(true);
            }

            break;
        }
    }
}

void PuissanceQuatre::checkWin(int row, int col, QString player)
{

    if (checkRow(row, player) || checkCol(row, col, player) || checkRightDiagonale(row, col, player) || checkLeftDiagonale(row, col, player))
    {
        qDebug() << player << "win !";
        ui->event->setText(player + " a gagné !");

        if (player == "player")
        {
            QMessageBox::information(this, "Le puissance 4", "Trop fort !!!");
        }
        else
        {
            QMessageBox::warning(this, "Le puissance 4", "Vous êtes vraiment pas très bon !!!");
        }

        this->_win = true;
    }

    if (this->_win)
    {
        disableAllButton();
    }
}

bool PuissanceQuatre::checkRightDiagonale(int row, int col, QString player)
{
    int somme = 1;

    for (int i = 1; i < 4; ++i)
    {
        if ((row - i) < 0 || (col + i) > (_COL - 1)){break;}
        if (player == _scores[row - i][col + i]){somme++;}
        else {break;}
    }

    for (int i = 1; i < 4; ++i)
    {
        if ((row + i) > (_ROW - 1) || (col - i) < 0){break;}
        if (player == _scores[row + i][col - i]){somme++;}
        else {break;}
    }

    if (somme >= 4){return true;}

    return false;
}

bool PuissanceQuatre::checkLeftDiagonale(int row, int col, QString player)
{
    int somme = 1;

    for (int i = 1; i < 4; ++i)
    {
        if ((row - i) < 0 || (col - i) < 0){break;}
        if (player == _scores[row - i][col - i]){somme++;}
        else {break;}
    }

    for (int i = 1; i < 4; ++i)
    {
        if ((row + i) > (_ROW - 1) || (col + i) > (_COL - 1)){break;}
        if (player == _scores[row + i][col + i]){somme++;}
        else {break;}
    }

    if (somme >= 4){return true;}

    return false;
}

bool PuissanceQuatre::checkRow(int row, QString player)
{
    int somme = 0;

    // check row
    for (int i = 0; i < _COL; i++)
    {
        if (player == _scores[row][i])
        {
            somme++;
            if (somme >= 4){return true;}
        }
        else {somme = 0;}
    }

    return false;
}

bool PuissanceQuatre::checkCol(int row, int col, QString player)
{
    int somme = 0;

    // check col -> en bas
    for (int i = row; i < _ROW; i++)
    {
        if (player == _scores[i][col]){somme++;}
        else {break;}
    }

    if (somme >= 4){return true;}

    return false;
}

PuissanceQuatre::~PuissanceQuatre()
{
    // On enleve les Qlabels de la mémoire
    for (int i = 0; i < _ROW; ++i)
    {
        for (int j = 0; j < _COL; ++j)
        {
            delete _gridGameQlabel[i][j];
        }
    }

    // On enleve les QPushButton de la mémoire
    for (int i = 0; i < _COL; ++i)
    {
        delete _gridQPushButton[i];
    }

    // delete _scores;
    // delete _gridQPushButton;
    // delete _gridGameQlabel;

    delete ui;
}
