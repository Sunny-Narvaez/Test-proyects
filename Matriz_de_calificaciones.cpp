#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct alumno {
    char nombre[20];
    int cta;
    float calif[3];
};

void leer(alumno*, int);
void calcular(alumno*, int);
void imprimir(alumno*, int);
int calc();

int main() {
    alumno* ptr;
    int num_1 = calc();
    ptr = (alumno*) malloc(num_1 * sizeof(alumno));
    leer(ptr, num_1);
    calcular(ptr, num_1);
    imprimir(ptr, num_1);
    free(ptr);
    return 0;
}

int calc() {
    int num;
    cout << "¿Cuántos alumnos deseas ingresar? ";
    cin >> num;
    return num;
}

void leer(alumno* a, int num_1) {
    for (int i = 0; i < num_1; i++) {
        cout << "Ingresa nombre: ";
        cin.ignore();
        cin.getline(a[i].nombre, 20);
        cout << "Ingresa cuenta: ";
        cin >> a[i].cta;
        for (int j = 0; j < 3; j++) {
            cout << "Ingresa calificación " << j + 1 << ": ";
            cin >> a[i].calif[j];
        }
    }
}

void imprimir(alumno* a, int num_1) {
    for (int i = 0; i < num_1; i++) {
        cout << "Nombre: " << a[i].nombre << endl;
        cout << "Cuenta: " << a[i].cta << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Calificación " << j + 1 << ": " << a[i].calif[j] << endl;
        }
    }
}

void calcular(alumno* a, int num_1) {
    float prom;
    for (int i = 0; i < num_1; i++) {
        prom = 0;
        for (int j = 0; j < 3; j++) {
            prom += a[i].calif[j];
        }
        prom /= 3;
        cout << "Promedio del alumno " << i + 1 << ": " << prom << endl;
    }
}
