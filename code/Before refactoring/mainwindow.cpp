#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QVector"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    double arr[] = {2, 3, 4, 5, 6};
    ui->doubleSpinBox->setValue(0);
    ui->doubleSpinBox_2->setValue(10);
    tree = new Tree(arr, 5, ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value());
    QWidget *w = new QWidget(this);
    w->setLayout(ui->verticalLayout);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    setCentralWidget(w);
    show_plot();
}

MainWindow::~MainWindow()
{
    delete tree;
    delete ui;
}

void MainWindow::on_pushButton_9_clicked()
{
    if(ui->lineEdit_5->text() != "")
    {
        double x = ui->lineEdit_5->text().toDouble();
        tree->insert_node(x, ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value());
        ui->lineEdit_5->setText("");
        show_plot();
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    if(ui->lineEdit_5->text() != "")
    {
        double x = ui->lineEdit_5->text().toDouble();
        tree->delete_node(x);
        ui->lineEdit_5->setText("");
        show_plot();
    }
}

void MainWindow::show_plot()
{
    ui->widget->clearGraphs();
    QVector<double> x_coord, y_coord;
    QVector<double> x_left, y_left;
    QVector<double> x_right, y_right;
    vector <vector <pair <double, double> > > v = tree->get_points();
    for(int i = 0; i < v.size(); i++)
    {
        x_coord.append(v[i][0].first);
        y_coord.append(v[i][0].second);
        x_left.append(v[i][1].first);
        y_left.append(v[i][1].second);
        x_right.append(v[i][2].first);
        y_right.append(v[i][2].second);
        //qDebug() <<"("<<x_coord<<";"<<y_coord<<")=>"<<x_left<<y_left<<x_right<<y_right;
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setData(x_coord, y_coord);
    for(int i = 0; i < x_left.size(); i++)
    {
        if(y_left[i] != -1)
            ui->widget->addGraph()->setData(QVector<double>({x_left[i], x_coord[i]}), QVector<double>({y_left[i], y_coord[i]}));
        if(y_right[i] != -1)
            ui->widget->addGraph()->setData(QVector<double>({x_right[i], x_coord[i]}), QVector<double>({y_right[i], y_coord[i]}));
    }
    ui->widget->yAxis->setRange(ui->doubleSpinBox->value() - 1, ui->doubleSpinBox_2->value() + 1);
    ui->widget->xAxis->setRange(tree->min_node() - 1, tree->max_node() + 1);
    ui->widget->replot();
    ui->widget->update();
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->doubleSpinBox->setMaximum(ui->doubleSpinBox_2->value());
}


void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    ui->doubleSpinBox_2->setMinimum(ui->doubleSpinBox->value() + 1.0);
}


void MainWindow::on_pushButton_clicked()
{
    vector <vector <pair <double, double> > > v = tree->get_points();
    for(int i = 0; i < v.size(); i++)
    {
        tree->delete_node(v[i][0].first);
    }
    show_plot();
}

