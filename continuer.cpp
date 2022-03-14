///
/// \file continuer.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "continuer.h"
#include "ui_continuer.h"

///
/// \brief Constructeur de la fenêtre continuer
/// \param parent
///
continuer::continuer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::continuer)
{
    ui->setupUi(this);
}

///
/// \brief Destructeur de la fenêtre continuer
///
continuer::~continuer()
{
    delete ui;
}

///
/// \fn continuer::getContinuer()
/// \brief Accesseur de la valeur continuer
/// \return true si l'utilisateur veut continuer la partie
///
bool continuer::getContinuer()
{
    return conti;
}

///
/// \fn continuer::on_bouton_oui_clicked()
/// \brief change la valeur du booléen conti à true
///
void continuer::on_bouton_oui_clicked()
{
    conti = true;
}

///
/// \fn continuer::on_bouton_non_clicked()
/// \brief change la valeur du booléen conti à false
///
void continuer::on_bouton_non_clicked()
{
    conti=false;
}
