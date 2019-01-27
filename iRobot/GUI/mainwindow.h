#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushbutton_go_left_clicked();

    void on_pushbutton_go_right_clicked();

    void on_pushbutton_go_down_clicked();

    void on_pushbutton_go_up_clicked();

    void on_pushbutton_start_mission_clicked();

    void on_pushbutton_abort_mission_clicked();

    void on_pushbutton_single_step_clicked();

    void on_pushbutton_automatic_clicked();

    void on_pushbutton_pause_mission_clicked();

    void on_pushbutton_stay_clicked();

    void on_pushbutton_delete_clicked();

    void on_pushbutton_change_colony_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
