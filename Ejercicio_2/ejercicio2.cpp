#include "ejercicio2.h"
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

Estudiante::Estudiante(string nombre, int legajo) : nombre(nombre), legajo(legajo){}

void Estudiante::agregarCurso(string nombre_curso, float nota_final){
    for (auto& curso : cursos) {
        if (curso.first == nombre_curso) {
            cout << "El curso ya está registrado." << endl;
            return;
        }
    }
    cursos.push_back(make_pair(nombre_curso, nota_final));
}

vector<pair<string, float>> Estudiante::getCursos() const {
    return cursos;
}

float Estudiante::calcularPromedioGeneral() {
    if (cursos.empty()) return 0.0;
    float suma = 0;
    int contadorDeCursos = 0;
    for (const auto& curso : cursos) { 
        // cout << curso.second << endl;
        suma += curso.second;
        contadorDeCursos++;
    }

    return (contadorDeCursos > 0) ? (suma / contadorDeCursos) : 0.0;
}

void Estudiante::eliminarCurso(string nombreCurso) {
    auto it = remove_if(cursos.begin(), cursos.end(), [&](const pair<string, float>& curso) {
        return curso.first == nombreCurso;
    });

    if (it != cursos.end()) {
        cursos.erase(it, cursos.end());
    }
}


Curso::Curso(string nombreCurso) : nombreCurso(nombreCurso) {}

string Curso::getCurso(){
    return nombreCurso;
}

void Curso::inscribirAlumno(Estudiante* estudiante, string nombreCurso, float notaFinal) {
    if (nombreCurso != this->nombreCurso) {
        cout << "El curso no existe." << endl;
        return;
    }
    if (estaCompleto(nombreCurso)) {
        cout << "El curso ya está completo." << endl;
        return;
    }
    if (estaInscripto(estudiante->getLegajo(), nombreCurso)) {
        cout << "El estudiante ya está inscrito en este curso." << endl;
        return;
    }
    estudiantes.push_back(estudiante);
    estudiante->agregarCurso(nombreCurso, notaFinal);
    cout << "El estudiante fue inscrito correctamente." << endl;
}

void Curso::desinscribirAlumno(int legajo, string nombreCurso) {
    if (nombreCurso != this->nombreCurso) {
        cout << "El curso no existe." << endl;
        return;
    }

    auto it = find_if(estudiantes.begin(), estudiantes.end(), [&](Estudiante* e) {
        return e->getLegajo() == legajo;
    });

    if (it == estudiantes.end()) {
        cout << "El estudiante no está inscrito en este curso." << endl;
        return;
    }

    Estudiante* estudiante = *it;
    estudiantes.erase(it);

    estudiante->eliminarCurso(nombreCurso);

    cout << "El estudiante fue desinscrito correctamente." << endl;
}


bool Curso::estaInscripto(int legajo, string nombreCurso) {
    if (nombreCurso != this->nombreCurso) return false;
    for (const auto& estudiante : estudiantes) {
        if (estudiante->getLegajo() == legajo) {
            return true;
        }
    }
    return false;
}

bool Curso::estaCompleto(string nombreCurso) {
    return nombreCurso == this->nombreCurso && estudiantes.size() == MAX_ALUMNOS;
}

vector<Estudiante*> Curso::getEstudiantes(){
    return estudiantes;
}

void Curso::mostrarEstudiantesOrdenados(string nombreCurso) {
    if (nombreCurso != this->nombreCurso) {
        cout << "El curso no existe." << endl;
        return;
    }
    if (estudiantes.empty()) {
        cout << "No hay estudiantes inscritos en este curso." << endl;
        return;
    }
    sort(estudiantes.begin(), estudiantes.end(), [](Estudiante* e1, Estudiante* e2) {
        return *e1 < *e2;
    });
    for (const auto& estudiante : estudiantes) {
        cout << *estudiante;
    }
    cout << endl;
}

Curso::Curso(const Curso& rht, string nombreCurso) : nombreCurso(nombreCurso) {
    if(rht.nombreCurso == nombreCurso){
        estudiantes = rht.estudiantes;
    }
}

Curso::~Curso() {
    for (const auto& estudiante : estudiantes) {
        delete estudiante;
    }
    estudiantes.clear();
}


int main() {
    vector<Curso*> cursos;
    int opcion;

    do {
        cout << "1. Crear curso\n";
        cout << "2. Inscribir estudiante\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Desinscribir estudiante\n";
        cout << "5. Verificar si un estudiante está inscripto\n";
        cout << "6. Verificar si el curso está completo\n";
        cout << "7. Consultar el promedio del alumno\n";
        cout << "8. Crear una copia del curso\n";
        cout << "9. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                string nombreCurso;
                cout << "Ingrese el nombre del curso: ";
                getline(cin, nombreCurso);
                bool existe = false;
                for (Curso* curso : cursos) {
                    if (curso->getCurso() == nombreCurso) {
                        existe = true;
                        break;
                    }
                }
                if (!existe) {
                    cursos.push_back(new Curso(nombreCurso));
                    cout << "Curso creado correctamente.\n";
                } else {
                    cout << "El curso ya existe.\n";
                }
                break;
            }
            case 2: {
                string nombre, nombreCurso;
                int legajo;
                float notaFinal;
                cout << "Ingrese el nombre completo del estudiante: ";
                getline(cin, nombre);
                cout << "Ingrese el legajo: ";
                cin >> legajo;
                cin.ignore();
                cout << "Ingrese el nombre del curso: ";
                getline(cin, nombreCurso);
                cout << "Ingrese la nota final: ";
                cin >> notaFinal;
                cin.ignore();
            
                Estudiante* estudianteEncontrado = nullptr;
            
                // Buscar si el estudiante ya existe en algún curso
                for (Curso* curso : cursos) {
                    for (Estudiante* estudiante : curso->getEstudiantes()) {
                        if (estudiante->getLegajo() == legajo) {
                            estudianteEncontrado = estudiante;
                            break;
                        }
                    }
                    if (estudianteEncontrado) break;
                }
            
                if (!estudianteEncontrado) {
                    estudianteEncontrado = new Estudiante(nombre, legajo);
                }
            
                bool cursoEncontrado = false;
                for (Curso* curso : cursos) {
                    if (curso->getCurso() == nombreCurso) {
                        curso->inscribirAlumno(estudianteEncontrado, nombreCurso, notaFinal);
                        cursoEncontrado = true;
                        break;
                    }
                }
            
                if (!cursoEncontrado) {
                    cout << "El curso no existe.\n";
                }
            
                break;
            }            
            case 3: {
                string nombreCurso;
                cout << "Ingrese el nombre del curso: ";
                getline(cin, nombreCurso);
                bool cursoEncontrado = false;
                for (Curso* curso : cursos) {
                    if (curso->getCurso() == nombreCurso) {
                        curso->mostrarEstudiantesOrdenados(nombreCurso);
                        cursoEncontrado = true;
                        break;
                    }
                }
                if (!cursoEncontrado) {
                    cout << "El curso no existe.\n";
                }
                break;
            }
            case 4: {
                int legajo;
                string nombreCurso;
                cout << "Ingrese el legajo del estudiante: ";
                cin >> legajo;
                cin.ignore();
                cout << "Ingrese el nombre del curso: ";
                getline(cin, nombreCurso);
                bool cursoEncontrado = false;
                for (Curso* curso : cursos) {
                    if (curso->getCurso() == nombreCurso) {
                        curso->desinscribirAlumno(legajo, nombreCurso);
                        cursoEncontrado = true;
                        break;
                    }
                }
                if (!cursoEncontrado) {
                    cout << "El curso no existe.\n";
                }
                break;
            }
            case 5: {
                int legajo;
                string nombreCurso;
                cout << "Ingrese el legajo del estudiante: ";
                cin >> legajo;
                cin.ignore();
                cout << "Ingrese el nombre del curso: ";
                getline(cin, nombreCurso);
                bool cursoEncontrado = false;
                for (Curso* curso : cursos) {
                    if (curso->getCurso() == nombreCurso) {
                        if (curso->estaInscripto(legajo, nombreCurso)) {
                            cout << "El estudiante está inscripto.\n";
                        } else {
                            cout << "El estudiante no está inscripto.\n";
                        }
                        cursoEncontrado = true;
                        break;
                    }
                }
                if (!cursoEncontrado) {
                    cout << "El curso no existe.\n";
                }
                break;
            }
            case 6: {
                string nombreCurso;
                cout << "Ingrese el nombre del curso: ";
                getline(cin, nombreCurso);
                bool cursoEncontrado = false;
                for (Curso* curso : cursos) {
                    if (curso->getCurso() == nombreCurso) {
                        if (curso->estaCompleto(nombreCurso)) {
                            cout << "El curso está completo.\n";
                        } else {
                            cout << "El curso no está completo.\n";
                        }
                        cursoEncontrado = true;
                        break;
                    }
                }
                if (!cursoEncontrado) {
                    cout << "El curso no existe.\n";
                }
                break;
            }
            case 7: {
                int legajo;
                cout << "Ingrese el legajo del estudiante: ";
                cin >> legajo;
                cin.ignore();
            
                Estudiante* estudianteEncontrado = nullptr;
                
            
                for (Curso* curso : cursos) {
                    for (Estudiante* estudiante : curso->getEstudiantes()) {
                        if (estudiante->getLegajo() == legajo) {
                            estudianteEncontrado = estudiante;
                            break;
                        }
                    }
                    if (estudianteEncontrado) break;
                }
            
                if (estudianteEncontrado) {
                    float promedio = estudianteEncontrado->calcularPromedioGeneral();
                    cout << "El promedio es: " << promedio << "\n";
                } else {
                    cout << "No se encontró un estudiante con el legajo ingresado.\n";
                }
                break;
            }
            case 8: {
                    string nombreCurso;
                    cout << "Ingrese el nombre del curso a copiar: ";
                    getline(cin, nombreCurso);
                
                    bool cursoEncontrado = false;
                    for (Curso* curso : cursos) {
                        if (curso->getCurso() == nombreCurso) {
                            Curso* nuevoCurso = new Curso(*curso, nombreCurso);
                            cursos.push_back(nuevoCurso);
                            cursoEncontrado = true;
                            break;
                        }
                    }
                    if (!cursoEncontrado) {
                        cout << "El curso no existe.\n";
                    }
                    break;
                }
            case 9:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida.\n";
                break;
        }
    } while (opcion != 9);
    
    for (Curso* curso : cursos) {
        delete curso;
    }
    cursos.clear();

    return 0;
}