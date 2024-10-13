#include "Parcial.h"
#include <iostream>
#include <cmath>

//Funcion para insertar nodos en el grafo
void Parcial::cargar()
{
    int n = 15;

    for (int i = 0; i < n; i++)
    {
        grafo.mapa.push_back(new Nodo(i));
    }


}

//Funcion que ejecuta la mayoria de procesos del programa
void Parcial::run(double **puntos, int numPuntos)
{
    double **distancias = calcularDistancias(puntos, numPuntos);

    int n = grafo.mapa.size();

    this->grafo.mapa[0]->nombre = "Laureles";
    this->grafo.mapa[1]->nombre = "Estadio";
    this->grafo.mapa[2]->nombre = "Belén";
    this->grafo.mapa[3]->nombre = "Envigado";
    this->grafo.mapa[4]->nombre = "El Poblado";
    this->grafo.mapa[5]->nombre = "Centro";
    this->grafo.mapa[6]->nombre = "Castilla";
    this->grafo.mapa[7]->nombre = "Robledo";
    this->grafo.mapa[8]->nombre = "Buenos Aires";
    this->grafo.mapa[9]->nombre = "Manrique";
    this->grafo.mapa[10]->nombre = "Aranjuez";
    this->grafo.mapa[11]->nombre = "Floresta";
    this->grafo.mapa[12]->nombre = "Guayabal";
    this->grafo.mapa[13]->nombre = "Itagüí";
    this->grafo.mapa[14]->nombre = "Sabaneta";

    //Procesos para dividir el grafo en 2 subgrafos
    vector<vector<int>> indiceSubgrafos = kernighanLinParticion(distancias, n);
    vector<Nodo *> subgrafo1 = generarSubgrafo(indiceSubgrafos[0], grafo.mapa);
    vector<Nodo *> subgrafo2 = generarSubgrafo(indiceSubgrafos[1], grafo.mapa);


  
    // Conectar nodos para subgrafo1
    for (int i = 0; i < subgrafo1.size(); i++)
    {
        Nodo &nodoActual = *(subgrafo1[i]);

        for (int j = 0; j < subgrafo1.size(); j++)
        {
            if (i != j)
            {
                nodoActual.adyacentes.push_back(subgrafo1[j]);
            }
        }
    }

    // Conectar nodos para subgrafo2
    for (int i = 0; i < subgrafo2.size(); i++)
    {
        Nodo &nodoActual = *(subgrafo2[i]);

        for (int j = 0; j < subgrafo2.size(); j++)
        {
            if (i != j)
            {
                nodoActual.adyacentes.push_back(subgrafo2[j]);
            }
        }
    }

    Nodo *nodoInicioA = grafo.mapa[14];
    Nodo *nodoInicioB = grafo.mapa[7];

    int nSubA;
    int nSubB;

    if (find(subgrafo1.begin(), subgrafo1.end(), nodoInicioA) != subgrafo1.end()) {
    nSubA = 8;
    nSubB = subgrafo2.size();
    } else {
    nSubA = subgrafo2.size();
    nSubB = 8;
    }

    //Busqueda de las rutas posibles en cada subgrafo
    vector<vector<Nodo *>> rutasA = BuscarRutas(nodoInicioA, nSubA);
    vector<vector<Nodo *>> rutasB = BuscarRutas(nodoInicioB, nSubB);

    cout << "Cantidad de rutas para el subgrafo1: " << rutasA.size() << endl;
    cout << "Cantidad de rutas para el subgrafo2: " << rutasB.size() << endl;

    vector<Nodo*> menorRutaA;
    vector<Nodo*> menorRutaB;

    double costoRutaA = 0;
    double costoRutaB = 0;

    //Proceso para encontrar la ruta con menor costo del subgrafo1
    for(vector<Nodo*> &ruta: rutasA){

        double costo = calcularCosto(ruta, distancias);

      if(costoRutaA == 0){

        costoRutaA = costo;
        menorRutaA = ruta;

        continue;
      }

      if(costo < costoRutaA){
        costoRutaA = costo;
        menorRutaA = ruta;
      }
    }

    //Proceso para encontrar la ruta con menor costo del subgrafo2
    for(vector<Nodo*> &ruta: rutasB){

        double costo = calcularCosto(ruta, distancias);

      if(costoRutaB == 0){

        costoRutaB = costo;
        menorRutaB = ruta;

        continue;
      }

      if(costo < costoRutaB){
        costoRutaB = costo;
        menorRutaB = ruta;
      }
    }

    //Print de los resultados
    cout << "\nRuta camion A:";
    for(Nodo* nodo : menorRutaA){

        cout << " -> " << nodo->nombre;
    }

    cout << "\nCosto ruta A: "<<costoRutaA/1000 << " Km" << endl;

    cout << "\nRuta camion B:";
    for(Nodo* nodo : menorRutaB){

        cout << " -> " << nodo->nombre;
    }

    cout << "\nCosto ruta B :" << costoRutaB/1000 << " Km" << endl;

    grafo.puntos = puntos;
    grafo.distancias = distancias;
}

//Funcion para crear un subgrafo segun los indices de los nodos en la variable mapa
vector<Nodo *> Parcial::generarSubgrafo(const vector<int> &subgrafo, const vector<Nodo *> &mapa)
{
    vector<Nodo *> conexiones;

    for (const int &n : subgrafo)
    {
        conexiones.push_back(mapa[n]);
    }

    return conexiones;
}

//Busca todas las rutas desde un nodo inicial hasta una longitud dada
vector<vector<Nodo *>> Parcial::BuscarRutas(Nodo *inicio, int longitud)
{
    vector<vector<Nodo *>> rutas;
    vector<Nodo *> ruta;
    ruta.push_back(inicio);

    for (Nodo *&vecino : inicio->adyacentes)
    {
        vector<Nodo *> nuevaRuta = ruta;
        nuevaRuta.push_back(vecino);
        BuscarRuta(vecino, nuevaRuta, rutas, longitud);
    }

    return rutas;
}

//Explora recursivamente rutas desde un nodo hasta alcanzar la longitud especificada, evitando ciclos
void Parcial::BuscarRuta(Nodo *nodo, vector<Nodo *> rutaActual, vector<vector<Nodo *>> &rutas, int longitud)
{
    if (longitud == rutaActual.size())
    {
        rutas.push_back(rutaActual);
        return;
    }
    else
    {
        for (Nodo *&vecino : nodo->adyacentes)
        {
            vector<Nodo *> nuevaRuta = rutaActual;

            // Búsqueda manual para ver si el vecino ya está en nuevaRuta
            bool yaEstaEnRuta = false;
            for (Nodo *&nodoEnRuta : nuevaRuta)
            {
                if (nodoEnRuta == vecino)
                {
                    yaEstaEnRuta = true;
                    break; // Detenemos la búsqueda si ya lo encontramos
                }
            }

            if (!yaEstaEnRuta)
            {
                nuevaRuta.push_back(vecino);                    // Agregamos el puntero del vecino
                BuscarRuta(vecino, nuevaRuta, rutas, longitud); // Llamada recursiva
            }
        }
    }
}

//Calcula el costo de una ruta
double Parcial::calcularCosto(vector<Nodo*> &ruta, double** distancias)
{
    double costo = 0.0;

    for (int i = 0; i < ruta.size() - 1; i++)
    {
        costo += distancias[ruta[i]->getID()][ruta[i + 1]->getID()];
    }

    return costo;
}

//Funcion que calcula las distancias entre cada uno de los nodos del grafo
double **Parcial::calcularDistancias(double **puntos, int numPuntos){

    numPuntos += 1;

    double **distancias = new double *[numPuntos];
    for (int i = 0; i < numPuntos; i++)
    {
        distancias[i] = new double[numPuntos];
    }

    for (int i = 0; i < numPuntos; i++)
    {
        double latitud1 = puntos[i][0];
        double longitud1 = puntos[i][1];

        for (int j = 0; j < numPuntos; j++)
        {
            double latitud2 = puntos[j][0];
            double longitud2 = puntos[j][1];
            distancias[i][j] = calcularGradosMetros(latitud1, longitud1, latitud2, longitud2);
        }
    }

    return distancias;
}

//Calcula la distancia en metros teniendo en cuenta la latitud y longitud de dos puntos
double Parcial::calcularGradosMetros(double lat1, double lon1, double lat2, double lon2)
{
    const int RADIO_TIERRA = 6371;
    double lat1Rad = lat1 * M_PI / 180;
    double lat2Rad = lat2 * M_PI / 180;
    double lon1Rad = lon1 * M_PI / 180;
    double lon2Rad = lon2 * M_PI / 180;

    double deltaLat = lat2Rad - lat1Rad;
    double deltaLon = lon2Rad - lon1Rad;

    double a = sin(deltaLat / 2) * sin(deltaLat / 2) + cos(lat1Rad) * cos(lat2Rad) * sin(deltaLon / 2) * sin(deltaLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distanciaKilometros = RADIO_TIERRA * c;
    double distanciaMetros = distanciaKilometros * 1000;

    return distanciaMetros;
}

//Divide el grafo en dos subconjuntos de nodos de tamaño aproximadamente igual
vector<vector<int>> Parcial::kernighanLinParticion(double **graph, int numnodos)
{
    vector<vector<int>> subgraph;

    // Inicializamos dos conjuntos a y b
    vector<int> a;
    vector<int> b;
    // Dividir nodos por igual entre los conjuntos
    for (int i = 0; i < 8; i++)
    {
        a.push_back(i);
    }
    for (int i = 8; i < 15; i++)
    {
        b.push_back(i);
    }

    // Inicializar variables de control
    bool mejora = true;
    while (mejora)
    {
        mejora = false;

        // Calcular distancia total de cada grupo
        double distanciaA = calcularDistanciaTotal(graph, a);
        double distanciaB = calcularDistanciaTotal(graph, b);
        double mejorMejora = 0;
        int mejorA = -1, mejorB = -1;   

        // Probar todos los pares de nodos para intercambio
        for (int nodoA : a)
        {
            for (int nodoB : b)
            {
                // Intercambiar nodos y calcular la nueva distancia total
                vector<int> nuevoA = a;
                vector<int> nuevoB = b;
                nuevoA.erase(remove(nuevoA.begin(), nuevoA.end(), nodoA), nuevoA.end());
                nuevoB.erase(remove(nuevoB.begin(), nuevoB.end(), nodoB), nuevoB.end());
                nuevoA.push_back(nodoB);
                nuevoB.push_back(nodoA);

                double nuevaDistanciaA = calcularDistanciaTotal(graph, nuevoA);
                double nuevaDistanciaB = calcularDistanciaTotal(graph, nuevoB);

                // Calcular la mejora neta
                double mejoraActual = (distanciaA + distanciaB) - (nuevaDistanciaA + nuevaDistanciaB);

                if (mejoraActual > mejorMejora)
                {
                    mejorMejora = mejoraActual;
                    mejorA = nodoA;
                    mejorB = nodoB;
                }
            }
        }

        // Si encontramos una mejora, realizar el intercambio
        if (mejorMejora > 0)
        {
            a.erase(remove(a.begin(), a.end(), mejorA), a.end());
            b.erase(remove(b.begin(), b.end(), mejorB), b.end());
            a.push_back(mejorB);
            b.push_back(mejorA);
            mejora = true;
        }
    }

    subgraph.push_back(a);
    subgraph.push_back(b);

    return subgraph;
}


double Parcial::calcularDistanciaTotal(double **graph, const vector<int> &grupo)
{
    double total = 0.0;


    for (int i = 0; i < grupo.size(); i++)
    {
        for (int j = i + 1; j < grupo.size(); j++)
        {
            total += graph[grupo[i]][grupo[j]];
        }
    }
    return total;
}
