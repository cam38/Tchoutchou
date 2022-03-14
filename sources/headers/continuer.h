///
/// \file continuer.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#ifndef CONTINUER_H
#define CONTINUER_H

#include <QDialog>

namespace Ui {
class continuer;
}
///
/// \class continuer
/// \brief La classe continuer représente la fenêtre s'ouvrant lorsque le joueur a perdu et lui permet de continuer le jeu s'il le souhaite
///
class continuer : public QDialog
{
    Q_OBJECT

public:
    explicit continuer(QWidget *parent = nullptr);
    ~continuer();
    bool getContinuer();

private slots:

    void on_bouton_oui_clicked();

    void on_bouton_non_clicked();

private:
    Ui::continuer *ui;
    bool conti ;
};

#endif // CONTINUER_H
