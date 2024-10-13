#ifndef PARCIAL_H
#define PARCIAL_H

#include <vector>
#include <string>
#include<algorithm>
#include "Nodo.h"
#include "Grafo.h"

//clase Parcial
class Parcial {
public:
    Grafo grafo;

    void cargar();
    void run(double** puntos, int numPuntos);

private:
    vector<Nodo*> generarSubgrafo(const vector<int>& subgrafo, const vector<Nodo*>& mapa);
    vector<vector<Nodo*>> BuscarRutas(Nodo* inicio, int longitud);
    void BuscarRuta(Nodo* nodo, vector<Nodo*> rutaActual, vector<vector<Nodo*>>& rutas, int longitud);

    double calcularCosto(vector<Nodo*>& ruta, double** distancias);
    double** calcularDistancias(double** puntos, int numPuntos);
    double calcularGradosMetros(double lat1, double lon1, double lat2, double lon2);
    vector<vector<int>> kernighanLinParticion(double** graph, int numnodos);
    double calcularDistanciaTotal(double** graph, const vector<int>& grupo);
};

#endif 


