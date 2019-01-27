#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushbutton_go_left_clicked()
{
    QMessageBox::information(this, "Information", "Button \"left\" clicked" );
}

void MainWindow::on_pushbutton_go_right_clicked()
{
    QMessageBox::information(this, "Information", "Button \"right\" clicked" );
}

void MainWindow::on_pushbutton_go_down_clicked()
{
    QMessageBox::information(this, "Information", "Button \"down\" clicked" );
}

void MainWindow::on_pushbutton_go_up_clicked()
{
    QMessageBox::information(this, "Information", "Button \"up\" clicked" );
}

void MainWindow::on_pushbutton_start_mission_clicked()
{
    QMessageBox::information(this, "Information", "Button \"Start\" clicked" );
}

void MainWindow::on_pushbutton_abort_mission_clicked()
{
    QMessageBox::information(this, "Information", "Button \"cancel\" clicked" );
}

void MainWindow::on_pushbutton_single_step_clicked()
{
    QMessageBox::information(this, "Information", "Button \"single step\" clicked" );
}

void MainWindow::on_pushbutton_automatic_clicked()
{
    QMessageBox::information(this, "Information", "Button \"automatic\" clicked" );
}

void MainWindow::on_pushbutton_pause_mission_clicked()
{
    QMessageBox::information(this, "Information", "Button \"pause\" clicked" );
}

void MainWindow::on_pushbutton_stay_clicked()
{
    QMessageBox::information(this, "Information", "Button \"wait\" clicked" );
}

void MainWindow::on_pushbutton_delete_clicked()
{
    QMessageBox::information(this, "Information", "Button \"delete\" clicked" );
}

void MainWindow::on_pushbutton_change_colony_clicked()
{
    QMessageBox::information(this, "Information", "Button \"switch colony\" clicked" );
}
