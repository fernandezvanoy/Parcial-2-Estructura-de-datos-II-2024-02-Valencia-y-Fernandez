#include <iostream>
#include <vector>
#include "Parcial.h"
#include <chrono>


class EvaluarParcial
{
public:
    void ejecutar()
    {
        Parcial parcial;

        int numPuntos = 14;

        double **puntos = new double *[15]; // Crear un array de 15 punteros a double

        puntos[0] = new double[2]{6.23457, -75.58132}; // Asignar valores a cada punto
        puntos[1] = new double[2]{6.24931, -75.57014};
        puntos[2] = new double[2]{6.26708, -75.56435};
        puntos[3] = new double[2]{6.17123, -75.58291};
        puntos[4] = new double[2]{6.20528, -75.56719};
        puntos[5] = new double[2]{6.24611, -75.56889};
        puntos[6] = new double[2]{6.28512, -75.55987};
        puntos[7] = new double[2]{6.29876, -75.58743};
        puntos[8] = new double[2]{6.24032, -75.57561};
        puntos[9] = new double[2]{6.27394, -75.55203};
        puntos[10] = new double[2]{6.25817, -75.56128};
        puntos[11] = new double[2]{6.23019, -75.57845};         
        puntos[12] = new double[2]{6.21854, -75.59320};
        puntos[13] = new double[2]{6.16256, -75.60183};
        puntos[14] = new double[2]{6.14589, -75.61027};

        // TODO: Agregar coordenadas estrella

        /*
         * Laureles
         * Estadio
         * Belén
         * Envigado
         * El Poblado
         * Centro
         * Castilla
         * Robledo
         * Buenos Aires
         * Manrique
         * Aranjuez
         * Floresta
         * Guayabal
         * Itagüí
         * Sabaneta
         * TODO: AGREGAR ESTRELLA
         */

        parcial.cargar();

        auto inicio = chrono::high_resolution_clock::now();
        parcial.run(puntos, numPuntos);
        auto fin = chrono::high_resolution_clock::now();
        auto duracion = chrono::duration_cast<chrono::microseconds>(fin - inicio);
        cout << "\nTiempo de ejecución del método run(): " << duracion.count() << " microsegundos" << endl;
    }
};

int main()
{
    EvaluarParcial evaluador;
    evaluador.ejecutar();
    return 0;
}
