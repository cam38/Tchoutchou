///
/// \file partie.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "partie.h"
///
/// \brief Constructeur de partie
/// \param niv : niveau de la partie (1 : grille 2x2, 2 : grille 3x3)
///
partie::partie(const int& niv)
{
    QPoint p_sortie;

    niveau = niv ;

    // en fonction du niveau de la partie ou initialise le nombre de case et la sortie
    switch (niveau){
        case 1 : nbCase = 2 ;
                 p_sortie = QPoint(1,1);

                 break ;
        case 2 : nbCase = 3;
                 p_sortie = QPoint(2,2);
                 break ;
    }

    QPoint  p1(0,0), p3(100,100) ;


    m_grille = new grille(p1, p_sortie,p3,nbCase) ;
    m_feu = new feu();
    m_train = new train();
    resultat = false ;
    partieEnCours = true ;

}

///
/// \brief Destucteur de partie
///
partie::~partie()
{
    delete m_feu;
    delete m_grille;
    delete m_train;
}

///
/// \fn partie::afficher(QPainter * e )
/// \brief pemet d'afficher tous les élements graphiques de la partie (feu, train, grille, drapeau de sortie)
/// \param e : QPainter du paintEvent de la fenêtre de jeu
///
void partie::afficher(QPainter * e ){
    m_grille->afficher(e);
    m_feu->afficher(e);
    // on affiche le drapeau qui marque l'arrivée
    e->drawPixmap(getPositionGrille().x()+100*nbCase,getPositionGrille().y()+(nbCase-1)*100+30,40,40,QPixmap(":/image/drapeau.jpg"));
    m_train->afficher(e);
}

///
/// \fn partie::trajectoire()
/// \brief appelle la fonction calculer chemin de grille
/// \return la liste de cases représentant le chemin que doit emprunter le train
///
QList<Case*> partie::trajectoire(){
    return m_grille->calculerChemin();
}

///
/// \fn partie::cheminValide()
/// \brief appelle l'accesseur de chemin_valide de grille
/// \return true si le chemin est valide (atteint la sortie de la grille), false sinon
///
bool partie::cheminValide(){
    resultat = m_grille->getCheminValide();
    return resultat ;
}

///
/// \fn partie::appuyerFeu(QPoint pos)
/// \brief appelle cliquerFeu de feu
/// \param pos : position cliquée par l'utilisateur dans la fenêtre
/// \return true si le feu a été cliqué, false sinon
///
bool partie::appuyerFeu(QPoint pos){
    return m_feu->cliquerFeu(pos);
}

///
/// \fn partie::deplacerCase(QPoint position)
/// \brief appelle deplacerCase de grille
/// \param position : position du curseur dans la fenetre
///
void partie::deplacerCase(QPoint position){
    m_grille->deplacerCase(position);
}

///
/// \fn partie::setTrain(QPoint pos)
/// \brief Mutateur de la position du train
/// \param pos : nouvelle position du train
///
void partie::setTrain(QPoint pos){
    m_train->setPositionT(pos);
}

///
/// \fn partie::getTrain()
/// \brief Accesseur de la position du train
/// \return la position du train
///
QPoint partie::getTrain(){
    return m_train->getPositionT() ;
}

///
/// \fn partie::directionDeplacement(Case& c1,Case& c2)
/// \brief appelle directionDeplacement de grille
/// \param c1 : case où se trouve le train
/// \param c2 : case où doit se rendre le train
/// \return un char 'h' (haut), 'b' (bas), 'd' (droite) ou 'g' (gauche)
///
char partie::directionDeplacement(Case& c1,Case& c2){
    return m_grille->directionDeplacement(c1,c2);
}

///
/// \fn partie::prochainePosition(Case * case_visit,int nbIntTim , char dir)
/// \brief appelle prochainePosition de train
/// \param case_visit : case sur laquelle se trouve le train
/// \param nbIntTim : la valeur du timer
/// \param dir : la direction dans laquelle doit se déplacer le train
/// \return la prochaine position que doit prendre le train
///
QPoint partie::prochainePosition(Case * case_visit,int nbIntTim , char dir){
    return m_train->prochainePosition(case_visit,nbIntTim,dir);
}

///
/// \fn partie::setFeu(int t)
/// \brief Mutateur du type de du feu
/// \param t : nouveau type du feu
///
void partie::setFeu(int t){
    m_feu->setTypeFeu(t);
}

///
/// \fn partie::getFeu()
/// \brief Accesseur du type du feu
/// \return le type du feu
///
int partie::getFeu(){
    return m_feu->getTypeFeu();
}

///
/// \fn partie::setPosFeu(QPoint t)
/// \brief Mutateur de la position du feu
/// \param t : nouvelle position du feu
///
void partie::setPosFeu(QPoint t){
    m_feu->setPosFeu(t);
}

///
/// \fn partie::getPosFeu()
/// \brief Accesseur de la position du feu
/// \return la position du feu
///
QPoint partie::getPosFeu(){
    return m_feu->getPosFeu();
}

///
/// \fn partie::setPositionGrille(QPoint pos)
/// \brief Mutateur de la position de la grille
/// \param pos : nouvelle position de la grille
///
void partie::setPositionGrille(QPoint pos)
{
    m_grille->setPositionG(pos);
}

///
/// \fn partie::getPositionGrille()
/// \brief Accesseur de la position de la grille
/// \return la position de la grille dans la fenêtre de jeu
///
QPoint partie::getPositionGrille()
{
    return m_grille->getPositionG();
}
