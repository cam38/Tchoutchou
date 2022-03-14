///
/// \file mainwindow.h
/// \author Euvrard Camille, Donnat Justine
/// \version 1.0
/// \date 28/03/2021
///

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


///
/// \class MainWindow
/// \brief La classe MainWindow représente la fenêtre d'accueil du jeu, où trois possibilités s'offrent au joueur : consulter l'aide, jouer, configurer le niveau du jeu
///
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Bouton_JT_clicked();

    void on_Bouton_Conf_clicked();

    void on_Bouton_aide_clicked();

private:
    Ui::MainWindow *ui;
    int niveau;
};
#endif // MAINWINDOW_H
