#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "tree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void show_plot();
    ~MainWindow();

private slots:
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Tree* tree;
};
#endif // MAINWINDOW_H
