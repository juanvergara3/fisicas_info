#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow) {

    srand(time(NULL));
    ui->setupUi(this);

    h_limit = 1000;
    v_limit = 500;

    scene =  new QGraphicsScene(this);
    scene->setSceneRect(0, 0 ,h_limit, v_limit);

    timer  =  new QTimer(this);

    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width(), scene->height());
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

    connect(timer, SIGNAL(timeout()), this, SLOT(update_bodies()));
}
MainWindow::~MainWindow() {
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::edge_collition(Cuerpo *b) {
    if(b->getPx() < b->getRadio()) {
        b->set_vel(b->getRadio(), b->getPy(), -1*b->getE()*b->getVx(), b->getVy());
    }
    if(b->getPx() > h_limit - b->getRadio()) {
        b->set_vel(h_limit - b->getRadio(), b->getPy(), -1*b->getE()*b->getVx(), b->getVy());
    }
    if(b->getPy() < b->getRadio()) {
        b->set_vel(b->getPx(), b->getRadio(), b->getVx(), -1*b->getE()*b->getVy());
    }
    if(b->getPy() > v_limit - b->getRadio()) {
        b->set_vel(b->getPx(), v_limit - b->getRadio(), b->getVx(), -1*b->getE()*b->getVy());
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    Cuerpo *b = bars.at(0)->getEsf();

    if(event->key() == Qt::Key_D){
        b->set_vel(b->getPx(), b->getPy(),10, b->getVy());
    }
    if(event->key() == Qt::Key_A){
        b->set_vel(b->getPx(), b->getPy(), -10, b->getVy());
    }
    if(event->key() == Qt::Key_W || event->key() == Qt::Key_Space){
        b->set_vel(b->getPx(), b->getPy(), b->getVx(), 50);
    }
    if(event->key() == Qt::Key_S){
        b->set_vel(b->getPx(), b->getPy(), b->getVx(), -50);
    }

}

void MainWindow::update_bodies() {
    for(int i = 0; i<bars.size(); i++) {

        bars.at(i)->update_draw(v_limit);
        edge_collition(bars.at(i)->getEsf());
    }
}

void MainWindow::on_pushButton_clicked() {

    timer->start(3);
    bars.push_back(new Cuerpograph);
    bars.back()->update_draw(v_limit);
    scene->addItem(bars.back());
}
