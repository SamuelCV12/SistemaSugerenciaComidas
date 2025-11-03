#include <iostream>
#include <limits>
#include "SistemaRecomendacion.h"
#include "InterfazConsola.h"
#include <windows.h>

using namespace std;

#include <iostream>
#include <limits>
#include "SistemaRecomendacion.h"
#include "InterfazConsola.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    SistemaRecomendacion sistema;
    int opcion = 0;

    while (true) {

        // Pantalla principal
        InterfazConsola::limpiar();
        InterfazConsola::titulo("🍴  SISTEMA DE RECOMENDACIÓN DE RECETAS  🍴");
        InterfazConsola::linea();

        // Opciones con estilo PRO
        InterfazConsola::menuOpcion(1, "Ingresar ingredientes");
        InterfazConsola::menuOpcion(2, "Ver recetas sugeridas");
        InterfazConsola::menuOpcion(3, "Ver sustituciones o alternativas");
        InterfazConsola::menuOpcion(4, "Ver pasos de preparación");
        InterfazConsola::menuOpcion(5, "Salir");

        InterfazConsola::linea();
        cout << "Seleccione una opción: ";

        // Validar entrada del usuario
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            InterfazConsola::mensajeError("Opción inválida. Intente nuevamente.");
            InterfazConsola::esperar();
            continue;
        }

        // Validar rango
        if (opcion < 1 || opcion > 5) {
            InterfazConsola::mensajeError("Opción fuera de rango. Intente nuevamente.");
            InterfazConsola::esperar();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer

        // Procesar opción
        InterfazConsola::limpiar();

        switch (opcion) {
            case 1:
                InterfazConsola::titulo("🥕 INGRESAR INGREDIENTES");
                sistema.ingresarIngredientes();
                InterfazConsola::esperar();
                break;

            case 2:
                InterfazConsola::titulo("📋 RECETAS SUGERIDAS");
                sistema.verRecetasSugeridas();
                InterfazConsola::esperar();
                break;

            case 3:
                InterfazConsola::titulo("🔄 SUSTITUCIONES Y ALTERNATIVAS");
                sistema.verAlternativas();
                InterfazConsola::esperar();
                break;

            case 4:
                InterfazConsola::titulo("👨‍🍳 PASOS DE PREPARACIÓN");
                sistema.verPasosReceta();
                InterfazConsola::esperar();
                break;

            case 5:
                InterfazConsola::mensajeOK("Gracias por preferirnos. ¡Hasta pronto! ⭐");
                return 0;
        }
    }
}
