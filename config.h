///
/// \file config.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#ifndef CONFIG_H
#define CONFIG_H

#include <QDialog>

namespace Ui {
class config;
}
///
/// \class config
/// \brief La classe config représente la fenêtre permettant la configuration du niveau du jeu (grille 2x2 ou 3x3)
///
class config : public QDialog
{
    Q_OBJECT

public:
    explicit config(QWidget *parent = nullptr);
    ~config();
    int getNiveau() const;


private slots:
    void on_niv1_clicked();

    void on_niv2_clicked();

private:
    Ui::config *ui;
    int m_niveau;
};

#endif // CONFIG_H
