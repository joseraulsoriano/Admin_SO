//
// Created by José Raúl Soriano Cazabal on 12/01/25.
//
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {
    int h0, h1, h2, h00, h01;

    // Crear HIJO 0
    h0 = fork();
    if (h0 == 0) {  // Proceso HIJO 0
        sleep(1);  // Retraso para diferenciar salida
        cout << "HIJO 0:-> PID: " << getpid() << " PPID: " << getppid() << "\n";

        // Crear HIJO 0.0 dentro del HIJO 0
        h00 = fork();
        if (h00 == 0) {  // Proceso HIJO 0.0
            sleep(1);  // Retraso para diferenciar salida
            cout << "HIJO 0.0:-> PID: " << getpid() << " PPID: " << getppid() << "\n";
            exit(0);  // Asegurarse de que termine después de imprimir
        }

        // Crear HIJO 0.1 dentro del HIJO 0
        h01 = fork();
        if (h01 == 0) {  // Proceso HIJO 0.1
            sleep(1);  // Retraso para diferenciar salida
            cout << "HIJO 0.1:-> PID: " << getpid() << " PPID: " << getppid() << "\n";
            exit(0);  // Asegurarse de que termine después de imprimir
        }

        // Asegurarse de que los procesos HIJO 0.0 y 0.1 impriman primero
        sleep(2);
        exit(0);  // Asegurarse de que HIJO 0 termine después de sus hijos

    } else {  // Proceso PADRE
        sleep(2);  // Retraso para diferenciar salida
        h1 = fork();  // Crear HIJO 1
        if (h1 == 0) {  // Proceso HIJO 1
            sleep(1);  // Retraso para diferenciar salida
            cout << "HIJO 1:-> PID: " << getpid() << " PPID: " << getppid() << "\n";
            exit(0);  // Asegurarse de que termine después de imprimir
        } else {
            sleep(3);  // Retraso para diferenciar salida
            h2 = fork();  // Crear HIJO 2
            if (h2 == 0) {  // Proceso HIJO 2
                sleep(4);  // Retraso para diferenciar salida
                cout << "HIJO 2:-> PID: " << getpid() << " PPID: " << getppid() << "\n";
                exit(0);  // Asegurarse de que termine después de imprimir
            } else {
                sleep(5);  // Retraso final antes de imprimir salida del PADRE
                cout << "PADRE:-> PID: " << getpid() << " PPID: " << getppid() << "\n";
            }
        }
    }

    return 0;
}