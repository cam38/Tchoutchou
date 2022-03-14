///
/// \file dialog.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "dialog.h"
#include "ui_dialog.h"
#include <QMovie>
#include <QTimer>

///
/// \brief Constructeur de la fenêtre Dialog
/// \brief permet de lancer le gif de victoire
/// \param parent
///
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // gif
    QMovie* gif = new QMovie(":/image/gagne.gif");
    ui->label->setMovie(gif);
    QTimer tim;
    ui->label->show();
    gif->start();

}

///
/// \brief Destructeur de la fenêtre Dialog
///
Dialog::~Dialog()
{
    delete ui;
}

