// Nombre del archivo: NodoLista.h
#pragma once

#include "Ingrediente.h" // Incluye la dependencia

// ==================== NODO LISTA ENLAZADA ====================
class NodoLista {
private:
    Ingrediente dato;
    NodoLista* siguiente;

public:
    NodoLista(Ingrediente d) : dato(d), siguiente(nullptr) {}
    
    Ingrediente getDato() const { return dato; }
    NodoLista* getSiguiente() const { return siguiente; }
    void setSiguiente(NodoLista* sig) { siguiente = sig; }
};