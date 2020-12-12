#ifndef CUERPO_H
#define CUERPO_H

#include <QObject>
#include <math.h>
#include <cmath>

class Cuerpo : public QObject {
    Q_OBJECT
private:
    float Px, Py;
    float Vx, Vy;
    float Ax, Ay;
    float mass;
    float radio;
    float angle;
    float g; //gravedad
    float K; //resistencia del aire
    float e; //coeficiente de restitucion
    float V; //vector de velocidad
    float dt; //delta de tiempo

public:
    explicit Cuerpo(QObject *parent = nullptr, float x = 0, float y = 0, float vx = 0, float vy = 0, float mass_ = 0, float radio_ = 0, float K_ = 0, float e_ = 0);
    ~Cuerpo();

    void update();
    void set_vel(float px, float py, float vx, float vy);

    float getPx() const;
    float getPy() const;

    float getVx() const;
    float getVy() const;

    float getMass() const;
    float getRadio() const;
    float getE() const;

signals:

};

#endif // CUERPO_H
