#ifndef PARCIAL_H
#define PARCIAL_H

#include <iostream>
#include <vector>
#include "Nodo.h"
#include <algorithm>

class Parcial {
public:
    static vector<vector<Nodo*>> BuscarRutas(Nodo* inicio, Nodo* destino);
    static void BuscarRuta(Nodo* nodo, Nodo* destino, vector<Nodo*>& rutaActual, vector<vector<Nodo*>>& rutas);
    static double calcularCosto(const vector<Nodo*>& ruta, const vector<vector<double>>& distancias);
};

#endif 
