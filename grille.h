///
/// \file grille.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#ifndef GRILLE_H
#define GRILLE_H

#include "caserail.h"
#include "casevide.h"

///
/// \class grille
/// \brief La classe grille représente la grille de la partie
///
class grille
{
private :
    QPoint m_entree , m_sortie, m_positiong;
    int m_nbCase ;
    int i_caseV = 0;
    int j_caseV = 0;
    bool chemin_valide ;
    Case *** m_matriceCase ;


public:

    grille();
    grille(const QPoint& entree,const QPoint& sortie,const QPoint& positiong,const int& nbCase);
    grille(const grille& g);
    ~grille();

    void deplacerCase(QPoint position);
    void afficher(QPainter * e);
    void genererGrilleAleatoire();
    char directionDeplacement(const Case& c1,const Case& c2);
    bool CasesConnectees(Case& c1, Case& c2);
    QList<Case*> listeVoisines(const Case& c);
    QList<Case*> calculerChemin();
    void setICaseVide(int i);
    void setJCaseVide(int j);
    int getICaseVide();
    int getJCaseVide();
    bool getCheminValide();
    QPoint getPositionG();
    void setPositionG(QPoint pos);
};

#endif // GRILLE_H
