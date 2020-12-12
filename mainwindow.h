#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "cuerpo.h"
#include "cuerpograph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTimer  *timer;
    QGraphicsScene *scene;

    QList<Cuerpograph *> bars;

    float dt;
    int h_limit, v_limit;

    void edge_collition(Cuerpo *b);

    void keyPressEvent(QKeyEvent *event);

public slots:
    void update_bodies();

private slots:
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
