#include "Grafo.h"

Grafo::Grafo(int numVertices) {
    matrizAdyacencia.resize(numVertices, std::vector<double>(numVertices, 0.0));
}

void Grafo::agregarVertice(const Vertice& vertice) {
    vertices.push_back(vertice);
}

void Grafo::calcularDistancias() {
    for (size_t i = 0; i < vertices.size(); i++) {
        for (size_t j = 0; j < vertices.size(); j++) {
            if (i != j) {
                matrizAdyacencia[i][j] = distanciaEuclidiana(vertices[i].latitud, vertices[i].longitud, vertices[j].latitud, vertices[j].longitud);
            }
        }
    }
}

double Grafo::distanciaEuclidiana(double lat1, double lon1, double lat2, double lon2) {
    double dx = lat2 - lat1;
    double dy = lon2 - lon1;
    return sqrt(dx * dx + dy * dy);
}

std::vector<Vertice>& Grafo::obtenerVertices() {
    return vertices;
}

std::vector<std::vector<double>>& Grafo::obtenerMatrizAdyacencia() {
    return matrizAdyacencia;
}
