///
/// \file Case.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#ifndef CASE_H
#define CASE_H

#include <QPoint>
#include <QPainter>
#include <iostream>

using namespace std ;
///
/// \class Case
/// \brief La classe Case représente une case de la grille, c'est une classe abstraite
///
class Case
{

protected :
    QPoint m_position ;
    int m_type_case ;

public :

    Case(const QPoint& position) ;
    Case(const Case& c);
    virtual void afficher(QPainter * e) const = 0 ;
    static void echanger(Case * c1,Case * c2) ;
    QPoint getPosition() const ;
    void setPosition(QPoint p) ;
    void setTypeCase(int type);
    int getTypeCase() const;
};

#endif // CASE
