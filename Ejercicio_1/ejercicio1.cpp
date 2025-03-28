#include "ejercicio1.h"

/*En el punto i, en vez de pedir nuevamente que pase los parametros fuera de rango, salgo del programa.*/

void Tiempo::mostrarTiempo(){
    cout << setfill('0') << setw(2) << horas << "h, "
            << setfill('0') << setw(2) << minutos << "m, "
            << setfill('0') << setw(2) << segundos << "s "
            << uso_horario << endl;
};
//Inicializada sin pasarle parametros
Tiempo::Tiempo() {
    horas = 0;
    minutos = 0;
    segundos = 0;
    uso_horario = "a.m.";
};
//Inicializada pasandole solo horas
Tiempo::Tiempo(int horas) {
    if(horas > 24){
        cout << "La hora no puede ser mayor a 24" << endl;
        return;
    }
    this->horas = horas;
    minutos = 0;
    segundos = 0;
    uso_horario = "a.m.";
};
//Inicializada pasandole solo horas y minutos
Tiempo::Tiempo(int horas, int minutos) {
    if(horas > 24 || minutos > 60){
        cout << "La hora no puede ser mayor a 24 o los minutos mayores a 60" << endl;
        return;
    }
    this->horas = horas;
    this->minutos = minutos;
    segundos = 0;
    uso_horario = "a.m.";
};
//Inicializada pasandole horas, minutos y segundos pero sin el a.m o p.m.
Tiempo::Tiempo(int horas, int minutos, int segundos) {
    if(horas > 24 || minutos > 60 || segundos > 60){
        cout << "La hora no puede ser mayor a 24 o los minutos o los segundos mayores a 60" << endl;
        return;
    }
    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;
    uso_horario = "a.m.";
};
//Inicializada pasandole todos los parametros 
Tiempo::Tiempo(int horas, int minutos, int segundos, string uso_horario) {
    if(horas > 24 || minutos > 60 || segundos > 60 || (uso_horario != "a.m." && uso_horario != "p.m.")){
        cout << "La hora no puede ser mayor a 24 o los minutos o los segundos mayores a 60" << endl;
        return;
    }
    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;
    this->uso_horario = uso_horario;
};

void Tiempo::getHoraIndividual(string tipo_hora){  
    if (tipo_hora == "Hora") {
        cout << "La hora es: " << horas << endl;
    } else if (tipo_hora == "Minuto") {
        cout << "Los minutos son: " << minutos << endl;
    } else if (tipo_hora == "Segundo") {
        cout << "Los segundos son: " << segundos << endl;
    } else if (tipo_hora == "UsoHorario") {
        cout << "El uso horario es: " << uso_horario << endl;
    } else {
        cout << "No existe ese tipo de hora" << endl;
    }
}

void Tiempo::setHoraIndividual(string tipo_hora, int valor){
    if (tipo_hora == "Hora") {
        setHora(valor);
    } else if (tipo_hora == "Minuto") {
        setMinuto(valor);
    } else if (tipo_hora == "Segundo") {
        setSegundo(valor);
    } else if (tipo_hora == "UsoHorario") {
        setUsoHorario(valor == 0 ? "a.m." : "p.m.");
    } else {
        cout << "No existe ese tipo de hora" << endl;
    }
}

void Tiempo::setHora(int horas){
    if(horas > 24){
        cout << "La hora no puede ser mayor a 24" << endl;
        return;
    };
    this->horas = horas;
};
void Tiempo::setMinuto(int minutos){
    if(minutos > 60){
        cout << "Los minutos no pueden ser mayores a 60" << endl;
        return;
    };
    this->minutos = minutos;
};
void Tiempo::setSegundo(int segundos){
    if(segundos > 60){
        cout << "Los segundos no pueden ser mayores a 60" << endl;
        return;
    };
    this->segundos = segundos;
};
void Tiempo::setUsoHorario(string uso_horario){
    if(uso_horario != "a.m." && uso_horario != "p.m."){
        cout << "El uso horario solo puede ser a.m. o p.m." << endl;
        return;
    };
    this->uso_horario = uso_horario;
};

void Tiempo::mostrarHoraFormato24(){
    if(uso_horario == "p.m." && horas != 12){
        horas += 12;
    }
    if(uso_horario == "a.m." && horas == 12){
        horas = 0;
    }
    cout << setfill('0') << setw(2) << horas << "h, "
            << setfill('0') << setw(2) << minutos << "m, "
            << setfill('0') << setw(2) << segundos << "s" << endl;
};

int main(){

Tiempo tiempo_a;
tiempo_a.mostrarTiempo();

Tiempo tiempo_b(9);
tiempo_b.mostrarTiempo();

Tiempo tiempo_c(12, 38);
tiempo_c.mostrarTiempo();

Tiempo tiempo_d(10, 29, 16);
tiempo_d.mostrarTiempo();

Tiempo tiempo_e(5, 3, 9, "p.m.");
tiempo_e.mostrarTiempo();

//Pruebo uno fuera de rango

Tiempo tiempo_fuera_de_rango(25,34,56); //Debería imprimir un error

//Probar el cambiar el horario individualmente en el tiempo_a el cual esta vacio.

tiempo_a.setHora(7);
tiempo_a.setMinuto(25);
tiempo_a.setSegundo(48);
tiempo_a.setUsoHorario("p.m.");
tiempo_a.mostrarTiempo();

tiempo_e.mostrarHoraFormato24(); //Deberia imprimir 17h, etc, etc.

int horas, minutos, segundos;
string uso_horario;

cout << "Ingrese la hora: ";
cin >> horas;
cout << "Ingrese los minutos: ";
cin >> minutos;
cout << "Ingrese los segundos: ";
cin >> segundos;
cout << "Ingrese el uso horario (a.m./p.m.): ";
cin >> uso_horario;

if(horas > 24 || minutos > 60 || segundos > 60 || (uso_horario != "a.m." && uso_horario != "p.m.")){
    cout << "La hora no puede ser mayor a 24 o los minutos o los segundos mayores a 60" << endl;
    return 0;
}

Tiempo tiempo_usuario(horas, minutos, segundos, uso_horario);
cout << "El tiempo ingresado es: ";
tiempo_usuario.mostrarTiempo();
cout << "La hora en formato 24 es: ";
tiempo_usuario.mostrarHoraFormato24();

//Que el usuario cambie valores del horario
cout << "Desea cambiar algunos valores? (s/n): ";
char respuesta;
cin >> respuesta;
if(respuesta == 's'){
    cout << "Que valor desea cambiar? (Hora/Minuto/Secundo/UsoHorario): ";
    string tipo_hora;
    cin >> tipo_hora;
    cout << "Ingrese el nuevo valor: ";
    int nuevo_valor;
    cin >> nuevo_valor;
    tiempo_usuario.setHoraIndividual(tipo_hora, nuevo_valor);
    cout << "El tiempo fue cambiado y es: ";
    tiempo_usuario.mostrarTiempo();
}else{
    cout << "No se cambiaron los valores. El tiempo es: " << endl;
    tiempo_usuario.mostrarTiempo();
}

return 0;

}