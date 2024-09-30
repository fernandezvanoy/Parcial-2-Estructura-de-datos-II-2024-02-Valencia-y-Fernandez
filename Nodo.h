#ifndef NODO_H
#define NODO_H

#include <vector>
using namespace std;

class Nodo {
private:
    int id;                          
    vector<Nodo*> adyacentes;    
    vector<int> distancias;      

public:
    // Constructor
    Nodo(int id);

    // Getter para adyacentes
    vector<Nodo*>& getAdyacentes();

    // Setter para adyacentes
    void setAdyacentes(const vector<Nodo*>& adyacentes);

    // Getter para distancias
    vector<int>& getDistancias();

    // Setter para distancias
    void setDistancias(const vector<int>& dist);

    // Setter para ID
    void setID(int id);

    // Getter para ID
    int getID() const;
};

#endif 
