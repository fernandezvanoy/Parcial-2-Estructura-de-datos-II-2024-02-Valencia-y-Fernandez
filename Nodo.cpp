#include "Nodo.h"

// Constructor
Nodo::Nodo(int id) : id(id) {}

// Getter para adyacentes
std::vector<Nodo*>& Nodo::getAdyacentes() {
    return adyacentes;
}

// Setter para adyacentes
void Nodo::setAdyacentes(const std::vector<Nodo*>& adyacentes) {
    this->adyacentes = adyacentes;
}

// Getter para distancias
std::vector<int>& Nodo::getDistancias() {
    return distancias;
}

// Setter para distancias
void Nodo::setDistancias(const std::vector<int>& dist) {
    this->distancias = dist;
}

// Setter para ID
void Nodo::setID(int id) {
    this->id = id;
}

// Getter para ID
int Nodo::getID() const {
    return id;
}
