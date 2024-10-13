#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Nodo.h"


using namespace std;



class Grafo {
private:



public:
    vector<Nodo*> mapa;
    double** puntos;
    double** distancias;
};

#endif
