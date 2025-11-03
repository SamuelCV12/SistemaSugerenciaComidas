#pragma once

#include "NodoLista.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==================== LISTA ENLAZADA ====================
class ListaEnlazada {
private:
    NodoLista* cabeza;
    int tamano;

public:
    ListaEnlazada() : cabeza(nullptr), tamano(0) {}
    
    ~ListaEnlazada() {
        while (cabeza != nullptr) {
            NodoLista* temp = cabeza;
            cabeza = cabeza->getSiguiente();
            delete temp;
        }
    }
    
    // Agregar ingrediente a la lista
    void agregar(Ingrediente ing) {
        NodoLista* nuevo = new NodoLista(ing);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        } else {
            NodoLista* actual = cabeza;
            while (actual->getSiguiente() != nullptr) {
                actual = actual->getSiguiente();
            }
            actual->setSiguiente(nuevo);
        }
        tamano++;
    }
    
    // Verificar si contiene un ingrediente
    bool contiene(const string& nombre) const {
        string nombreMin = nombre;
        transform(nombreMin.begin(), nombreMin.end(), nombreMin.begin(), ::tolower); // 🔽 Normaliza
        
        NodoLista* actual = cabeza;
        while (actual != nullptr) {
            string actualNombre = actual->getDato().getNombre();
            transform(actualNombre.begin(), actualNombre.end(), actualNombre.begin(), ::tolower); // 🔽 Normaliza también
            if (actualNombre == nombreMin) {
                return true;
            }
            actual = actual->getSiguiente();
        }
        return false;
    }
    
    // Obtener todos los ingredientes
    vector<string> obtenerTodos() const {
        vector<string> resultado;
        NodoLista* actual = cabeza;
        while (actual != nullptr) {
            resultado.push_back(actual->getDato().getNombre());
            actual = actual->getSiguiente();
        }
        return resultado;
    }
    
    int getTamano() const { return tamano; }
    bool estaVacia() const { return cabeza == nullptr; }
    
    void limpiar() {
        while (cabeza != nullptr) {
            NodoLista* temp = cabeza;
            cabeza = cabeza->getSiguiente();
            delete temp;
        }
        tamano = 0;
    }
};