///
/// \file casevide.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#ifndef CASEVIDE_H
#define CASEVIDE_H

#include "Case.h"

///
/// \class casevide
/// \brief La classe casevide représente une case vide (sans rail) dans la grille, c'est une classe dérivée de la classe Case
///

class caseVide : public Case
{
protected :


 public :
    caseVide(const QPoint& position);
    caseVide(caseVide& cv);
    void afficher(QPainter * e) const ;
};

#endif // CASEVIDE_H
