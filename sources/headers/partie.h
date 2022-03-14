///
/// \file partie.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#ifndef PARTIE_H
#define PARTIE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <string.h>
#include <stdio.h>

#include "iostream"
#include "grille.h"
#include "feu.h"
#include "train.h"

using namespace std ;

///
/// \class partie
/// \brief La classe partie permet la récupération de tous les élements importants pour jouer une partie : la grille, le train et le feu
///

class partie
{
private :
    bool resultat ;
    int niveau ;
    int nbCase ;
    bool partieEnCours ;
    feu * m_feu ;
    grille * m_grille ;
    train * m_train ;

public:
    partie();
    partie(const int& niveau);
    ~partie();

    //changer les arguments
    void afficher(QPainter * e);
    bool cheminValide();
    //bool lancerTrain();
    QList<Case*> trajectoire();
    bool appuyerFeu(QPoint pos);
    void deplacerCase(QPoint position);
    char directionDeplacement(Case& c1,Case& c2);
    QPoint prochainePosition(Case * case_visit,int nbIntTim , char dir);

    void setTrain(QPoint pos);
    QPoint getTrain();
    void setFeu(int t);
    int getFeu();
    void setPositionGrille(QPoint pos);
    QPoint getPositionGrille();
    void setPosFeu(QPoint t);
    QPoint getPosFeu();

};

#endif // PARTIE_H



