///
/// \file caserail.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#ifndef CASERAIL_H
#define CASERAIL_H

#include "Case.h"
///
/// \class caserail
/// \brief La classe caserail représente une case ayant un rail dans la grille, c'est une classe dérivée de la classe Case
///
class caseRail : public Case {

protected:

    // 0 : case vide
    // 1 : traversé horizontale
    // 2 : traversé verticale
    // 3 : coin bas droit
    // 4 : coin bas gauche
    // 5 : coin haut droit
    // 6 coin haut gauche


public :

    caseRail(const QPoint& position,const int& type_case);
    caseRail(caseRail& cr);
    void afficher(QPainter* e) const;
};

#endif // CASERAIL_H
