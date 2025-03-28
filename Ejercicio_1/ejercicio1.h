#ifndef EJERCICIO1_H
#define EJERCICIO1_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Tiempo {
    private:
        int horas;
        int minutos;
        int segundos;
        std::string uso_horario;
    public:
        Tiempo();
        Tiempo(int horas);
        Tiempo(int horas, int minutos);
        Tiempo(int horas, int minutos, int segundos);
        Tiempo(int horas, int minutos, int segundos, std::string uso_horario);

        void setHora(int horas);
        void setMinuto(int minutos);
        void setSegundo(int segundos);
        void setUsoHorario(std::string uso_horario);

        void getHoraIndividual(std::string tipo_hora);
        void setHoraIndividual(std::string tipo_hora, int valor);

        void mostrarTiempo();
        void mostrarHoraFormato24();
};

#endif