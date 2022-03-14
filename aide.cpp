///
/// \file aide.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "aide.h"
#include "ui_aide.h"
///
/// \brief Constructeur de la fenêtre aide
/// \param parent
///
aide::aide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aide)
{
    ui->setupUi(this);
    // texte de l'aide
    ui->aidetexte->setText("Règles du jeu \n"
                       "    - Dans la fenêtre principale, si vous cliquez sur\n"
                       "Configurer jeu, vous pouvez selectionner le niveau du jeu\n"
                       "c'est-à dire jouer sur une grille 2x2 ou 3x3\n"
                       "    - Une fois la partie lancée (appuyer sur Jouer à TchouTchou)\n"
                       "une nouvelle fenêtre s'ouvre et s'affiche la grille, le train,\n"
                       "le drapeau marquant la sortie et le feu\n"
                       "Le but du jeu est de déplacer les cases de la grille pour \n"
                       "obtenir un chemin empruntable par le train pour rejoindre le\n"
                       "drapeau de sortie.\n"
                       "Pour ça il faut cliquer sur la case que vous vous voulez échanger\n"
                       "avec la case vide et l'échange se produit.\n"
                       "Une fois que vous pensez avoir trouvé un chemin valide, cliquez\n"
                       "sur le feu.\n"
                       "Le train commence à rouler, puis lorsqu'il s'arrête le feu s'allume\n"
                       "vert si le chemin est valide, rouge sinon\n"
                       "Si le chemin est valide une nouvelle fenêtre avec un gif de félicitation\n"
                       "s'ouvre, sinon une fenêtre s'ouvre pour s'avoir si vous voulez continuer\n"
                       "la partie en cours.\n"
                       "Si oui, la fenêtre se ferme, le train reprend sa position de départ et\n"
                       "le feu repasse au gris\n"
                       "Sinon, la fenêtre de la partie en cours se ferme et vous retournez à la\n"
                       "fenêtre du menu principal\n");
}

///
/// \brief Destructeur de la fenêtre aide
///
aide::~aide()
{
    delete ui;
}
