// Nombre del archivo: NodoArbol.h
#pragma once

#include "Receta.h" // Incluye la dependencia

// ==================== NODO ÁRBOL BST ====================
class NodoArbol {
private:
    Receta receta;
    NodoArbol* izquierdo;
    NodoArbol* derecho;

public:
    NodoArbol(Receta r) : receta(r), izquierdo(nullptr), derecho(nullptr) {}
    
    Receta& getReceta() { return receta; }
    const Receta& getReceta() const { return receta; }
    NodoArbol* getIzquierdo() const { return izquierdo; }
    NodoArbol* getDerecho() const { return derecho; }
    
    void setIzquierdo(NodoArbol* izq) { izquierdo = izq; }
    void setDerecho(NodoArbol* der) { derecho = der; }
};