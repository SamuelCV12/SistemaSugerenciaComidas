int main() {
    SistemaRecomendacion sistema;
    int opcion = 0;

    while (true) {
        cout << "\n=================================================\n";
        cout << "SISTEMA INTELIGENTE DE RECOMENDACIONES DE RECETAS\n";
        cout << "=================================================\n";
        cout << "1. Ingresar ingredientes\n";
        cout << "2. Ver recetas sugeridas\n";
        cout << "3. Ver sustituciones o alternativas\n";
        cout << "4. Ver pasos de preparacion de receta\n";
        cout << "5. Salir\n";
        cout << "-------------------------------------------------\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            // Entrada no numérica (por ejemplo, letras)
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
            cout << "\n[ERROR] Opcion invalida. Intente nuevamente.\n";
            continue; // Regresa inmediatamente al menú principal
        }

        // Si el usuario mete un número fuera del rango
        if (opcion < 1 || opcion > 5) {
            cout << "\n[ERROR] Opcion fuera de rango. Intente nuevamente.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia salto de línea extra

        switch (opcion) {
            case 1:
                sistema.ingresarIngredientes();
                break;
            case 2:
                sistema.verRecetasSugeridas();
                break;
            case 3:
                sistema.verAlternativas();
                break;
            case 4:
                sistema.verPasosReceta();
                break;
            case 5:
                cout << "Gracias por Preferirnos. Hasta Pronto...";
                return 0;
        }
    }
}
