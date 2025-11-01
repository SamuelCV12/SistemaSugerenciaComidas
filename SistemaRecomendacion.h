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
    
    // Este es el método que controla todo el flujo del programa
    void mostrarMenu() {
        int opcion;
        
        do {
            mostrarLinea('=', 65);
            cout << "   SISTEMA INTELIGENTE DE RECOMENDACIONES DE RECETAS" << endl;
            mostrarLinea('=', 65);
            cout << "\n1. Ingresar ingredientes disponibles" << endl;
            cout << "2. Ver recetas sugeridas" << endl;
            cout << "3. Ver alternativas (sustituciones)" << endl;
            cout << "4. Ver pasos de una receta" << endl;
            cout << "0. Salir" << endl;
            mostrarLinea('-', 65);
            cout << "\nSeleccione una opcion: ";
            
            // Validacion segura de entrada numerica
            if (!(cin >> opcion)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n[ERROR] Entrada invalida. Debe ingresar un numero.\n" << endl;
                opcion = -1; // Asigna un valor inválido para repetir el bucle
            } else {
                cout << endl;
                // Procesar opcion
                switch (opcion) {
                    case 1:
                        ingresarIngredientes();
                        break;
                    case 2:
                        verRecetasSugeridas();
                        break;
                    case 3:
                        verAlternativas();
                        break;
                    case 4:
                        verPasosReceta();
                        break;
                    case 0:
                        cout << "Gracias por usar el sistema. Buen provecho!\n" << endl;
                        break;
                    default:
                        cout << "[ERROR] Opcion no valida. Intente nuevamente.\n" << endl;
                }
            }
            
            if (opcion != 0) {
                cout << "\nPresione Enter para continuar...";
                // cin.get() espera a que el usuario presione Enter
                // Necesita un ignore() antes si la operación anterior fue 'cin >>'
                // pero como todas nuestras funciones limpian el buffer o usan getline
                // o terminan con un cin.ignore(), cin.get() debería funcionar solo.
                // Para estar seguros, limpiamos el buffer residual de 'cin >> opcion'
                // que NO fue limpiado si la opción fue 2, 3, o 4.
                
                // Si la última operación NO fue 'ingresarIngredientes' o 'verPasosReceta'
                // (que ya limpian el buffer), lo limpiamos aquí.
                if(opcion != 1) {
                   cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.get();
                cout << "\n\n";
            }
            
        } while (opcion != 0);
    }
};