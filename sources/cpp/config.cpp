///
/// \file config.cpp
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#include "config.h"
#include "ui_config.h"
///
/// \brief Constructeur de la fenêtre config
/// \param parent
///
config::config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::config)
{
    ui->setupUi(this);
    m_niveau=1; //on part du principe que la partie est niveau 1

}

///
/// \brief Destructeur de la fenêtre config
///
config::~config()
{
    delete ui;
}

///
/// \brief config::on_niv1_clicked()
/// \brief permet de changer le niveau de la partie à 1
///
void config::on_niv1_clicked()
{
    m_niveau = 1;

    ui->niv2->setCheckState( Qt::Unchecked );
}

///
/// \brief config::on_niv1_clicked()
/// \brief permet de changer le niveau de la partie à 2
///
void config::on_niv2_clicked()
{
    m_niveau = 2;
    ui->niv1->setCheckState( Qt::Unchecked );
}

///
/// \fn config::getNiveau()
/// \brief accesseur du niveau de la partie
/// \return le niveau de la partie
///
int config::getNiveau() const
{
    return m_niveau;
}




