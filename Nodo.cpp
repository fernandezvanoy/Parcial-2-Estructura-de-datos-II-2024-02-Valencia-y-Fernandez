#include "Nodo.h"

// Constructor
Nodo::Nodo(int id) : id(id) {}

// Getter para distancias
vector<int> &Nodo::getDistancias()
{
    return distancias;
}

// Setter para distancias
void Nodo::setDistancias(const vector<int> &dist)
{
    this->distancias = dist;
}

// Setter para id
void Nodo::setID(int id)
{
    this->id = id;
}

// Getter para id
int Nodo::getID() const
{
    return id;
}


