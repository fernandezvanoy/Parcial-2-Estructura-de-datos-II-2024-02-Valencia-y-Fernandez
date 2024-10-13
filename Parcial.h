#ifndef PARCIAL_H
#define PARCIAL_H

#include <vector>
#include <string>
#include<algorithm>
#include "Nodo.h"
#include "Grafo.h"

class Parcial {
public:
    Grafo grafo;

    void cargar();
    void run(double** puntos, int numPuntos);

private:
    static std::vector<Nodo*> generarSubgrafo(const std::vector<int>& subgrafo, const std::vector<Nodo*>& mapa);
    static std::vector<std::vector<Nodo*>> BuscarRutas(Nodo* inicio, int longitud);
    static void BuscarRuta(Nodo* nodo, vector<Nodo*> rutaActual, std::vector<std::vector<Nodo*>>& rutas, int longitud);

    static double calcularCosto(std::vector<Nodo*>& ruta, double** distancias);
    static double** calcularDistancias(double** puntos, int numPuntos);
    static double calcularGradosMetros(double lat1, double lon1, double lat2, double lon2);
    static double calcularDistanciaEuclidiana(double x1, double y1, double x2, double y2);
    static vector<vector<int>> kernighanLinParticion(double** graph, int numnodos);
    static double calcularDistanciaTotal(double** graph, const std::vector<int>& grupo);
};

#endif // PARCIAL_H


