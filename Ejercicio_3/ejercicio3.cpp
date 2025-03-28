#include "ejercicio3.h"


Entero* Entero::suma(Numero* otro) {
    Entero* otroEntero = dynamic_cast<Entero*>(otro);
    if (otroEntero) {
        return new Entero(this->valor + otroEntero->valor);
    }
    return nullptr;
}

Real* Real::suma(Numero* otro) {
    Real* otroReal = dynamic_cast<Real*>(otro);
    if (otroReal) {
        return new Real(this->valor + otroReal->valor);
    }
    return nullptr;
}

Complejo* Complejo::suma(Numero* otro) {
    Complejo* otroComplejo = dynamic_cast<Complejo*>(otro);
    if (otroComplejo) {
        return new Complejo(this->real + otroComplejo->real, 
                            this->imaginario + otroComplejo->imaginario);
    }
    return nullptr;
}

int main() {


    return 0;
}

