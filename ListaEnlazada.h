// Nombre del archivo: ListaEnlazada.h
#pragma once

#include "NodoLista.h" // Incluye la dependencia
#include <vector>
#include <string>

using namespace std;

// ==================== LISTA ENLAZADA ====================
class ListaEnlazada {
private:
    NodoLista* cabeza;
    int tamano;

public:
    ListaEnlazada() : cabeza(nullptr), tamano(0) {}
    
    ~ListaEnlazada() {
        limpiar();
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
        NodoLista* actual = cabeza;
        while (actual != nullptr) {
            if (actual->getDato().getNombre() == nombre) {
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