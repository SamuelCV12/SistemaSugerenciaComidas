class Grafo {
private:
    map<string, set<string>> adyacencias; // Relaciones entre ingredientes

public:
    // Agregar una relación entre ingredientes (sustitución o combinación)
    void agregarRelacion(string ing1, string ing2) {
        adyacencias[ing1].insert(ing2);
        adyacencias[ing2].insert(ing1);
    }
    
    // Obtener sustitutos de un ingrediente
    set<string> obtenerSustitutos(const string& ingrediente) const {
        auto it = adyacencias.find(ingrediente);
        if (it != adyacencias.end()) {
            return it->second;
        }
        return set<string>();
    }
    
    // Verificar si hay una relación entre dos ingredientes
    bool hayRelacion(const string& ing1, const string& ing2) const {
        auto it = adyacencias.find(ing1);
        if (it != adyacencias.end()) {
            return it->second.find(ing2) != it->second.end();
        }
        return false;
    }
    
    // Sugerir ingredientes alternativos basados en lo que falta
    vector<string> sugerirAlternativas(const vector<string>& faltantes) const {
        set<string> alternativas;
        
        for (const auto& faltante : faltantes) {
            set<string> sustitutos = obtenerSustitutos(faltante);
            alternativas.insert(sustitutos.begin(), sustitutos.end());
        }
        
        return vector<string>(alternativas.begin(), alternativas.end());
    }
};
