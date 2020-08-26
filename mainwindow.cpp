#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer;
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, [this](){time_is_up();});

    pop_0s_notif = new QProcess;
    pop_0s_notif->setProgram("notify-send");
    pop_0s_notif->setArguments(QStringList("Joker: -\"Rest your eyes, little shit\""));

    sound_notif = new QSound("./joker_music.wav");
    gif_joker = new QMovie("./joker_alpha.gif");
    ui->label_2->setMovie(gif_joker);
    gif_joker->start();
    gif_joker->stop();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_released()
{
    timer->start(3600000);
    ui->label->setText("Set for hour");
    sound_notif->stop();
    gif_joker->stop();
    this->hide();
}

void MainWindow::on_pushButton_2_released()
{
    timer->start(600000);
    ui->label->setText("Set for 10 min");
    sound_notif->stop();
    gif_joker->stop();
    this->hide();
}

void MainWindow::time_is_up()
{
    pop_0s_notif->start();
    sound_notif->play();
    ui->label->setText("Time is up");
    gif_joker->start();
    this->show();
}
