/*
1. Programe una clase que permita expresar un determinado momento en el tiempo en
el siguiente formato: HHh, MMm, SSs p.m./a.m. Por ejemplo: “03h, 14m, 42s p.m.”.
Para este ejercicio, puede utilizar la librería iomanip con la funcionalidad provista por
setw y/o setfill.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*En el punto i, en vez de pedir nuevamente que pase los parametros fuera de rango, salgo del programa.*/

class Tiempo {
    private:
        int horas;
        int minutos;
        int segundos;
        string uso_horario;
    public:
    void mostrarTiempo(){
        cout << setfill('0') << setw(2) << horas << "h, "
             << setfill('0') << setw(2) << minutos << "m, "
             << setfill('0') << setw(2) << segundos << "s "
             << uso_horario << endl;
    };
    //Inicializada sin pasarle parametros
    Tiempo() {
        horas = 0;
        minutos = 0;
        segundos = 0;
        uso_horario = "a.m.";
    };
    //Inicializada pasandole solo horas
    Tiempo(int horas) {
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
    Tiempo(int horas, int minutos) {
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
    Tiempo(int horas, int minutos, int segundos) {
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
    Tiempo(int horas, int minutos, int segundos, string uso_horario) {
        if(horas > 24 || minutos > 60 || segundos > 60 || (uso_horario != "a.m." && uso_horario != "p.m.")){
            cout << "La hora no puede ser mayor a 24 o los minutos o los segundos mayores a 60" << endl;
            return;
        }
        this->horas = horas;
        this->minutos = minutos;
        this->segundos = segundos;
        this->uso_horario = uso_horario;
    };

    void setHora(int horas){
        if(horas > 24){
            cout << "La hora no puede ser mayor a 24" << endl;
            return;
        };
        this->horas = horas;
    };
    void setMinuto(int minutos){
        if(minutos > 60){
            cout << "Los minutos no pueden ser mayores a 60" << endl;
            return;
        };
        this->minutos = minutos;
    };
    void setSegundo(int segundos){
        if(segundos > 60){
            cout << "Los segundos no pueden ser mayores a 60" << endl;
            return;
        };
        this->segundos = segundos;
    };
    void setUsoHorario(string uso_horario){
        if(uso_horario != "a.m." && uso_horario != "p.m."){
            cout << "El uso horario solo puede ser a.m. o p.m." << endl;
            return;
        };
        this->uso_horario = uso_horario;
    };
    int getHora(){
        return horas;
    };
    int getMinuto(){
        return minutos;
    };
    int getSegundo(){
        return segundos;
    };
    string getUsoHorario(){
        return uso_horario;
    };

    void mostrarHoraFormato24(){
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

    //Pruebo los leer horario indivualmente

    tiempo_e.getHora();
    tiempo_e.getMinuto();
    tiempo_e.getSegundo();
    tiempo_e.getUsoHorario();

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
    tiempo_usuario.mostrarTiempo();
    tiempo_usuario.mostrarHoraFormato24();
    
    //Que el usuario cambie valores del horario
    cout << "Desea cambiar algunos valores? (s/n): ";
    char respuesta;
    cin >> respuesta;
    if(respuesta == 's'){


        cout << "Ingrese la hora: ";
        cin >> horas;
        tiempo_usuario.setHora(horas);

        cout << "Ingrese los minutos: ";
        cin >> minutos;
        tiempo_usuario.setMinuto(minutos);

        cout << "Ingrese los segundos: ";
        cin >> segundos;
        tiempo_usuario.setSegundo(segundos);

        cout << "Ingrese el uso horario (a.m./p.m.): ";
        cin >> uso_horario;
        tiempo_usuario.setUsoHorario(uso_horario);

        cout << "Los valores fueron cambiados. El tiempo es: " << endl;
        tiempo_usuario.mostrarTiempo();

        }else{
        cout << "No se cambiaron los valores. El tiempo es: " << endl;
        tiempo_usuario.mostrarTiempo();
    }
    
    return 0;

}