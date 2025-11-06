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
#include "ListaEnlazada.h"
#include "ArbolBST.h"
#include "Grafo.h"
#include "Receta.h"
#include "InterfazConsola.h"
using namespace std;

class SistemaRecomendacion {
private:
    ListaEnlazada ingredientesDisponibles;
    ArbolBST recetas;
    Grafo relacionesIngredientes;
    
    void mostrarLinea(char c = '=', int n = 60) {
        cout << string(n, c) << endl;
    }
    
    void cargarRecetasPredeterminadas() {
        // Receta 1: Arroz con pollo
        Receta r1("Arroz con pollo", "plato principal");
        r1.agregarIngrediente("arroz");
        r1.agregarIngrediente("pollo");
        r1.agregarIngrediente("cebolla");
        r1.agregarIngrediente("ajo");
        r1.agregarIngrediente("aceite");
        r1.agregarPaso("1. Cortar el pollo en trozos medianos");
        r1.agregarPaso("2. Picar la cebolla y el ajo finamente");
        r1.agregarPaso("3. Sofreir el pollo con cebolla y ajo");
        r1.agregarPaso("4. Agregar el arroz y agua");
        r1.agregarPaso("5. Cocinar hasta que el arroz este listo");
        recetas.insertar(r1);
        
        // Receta 2: Pollo al horno
        Receta r2("Pollo al horno", "plato principal");
        r2.agregarIngrediente("pollo");
        r2.agregarIngrediente("limon");
        r2.agregarIngrediente("ajo");
        r2.agregarIngrediente("aceite");
        r2.agregarPaso("1. Marinar el pollo con limon y ajo");
        r2.agregarPaso("2. Dejar reposar 30 minutos");
        r2.agregarPaso("3. Hornear a 180C por 45 minutos");
        r2.agregarPaso("4. Servir caliente");
        recetas.insertar(r2);
        
        // Receta 3: Sopa de verduras
        Receta r3("Sopa de verduras", "sopa");
        r3.agregarIngrediente("papa");
        r3.agregarIngrediente("zanahoria");
        r3.agregarIngrediente("cebolla");
        r3.agregarIngrediente("apio");
        r3.agregarPaso("1. Pelar y cortar todas las verduras");
        r3.agregarPaso("2. Hervir agua en una olla grande");
        r3.agregarPaso("3. Agregar las verduras y cocinar 20 minutos");
        r3.agregarPaso("4. Sazonar al gusto");
        recetas.insertar(r3);
        
        // Receta 4: Ensalada Cesar
        Receta r4("Ensalada Cesar", "ensalada");
        r4.agregarIngrediente("lechuga");
        r4.agregarIngrediente("pollo");
        r4.agregarIngrediente("queso");
        r4.agregarIngrediente("pan");
        r4.agregarPaso("1. Lavar y cortar la lechuga");
        r4.agregarPaso("2. Cocinar y cortar el pollo");
        r4.agregarPaso("3. Preparar crutones con el pan");
        r4.agregarPaso("4. Mezclar todo con aderezo Cesar");
        recetas.insertar(r4);
        
        // Receta 5: Pasta con tomate
        Receta r5("Pasta con tomate", "plato principal");
        r5.agregarIngrediente("pasta");
        r5.agregarIngrediente("tomate");
        r5.agregarIngrediente("ajo");
        r5.agregarIngrediente("aceite");
        r5.agregarIngrediente("albahaca");
        r5.agregarPaso("1. Cocinar la pasta en agua hirviendo");
        r5.agregarPaso("2. Preparar salsa con tomate y ajo");
        r5.agregarPaso("3. Mezclar pasta con salsa");
        r5.agregarPaso("4. Decorar con albahaca fresca");
        recetas.insertar(r5);

        // Receta 6: Arepas con queso
        Receta r6("Arepas con queso", "desayuno");
        r6.agregarIngrediente("harina de maiz");
        r6.agregarIngrediente("queso");
        r6.agregarIngrediente("mantequilla");
        r6.agregarIngrediente("sal");
        r6.agregarPaso("1. Mezclar la harina con agua, sal y mantequilla derretida");
        r6.agregarPaso("2. Formar las arepas y cocinarlas en una plancha caliente");
        r6.agregarPaso("3. Abrir por la mitad y rellenar con queso");
        recetas.insertar(r6);

        // Receta 7: Batido de frutas
        Receta r7("Batido de frutas", "bebida");
        r7.agregarIngrediente("leche");
        r7.agregarIngrediente("banana");
        r7.agregarIngrediente("fresa");
        r7.agregarIngrediente("azucar");
        r7.agregarPaso("1. Pelar las frutas y cortarlas en trozos");
        r7.agregarPaso("2. Colocar en la licuadora junto con la leche y el azucar");
        r7.agregarPaso("3. Licuar hasta obtener una mezcla homogenea");
        recetas.insertar(r7);

        // Receta 8: Omelette de verduras
        Receta r8("Omelette de verduras", "desayuno");
        r8.agregarIngrediente("huevo");
        r8.agregarIngrediente("cebolla");
        r8.agregarIngrediente("pimenton");
        r8.agregarIngrediente("tomate");
        r8.agregarPaso("1. Batir los huevos con sal al gusto");
        r8.agregarPaso("2. Sofreir las verduras picadas en una sarten");
        r8.agregarPaso("3. Agregar los huevos y cocinar hasta que cuaje");
        recetas.insertar(r8);

        // Receta 9: Lentejas guisadas
        Receta r9("Lentejas guisadas", "plato principal");
        r9.agregarIngrediente("lentejas");
        r9.agregarIngrediente("zanahoria");
        r9.agregarIngrediente("cebolla");
        r9.agregarIngrediente("ajo");
        r9.agregarIngrediente("tomate");
        r9.agregarPaso("1. Remojar las lentejas por una hora");
        r9.agregarPaso("2. Sofreir ajo, cebolla y tomate");
        r9.agregarPaso("3. Agregar las lentejas y cocinar hasta que esten blandas");
        recetas.insertar(r9);

        // Receta 10: Tostadas francesas
        Receta r10("Tostadas francesas", "desayuno");
        r10.agregarIngrediente("pan");
        r10.agregarIngrediente("huevo");
        r10.agregarIngrediente("leche");
        r10.agregarIngrediente("azucar");
        r10.agregarPaso("1. Batir el huevo con la leche y el azucar");
        r10.agregarPaso("2. Remojar las rebanadas de pan en la mezcla");
        r10.agregarPaso("3. Dorar en una sarten con mantequilla");
        recetas.insertar(r10);

        Receta r11("Caldo de costilla", "sopa");
        r11.agregarIngrediente("costilla");
        r11.agregarIngrediente("papa");
        r11.agregarIngrediente("cebolla");
        r11.agregarIngrediente("ajo");
        r11.agregarIngrediente("sal");
        r11.agregarPaso("1. Hervir agua y agregar la costilla.");
        r11.agregarPaso("2. Añadir papa, cebolla y ajo.");
        r11.agregarPaso("3. Cocinar a fuego medio hasta ablandar la carne.");
        recetas.insertar(r11);

        Receta r12("Arequipe casero", "postre");
        r12.agregarIngrediente("leche");
        r12.agregarIngrediente("azucar");
        r12.agregarIngrediente("bicarbonato");
        r12.agregarPaso("1. Calentar la leche con azucar y bicarbonato.");
        r12.agregarPaso("2. Revolver hasta que espese y tomar color caramelo.");
        recetas.insertar(r12);

        Receta r13("Bandeja paisa", "plato principal");
        r13.agregarIngrediente("arroz");
        r13.agregarIngrediente("carne molida");
        r13.agregarIngrediente("frijoles rojos");
        r13.agregarIngrediente("aguacate");
        r13.agregarIngrediente("huevo");
        r13.agregarIngrediente("arepa");
        recetas.insertar(r13);

        Receta r14("Chocolate con queso", "bebida");
        r14.agregarIngrediente("chocolate");
        r14.agregarIngrediente("leche");
        r14.agregarIngrediente("queso");
        recetas.insertar(r14);

        Receta r15("Empanadas de carne", "pasabocas");
        r15.agregarIngrediente("harina de maiz");
        r15.agregarIngrediente("carne molida");
        r15.agregarIngrediente("papa");
        r15.agregarIngrediente("cebolla");
        r15.agregarIngrediente("ajo");
        recetas.insertar(r15);

        
        // Configurar relaciones entre ingredientes (sustituciones)
        relacionesIngredientes.agregarRelacion("limon", "vinagre");
        relacionesIngredientes.agregarRelacion("pollo", "pavo");
        relacionesIngredientes.agregarRelacion("pollo", "carne");
        relacionesIngredientes.agregarRelacion("papa", "yuca");
        relacionesIngredientes.agregarRelacion("arroz", "pasta");
        relacionesIngredientes.agregarRelacion("cebolla", "cebollin");
        relacionesIngredientes.agregarRelacion("leche", "crema");
        relacionesIngredientes.agregarRelacion("mantequilla", "aceite");
        relacionesIngredientes.agregarRelacion("zanahoria", "calabaza");
        relacionesIngredientes.agregarRelacion("harina de maiz", "harina de trigo");
        relacionesIngredientes.agregarRelacion("queso", "queso rallado");
        relacionesIngredientes.agregarRelacion("fresa", "mora");
        relacionesIngredientes.agregarRelacion("banana", "mango");
        relacionesIngredientes.agregarRelacion("huevo", "claras de huevo");
        relacionesIngredientes.agregarRelacion("pimenton", "aji");
        relacionesIngredientes.agregarRelacion("lentejas", "frijoles");
        relacionesIngredientes.agregarRelacion("azucar", "miel");
        relacionesIngredientes.agregarRelacion("mantequilla", "margarina");
        relacionesIngredientes.agregarRelacion("leche", "bebida vegetal");
        relacionesIngredientes.agregarRelacion("costilla", "carne de res");
        relacionesIngredientes.agregarRelacion("carne molida", "pollo");
        relacionesIngredientes.agregarRelacion("chocolate", "cacao");
        relacionesIngredientes.agregarRelacion("arequipe", "dulce de leche");
        relacionesIngredientes.agregarRelacion("frijoles rojos", "lentejas");
        relacionesIngredientes.agregarRelacion("aguacate", "mantequilla");
        relacionesIngredientes.agregarRelacion("arepa", "pan");
        relacionesIngredientes.agregarRelacion("bicarbonato", "polvo de hornear");
        relacionesIngredientes.agregarRelacion("queso", "queso rallado");
        relacionesIngredientes.agregarRelacion("maiz", "harina de maiz");
    }


public:
    SistemaRecomendacion() {
        cargarRecetasPredeterminadas();
    }
    
    void ingresarIngredientes() {
        ingredientesDisponibles.limpiar();
    
        InterfazConsola::limpiar();
        InterfazConsola::titulo("🥕  INGRESO DE INGREDIENTES DISPONIBLES  🥕");
        InterfazConsola::linea();
    
        cout << "\n📝  Escribe los ingredientes que tienes uno por línea.\n";
        cout << "👉  Escribe ";
        InterfazConsola::color(14);
        cout << "'fin'";
        InterfazConsola::color(7);
        cout << " cuando termines.\n\n";
    
        string ingrediente;
        int contador = 0;
    
        // Lista visual en tiempo real
        cout << "📦  Ingredientes registrados:\n\n";
    
        while (true) {
            InterfazConsola::color(11);
            cout << " ➤ Ingrediente " << (contador + 1) << ": ";
            InterfazConsola::color(7);
    
            getline(cin, ingrediente);
    
            // Normalizar
            transform(ingrediente.begin(), ingrediente.end(), ingrediente.begin(), ::tolower);
    
            if (ingrediente == "fin")
                break;
    
            if (ingrediente.empty() || ingrediente.find_first_not_of(' ') == string::npos) {
                InterfazConsola::mensajeError("El ingrediente no puede estar vacío.");
                continue;
            }
    
            if (ingredientesDisponibles.contiene(ingrediente)) {
                InterfazConsola::mensajeError("Ingrediente duplicado. No se agregó.");
                continue;
            }
    
            // Agregar
            ingredientesDisponibles.agregar(Ingrediente(ingrediente));
            contador++;
    
            // Mostrar en lista
            InterfazConsola::itemLista("• " + ingrediente, true);
            cout << "\n";
        }
    
        cout << "\n───────────────────────────────────────────────────────────────\n";
        InterfazConsola::mensajeOK("Se han registrado " + to_string(contador) + " ingredientes.");
    
        cout << "\n📦 Ingredientes finales:\n\n";
    
        for (auto& ing : ingredientesDisponibles.obtenerTodos())
            InterfazConsola::itemLista("• " + ing, true);
    
        cout << "\n";
    }
    
    void verRecetasSugeridas() {
    if (ingredientesDisponibles.estaVacia()) {
        InterfazConsola::mensajeError("Primero debe ingresar sus ingredientes disponibles.");
        return;
    }

    InterfazConsola::limpiar();
    InterfazConsola::titulo("📋  RECETAS SUGERIDAS SEGÚN TUS INGREDIENTES  📋");
    InterfazConsola::linea();

    vector<string> misIngredientes = ingredientesDisponibles.obtenerTodos();

    // Mostrar ingredientes disponibles
    cout << "\n🛒  Ingredientes disponibles:\n\n";
    for (auto& ing : misIngredientes) {
        InterfazConsola::itemLista("• " + ing, true);
    }

    cout << "\n───────────────────────────────────────────────────────────────\n";
    cout << "Buscando recetas...\n\n";

    auto resultados = recetas.buscarRecetas(ingredientesDisponibles);

    if (resultados.empty()) {
        cout << "\n❌ No se encontraron recetas con los ingredientes disponibles.\n\n";
        return;
    }

    cout << "✅ Se encontraron " << resultados.size() << " recetas compatibles:\n\n";

    int num = 1;

    for (const auto& par : resultados) {
        Receta* receta = par.first;
        double coincidencia = par.second;

        // Encabezado de receta
        InterfazConsola::color(14);
        cout << "🍽️  " << num++ << ") " << receta->getNombre() << "\n";
        InterfazConsola::color(7);

        // Porcentaje
        cout << "   ";
        InterfazConsola::color(11);
        cout << fixed << setprecision(0) << coincidencia << "% coincidencia\n";
        InterfazConsola::color(7);

        // Obtener faltantes
        vector<string> faltantes = receta->obtenerFaltantes(ingredientesDisponibles);

        // Obtener ingredientes disponibles de la receta
        vector<string> disponiblesEnReceta;
        for (const auto& ing : receta->getIngredientes()) {
            bool esFaltante = false;
            for (const auto& f : faltantes) {
                if (f == ing) { esFaltante = true; break; }
            }
            if (!esFaltante) disponiblesEnReceta.push_back(ing);
        }

        // Mostrar ingredientes disponibles
        if (!disponiblesEnReceta.empty()) {
            InterfazConsola::color(10);
            cout << "   ✅ Ingredientes disponibles:\n";
            InterfazConsola::color(7);
            for (const auto& ing : disponiblesEnReceta)
                InterfazConsola::itemLista("• " + ing, true);
            cout << "\n";
        }

        // Mostrar ingredientes faltantes
        if (!faltantes.empty()) {
            InterfazConsola::color(12);
            cout << "   ❌ Ingredientes faltantes:\n";
            InterfazConsola::color(7);
            for (auto& f : faltantes)
                InterfazConsola::itemLista("• " + f, false);
            cout << "\n";
        } else {
            // Si no hay faltantes, mensaje de receta completa
            InterfazConsola::color(10);
            cout << "   ✅ Puedes preparar esta receta completamente.\n\n";
            InterfazConsola::color(7);
        }

        InterfazConsola::linea();
        cout << "\n";
    }
}
    void verAlternativas() {
        if (ingredientesDisponibles.estaVacia()) {
            InterfazConsola::mensajeError("Primero debe ingresar sus ingredientes disponibles.");
            return;
        }
    
        auto resultados = recetas.buscarRecetas(ingredientesDisponibles);
    
        if (resultados.empty()) {
            InterfazConsola::mensajeInfo("No hay recetas suficientes para sugerir alternativas.");
            return;
        }
    
        InterfazConsola::limpiar();
        InterfazConsola::titulo("🔄  SUSTITUCIONES Y ALTERNATIVAS DE INGREDIENTES  🔄");
        InterfazConsola::linea();
    
        bool hayAlternativas = false;
    
        cout << "\n📌 Análisis de recetas y sus posibles sustituciones:\n\n";
    
        for (const auto& par : resultados) {
            Receta* receta = par.first;
            double coincidencia = par.second;
    
            if (coincidencia == 100) continue;
    
            vector<string> faltantes = receta->obtenerFaltantes(ingredientesDisponibles);
            vector<string> alternativas = relacionesIngredientes.sugerirAlternativas(faltantes);
    
            // Mostrar solo recetas con faltantes
            if (!faltantes.empty()) {
                hayAlternativas = true;
    
                // Mostrar nombre de receta
                InterfazConsola::color(14);
                cout << "🍽️  " << receta->getNombre() << "\n";
                InterfazConsola::color(7);
                cout << "   (" << fixed << setprecision(0) << coincidencia << "% de coincidencia)\n\n";
    
                // Ingredientes faltantes
                InterfazConsola::color(12);
                cout << "   ❌ Ingredientes faltantes:\n";
                InterfazConsola::color(7);
    
                for (const auto& f : faltantes)
                    InterfazConsola::itemLista("• " + f, false);
    
                cout << "\n";
    
                // Alternativas disponibles
                if (!alternativas.empty()) {
                    InterfazConsola::color(11);
                    cout << "   🔁 Posibles sustitutos:\n";
                    InterfazConsola::color(7);
    
                    for (const auto& alt : alternativas)
                        InterfazConsola::itemLista("• " + alt, true);
    
                    cout << "\n";
                } else {
                    InterfazConsola::color(8);
                    cout << "   (No se encontraron sustitutos para esta receta)\n\n";
                    InterfazConsola::color(7);
                }
    
                InterfazConsola::linea();
                cout << "\n";
            }
        }
    
        if (!hayAlternativas) {
            InterfazConsola::mensajeOK("🎉 Todas tus recetas tienen 100% coincidencia. No se necesitan sustitutos.");
        }
    }
    
    void verPasosReceta() {
        if (ingredientesDisponibles.estaVacia()) {
            InterfazConsola::mensajeError("Primero debe ingresar sus ingredientes disponibles.");
            return;
        }
    
        auto resultados = recetas.buscarRecetas(ingredientesDisponibles);
    
        if (resultados.empty()) {
            InterfazConsola::mensajeError("No hay recetas disponibles.");
            return;
        }
    
        InterfazConsola::limpiar();
        InterfazConsola::titulo("👨‍🍳  SELECCIONAR RECETA PARA VER LOS PASOS  👨‍🍳");
        InterfazConsola::linea();
    
        // Mostrar lista numerada profesional
        cout << "\n📋  Recetas encontradas:\n\n";
    
        for (size_t i = 0; i < resultados.size(); i++) {
            cout << "   ";
            InterfazConsola::color(14);
            cout << (i + 1) << ") ";
            InterfazConsola::color(11);
            cout << resultados[i].first->getNombre() << "\n";
            InterfazConsola::color(7);
        }
    
        cout << "\n───────────────────────────────────────────────────────────────\n";
        cout << "Seleccione el número de la receta: ";
    
        int opcion;
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            InterfazConsola::mensajeError("Entrada inválida. Debe ingresar un número.");
            return;
        }
    
        if (opcion < 1 || opcion > (int)resultados.size()) {
            InterfazConsola::mensajeError("Opción inválida.");
            return;
        }
    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
        Receta* receta = resultados[opcion - 1].first;
        receta->incrementarUso();
    
        // Pantalla de pasos
        InterfazConsola::limpiar();
        InterfazConsola::titulo("🍽️  " + receta->getNombre());
        InterfazConsola::linea();
    
        // Ingredientes
        cout << "\n🛒  INGREDIENTES NECESARIOS:\n\n";
    
        for (const auto& ing : receta->getIngredientes()) {
            bool disponible = ingredientesDisponibles.contiene(ing);
            InterfazConsola::itemLista(ing, disponible);
        }
    
        cout << "\n👨‍🍳  PASOS DE PREPARACIÓN:\n\n";
    
        int numPaso = 1;
        for (const auto& paso : receta->getPasos()) {
            InterfazConsola::color(11);
            cout << "   🔸 Paso " << numPaso++ << ": ";
            InterfazConsola::color(7);
            cout << paso << "\n\n";
        }
    
        // Información final
        InterfazConsola::color(10);
        cout << "\n📌 Esta receta se ha preparado ";
        InterfazConsola::color(14);
        cout << receta->getVecesUsada();
        InterfazConsola::color(10);
        cout << " veces.\n";
        InterfazConsola::color(7);
    }
    
};




