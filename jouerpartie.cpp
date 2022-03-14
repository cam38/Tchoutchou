///
/// \file jouerpartie.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "jouerpartie.h"
#include "ui_jouerpartie.h"

///
/// \brief Constructeur de la fenêtre jouerpartie
/// \param parent
/// \param niveau : niveau de la partie
///
jouerPartie::jouerPartie(QWidget *parent, int niveau) :
    QDialog(parent),
    ui(new Ui::jouerPartie)
{
    ui->setupUi(this);
    p = new partie(niveau);
    if (niveau == 1){
        // dimension de la fenêtre pour la grille 2x2
        this->setFixedHeight(400);
        this->setFixedWidth(500);
        // emplacement du feu pour la grille 2x2
        p->setPosFeu(QPoint(400,100));
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTrain()));
    nbIntTimer = 0;
}

///
/// \brief Destructeur de jouerpartie
///
jouerPartie::~jouerPartie()
{
    delete timer;
    delete ui;
    delete p;
}

///
/// \brief paintEvent de jouerpartie
/// \brief permet l'affichage graphique des différents éléments (images, dessins)
/// \param e : QPaintEvent de la fenetre jouerpartie
///
void jouerPartie::paintEvent(QPaintEvent* e) {

     QWidget::paintEvent(e);
     QPainter painter(this);

     p->afficher(&painter);

}

///
/// \brief mousePressEvent de jouerpartie
/// \brief permet de récuperer la position sur laquelle a cliqué le joueur dans la fenêtre
/// \param e : QMouseEvent de la fenêtre
///
void jouerPartie::mousePressEvent(QMouseEvent *e) {

    // si le joueur clique sur sa souris
    if(e->button() == Qt::LeftButton){

         if (!timer->isActive()){

            // on regarde si le clique correspond à un échange de case
            p->deplacerCase(e->pos());

             // on regarde si le clique correspond à une action sur le feu
             if (p->appuyerFeu(e->pos())){

                 // on recupère le chemin tracé par les rails dans la grille
                 cases_visitees = p->trajectoire() ;

                 //on place le train au bord de la première case
                 QPoint pt = QPoint(p->getPositionGrille().x() - 12 , p->getPositionGrille().y()+38);
                 p->setTrain(pt);

                 i = 0 ;
                 timer->start(1);
             }
         }

         this->repaint();
    }
}

///
/// \fn jouerPartie::updateTrain()
/// \brief permet de faire bouger le train en changeant sa position
///
void jouerPartie::updateTrain()
{
    // si la liste de cases visitées est non nulle et qu'on a pas dépassé la dernière case du chemin
    if ((cases_visitees.length() != 0) && (i != cases_visitees.length()) ){

        // si on se trouve sur le bord d'une case
        if (nbIntTimer%100 == 0 && nbIntTimer != 0 && flag){
            i ++ ;
            // si le train n'est pas sur la dernière case du chemin
            if (i != cases_visitees.length()){
                // on regarde dans quelle direction le train doit aller par la suite
                dir = p->directionDeplacement(*cases_visitees[i-1],*cases_visitees[i]);
            }
            flag = false ;
        }
        else {
            // on incrémente le timer
            nbIntTimer++;

            // on calcule la prochaine position du train
            QPoint newpos = p->prochainePosition(cases_visitees[i],nbIntTimer%100,dir);
            p->setTrain(newpos);

            flag = true ;


        }
    }
    else {
       // soit la liste de cases visitées est nulle, soit on a déjà parcouru tout le chemin
       // dans les deux cas le train s'arrête
       timer->stop();
       // si le chemin est entièrement valide (le train est sur la sortie), le passe passe au vert
       if (p->cheminValide()){
            p->setFeu(2);
            Dialog d(this);
            d.exec();
            this->done(0);


       }
       // sinon le feu passe au rouge
       else {
           p->setFeu(1);
           // la fenetre continuer s'affiche
           continuer c(this);
           c.exec();
           // si le joueur souhaite continuer, on place le train sur départ, et le feu devient gris
           if (c.getContinuer())
           {
               p->setTrain(QPoint(75,140));
               p->setFeu(0);
               // on remet le timer à 0
               nbIntTimer = 0;
               // on vide la liste de cases visitées
               cases_visitees.empty();

           }
           else
           {
               this->done(0);
           }
       }
    }

    this->repaint();
}
