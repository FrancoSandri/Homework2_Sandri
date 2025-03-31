#include "ejercicio4.h"

ostream& operator<<(ostream& os, const cuentaBanco& cuenta) {
    os << "Nombre del titular: " << cuenta.nombreTitular << ", Tipo de cuenta: " << cuenta.tipoCuenta << ", Balance: " << cuenta.balance <<endl;
    return os;
};

cuentaBanco::cuentaBanco(string nombreTitular, string tipoCuenta, double balance){};

void cuentaBanco::depositar(double dinero){
    balance += dinero;
};

void cuentaBanco::retirar(double dinero){
    if(dinero > balance){
        cout << "Fondos insuficientes. " << endl;
    }
    balance-= dinero;
};

void cuentaBanco::mostrarInfo(){
    cout << *this;
};

cajaDeAhorro::cajaDeAhorro(string nombreTitular, double balance) : cuentaBanco(nombreTitular, "Caja de Ahorro", balance){};

void cajaDeAhorro::retirar(double dinero){
    if(dinero > balance){
        cout << "Fondos insuficientes en la cuenta de ahorro." << endl;
    }
    balance -= dinero;
}

void cajaDeAhorro::realizarDescuento(){
    if(contadorDeMuestras >= 2){
        balance -= 20;
        cout << "Por hacer más de dos llamados a la informacion, se le descontó $20." << endl;
    }
}

void cajaDeAhorro::mostrarInfo(){
    contadorDeMuestras+=1;
    cout << *this;
    realizarDescuento();
}

cuentaCorriente::cuentaCorriente(string nombreTitular, double balance): cuentaBanco(nombreTitular, "Cuenta Corriente", balance){};

void cuentaCorriente::retirar(double dinero){
    balance -= dinero;
    if(balance < 0){
        cout << "Su cuenta corriente esta en descubierto. " << endl;
    }
};

void cuentaCorriente::avisoSinDinero(const cajaDeAhorro& caja){

    if(balance <= 0 && caja.balance <= 0){
        cout << "No tenes saldo en la Cuenta Corriente ni en la caja de Ahorro." << endl;
    }

}

int main(){
    string titularCuenta;
    double balanceCaja;
    double balanceCuenta;

    cout << "Ingrese su nombre: " << endl;
    cin >> titularCuenta;

    cout << "Ingrese el balance de la caja de ahorro: " << endl;
    cin >> balanceCaja;

    cout << "Ingrese el balance de la cuenta corriente: " << endl;
    cin >> balanceCuenta;

    cajaDeAhorro cuentaDeAhorro(titularCuenta,balanceCaja);
    cuentaCorriente cuentaCorriente(titularCuenta, balanceCuenta);


    int opcion;
    double dinero;

    do {
        cout << "¿Que desea hacer con sus cuenta?" << endl;
        cout << "1. Depositar dinero en Caja de Ahorro" << endl;
        cout << "2. Retirar dinero de Caja de Ahorro" << endl;
        cout << "3. Retirar dinero de Cuenta Corriente" << endl;
        cout << "4. Mostrar información de Caja de Ahorro" << endl;
        cout << "5. Mostrar información de Cuenta Corriente" << endl;
        // cout << "6. Verificar si ambas cuentas están sin dinero" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Ingrese la cantidad a depositar en la caja de ahorro: ";
                cin >> dinero;
                cuentaDeAhorro.depositar(dinero);
                cout << "Dinero depositado correctamente." << endl;
                break;
            
            case 2: 
                cout << "Ingrese la cantidad a retirar de la caja de ahorro: ";
                cin >> dinero;
                cuentaDeAhorro.retirar(dinero);
                break;
            
            case 3:
                cout << "Ingrese la cantidad a retirar de la cuenta corriente: ";
                cin >> dinero;
                cuentaCorriente.retirar(dinero);
                break;

            case 4:
                cuentaDeAhorro.mostrarInfo();
                break;

            case 5:
                cuentaCorriente.mostrarInfo();
                break;

            // case 6:
            //     cuentaCorriente.avisoSinDinero(cuentaDeAhorro);
            //     break;

            case 7:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción invalida." << endl;
        }

    } while (opcion != 7);

    return 0;
}

