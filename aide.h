///
/// \file aide.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///



#ifndef AIDE_H
#define AIDE_H

#include <QDialog>

namespace Ui {
///
/// \class aide
/// \brief La classe aide représente la fenêtre graphique pour le cas d'utilisation de l'aide
///
class aide;
}

class aide : public QDialog
{
    Q_OBJECT

public:
    explicit aide(QWidget *parent = nullptr);
    ~aide();

private:
    Ui::aide *ui;
};

#endif // AIDE_H
