#ifndef NODO_H
#define NODO_H

#include <string>
#include <vector>

using namespace std;

//Clase Nodo
class Nodo {
private:
    vector<int> distancias;     // Lista de distancias
public:
    int id;
    string nombre;
    vector<Nodo*> adyacentes;   // Lista de punteros a nodos adyacentes

    // Constructor
    Nodo(int id);

    // Getter para distancias
    vector<int>& getDistancias();

    // Setter para distancias
    void setDistancias(const vector<int>& dist);

    // Getter y Setter para id
    void setID(int id);
    int getID() const;
    
};

#endif
