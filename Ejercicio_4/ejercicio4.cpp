#include "ejercicio4.h"

//sobrecarga del operador << para poder mostrar la cuenta por pantalla con el formato pedido
ostream& operator<<(ostream& os, const cuentaBanco& cuenta) {
    os << "Nombre del titular: " << cuenta.nombreTitular << ", Tipo de cuenta: " << cuenta.tipoCuenta << ", Balance: " << cuenta.balance <<endl;
    return os;
};

//funcion que inicializa la cuenta de banco
cuentaBanco::cuentaBanco(string nombreTitular, string tipoCuenta, double balance){
    this->nombreTitular = nombreTitular;
    this->tipoCuenta = tipoCuenta;
    this->balance = balance;
};

//funcion que suma el dinero al balance de la cuenta
void cuentaBanco::depositar(double dinero){
    balance += dinero;
};

//funcion que resta el dinero al balance de la cuenta, si el dinero a retirar es mayor al balance, no se puede retirar
void cuentaBanco::retirar(double dinero){
    if(dinero > balance){
        cout << "Fondos insuficientes. " << endl;
    }
    balance-= dinero;
};

//funcion que muestra la informacion de la cuenta, llama al operador << para mostrar los datos
void cuentaBanco::mostrarInfo(){
    cout << *this;
};

//funcion que inicializa la caja de ahorro, llama al constructor de la clase cuentaBanco
cajaDeAhorro::cajaDeAhorro(string nombreTitular, double balance) : cuentaBanco(nombreTitular, "Caja de Ahorro", balance){};

//funcion que resta el dinero al balance de la caja de ahorro
void cajaDeAhorro::retirar(double dinero){
    if(dinero > balance){
        cout << "Fondos insuficientes en la cuenta de ahorro." << endl;
    }
    balance -= dinero;
}

//funcion que realiza un descuento de $20 si el balance es mayor a 20 y el contador de llamados a la funcion es mayor a 2
void cajaDeAhorro::realizarDescuento(){
    if(contadorDeMuestras > 2 && balance >= 20){
        this->balance -= 20;
        cout << "Por hacer más de dos llamados a la informacion, se le descontó $20." << endl;
    }
}

//funcion que muestra la informacion de la cuenta, y suma 1 al contador de veces que llama a la funcion
void cajaDeAhorro::mostrarInfo(){
    this->contadorDeMuestras+=1;
    realizarDescuento();
    cout << *this;
}

//funcion que inicializa la cuenta corriente
cuentaCorriente::cuentaCorriente(string nombreTitular, double balance): cuentaBanco(nombreTitular, "Cuenta Corriente", balance){};

//funcion que resta el dinero al balance de la cuenta corriente, si el balance es menor a 0, muestra un mensaje de cuenta descubierta
void cuentaCorriente::retirar(double dinero){
    balance -= dinero;
    if(balance < 0){
        cout << "Su cuenta corriente esta en descubierto. " << endl;
    }
};

//funcion que muestra un mensaje si el balance de la cuenta corriente y el balance de la caja de ahorro son menores a 0
void cuentaCorriente::avisoSinDinero(cajaDeAhorro* caja){

    if(balance <= 0 && caja->balance <= 0){
        cout << "No tenes saldo en la Cuenta Corriente ni en la caja de Ahorro." << endl;
    }

}

//funcion que muestra la informacion de la cuenta corriente
void cuentaCorriente::mostrarInfo(){
    cout << *this;
}

//funcion sobrecargada que muestra la informacion de la cuenta corriente y llama a la funcion de avisosSinDinero
void cuentaCorriente::mostrarInfo(cajaDeAhorro* caja){
    cout << *this;
    avisoSinDinero(caja);
}

int main(){
    string titularCuenta;
    double balanceCaja;
    double balanceCuenta;

    cout << "Ingrese su nombre: " << endl;
    getline(cin, titularCuenta);

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
        cout << "6. Salir" << endl;
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
                cuentaCorriente.mostrarInfo(&cuentaDeAhorro);
                break;

            case 6:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción invalida." << endl;
        }

    } while (opcion != 6);

    return 0;
}

