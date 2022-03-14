///
/// \file caserail.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "caserail.h"
///
/// \brief Constructeur de la case rail
/// \param position : position de la case dans la fenêtre
/// \param type_case : type de la case (type de rail que représente la case)
///
caseRail::caseRail(const QPoint& position, const int& type_case):Case(position)
{
    m_type_case = type_case ;
}

///
/// \brief Constructeur de recopie de la case rail
/// \param cr : case à recopier
///
caseRail::caseRail(caseRail& cr):Case(cr)
{
    m_type_case = cr.m_type_case;

}

///
/// \fn caseRail::afficher(QPainter * e)
/// \brief permet d'afficher la case dans la fenêtre
/// \param e : QPainter de la fenêtre principale
///
void caseRail::afficher(QPainter * e) const {
    // affichage graphique d'une case rail
    // on affiche une image différente en fonction du type de rail
    switch(m_type_case)
    {
        case 1 : e->drawPixmap(getPosition().x(),getPosition().y(),100,100,QPixmap(":/image/railH.PNG"));
                break;
        case 2 : e->drawPixmap(getPosition().x(),getPosition().y(),100,100,QPixmap(":/image/railV.PNG"));
                break;
        case 3 : e->drawPixmap(getPosition().x(),getPosition().y(),100,100,QPixmap(":/image/railCBD.PNG"));
                break;
        case 4 : e->drawPixmap(getPosition().x(),getPosition().y(),100,100,QPixmap(":/image/railCBG.PNG"));
                break;
        case 5 : e->drawPixmap(getPosition().x(),getPosition().y(),100,100,QPixmap(":/image/railCHD.PNG"));
                break;
        case 6 : e->drawPixmap(getPosition().x(),getPosition().y(),100,100,QPixmap(":/image/railCHG.PNG"));
                break;
    }
}
