class Receta {
private:
    string nombre;
    vector<string> ingredientes;
    vector<string> pasos;
    string categoria;
    int vecesUsada;

public:
    Receta(string n = "", string cat = "general") 
        : nombre(n), categoria(cat), vecesUsada(0) {}
    
    // Getters
    string getNombre() const { return nombre; }
    vector<string> getIngredientes() const { return ingredientes; }
    vector<string> getPasos() const { return pasos; }
    string getCategoria() const { return categoria; }
    int getVecesUsada() const { return vecesUsada; }
    
    // Setters
    void setNombre(string n) { nombre = n; }
    void setCategoria(string c) { categoria = c; }
    void incrementarUso() { vecesUsada++; }
    
    void agregarIngrediente(string ing) {
        ingredientes.push_back(ing);
    }
    
    void agregarPaso(string paso) {
        pasos.push_back(paso);
    }
    
    // Calcular porcentaje de coincidencia con ingredientes disponibles
    double calcularCoincidencia(const ListaEnlazada& disponibles) const {
        if (ingredientes.empty()) return 0.0;
        
        int coincidencias = 0;
        for (const auto& ing : ingredientes) {
            if (disponibles.contiene(ing)) {
                coincidencias++;
            }
        }
        
        return (coincidencias * 100.0) / ingredientes.size();
    }
    
    // Obtener ingredientes faltantes
    vector<string> obtenerFaltantes(const ListaEnlazada& disponibles) const {
        vector<string> faltantes;
        for (const auto& ing : ingredientes) {
            if (!disponibles.contiene(ing)) {
                faltantes.push_back(ing);
            }
        }
        return faltantes;
    }
};
