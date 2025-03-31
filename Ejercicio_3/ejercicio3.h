#ifndef EJERCICIO3_H
#define EJERCICIO3_H

#include <iostream>
#include <string>

using namespace std;

class Numero {
public:
    virtual ~Numero() {}
    virtual Numero* suma(Numero* otro) = 0;
    virtual Numero* resta(Numero* otro) = 0;
    virtual Numero* multiplicacion(Numero* otro) = 0;
    virtual string toString() const = 0;
};

class Entero : public Numero {
private:
    int valor;
public:
    Entero(int valor) : valor(valor) {};
    Entero* suma(Numero* otro) override;
    Entero* resta(Numero* otro) override;
    Entero* multiplicacion(Numero* otro) override;
    string toString() const override;
};

class Real : public Numero {
private:
    float valor;
public:
    Real(float valor) : valor(valor) {};
    Real* suma(Numero* otro) override;
    Real* resta(Numero* otro) override;
    Real* multiplicacion(Numero* otro) override;
    string toString() const override;
};

class Complejo : public Numero {
private:
    float real;
    float imaginario;
public:
    Complejo(float real, float imaginario) : real(real), imaginario(imaginario) {};
    Complejo* suma(Numero* otro) override;
    Complejo* resta(Numero* otro) override;
    Complejo* multiplicacion(Numero* otro) override;
    string toString() const override;
};

#endif