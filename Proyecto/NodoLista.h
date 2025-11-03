#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <limits>
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



