// Nombre del archivo: SistemaRecomendacion.h
#pragma once

// Incluye todas las estructuras de datos
#include "ListaEnlazada.h"
#include "ArbolBST.h"
#include "Grafo.h"

// Incluye todas las librerías estándar necesarias
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm> // Para transform
#include <iomanip>   // Para setprecision
#include <sstream>
#include <limits>    // Para numeric_limits
#include <stdexcept> // Para invalid_argument

using namespace std;

// ==================== SISTEMA DE RECOMENDACIÓN ====================
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
    }

public:
    SistemaRecomendacion() {
        cargarRecetasPredeterminadas();
    }
    
    void ingresarIngredientes() {
        ingredientesDisponibles.limpiar();
        
        mostrarLinea();
        cout << "  INGRESAR INGREDIENTES DISPONIBLES" << endl;
        mostrarLinea();
        cout << "\nIngrese los ingredientes que tiene (uno por linea)." << endl;
        cout << "Escriba 'fin' cuando termine.\n" << endl;
        
        string ingrediente;
        int contador = 0;
        
        // Limpiar el buffer de entrada antes de usar getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        while (true) {
            cout << "Ingrediente " << (contador + 1) << ": " << flush;
            getline(cin, ingrediente);
            
            if (ingrediente == "fin" || ingrediente == "FIN") break;
            
            if (!ingrediente.empty()) {
                // Convertir a minusculas
                transform(ingrediente.begin(), ingrediente.end(), 
                          ingrediente.begin(), ::tolower);
                // Validaciones con excepciones
                try {
                    if (ingrediente.find_first_not_of(' ') == string::npos) {
                        throw invalid_argument("El ingrediente no puede ser solo espacios.");
                    }
                    if (ingredientesDisponibles.contiene(ingrediente)) {
                        throw invalid_argument("Ingrediente duplicado. No se agrego.");
                    }
                    Ingrediente ing(ingrediente);
                    ingredientesDisponibles.agregar(ing);
                    contador++;
                } catch (const invalid_argument& e) {
                    cout << "[ERROR] " << e.what() << endl;
                }
            } else {
                cout << "[ERROR] No se aceptan cadenas vacias." << endl;
            }
        }
        
        cout << "\n[OK] Se han registrado " << contador << " ingredientes.\n" << endl;
    }
    
    void verRecetasSugeridas() {
        if (ingredientesDisponibles.estaVacia()) {
            cout << "\n[ERROR] Primero debe ingresar sus ingredientes disponibles.\n" << endl;
            return;
        }
        
        mostrarLinea();
        cout << "  RECETAS SUGERIDAS" << endl;
        mostrarLinea();
        
        vector<string> misIngredientes = ingredientesDisponibles.obtenerTodos();
        cout << "\nIngredientes disponibles: ";
        for (size_t i = 0; i < misIngredientes.size(); i++) {
            cout << misIngredientes[i];
            if (i < misIngredientes.size() - 1) cout << ", ";
        }
        cout << "\n" << endl;
        
        auto resultados = recetas.buscarRecetas(ingredientesDisponibles);
        
        if (resultados.empty()) {
            cout << "No se encontraron recetas con los ingredientes disponibles.\n" << endl;
            return;
        }
        
        int num = 1;
        for (const auto& par : resultados) {
            Receta* receta = par.first;
            double coincidencia = par.second;
            
            cout << num++ << ". " << receta->getNombre() 
                 << " (" << fixed << setprecision(0) << coincidencia 
                 << "% coincidencia)" << endl;
            
            if (coincidencia < 100) {
                vector<string> faltantes = receta->obtenerFaltantes(ingredientesDisponibles);
                cout << "   Faltan: ";
                for (size_t i = 0; i < faltantes.size(); i++) {
                    cout << faltantes[i];
                    if (i < faltantes.size() - 1) cout << ", ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    
    void verAlternativas() {
        if (ingredientesDisponibles.estaVacia()) {
            cout << "\n[ERROR] Primero debe ingresar sus ingredientes disponibles.\n" << endl;
            return;
        }
        
        mostrarLinea();
        cout << "  SUSTITUCIONES E INGREDIENTES ALTERNATIVOS" << endl;
        mostrarLinea();
        
        auto resultados = recetas.buscarRecetas(ingredientesDisponibles);
        
        if (resultados.empty()) {
            cout << "\nNo hay recetas para analizar alternativas.\n" << endl;
            return;
        }
        
        bool hayAlternativas = false;
        
        for (const auto& par : resultados) {
            Receta* receta = par.first;
            double coincidencia = par.second;
            
            if (coincidencia < 100) {
                vector<string> faltantes = receta->obtenerFaltantes(ingredientesDisponibles);
                vector<string> alternativas = relacionesIngredientes.sugerirAlternativas(faltantes);
                
                if (!alternativas.empty()) {
                    if (!hayAlternativas) {
                        cout << "\n";
                        hayAlternativas = true;
                    }
                    
                    cout << "-> " << receta->getNombre() << endl;
                    cout << "   Ingredientes faltantes: ";
                    for (size_t i = 0; i < faltantes.size(); i++) {
                        cout << faltantes[i];
                        if (i < faltantes.size() - 1) cout << ", ";
                    }
                    cout << endl;
                    
                    cout << "   Posibles sustitutos: ";
                    for (size_t i = 0; i < alternativas.size(); i++) {
                        cout << alternativas[i];
                        if (i < alternativas.size() - 1) cout << ", ";
                    }
                    cout << "\n" << endl;
                }
            }
        }
        
        if (!hayAlternativas) {
            cout << "\n[OK] No se encontraron sustituciones para los ingredientes faltantes, o ya tienes recetas al 100%.\n" << endl;
        }
    }
    
    void verPasosReceta() {
        if (ingredientesDisponibles.estaVacia()) {
            cout << "\n[ERROR] Primero debe ingresar sus ingredientes disponibles.\n" << endl;
            return;
        }
        
        auto resultados = recetas.buscarRecetas(ingredientesDisponibles);
        
        if (resultados.empty()) {
            cout << "\nNo hay recetas disponibles.\n" << endl;
            return;
        }
        
        mostrarLinea();
        cout << "  SELECCIONAR RECETA" << endl;
        mostrarLinea();
        
        cout << "\nRecetas disponibles:\n" << endl;
        for (size_t i = 0; i < resultados.size(); i++) {
            cout << (i + 1) << ". " << resultados[i].first->getNombre() << endl;
        }
        
        cout << "\nSeleccione el numero de la receta: ";
        int opcion;
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n[ERROR] Entrada invalida. Debe ingresar un numero.\n" << endl;
            return;
        }
        
        // Limpiar buffer después de leer número
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opcion < 1 || opcion > (int)resultados.size()) {
            cout << "\n[ERROR] Opcion invalida.\n" << endl;
            return;
        }
        
        Receta* receta = resultados[opcion - 1].first;
        receta->incrementarUso();
        
        mostrarLinea();
        cout << "  " << receta->getNombre() << endl;
        mostrarLinea();
        
        cout << "\nINGREDIENTES NECESARIOS:" << endl;
        auto ings = receta->getIngredientes();
        for (const auto& ing : ings) {
            bool disponible = ingredientesDisponibles.contiene(ing);
            cout << "   " << (disponible ? "[OK]" : "[X]") << " " << ing << endl;
        }
        
        cout << "\nPASOS DE PREPARACION:" << endl;
        auto pasos = receta->getPasos();
        for (const auto& paso : pasos) {
            cout << " " << paso << endl;
        }
        
        cout << "\n[OK] Esta receta se ha preparado " << receta->getVecesUsada() 
             << " veces.\n" << endl;
    }
};
