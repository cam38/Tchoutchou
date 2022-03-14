///
/// \file Case.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "Case.h"
///
/// \brief Constructeur de Case
/// \param position : la position de la case dans la fenêtre
///
Case::Case(const QPoint& position){
    m_position = position ;
}

///
/// \brief Constructeur de recopie de Case
/// \param c : prend en argument une case et recopie celle-ci dans la case courante
///
Case::Case(const Case& c)
{
    m_position = c.m_position;
    m_type_case = c.m_type_case;
}

///
/// \fn Case::echanger(Case * c1,Case * c2)
/// \brief Permet d'échanger deux cases
/// \param c1 : première case à échanger
/// \param c2 : deuxième case à échanger
///
void Case::echanger(Case * c1,Case * c2){
    QPoint p = c2->getPosition();
    c2->setPosition(c1->getPosition());
    c1->setPosition(p);


}

///
/// \fn Case::getPosition()
/// \brief accesseur de la position
/// \return la position de la case
///
QPoint Case::getPosition() const {
    return m_position ;
}

///
/// \fn Case::setPosition(QPoint p)
/// \brief mutateur de la position
/// \param p : la nouvelle position de la case
///
void Case::setPosition(QPoint p){
    m_position = p ;
}

///
/// \fn Case::getTypeCase
/// \brief accesseur du type de case
/// \return le type de la case
///
int Case::getTypeCase() const{
    return m_type_case ;
}

///
/// \fn Case::setTypeCase(int type)
/// \brief mutateur du type de la case
/// \param type : le nouveau type de la case
///
void Case::setTypeCase(int type){
    m_type_case = type ;
}
