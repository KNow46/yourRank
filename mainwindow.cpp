#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int globalWeight = 50;
int globalHeight = 130;
int bmi = 400000 / (130*130);

QString getRankByBmi(int bmi)
{
    if(bmi < 15)
        return "chudy szczur";
    if(bmi < 20)
        return "szczur bojowy";
    if(bmi < 25)
        return "pora na mase";
    if(bmi < 30)
        return "kawał chłopa";
    if(bmi < 35)
        return "spore bydle";
    else
        return "odstaw maka grubasie";
}

void MainWindow::on_weightSlider_sliderMoved(int position)
{
    ui->weightText->setText(QString::number(50 + position));
    globalWeight= 50 + position;
    bmi = globalWeight * 10000 / (globalHeight * globalHeight);
    ui->rank->setText(getRankByBmi(bmi));
}


void MainWindow::on_heightSlider_sliderMoved(int position)
{
    ui->heightText->setText(QString::number(130 + position));
    globalHeight = position + 130;
    bmi = globalWeight * 10000 / (globalHeight * globalHeight);
    ui->rank->setText(getRankByBmi(bmi));
}

