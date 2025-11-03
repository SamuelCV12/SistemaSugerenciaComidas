#pragma once

#include "Ingrediente.h"

using namespace std;

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