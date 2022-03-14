///
/// \file train.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "train.h"

///
/// \brief Constructeur de train
///
train::train()
{
    m_positiont = QPoint(75,140) ;
}

///
/// \fn train::afficher(QPainter * e)
/// \brief permet l'affichage du train
/// \param e : QPainter du painEvent de la fenêtre principale
///
void train::afficher(QPainter * e){
    e->drawPixmap(getPositionT().x(),getPositionT().y(),24,24,QPixmap(":/image/train.png"));

}

///
/// \fn train::prochainePosition(Case * case_visit,int nbIntTim , char dir)
/// \brief permet de calculer la prochaine position que le train va prendre
/// \param case_visit : la case sur laquelle se trouve le train
/// \param nbIntTim : la valeur du compteur du timer
/// \param dir : la direction dans laquelle doit se diriger le train
/// \return la prochaine position du train dans la fenêtre
///
QPoint train::prochainePosition(Case * case_visit,int nbIntTim , char dir){
    int delta_x = 0, delta_y = 0 ;
    // on prend en compte le type de rail dans le déplacement du train
    int type = case_visit->getTypeCase() ;
    switch (type){
        case 1 : if (dir == 'd'){ // si le train se déplace vers la droite
                    delta_x = 1 ; // le train se déplace de une unité horizontale vers la droite
                 }
                 if (dir == 'g'){ // le train se déplace vers la gauche
                     delta_x = -1 ; // le train se déplace de une unité horizontale vers la gauche
                 }
                 break ;
        case 2 : if (dir == 'h'){ // le train se déplace vers le haut
                    delta_y = - 1 ; // le train se déplace de une unité verticalement vers le bas
                  }
                  if (dir == 'b'){ // le train se déplace vers le bas
                      delta_y = 1 ; // le train se déplace de une unité verticalement vers le haut
                  }
                  break ;
         case 3 : if ( dir == 'b'){ // si le train se déplace vers le bas
                    if ( nbIntTim <= 50 ){ // si le train n'est pas encore parvenu à l'angle du rail
                       delta_y = 1 ;
                    }
                    else {
                       delta_x = -1 ; // si le train a dépassé l'angle du rail
                    }

                  }
                  if (dir == 'd'){ // si le train se déplace vers la droite
                      if ( nbIntTim <= 50 ){
                         delta_x = 1 ;
                      }
                      else {
                         delta_y = -1 ;
                      }
                  }
                  break ;
         case 4 : if ( dir == 'b'){ // si le train se déplace vers le bas
                    if ( nbIntTim <= 50 ){
                       delta_y = 1 ;
                    }
                    else {
                       delta_x = 1 ;
                    }

                  }
                  if (dir == 'g'){ // si le train se déplace vers la gauche
                      if ( nbIntTim <= 50 ){
                         delta_x = -1 ;
                      }
                      else {
                         delta_y = -1 ;
                      }
                  }
                  break ;
         case 5 : if (dir == 'd'){ // si le train se déplace vers la droite
                    if ( nbIntTim <= 50 ){
                       delta_x = 1 ;
                    }
                    else {
                       delta_y = 1 ;
                    }

                  }
                  if (dir == 'h'){ // si le train se déplace vers le haut
                      if ( nbIntTim <= 50 ){
                         delta_y = -1 ;
                      }
                      else {
                         delta_x = -1 ;
                      }
                  }
                  break ;
          case 6 : if (dir == 'h'){ // si le train se déplace vers le haut
                        if ( nbIntTim <= 50 ){
                           delta_y = -1 ;
                        }
                        else {
                           delta_x = 1 ;
                        }

                    }
                    if (dir == 'g'){ // si le train se déplace vers la gauche
                        if ( nbIntTim <= 50 ){
                             delta_x = -1 ;
                          }
                          else {
                             delta_y = 1 ;
                          }
                    }
                    break ;

    }
    // on retourne la nouvelle position du train
    return QPoint(m_positiont.x()+delta_x,m_positiont.y()+delta_y);

}

///
/// \fn train::getPositionT()
/// \brief Accesseur de la postion du train
/// \return la position du train
///
QPoint train::getPositionT(){
    return m_positiont ;
}

///
/// \fn train::setPositionTQPoint pos)
/// \brief Mutateur de la position du train
/// \param pos : nouvelle position du train
///
void train::setPositionT(QPoint pos){
    m_positiont = pos ;
}
