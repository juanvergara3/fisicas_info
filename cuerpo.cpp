#include "cuerpo.h"

Cuerpo::Cuerpo(QObject *parent, float x, float y, float vx, float vy, float mass_, float radio_, float K_, float e_) : QObject(parent) {
    Px = x;
    Py = y;
    Vx = vx;
    Vy = vy;
    Ax = 0;
    Ay = 0;
    mass = mass_;
    radio = radio_;
    g = 5;
    K = K_;
    e = e_;
    V = 0;
    dt = 0.1;
}
Cuerpo::~Cuerpo() {

}

void Cuerpo::update() {
     V = sqrt( pow(Vx ,2) + pow(Vy ,2) );

     angle = atan2(Vy, Vx); //arc_tan

     Ax = -1*((K*pow(V, 2) * pow(radio, 2))/mass) * cos(angle);
     Ay = (-1*((K*pow(V, 2) * pow(radio, 2))/mass) * sin(angle)) - g;

     Px = Px + Vx*dt + Ax*pow(dt, 2)/2;
     Py = Py + Vy*dt + Ay*pow(dt, 2)/2;

     Vx = Vx + Ax*dt;
     Vy = Vy + Ay*dt;
}
void Cuerpo::set_vel(float px, float py, float vx, float vy) {

    Px = px;
    Py = py;
    Vx = vx;
    Vy = vy;
}

float Cuerpo::getPx() const {
    return Px;
}
float Cuerpo::getPy() const {
    return Py;
}

float Cuerpo::getVx() const {
    return Vx;
}
float Cuerpo::getVy() const {
    return Vy;
}

float Cuerpo::getMass() const {
    return mass;
}
float Cuerpo::getRadio() const {
    return radio;
}
float Cuerpo::getE() const {
    return e;
}
