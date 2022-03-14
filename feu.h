///
/// \file feu.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#ifndef FEU_H
#define FEU_H

#include <QPoint>
#include <QPainter>
#include <QWidget>
#include <iostream>

using namespace std ;

///
/// \class feu
/// \brief La classe feu représente le feu cliquable permettant de lancer le train, il change de couleur selon le résultat de la partie (vert : gagné, rouge : perdu)

class feu
{
private :
    QPoint m_positionf ;
    int m_type_feu = 0;
public:
    feu();
    void setTypeFeu(int type);
    int getTypeFeu();
    void setPosFeu(QPoint p);
    QPoint getPosFeu();
    void afficher(QPainter * e);
    bool cliquerFeu(QPoint pos);
};

#endif // FEU_H
