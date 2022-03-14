///
/// \file main.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "mainwindow.h"
#include "iostream"

#include "caserail.h"
#include "casevide.h"
#include "grille.h"

using namespace std ;

#include <QApplication>
///
/// \brief qMain
/// \brief permet d'ouvrir la fenêtre principale/d'accueil du jeu
///
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // on ouvre la fenêtre principale
    MainWindow w;
    w.show();
    return a.exec();

}
