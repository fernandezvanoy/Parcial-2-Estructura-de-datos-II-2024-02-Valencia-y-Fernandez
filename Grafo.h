#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <cmath>

struct Vertice {
    int id;
    double latitud;
    double longitud;
    Vertice(int id, double lat, double lon) : id(id), latitud(lat), longitud(lon) {}
};

class Grafo {
private:
    std::vector<std::vector<double>> matrizAdyacencia;
    std::vector<Vertice> vertices;

public:
    Grafo(int numVertices);

    void agregarVertice(const Vertice& vertice);
    void calcularDistancias();
    double distanciaEuclidiana(double lat1, double lon1, double lat2, double lon2);
    std::vector<Vertice>& obtenerVertices();
    std::vector<std::vector<double>>& obtenerMatrizAdyacencia();
};

#endif
