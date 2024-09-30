#include "Parcial.h"

// Función que busca rutas entre dos nodos
vector<vector<Nodo*>> Parcial::BuscarRutas(Nodo* inicio, Nodo* destino) {
    // Crea la lista donde irá almacenando las rutas encontradas
    vector<vector<Nodo*>> rutas;

    // Crea un vector que representa una ruta
    vector<Nodo*> ruta;
    
    // Agrega el nodo de inicio a la ruta
    ruta.push_back(inicio);

    // Empieza a iterar sobre los vecinos del nodo de inicio
    for (Nodo* actual : inicio->getAdyacentes()) {
        // Crea una copia de la ruta actual
        vector<Nodo*> nuevaRuta = ruta;

        // Agrega el vecino a la nueva ruta
        nuevaRuta.push_back(actual);

        // Invoca la función recursiva
        BuscarRuta(actual, destino, nuevaRuta, rutas);
    }

    return rutas;
}

// Función recursiva para buscar rutas
void Parcial::BuscarRuta(Nodo* nodo, Nodo* destino, vector<Nodo*>& rutaActual, vector<vector<Nodo*>>& rutas) {
    // Compara si el nodo actual es el destino
    if (nodo == destino) {
        rutas.push_back(rutaActual);
        return;
    } else {
        // Busca en los vecinos del nodo actual
        for (Nodo* actual : nodo->getAdyacentes()) {
            // Crea una copia de la ruta correspondiente al nodo "actual"
            vector<Nodo*> nuevaRuta = rutaActual;

            // Verifica si el nodo actual ya está en la lista para evitar repeticiones
            if (find(nuevaRuta.begin(), nuevaRuta.end(), actual) == nuevaRuta.end()) {
                // Agrega el nodo y busca nuevamente un vecino de este nodo
                nuevaRuta.push_back(actual);
                BuscarRuta(actual, destino, nuevaRuta, rutas);
            }
        }
    }
}

// Función que calcula el costo de una ruta
double Parcial::calcularCosto(const vector<Nodo*>& ruta, const vector<vector<double>>& distancias) {
    // Inicia el contador
    double costo = 0.0;

    // Recorre cada uno de los nodos de la ruta
    for (size_t i = 0; i < ruta.size() - 1; i++) {
        // Busca los kilómetros entre los dos nodos en las distancias
        costo += distancias[ruta[i]->getID()][ruta[i + 1]->getID()];
    }

    return costo;
}
