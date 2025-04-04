#include "ejercicio1.h"

/*En el punto i, en vez de pedir nuevamente que pase los parametros fuera de rango, salgo del programa.*/

void Tiempo::mostrarTiempo(){
    /*
        Muestro la hora con la funcion setfill.
    */
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
    if(horas > 12){
        cout << "Error: La hora esta fuera de rango." << endl;
        return;
    }
    this->horas = horas;
    minutos = 0;
    segundos = 0;
    uso_horario = "a.m.";
};
//Inicializada pasandole solo horas y minutos
Tiempo::Tiempo(int horas, int minutos) {
    if(horas > 12 || minutos >= 60){
        cout << "Error: Alguno de los parametros esta fuera de rango" << endl;
        return;
    }
    this->horas = horas;
    this->minutos = minutos;
    segundos = 0;
    uso_horario = "a.m.";
};
//Inicializada pasandole horas, minutos y segundos pero sin el a.m o p.m.
Tiempo::Tiempo(int horas, int minutos, int segundos) {
    if(horas > 12 || minutos >= 60 || segundos >= 60){
        cout << "Error: alguno de los parametros esta fuera de rango" << endl;
        return;
    }
    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;
    uso_horario = "a.m.";
};
//Inicializada pasandole todos los parametros 
Tiempo::Tiempo(int horas, int minutos, int segundos, string uso_horario) {
    if(horas > 12 || minutos >= 60 || segundos >= 60 || (uso_horario != "a.m." && uso_horario != "p.m.")){
        cout << "Error: alguno de los parametros esta fuera de rango" << endl;
        return;
    }
    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;
    this->uso_horario = uso_horario;
};

//funcion que muestra la hora
void Tiempo::getHora(){
    cout << "La hora es: " << horas << endl;
}
//funcion que muestra los minutos
void Tiempo::getMinuto(){
    cout << "Los minutos son: " << minutos<< endl;
}
//funcion que muestra los segundos
void Tiempo::getSegundo(){
    cout << "Los segundos son: " << segundos << endl;
}
//funcion que muestra el uso horario
void Tiempo::getUsoHorario(){
    cout << "El uso horario es: " << uso_horario << endl;
}
//funcion que modifica solo la hora
void Tiempo::setHora(int horas){
    if(horas > 12){
        cout << "La hora no puede ser mayor a 24" << endl;
        return;
    };
    this->horas = horas;
};
//funcion que modifica solo los minutos
void Tiempo::setMinuto(int minutos){
    if(minutos >= 60){
        cout << "Los minutos no pueden ser mayores a 60" << endl;
        return;
    };
    this->minutos = minutos;
};
//funcion que modifica solo los segundos
void Tiempo::setSegundo(int segundos){
    if(segundos >= 60){
        cout << "Los segundos no pueden ser mayores a 60" << endl;
        return;
    };
    this->segundos = segundos;
};
//funcion que modifica solo el uso horario
void Tiempo::setUsoHorario(string uso_horario){
    if(uso_horario != "a.m." && uso_horario != "p.m."){
        cout << "El uso horario solo puede ser a.m. o p.m." << endl;
        return;
    };
    this->uso_horario = uso_horario;
};

//funcion que muestra la hora en formato 24 horas
void Tiempo::mostrarHoraFormato24(){
    if(uso_horario == "p.m." && horas != 12){
        horas += 12;
    }
    if(uso_horario == "a.m." && horas == 12){
        horas = 0;
    }
    if(horas > 23){
        cout << "Error: La hora esta fuera de rango." << endl;
        return;
    }
    cout << setfill('0') << setw(2) << horas << "h, "
            << setfill('0') << setw(2) << minutos << "m, "
            << setfill('0') << setw(2) << segundos << "s" << endl;
};

int main(){

int horas, minutos, segundos;
string uso_horario;

Tiempo tiempo_usuario;

cout << "¿Cómo quiere ingresar su hora? \n1. Hora \n2. Hora y minutos \n3. Hora, minutos y segundos \n4. Hora, minutos, segundos y uso horario" << endl;

int opcion;
cin >> opcion;

switch(opcion){
    case 1:
        cout << "Ingrese la hora: ";
        cin >> horas;
        tiempo_usuario = Tiempo(horas);
        break;
    case 2:
        cout << "Ingrese la hora: ";
        cin >> horas;
        cout << "Ingrese los minutos: ";
        cin >> minutos;
        tiempo_usuario = Tiempo(horas, minutos);
        break;
    case 3:
        cout << "Ingrese la hora: ";
        cin >> horas;
        cout << "Ingrese los minutos: ";
        cin >> minutos;
        cout << "Ingrese los segundos: ";
        cin >> segundos;
        tiempo_usuario = Tiempo(horas, minutos, segundos);
        break;
    case 4:
        cout << "Ingrese la hora: ";
        cin >> horas;
        cout << "Ingrese los minutos: ";
        cin >> minutos;
        cout << "Ingrese los segundos: ";
        cin >> segundos;
        cout << "Ingrese el uso horario (a.m./p.m.): ";
        cin >> uso_horario;
        tiempo_usuario = Tiempo(horas, minutos, segundos, uso_horario);
        break;
    default:
        cout << "Opción no válida" << endl;
        return 0;
}

//Segundo menu
cout << "¿Que desea hacer ahora? \n1. Mostrar hora \n2. Mostrar hora en formato 24 \n3. Leer hora individual \n4. Leer minuto individual \n5. Leer segundo individual \n6. Leer uso horario individual \n7. Cambiar hora \n8. Cambiar minutos \n9. Cambiar segundos \n10. Cambiar uso horario" << endl;
int respuesta;
cin >> respuesta;
switch(respuesta){
    case 1:
        cout << "La hora es: " << endl;
        tiempo_usuario.mostrarTiempo();
        break;
    case 2:
        cout << "La hora en formato 24 es: " << endl;
        tiempo_usuario.mostrarHoraFormato24();
        break;
    case 3:
        tiempo_usuario.getHora();
        break;
    case 4:
        tiempo_usuario.getMinuto();
        break;
    case 5:
        tiempo_usuario.getSegundo();
        break;
    case 6:
        tiempo_usuario.getUsoHorario();
        break;
    case 7:
        cout << "Ingrese la nueva hora: ";
        cin >> horas;
        tiempo_usuario.setHora(horas);
        break;
    case 8:
        cout << "Ingrese los nuevos minutos: ";
        cin >> minutos;
        tiempo_usuario.setMinuto(minutos);
        break;
    case 9:
        cout << "Ingrese los nuevos segundos: ";
        cin >> segundos;
        tiempo_usuario.setSegundo(segundos);
        break;
    case 10:
        cout << "Ingrese el nuevo uso horario (a.m./p.m.): ";
        cin >> uso_horario;
        tiempo_usuario.setUsoHorario(uso_horario);
        break;
    default:
        cout << "Opción no válida" << endl;
        return 0;
    }
    return 0;
}