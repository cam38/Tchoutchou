///
/// \file mainwindow.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jouerpartie.h"
#include "config.h"
#include "aide.h"

///
/// \brief Constructeur de la MainWindow
///
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    niveau = 1; // niveau par défaut
    ui->setupUi(this);
}

///
/// \brief Destructeur de la MainWindow
///
MainWindow::~MainWindow()
{
    delete ui;
}

///
/// \fn MainWindow::on_Bouton_JT_clicked()
/// \brief permet de lancer la fenêtre jouerpartie
///
void MainWindow::on_Bouton_JT_clicked()
{
    jouerPartie f(this, niveau);
    f.exec();
}

///
/// \fn MainWindow::on_Bouton_Conf_clicked
/// \brief permet de lancer la fenêtre de configuration
///
void MainWindow::on_Bouton_Conf_clicked()
{
    config f(this);
    f.exec();
    niveau = f.getNiveau();
}

///
/// \fn MainWindow::on_Bouton_aide_clicked
/// \brief permet de lancer la fenêtre d'aide
///
void MainWindow::on_Bouton_aide_clicked()
{
    aide a(this);
    a.exec();
}
