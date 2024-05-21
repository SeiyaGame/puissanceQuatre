#ifndef CHOOSEMONE_H
#define CHOOSEMONE_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

class ChooseMode : public QDialog
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event) override;

public:
    explicit ChooseMode(QWidget *parent = nullptr);

private slots:
    void onBotClicked();
    void onPlayerClicked();

signals:
    void modeSelected(bool bot);

private:
    QPushButton *botButton;
    QPushButton *playerButton;
};

#endif // CHOOSEMONE_H
