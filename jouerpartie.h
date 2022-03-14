///
/// \file jouerpartie.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#ifndef JOUERPARTIE_H
#define JOUERPARTIE_H

#include <QDialog>
#include <QMouseEvent>
#include <QTimer>
#include "QPainter"
#include "partie.h"
#include "continuer.h"
#include "dialog.h"

namespace Ui {
class jouerPartie;
}

///
/// \class jouerpartie
/// \brief La classe jouerpartie représente la fenêtre de la partie elle contient l'affichage graphique de la partie et permet à l'utilisateur de jouer
///
class jouerPartie : public QDialog
{
    Q_OBJECT

public:
    explicit jouerPartie(QWidget *parent = nullptr, int niveau=1);
    ~jouerPartie();
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent *e);


private slots:
    void updateTrain();

private:
    Ui::jouerPartie *ui;
    partie * p ;
    QTimer *timer;
    QList<Case*> cases_visitees ;
    int nbIntTimer, i;
    char dir = 'd';
    bool flag = true ;
};

#endif // JOUERPARTIE_H


