///
/// \file train.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#ifndef TRAIN_H
#define TRAIN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QPainter>

#include "Case.h"

///
/// \class train
/// \brief La classe train représente le train se déplaçant sur le chemin créé par l'utilisateur
///

class train
{
private :
    QPoint m_positiont ;

public:
    train();
    void afficher(QPainter *e );
    QPoint prochainePosition(Case * case_visit,int nbIntTim , char dir);
    QPoint getPositionT();
    void setPositionT(QPoint pos);
    // affichage train : plusieurs affichages consécutifs à des positions différentes pour donner l'illusion de mouvement
};

#endif // TRAIN_H
