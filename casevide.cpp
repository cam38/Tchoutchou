///
/// \file casevide.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "casevide.h"
///
/// \brief Constucteur de la case vide
/// \param position : position de la case dans la fenêtre
///
caseVide::caseVide(const QPoint& position):Case(position)
{
    m_type_case = 0 ;
}

///
/// \brief Constructeur de recopie de la case vide
/// \param cv : case vide à recopier
///
caseVide::caseVide(caseVide& cv):Case(cv)
{
    m_type_case = 0;
}

///
/// \fn caseVide::afficher(QPainter * e)
/// \brief permet d'afficher la case vide dans la fenêtre
/// \param e : QPainter du paintevent de la fenêtre
///
void caseVide::afficher(QPainter * e) const {
    // affichage graphique
    e->drawPixmap(getPosition().x(),getPosition().y(),100,100,QPixmap(":/image/railVide.png"));
}

