#include "cuerpograph.h"

Cuerpograph::Cuerpograph(QObject *parent) : QObject(parent),  scale(1) {

    float posx = 50+(rand()%951),
            posy = 50+(rand()%351),
            velx = (rand()%301),
            vely = (rand()%301),
            mass_ = 50+(rand()%651),
            radio_ = 5+(rand()%26),
            k_ = (rand()%10)/1000,
            e_ = (0.5+(rand()%5)/10);

//    posx = 32;
//    posy = 150;
//    mass_ = 50;
//    velx = 0;
//    vely = 0;
//    k_ = 0.08;
//    e_ = 0.2;
//    radio_ = 20;

    esf = new Cuerpo(nullptr, posx, posy, velx, vely, mass_, radio_, k_, e_);
}
Cuerpograph::~Cuerpograph() {
    delete esf;
}

QRectF Cuerpograph::boundingRect() const {
    return QRectF(-1*scale*esf->getRadio(), -1*scale*esf->getRadio(), 2*scale*esf->getRadio(), 2*scale*esf->getRadio());
}
void Cuerpograph::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void Cuerpograph::setScale(float s) {
    scale = s;
}

void Cuerpograph::update_draw(float v_limit) {
    esf->update();
    setPos(esf->getPx(), v_limit - esf->getPy());
}

Cuerpo *Cuerpograph::getEsf() {
    return esf;
}
