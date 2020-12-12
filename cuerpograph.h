#ifndef CUERPOGRAPH_H
#define CUERPOGRAPH_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <time.h>
#include <stdlib.h>
#include "cuerpo.h"


class Cuerpograph : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    explicit Cuerpograph(QObject *parent = nullptr);
    ~Cuerpograph();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void setScale(float s);

    void update_draw(float v_limit);

    Cuerpo* getEsf();

private:
    Cuerpo *esf;
    float scale;

signals:

};

#endif // CUERPOGRAPH_H
