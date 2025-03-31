#include "ejercicio3.h"


Entero* Entero::suma(Numero* n) {
    Entero* nEntero = dynamic_cast<Entero*>(n);
    if (nEntero) {
        return new Entero(this->valor + nEntero->valor);
    }
    return nullptr;
}

Entero* Entero::resta(Numero* n){
    Entero* nEntero = dynamic_cast<Entero*>(n); //*>(n);
    if(nEntero){
        return new Entero(this->valor - nEntero->valor);
    }
    return nullptr;
};

Entero* Entero::multiplicacion(Numero*n){
    Entero*nEntero = dynamic_cast<Entero*>(n);
    if(nEntero){
        return new Entero(this->valor * nEntero->valor);
    }
    return nullptr;
}

string Entero::toString() const {
    return to_string(valor);
}

Real* Real::suma(Numero* n) {
    Real* nReal = dynamic_cast<Real*>(n);
    if (nReal) {
        return new Real(this->valor + nReal->valor);
    }
    return nullptr;
}

Real* Real::resta(Numero* n){
    Real* nReal = dynamic_cast<Real*>(n);
    if(nReal){
        return new Real(this->valor - nReal->valor);
    }
    return nullptr;
};

Real* Real::multiplicacion(Numero*n){
    Real*nReal = dynamic_cast<Real*>(n);
    if(nReal){
        return new Real(this->valor * nReal->valor);
    }
    return nullptr;
}

string Real::toString() const {
    return to_string(valor);
}

Complejo* Complejo::suma(Numero* n) {
    Complejo* nComplejo = dynamic_cast<Complejo*>(n);
    if (nComplejo) {
        return new Complejo(this->real + nComplejo->real, 
                            this->imaginario + nComplejo->imaginario);
    }
    return nullptr;
}

Complejo* Complejo::resta(Numero* n){
    Complejo* nComplejo = dynamic_cast<Complejo*>(n);
    if(nComplejo){
        return new Complejo(this->real - nComplejo->real, 
                            this->imaginario - nComplejo->imaginario);
    }
    return nullptr;
};

Complejo* Complejo::multiplicacion(Numero*n){
    Complejo*nComplejo = dynamic_cast<Complejo*>(n);
    if(nComplejo){
        return new Complejo(this->real * nComplejo->real - this->imaginario * nComplejo->imaginario, 
                            this->real * nComplejo->imaginario + this->imaginario * nComplejo->real);
    }
    return nullptr;
}

string Complejo::toString() const {
    return to_string(real) + " + " + to_string(imaginario) + "i";
}

int main() {

    // Verificacion de Entero

    Entero* entero1 = new Entero(10);
    Entero* entero2 = new Entero(7);

    Entero* sumaEntero = entero1->suma(entero2);
    Entero* restaEntero = entero1->resta(entero2);
    Entero* multiplicacionEntero = entero1->multiplicacion(entero2);

    cout << "Suma Entero: " << sumaEntero->toString() << endl;
    cout << "Resta Entero: " << restaEntero->toString() << endl;
    cout << "Multiplicacion Entero: " << multiplicacionEntero->toString() << endl;

    cout << "Entero 1: " << entero1->toString() << endl;
    cout << "Entero 2: " << entero2->toString() << "\n" << endl;

    //Verificacion de Real

    Real* real1 = new Real(14);
    Real* real2 = new Real(8);

    Real* sumaReal = real1->suma(real2);
    Real* restaReal = real1->resta(real2);
    Real* multiplicacionReal = real1->multiplicacion(real2);

    cout << "Suma Real: " << sumaReal->toString() << endl;
    cout << "Resta Real: " << restaReal->toString() << endl;
    cout << "Multiplicacion Real: " << multiplicacionReal->toString() << endl;

    cout << "Real 1: " << real1->toString() << endl;
    cout << "Real 2: " << real2->toString() << "\n" << endl;

    //Verificacion de Complejos

    Complejo* complejo1 = new Complejo(6, 0);
    Complejo* complejo2 = new Complejo(4, 7);

    Complejo* sumaComplejo = complejo1->suma(complejo2);
    Complejo* restaComplejo = complejo1->resta(complejo2);
    Complejo* multiplicacionComplejo = complejo1->multiplicacion(complejo2);

    cout << "Suma Complejo: " << sumaComplejo->toString() << endl;
    cout << "Resta Complejo: " << restaComplejo->toString() << endl;
    cout << "Multiplicacion Complejo: " << multiplicacionComplejo->toString() << endl;

    cout << "Complejo 1: " << complejo1->toString() << endl;
    cout << "Complejo 2: " << complejo2->toString() << endl;

    return 0;
}

