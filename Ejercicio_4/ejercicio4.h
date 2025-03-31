#ifndef EJERCICIO4_H
#define EJERCICIO4_H

#include <iostream>

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
        int contadorDeMuestras; 
};

class cuentaCorriente: public cuentaBanco{
    public:
        cuentaCorriente(string nombreTitular, double balance);
        void retirar(double) override;
        friend class cajaDeAhorro;
        void avisoSinDinero(const cajaDeAhorro& caja); //en caso de que la cuenta no posea dinero
};

#endif