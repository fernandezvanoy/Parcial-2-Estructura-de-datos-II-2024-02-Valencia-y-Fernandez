#include "Parcial.h"
#include <iostream>
#include <cmath> 

void Parcial::cargar() {
    int n = 15;

    for (int i = 0; i < n; i++) {
        grafo.mapa.push_back(new Nodo(i));
    }

    // Conectar nodos todos con todos
    for (int i = 0; i < n; i++) {
        Nodo& nodoActual = *(this->grafo.mapa[i]);

        for (int j = 0; j < n; j++) {
            if (i != j) {
                nodoActual.getAdyacentes().push_back(grafo.mapa[j]);
            }
        }
    }
}

void Parcial::run(double** puntos, int numPuntos) {
    double** distancias = calcularDistancias(puntos, numPuntos);

    int n = grafo.mapa.size();

    this->grafo.mapa[0]->nombre = "Laureles";
    this->grafo.mapa[1]->nombre = "Estadio";
    this->grafo.mapa[2]->nombre = "Belén";
    this->grafo.mapa[3]->nombre = "Envigado";
    this->grafo.mapa[4]->nombre = "El Poblado";
    this->grafo.mapa[5]->nombre = "Centro";
    this->grafo.mapa[6]->nombre = "Castilla";
    this->grafo.mapa[7]->nombre = "Robledo";
    this->grafo.mapa[8]->nombre = "Buenos Aires";
    this->grafo.mapa[9]->nombre = "Manrique";
    this->grafo.mapa[10]->nombre = "Aranjuez";
    this->grafo.mapa[11]->nombre = "Floresta";
    this->grafo.mapa[12]->nombre = "Guayabal";
    this->grafo.mapa[13]->nombre = "Itagüí";
    this->grafo.mapa[14]->nombre = "Sabaneta";

    auto indiceSubgrafos = kernighanLinParticion(distancias, n);
    std::vector<Nodo*> subgrafo1 = generarSubgrafo(indiceSubgrafos[0], grafo.mapa);
    std::vector<Nodo*> subgrafo2 = generarSubgrafo(indiceSubgrafos[1], grafo.mapa);

    for (auto& nodo1 : subgrafo1) {
        for (auto& nodo2 : subgrafo2) {
            nodo1->getAdyacentes().erase(std::remove(nodo1->getAdyacentes().begin(), nodo1->getAdyacentes().end(), nodo2), nodo1->getAdyacentes().end());
        }
    }


    

    for (auto& nodo2 : subgrafo2) {
        for (auto& nodo1 : subgrafo1) {
            nodo2->getAdyacentes().erase(std::remove(nodo2->getAdyacentes().begin(), nodo2->getAdyacentes().end(), nodo1), nodo2->getAdyacentes().end());
        }
    }

    for (int i = 0; i < numPuntos; i++) {
        for (int j = 0; j < numPuntos; j++) {
            std::cout << distancias[i][j] << " ";
        }
        std::cout << std::endl;
    }

    Nodo* nodoInicioA = grafo.mapa[14];
    Nodo* nodoInicioB = grafo.mapa[7];

    int nSubA = subgrafo1.size();
    int nSubB = subgrafo2.size();

    std::vector<std::vector<Nodo*>> rutasA = BuscarRutas(nodoInicioA, nSubA);
    std::vector<std::vector<Nodo*>> rutasB = BuscarRutas(nodoInicioB, nSubB);

    grafo.puntos = puntos;
    grafo.distancias = distancias;
}

std::vector<Nodo*> Parcial::generarSubgrafo(const std::vector<int>& subgrafo, const std::vector<Nodo*>& mapa) {
    std::vector<Nodo*> conexiones;

    for (const auto& n : subgrafo) {
        conexiones.push_back(mapa[n]);
    }

    return conexiones;
}

std::vector<std::vector<Nodo*>> Parcial::BuscarRutas(Nodo* inicio, int longitud) {
    std::vector<std::vector<Nodo*>> rutas;
    std::vector<Nodo*> ruta;
    ruta.push_back(inicio);

    for (auto& vecino : inicio->getAdyacentes()) {
        std::vector<Nodo*> nuevaRuta = ruta;
        nuevaRuta.push_back(vecino);
        BuscarRuta(vecino, nuevaRuta, rutas, longitud);
    }

    return rutas;
}


void Parcial::BuscarRuta(Nodo* nodo, vector<Nodo*> rutaActual, vector<vector<Nodo*>>& rutas, int longitud) {
    if (longitud == rutaActual.size()) {
        rutas.push_back(rutaActual);
        return;
    } else {
        for (auto& vecino : nodo->getAdyacentes()) {
            vector<Nodo*> nuevaRuta = rutaActual;
            
            // Búsqueda manual para ver si el vecino ya está en nuevaRuta
            bool yaEstaEnRuta = false;
            for (auto& nodoEnRuta : nuevaRuta) {
                if (nodoEnRuta == vecino) {
                    yaEstaEnRuta = true;
                    break;  // Detenemos la búsqueda si ya lo encontramos
                }
            }

            if (!yaEstaEnRuta) {
                nuevaRuta.push_back(vecino);  // Agregamos el puntero del vecino
                BuscarRuta(vecino, nuevaRuta, rutas, longitud);  // Llamada recursiva
            }
        }
    }
}





double Parcial::calcularCosto(const std::vector<Nodo>& ruta, double distancias[][15]) {
    double costo = 0.0;

    for (size_t i = 0; i < ruta.size() - 1; i++) {
        costo += distancias[ruta[i].getID()][ruta[i + 1].getID()];
    }

    return costo;
}

double** Parcial::calcularDistancias(double** puntos, int numPuntos) {
    double** distancias = new double*[numPuntos];
    for (int i = 0; i < numPuntos; i++) {
        distancias[i] = new double[numPuntos];
    }

    for (int i = 0; i < numPuntos; i++) {
        double latitud1 = puntos[i][0];
        double longitud1 = puntos[i][1];

        for (int j = 0; j < numPuntos; j++) {
            double latitud2 = puntos[j][0];
            double longitud2 = puntos[j][1];
            distancias[i][j] = calcularGradosMetros(latitud1, longitud1, latitud2, longitud2);
        }
    }

    return distancias;
}

double Parcial::calcularGradosMetros(double lat1, double lon1, double lat2, double lon2) {
    const int RADIO_TIERRA = 6371;
    double lat1Rad = lat1 * M_PI / 180;
    double lat2Rad = lat2 * M_PI / 180;
    double lon1Rad = lon1 * M_PI / 180;
    double lon2Rad = lon2 * M_PI / 180;

    double deltaLat = lat2Rad - lat1Rad;
    double deltaLon = lon2Rad - lon1Rad;

    double a = sin(deltaLat / 2) * sin(deltaLat / 2)
               + cos(lat1Rad) * cos(lat2Rad)
               * sin(deltaLon / 2) * sin(deltaLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distanciaKilometros = RADIO_TIERRA * c;
    double distanciaMetros = distanciaKilometros * 1000;

    return distanciaMetros;
}

double Parcial::calcularDistanciaEuclidiana(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

std::vector<std::vector<int>> Parcial::kernighanLinParticion(double** graph, int numnodos) {
    // Lógica para realizar la partición de Kernighan-Lin (no implementada en el ejemplo).
    std::vector<std::vector<int>> particiones;
    // Se debe implementar la lógica aquí...
    return particiones;
}

double Parcial::calcularDistanciaTotal(double** graph, const std::vector<int>& grupo) {
    double total = 0.0;
    for (size_t i = 0; i < grupo.size(); i++) {
        for (size_t j = i + 1; j < grupo.size(); j++) {
            total += graph[grupo[i]][grupo[j]];
        }
    }
    return total;
}
