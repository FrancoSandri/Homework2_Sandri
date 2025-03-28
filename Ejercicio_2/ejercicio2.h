#ifndef EJERCICIO2_H
#define EJERCICIO2_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;


class Estudiante{
    private:
        string nombre;
        int legajo;
        vector <pair<string, float>> cursos;

    public:
        Estudiante(string nombre, int legajo);
        void agregarCurso(string nombre_curso, float nota_final);
        float calcularPromedioGeneral();
        string getNombre() const;
        int getLegajo() const;
};

class Curso{
    private:
        vector <Estudiante*> estudiantes;
        static const int MAX_ALUMNOS = 20;

    public: 
        Curso();
        Curso(const Curso& rht);
        ~Curso();
        void inscribirAlumno(Estudiante* estudiante);
        void desinscribirAlumno(int legajo);
        bool estaInscripto(int legajo);
        bool estaCompleto();
        void mostrarEstudiantesOrdenados();

        friend ostream& operator<<(ostream& os, const Estudiante& estudiante);
        friend bool operator<(const Estudiante& e1, const Estudiante& e2);


        /*
        Indicando de que tipo de copia se trata y como la hizo.

        Hice un deep copy el cual me permite copiar un objeto que posee punteros de memoria alocada dinámicamente, y me da como resultado un nuevo
        objeto, con data allocada en una posición distina. No utilice un shallow copy, ya que estoy utilizando memoria alocada dinamicamente dentro
        del objeto. Este ultimo lo que genera es copiar la direción del puntero, generando problemas de borrado o dangling pointers, que es 
        cuando un puntero apunta a una dirección de memoria que ya fue liberada.

        Para llevarlo a cabo, segui los ejemplos de las diapositivas del campus, donde se muestran varios casos de deep copy.
        A su vez, cree un destructor para liberar la memoria de los Estudiantes que se encuentran dentro del vector de estudiantes, evitando
        pérdidas de memoria.

        En el constructor de copia, recorro el vector de estudiantes y creo un nuevo Estudiante con el mismo nombre y legajo que el original.
        Luego, lo agrego al vector de estudiantes. Esto es importante porque si no lo hiciera, los Estudiantes seguirían ocupando espacio en memoria.

        En el destructor, recorro el vector de estudiantes y elimino cada uno de los Estudiantes que se encuentran dentro del vector, y luego
        elimino el vector de estudiantes. Esto es importante porque si no lo hiciera, los Estudiantes seguirían ocupando espacio en memoria. 

        Lo hice de esta manera porque es la forma más segura de manejar la memoria y evitar fugas.
        
        */


        /*
        c. ¿Qué tipo de relación existe entre los objetos curso y estudiante?
        */

        /*La relación entre Curso y Estudiante es que un Curso está compuesto por varios Estudiantes.
        A su vez, un Curso no puede existis sin Estudiantes, pero los Estudiantes si pueden vivir sin Curso.
        En caso de destruir un Curso, también se destruyen los Estudiantes que contiene.
        Pero en caso de destruir un Estudiante, los Cursos siguen existiendo.
        */

};

#endif