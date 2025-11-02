// Nombre del archivo: main.cpp

// Solo necesitamos incluir el sistema principal,
// que a su vez incluye todo lo demás.
#include "SistemaRecomendacion.h"

// ==================== FUNCIÓN PRINCIPAL ====================
int main() {
    // 1. Se crea una instancia del sistema
    SistemaRecomendacion sistema;
    
    // 2. Se llama al método que contiene el bucle principal del menú
    sistema.mostrarMenu();
    
    // 3. El programa termina cuando 'mostrarMenu' finaliza (opcion 0)
    return 0;
}