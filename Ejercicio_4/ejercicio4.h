#ifndef EJERCICIO4_H
#define EJERCICIO4_H

#include <iostream>
#include <string>

using namespace std;

class cuentaBanco{
    public:
        cuentaBanco(string nombreTitular, string tipoCuenta, double balance);
        void depositar(double dinero);
        virtual void retirar(double dinero);
        virtual void mostrarInfo(); //balance, tipo de cuenta y nombre de titular
        friend ostream& operator<<(ostream& os, const cuentaBanco& cuenta);
    protected:
        double balance;
        string nombreTitular;
        string tipoCuenta; // lo pide en mostrarInfo()
};

class cajaDeAhorro: public cuentaBanco{
    public:
        cajaDeAhorro(string nombreTitular, double balance);
        void retirar(double dinero) override;
        void realizarDescuento(); //descuento de 20$ del balance luego de mostrar mas de 2 veces la informacion de la cuenta
        void mostrarInfo() override;
        friend class cuentaCorriente;
    private:
        int contadorDeMuestras = 0; 
};

class cuentaCorriente: public cuentaBanco{
    public:
        cuentaCorriente(string nombreTitular, double balance);
        void retirar(double) override;
        friend class cajaDeAhorro;
        void avisoSinDinero(cajaDeAhorro* caja); //en caso de que la cuenta no posea dinero
        void mostrarInfo() override; //no encontré mejor solucion :)
        void mostrarInfo(cajaDeAhorro* caja);
};

#endif

/*
a) Establecer los especificadores de acceso (public, private y private) en los atributos y métodos de todas las clases, 
explicando su elección en función de la seguridad y la flexibilidad para futuros requerimientos de cambio.

Los atributos de las clases son privados, ya que no quiero que se puedan modificar desde afuera de la clase y que solo 
se puedan acceder desde los métodos publicos de la misma. 
Esto en función de seguridad, sirve para que no puedan modificar el balance de la cuenta, o el nombre de titular, o el tipo de cuenta que 
son datos sensibles. Mientras que los métodos publicos son los que permiten interactuar con la clase, pudiendo acceder a esos atributos privados
para realizar las operaciones necesarias. 

*/