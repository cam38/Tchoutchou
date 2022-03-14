///
/// \file feu.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "feu.h"
///
/// \brief Constructeur de feu
///
feu::feu(){
    m_positionf = QPoint(500,100) ;
    m_type_feu = 0;
}

///
/// \fn feu::setTypeFeu(int type)
/// \brief Mutateur du type du feu
/// \param type : nouveau type du feu
///
void feu::setTypeFeu(int type)
{
    m_type_feu = type;
}

///
/// \fn feu::getTypeFeu()
/// \brief Accesseur du type du feu
/// \return le type du feu
///
int feu::getTypeFeu()
{
    return m_type_feu;
}

///
/// \fn feu::setPosFeu(QPoint p)
/// \brief Mutateur de la position du feu
/// \param p : nouvelle position du feu
///
void feu::setPosFeu(QPoint p)
{
    m_positionf = p;
}

///
/// \fn feu::getPosFeu()
/// \brief Accesseur de la position du feu
/// \return la position du feu
///
QPoint feu::getPosFeu()
{
    return m_positionf;
}

///
/// \fn feu::afficher(QPainter * e)
/// \brief permet l'affichage du feu
/// \param e : QPainter du paintEvent de la fenêtre de jeu
///
void feu::afficher(QPainter * e)
{
    // en fonction du type de feu, il prend une couleur différente
    // 0 : le feu n'est pas allumé
    // 1 : le feu est rouge
    // 2 : le feu est vert
    switch(m_type_feu)
    {
        case 0: e->setPen(Qt::gray);
                e->setBrush(Qt::gray);
                e->drawEllipse(m_positionf, 30, 30);
                break ;
        case 1: e->setPen(Qt::red);
                e->setBrush(Qt::red);
                e->drawEllipse(m_positionf, 30, 30);
                break ;
        case 2: e->setPen(Qt::green);
                e->setBrush(Qt::green);
                e->drawEllipse(m_positionf, 30, 30);
                break ;

    }
}

///
/// \fn feu::cliquerFeu(QPoint position)
/// \brief permet de reconnaitre si le joueur a cliqué sur le feu
/// \param position : point cliqué par l'utilisateur dans la fenêtre
/// \return true si le feu a été cliqué, false sinon
///
bool feu::cliquerFeu(QPoint position){

    bool clique = false ;
    // on regarde si le curseur se situe sur l'emplacement du feu dans la fenêtre
    if (position.x()>=m_positionf.x()-30 && position.x()<=m_positionf.x()+30 && position.y()>=m_positionf.y()-30 && position.y()<=m_positionf.y()+30){
        clique  = true ;
    }

    return clique ;
}

