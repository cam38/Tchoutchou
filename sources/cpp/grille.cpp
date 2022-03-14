///
/// \file grille.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "grille.h"
///
/// \brief Constructeur par défaut de grille
///
grille::grille()
{
    QPoint p(0,0);
    m_entree = p ;
    m_sortie = p ;
    m_positiong = p ;
    m_nbCase = 2 ; // par defaut la grille est de dimension 2x2
    // la case vide est toujours la première case de la grille
    i_caseV = 0 ;
    j_caseV = 0 ;
    chemin_valide = false ;
    m_matriceCase = new Case ** [m_nbCase] ;
    for (int i=0; i<m_nbCase ;i++){
        (m_matriceCase)[i] = new Case * [m_nbCase];
    }


}

///
/// \brief Constructeur de grille
/// \param entree : position de l'entrée de la grille
/// \param sortie : position de la sortie de la grille
/// \param position : position de la grille dans la fenêtre
/// \param nbCase : le nombre de cases par lignes et colonnes de la grille
///
grille::grille(const QPoint& entree,const QPoint& sortie,const QPoint& position,const int& nbCase){
    m_entree = entree ;
    m_sortie = sortie ;
    m_positiong = position ;
    m_nbCase = nbCase ;
    // on part du principe que la case vide est toujours cette en haut à gauche au début de la partie
    i_caseV = 0;
    j_caseV = 0;
    chemin_valide = false ;

    m_matriceCase = new Case ** [nbCase] ;
    for (int i=0; i<nbCase ;i++){
        (m_matriceCase)[i] = new Case * [nbCase];
    }
    // on veut remplir la grille de cases aléatoires de sorte à ce qu'il existe un chemin valide
    // Pour cela on appelle la méthode genererGrilleAleatoire
    genererGrilleAleatoire();

}

///
/// \brief Constructeur de recopie de grille
/// \param g : grille qu'on veut recopier
///
grille::grille(const grille& g){

    m_entree = g.m_entree ;
    m_sortie = g.m_sortie ;
    m_positiong = g.m_positiong ;
    m_nbCase = g.m_nbCase ;
    i_caseV = g.i_caseV ;
    j_caseV = g.j_caseV ;
    chemin_valide = g.chemin_valide ;

    m_matriceCase = new Case ** [m_nbCase] ;
    for (int i=0; i<m_nbCase ;i++){
        (m_matriceCase)[i] = new Case * [m_nbCase];
    }

    for(int i = 0 ; i<m_nbCase ; i++){
        for(int j = 0 ; j<m_nbCase ; j++){
           *(m_matriceCase)[i][j] = *g.m_matriceCase[i][j] ;
        }
    }
}

///
/// \brief Destructeur de grille
///
grille::~grille(){

    for (int i = 0; i < m_nbCase; i++)
        {
            for (int j = 0; j < m_nbCase; j++)
            {
                m_matriceCase[i][j] = NULL;
            }
            delete[] m_matriceCase[i];
        }
        delete[] m_matriceCase;
}

///
/// \fn grille::afficher(QPainter * e)
/// \brief permet d'afficher la grille dans la fenêtre
/// \param e : QPainter du paintEvent de la fenêtre de jeu
///
void grille::afficher(QPainter * e) {

    for (int i = 0 ; i < m_nbCase ; i++ )
    {
         for (int j = 0 ; j < m_nbCase ; j++ )
         {
             // on affiche chaque case de la matrice
              m_matriceCase[i][j]->afficher(e);
         }
    }
}

///
/// \brief grille::genererGrilleAleatoire()
/// \brief permet de genérer une grille aléatoire ayant au moins un chemin valide
///
void grille::genererGrilleAleatoire()
{
    Case * c;

    // liste qui contient le type de case de toutes les cases rails de la grille
    int* chemin = new int[m_nbCase*m_nbCase-1] ;

    // il y a 4 combinaisons de cases possibles pour couvrir tout les chemins.
    // par abus de langage, on les appellera chemin1, chemin2, chemin3 et chemin4
    int choix_chemin ;

    srand((unsigned int)time(0)); // cette ligne permet de faire en sorte que le tirage soit totalement aléatoire

    // on fait en sorte que il y ait toujours un chemin possible pour relier l'entree à la sortie dans les grilles 3x3
    if (m_nbCase == 3){
        // On tire un numéro au hasard entre 1 et 4 : ce sera le numéro du chemin que nous ferons apparaitre dans la grille
        choix_chemin = rand()%4 + 1 ;
        switch (choix_chemin){
            // on ajoute à la liste chemin les types de rail nécessaires pour former le chemin 1
            case 1 : chemin[0] =5;
                     chemin[1] =2;
                     chemin[2] =4;
                     chemin[3] =1;
                     chemin[4] =1;
                     // on remplit le reste de la liste de types de rail aléatoire
                     for (int i = 5 ; i<8 ; i++){
                         chemin[i] =(rand()%6 + 1); // 6 types de rail possibles
                     }
                     break ;
             //chemin 2
             case 2 : chemin[0] = 5;
                      chemin[1] = 5;
                      chemin[2] = 4;
                      chemin[3] = 4;
                      chemin[4] = 1;
                      for (int i = 5 ; i<8 ; i++){
                          chemin[i] = rand()%6 + 1;
                      }
                      break ;
             // chemin 3
             case 3 : chemin[0] = 5;
                      chemin[1] = 5;
                      chemin[2] = 4;
                      chemin[3] = 4;
                      chemin[4] = 3;
                      chemin[5] = 6;
                      chemin[6] = 2;
                      chemin[7] = rand()%6 + 1;
                      break ;
             // chemin 4
             case 4 :
                      chemin[0] = 1;
                      chemin[1] = 1;
                      chemin[2]=  1;
                      chemin[3] = 5;
                      chemin[4] = 3;
                      chemin[5] = 6;
                      chemin[6] = 4;
                      chemin[7] = rand()%6 + 1;
                      break ;
        }

    }
    // m_nbCase = 2
    // il n'y a qu'une seule combinaison de cases possible pour qu'il y ait un chemin valide dans la grille 2x2
    else {
        chemin[0] = 5;
        chemin[1] = 1;
        chemin[2] = 4;
    }
    //on mélange la liste pour que les types de cases soient disposés de manière aléatoire
    random_shuffle(&chemin[0],&chemin[m_nbCase*m_nbCase-2]);

    // on parcourt la matrice
    for (int i=0; i<m_nbCase ;i++){
        for (int j=0; j<m_nbCase;j++){

            // on inverse i et j pour que la position des cases correspondent à celle du pointeur dans déplacer case
            // Matrice :
            // 100100 200100 300100
            // 100200 200200 300200
            // 100300 200300 3003000

            QPoint p(j*100+m_positiong.x(),i*100+m_positiong.y());

            // cas case vide
            if (i == i_caseV && j== j_caseV)
                m_matriceCase[i][j] = new caseVide(p);
            // cas case rail
            else {
                // on affecte à la case rail le type de la case correspondant à celui dans la liste chemin
                c = new caseRail(p,chemin[i*m_nbCase + j-1]);
                this->m_matriceCase[i][j] = c;
            }
        }
    }
}

///
/// \fn grille::deplacerCase(QPoint position)
/// \brief permet de deplacer une case
/// \param position : position cliquée par l'utilisateur
/// la case vide va être échanger avec la case qui contient la position cliquée
///
void grille::deplacerCase(QPoint position)
{

    int x = position.x();
    int y = position.y();
    int t ;
    int icourant = 0;
    int jcourant = 0;

    // x_pos et y_pos sont les coordonnées de la case sur laquelle le curseur se trouve
    int x_pos = x - (x%m_positiong.x()) ;

    int y_pos = y - (y%m_positiong.y()) ;

    // on modifie la position du curseur pour qu'il coïncide avec les cases
    position.setX(x_pos);
    position.setY(y_pos);


    for (int i = 0; i <m_nbCase; i++)
    {
        for (int j = 0; j < m_nbCase; j++)
        {

            // si la case correspond à la case de la position du curseur et que ce n'est pas une case vide
            if (m_matriceCase[i][j]->getPosition() == position && m_matriceCase[i][j]->getTypeCase() != 0)
            {
                // on sauvegarde i_caseVide et j_caseVide
                icourant = getICaseVide();
                jcourant = getJCaseVide();

                // on sauvegarde le type de la case qu'on veut déplacer
                t =  m_matriceCase[i][j]->getTypeCase() ;

                // position de la case rail
                QPoint p1(m_matriceCase[i][j]->getPosition().x(),m_matriceCase[i][j]->getPosition().y());
                // position de la case vide
                QPoint p2(m_matriceCase[i_caseV][j_caseV]->getPosition().x(),m_matriceCase[i_caseV][j_caseV]->getPosition().y());

                // on modifie les attributs i_caseVide et j_caseVide
                setICaseVide(i);
                setJCaseVide(j);

                // on "réinitialise" les cases avec leur nouveau type
                m_matriceCase[i_caseV][j_caseV] = new caseVide(p1);
                m_matriceCase[icourant][jcourant] = new caseRail(p2, t);

            }
        }
    }

}



//
///
/// \fn grille::directionDeplacement(const Case& c1,const Case& c2)
/// \brief permet de connaitre dans quel direction le train doit se déplacer en sortie de la case courante
/// precondition : les cases c1 et c2 sont voisines et sont différentes
/// \param c1 : case sur laquelle se trouve le train
/// \param c2 : case sur laquelle il doit se rendre
/// \return un char 'h' (haut), 'b' (bas), 'd' (droite) ou 'g' (gauche)
///
char grille::directionDeplacement(const Case& c1,const Case& c2){

    // Etant donné que largeur_case et hauteur_case ont des valeurs identiques, on multiple la différence entre les ordonnées par 10
    // pour avoir une valeur différentes dans les cas h/b (sinon probleme dans le switch : case largeur_case et case hauteur_case identique)
    // on fonction de la valeur de emplacement on pourra connaitre la position de c2 par rapport à c1
    int emplacement = (c1.getPosition().x() - c2.getPosition().x()) + 10*(c1.getPosition().y()-c2.getPosition().y());
    char dir = 'd';
    const int largeur_case = 100 ;
    const int hauteur_case = 100;


    switch(emplacement){

        case -hauteur_case*10 : dir = 'b';
                                break ;
        case hauteur_case*10 : dir = 'h';
                               break ;
        case -largeur_case : dir = 'd';
                             break ;
        case largeur_case : dir = 'g';
                            break ;
    }

    return dir ;
}


///
/// \brief grille::listeVoisines(const Case& c)
/// \param c : la case dont on veut la liste des voisines
/// \return la liste des cases voisines de la case prise en paramètre
///
QList<Case*> grille::listeVoisines(const Case& c){


    int j = (c.getPosition().x() - m_positiong.x())/100 ; // on divise par la largeur/hauteur des cases
    int i = (c.getPosition().y() - m_positiong.y())/100;

    QList <Case*> listeCasesVoisines ;

    // premiere ligne
    if (i == 0){
        // coin haut gauche
        if (j == 0){
            listeCasesVoisines.append(m_matriceCase[i+1][j]);
            listeCasesVoisines.append(m_matriceCase[i][j+1]);
        }
        //coin haut droit
        else if (j == (m_nbCase-1)){
            listeCasesVoisines.append(m_matriceCase[i+1][j]);
            listeCasesVoisines.append(m_matriceCase[i][j-1]);
        }
        // case du milieu premiere ligne
        else {
            listeCasesVoisines.append(m_matriceCase[i+1][j]);
            listeCasesVoisines.append(m_matriceCase[i][j-1]);
            listeCasesVoisines.append(m_matriceCase[i][j+1]);
        }
    }
    // derniere ligne
    else if ( i == (m_nbCase - 1)){
        // coin bas droit
        if (j == 0){

            listeCasesVoisines.append(m_matriceCase[i-1][j]);
            listeCasesVoisines.append(m_matriceCase[i][j+1]);
        }
        // coin bas gauche
        else if (j == (m_nbCase-1)){
            listeCasesVoisines.append(m_matriceCase[i-1][j]);
            listeCasesVoisines.append(m_matriceCase[i][j-1]);
        }
        // case du milieu derniere ligne
        else {
            listeCasesVoisines.append(m_matriceCase[i-1][j]);
            listeCasesVoisines.append(m_matriceCase[i][j+1]);
            listeCasesVoisines.append(m_matriceCase[i][j-1]);
        }
    }
    // premiere colonne case du milieu
    else if (j == 0 ){
        listeCasesVoisines.append(m_matriceCase[i][j+1]);
        listeCasesVoisines.append(m_matriceCase[i+1][j]);
        listeCasesVoisines.append(m_matriceCase[i-1][j]);
    }
    // derniere colonne case du milieu
    else if (j == (m_nbCase -1)){
        listeCasesVoisines.append(m_matriceCase[i][j-1]);
        listeCasesVoisines.append(m_matriceCase[i+1][j]);
        listeCasesVoisines.append(m_matriceCase[i-1][j]);
    }
    // case du milieu
    else {
        listeCasesVoisines.append(m_matriceCase[i][j-1]);
        listeCasesVoisines.append(m_matriceCase[i+1][j]);
        listeCasesVoisines.append(m_matriceCase[i-1][j]);
        listeCasesVoisines.append(m_matriceCase[i][j+1]);
    }
    return listeCasesVoisines ;


}

///
/// \fn grille::CasesConnectees(Case& c1, Case& c2)
/// \brief permet de savoir si deux case sont connectées, c'est à dire si le train peut passer de l'une à l'autre
/// precondition : c1 et c2 sont des cases voisines et différentes
/// \param c1 : case sur laquelle se trouve le train
/// \param c2 : case sur laquelle le train doit aller
/// \return true si les cases sont connectées, false sinon
///
bool grille::CasesConnectees(Case& c1, Case& c2)
{
    bool connecte = false;
    int t2 = c2.getTypeCase();
    // direction de la case c2 par rapport à la case c1
    char dir = directionDeplacement(c1,c2);
    switch(c1.getTypeCase())
    {
        case 1: if ((t2 == 3 || t2 == 5 || t2 == 1) && dir == 'd') { // si on va vers la droite
                        connecte = true;
                }
                if ((t2 == 4 || t2 == 6 || t2 == 1) && dir == 'g') { // si on va vers la gauche
                        connecte = true;
                }
                break;
        case 2: if ((t2 == 2 || t2 == 5 || t2 == 6) && dir == 'h'){ // si on va vers le haut
                        connecte = true;
                }
                if ((t2 == 2 || t2 == 3 || t2 == 4) && dir == 'b') { // si on va vers le bas
                        connecte = true;
                }
                break;
        case 3: if ((t2 == 2 || t2 == 6 || t2 == 5) && dir == 'h') { // si on va vers le haut
                        connecte = true;
                }
                if ((t2 == 1 || t2 == 4 || t2 == 6) && dir == 'g') { // si on va vers la gauche
                        connecte = true;
                }
                break;
        case 4: if ((t2 == 2 || t2 == 6 || t2 == 5) && dir == 'h') { // si on va vers le haut
                        connecte = true;
                }
                if ((t2 == 3 || t2 == 5 || t2 == 1) && dir == 'd') { // si on va vers la droite
                        connecte = true;
                }
                break;
        case 5: if ((t2 == 2 || t2 == 3 || t2 == 4) && dir == 'b') { // si on va vers le bas
                        connecte = true;
                }
                if ((t2 == 1 || t2 == 3 || t2 == 6) && dir == 'g') { // si on va vers la gauche
                        connecte = true;
                }
                break;
        case 6: if ((t2 == 4 || t2 == 5 || t2 == 1) && dir == 'd') { // si on va vers la droite
                        connecte = true;
                }
                if ((t2 == 2 || t2 == 3 || t2 == 4) && dir == 'b') { // si on va vers le bas
                        connecte = true;
                }
                break;
    }

    return connecte;
}



///
/// \fn grille::calculerChemin()
/// \brief crée une liste des cases formant un chemin
/// \return une liste de cases formant le chemin que le train peut suivre
///
QList<Case*> grille::calculerChemin(){

    // on initialise la case courante à l'entrée de la grille
    Case * case_courante = m_matriceCase[m_entree.x()][m_entree.y()] ;

    bool continuer = true , flag = false, cond_fin = false ;

    QList <Case*> case_visitees, listeCasesVoisines ;


    // verification premiere case
    // si la case d'entrée est valide (c'est à dire qu'elle relie l'extérieur de la grille à l'intérieur), on l'ajoute à la liste de cases visitées
    if (case_courante->getTypeCase() != 2 && case_courante->getTypeCase() != 4 && case_courante->getTypeCase() != 6){
        case_visitees.append(case_courante);

    }
    // si la premiere case n'est pas valide on ne rentre pas dans la boucle
    else {
        continuer = false ;
    }

    while (continuer){

        // liste des cases voisines de la case courante
        listeCasesVoisines = listeVoisines(*case_courante);

        // on parcourt la liste de cases voisines
        for (int i = 0 ; i<listeCasesVoisines.length();i++){

            // on regarde si la case courante et ses voisines sont connectées, si on n'a pas déjà visité ses voisines, et si une de ses cases voisines était déjà connectée avec elle
            if ((CasesConnectees(*case_courante,*listeCasesVoisines[i])) && !(case_visitees.contains(listeCasesVoisines[i])) && !flag){
                // on ajoute la voisine à la liste des cases visitées si elle est connectée à la case courante
                case_visitees.append(listeCasesVoisines[i]);
                // la case courante devient la case voisine
                case_courante = listeCasesVoisines[i] ;
                flag = true ;

            }
        }
        // condition de fin : la case courante correspond à la case de sortie, et son type de rail ammène vers l'extérieur de la grille
        cond_fin = (case_courante == m_matriceCase[m_sortie.x()][m_sortie.y()]) && (case_courante->getTypeCase() != 2 && case_courante->getTypeCase() != 3 && case_courante->getTypeCase() != 5);

        // si aucune des cases voisines n'étaient connectées à la case courante et que nous ne somme pas sur la case de sortie, le chemin n'est pas valide
        if (!flag && !cond_fin){
            continuer = false ;

        }
        // sinon chemin valide on remet le flag à false pour pouvoir reboucler
        else {
            flag = false ;
        }

        // si on est sur la case de sortie, on ajoute la dernière case à la liste de cases visitées et on arrête de boucler
        if (cond_fin){
            chemin_valide = true ;
            continuer = false ;

        }

    }
    return case_visitees ;

}

///
/// \fn grille::setICaseVide(int i)
/// \brief Mutateur de l'abscisse de la case vide dans la matrice case
/// \param i : nouvelle abscisse de la case vide dans la matrice
///
void grille::setICaseVide(int i){
    i_caseV = i ;
}

///
/// \fn grille::setJCaseVide(int j)
/// \brief Mutateur de l'ordonnée de la case vide dans la matrice case
/// \param j : nouvelle ordonnée de la case vide dans la matrice
///
void grille::setJCaseVide(int j){
    j_caseV = j ;
}

///
/// \fn grille::getICaseVide()
/// \brief Accesseur de l'abscisse de la case vide dans la matrice case
/// \return la valeur de l'abscisse de la case vide dans la matrice case
///
int grille::getICaseVide(){
    return i_caseV ;
}

///
/// \fn grille::getJCaseVide()
/// \brief Accesseur de l'ordonnée de la case vide dans la matrice case
/// \return la valeur de l'ordonnée de la case vide dans la matrice case
///
int grille::getJCaseVide(){
    return j_caseV ;
}

///
/// \fn grille::getCheminValide()
/// \brief Accesseur de chemin_valide
/// \return true si le chemin est valide (il mène à la sortie de la grille), false sinon
///
bool grille::getCheminValide(){
    return chemin_valide ;
}

///
/// \fn grille::getPositionG()
/// \brief Accesseur de la position de la grille
/// \return la position de la grille dans la fenêtre de jeu
///
QPoint grille::getPositionG()
{
    return m_positiong;
}

///
/// \fn grille::setPositionG(QPoint pos)
/// \brief Mutateur de la position de la grille
/// \param pos : nouvelle position de la grille
///
void grille::setPositionG(QPoint pos)
{
    m_positiong = pos;
}
