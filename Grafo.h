#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Nodo.h"


using namespace std;


//Clae Grafo con los atributos que consideramos necesarios
class Grafo {
public:
    vector<Nodo*> mapa;
    double** puntos;
    double** distancias;

    
};

#endif
