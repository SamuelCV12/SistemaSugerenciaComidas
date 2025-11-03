#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <limits>

using namespace std;

class ArbolBST {
private:
    NodoArbol* raiz;
    
    // Insertar recursivamente
    NodoArbol* insertarRecursivo(NodoArbol* nodo, Receta receta) {
        if (nodo == nullptr) {
            return new NodoArbol(receta);
        }
        
        if (receta.getNombre() < nodo->getReceta().getNombre()) {
            nodo->setIzquierdo(insertarRecursivo(nodo->getIzquierdo(), receta));
        } else if (receta.getNombre() > nodo->getReceta().getNombre()) {
            nodo->setDerecho(insertarRecursivo(nodo->getDerecho(), receta));
        }
        
        return nodo;
    }
    
    // Buscar recursivamente todas las recetas y calcular coincidencias
    void buscarCoincidencias(NodoArbol* nodo, const ListaEnlazada& ingredientes, 
                        vector<pair<Receta*, double>>& resultados) {
        if (nodo == nullptr) return;
        
        buscarCoincidencias(nodo->getIzquierdo(), ingredientes, resultados);
        
        double coincidencia = nodo->getReceta().calcularCoincidencia(ingredientes);
        if (coincidencia > 0) {
            resultados.push_back({&nodo->getReceta(), coincidencia});
        }
        
        buscarCoincidencias(nodo->getDerecho(), ingredientes, resultados);
    }
    
    // Destruir árbol recursivamente
    void destruirArbol(NodoArbol* nodo) {
        if (nodo != nullptr) {
            destruirArbol(nodo->getIzquierdo());
            destruirArbol(nodo->getDerecho());
            delete nodo;
        }
    }

public:
    ArbolBST() : raiz(nullptr) {}
    
    ~ArbolBST() {
        destruirArbol(raiz);
    }
    
    void insertar(Receta receta) {
        raiz = insertarRecursivo(raiz, receta);
    }
    
    vector<pair<Receta*, double>> buscarRecetas(const ListaEnlazada& ingredientes) {
        vector<pair<Receta*, double>> resultados;
        buscarCoincidencias(raiz, ingredientes, resultados);
        
        // Ordenar por coincidencia descendente
        sort(resultados.begin(), resultados.end(), 
            [](const auto& a, const auto& b) { return a.second > b.second; });
        
        return resultados;
    }
};

