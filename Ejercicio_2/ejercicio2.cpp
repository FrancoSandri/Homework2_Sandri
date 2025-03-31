#include "ejercicio2.h"


bool operator<(const Estudiante& e1, const Estudiante& e2) {
    return e1.getNombre() < e2.getNombre();
}

ostream& operator<<(ostream& os, const Estudiante& e) {
    os << "Nombre completo: " << e.getNombre() << ", Legajo: " << e.getLegajo() << endl;
    return os;
}

string Estudiante::getNombre() const {
    return nombre;
}

int Estudiante::getLegajo() const {
    return legajo;
}

Estudiante::Estudiante(string nombre, int legajo) : nombre(nombre), legajo(legajo){};

void Estudiante::agregarCurso(string nombre_curso, float nota_final){
    cursos.push_back(make_pair(nombre_curso, nota_final));
};

float Estudiante::calcularPromedioGeneral() {
    float suma = 0;
    for (const auto& curso : cursos) {
        suma += curso.second;
    }
    return suma / cursos.size();
}

Curso::Curso() {}

void Curso::inscribirAlumno(Estudiante* estudiante) {
    if(estaCompleto()){
        cout << "El curso ya está completo." << endl;
        return;
    }
    if(estaInscripto(estudiante->getLegajo())){
        cout << "El legajo ya está registrado." << endl;
        return;
    }
    estudiantes.push_back(estudiante);
    cout << "El estudiante fue inscripto correctamente" << endl;
}

void Curso::desinscribirAlumno(int legajo) {
    Estudiante* estudiante = nullptr;
    for (const auto& est : estudiantes) {
        if (est->getLegajo() == legajo) {
            estudiante = est;
            break;
        }
    }
    if(!estaInscripto(estudiante->getLegajo())){
        cout << "El estudiante no está inscripto." << endl;
        return;
    }
    estudiantes.erase(remove(estudiantes.begin(), estudiantes.end(), estudiante), estudiantes.end());
    cout << "El estudiante fue desinscripto correctamente" << endl;
}

bool Curso::estaInscripto(int legajo){
    for (const auto& est : estudiantes) {
        if (est->getLegajo() == legajo) {
            return true;
        }
    }
    return false;
}

bool Curso::estaCompleto(){
    return estudiantes.size() == MAX_ALUMNOS;
}

void Curso::mostrarEstudiantesOrdenados(){
    sort(estudiantes.begin(), estudiantes.end(), [](Estudiante* e1, Estudiante* e2) {
        return *e1 < *e2;
    });
    
    for (const auto& estudiante : estudiantes) {
        cout << *estudiante;
    }
    cout << endl;
}

Curso::Curso(const Curso& rht) : estudiantes(rht.estudiantes) {
    for(const auto& estudiante : estudiantes) {
        Estudiante* nuevoEstudiante = new Estudiante(*estudiante);
        estudiantes.push_back(nuevoEstudiante);
    }
}
Curso::~Curso() {
    for (const auto& estudiante : estudiantes) {
        delete estudiante;
    }
    estudiantes.clear();
}


int main(){

    Curso curso;
    Curso copiaCurso;
    int opcion;

    do{

    cout << "\n Bienvenido al Curso, que desea hacer?\n";
    cout << "1. Inscribir estudiante\n";
    cout << "2. Mostrar estudiantes\n";
    cout << "3. Hacer copia del curso\n";
    cout << "4. Desinscribir estudiante\n";
    cout << "5. Verificar si un estudiante está inscripto\n";
    cout << "6. Verificar si el curso está completo\n";
    cout << "7. Salir\n";
    cout << "Ingrese una opción: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
        case 1: { 
            string nombre;
            int legajo;
            cout << "Ingrese el nombre completo del estudiante: " << endl;
            getline(cin, nombre);
            cout << "Ingrese el legajo: " << endl;
            cin >> legajo;
            curso.inscribirAlumno(new Estudiante(nombre, legajo));
            break;
        }

        case 2:
            cout << "Lista de estudiantes:" << endl;
            curso.mostrarEstudiantesOrdenados();
            break;

        case 3: 
            copiaCurso = curso;
            cout << "Se ha realizado una copia del curso." << endl;
            break;

        case 4: {
            int legajo;
            cout << "Ingrese el legajo del estudiante a desinscribir: " << endl;
            cin >> legajo;
            curso.desinscribirAlumno(legajo);
            break;
        }

        case 5: { 
            int legajo;
            cout << "Ingrese el legajo del estudiante: " << endl;
            cin >> legajo;
            if (curso.estaInscripto(legajo)) {
                cout << "El estudiante está inscripto." << endl;
            } else {
                cout << "El estudiante no está inscripto." << endl;
            }
            break;
        }

        case 6:
            if (curso.estaCompleto()) {
                cout << "El curso está completo." << endl;
            } else {
                cout << "El curso no está completo." << endl;
            }
            break;
        case 7: 
            cout << "Saliendo del programa." << endl;
            break;

        default:
            cout << "Opción inválida." << endl;
            break;
        }
    } while (opcion != 7);

    return 0;
}