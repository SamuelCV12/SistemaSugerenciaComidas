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

using namespace std;
class Ingrediente {
private:
    string nombre;
    string categoria;

public:
    Ingrediente(string n = "", string c = "general") : nombre(n), categoria(c) {}
    
    // Getters
    string getNombre() const { return nombre; }
    string getCategoria() const { return categoria; }
    
    // Setters
    void setNombre(string n) { nombre = n; }
    void setCategoria(string c) { categoria = c; }
    
    bool operator==(const Ingrediente& otro) const {
        return nombre == otro.nombre;
    }
    
    bool operator<(const Ingrediente& otro) const {
        return nombre < otro.nombre;
    }
};


