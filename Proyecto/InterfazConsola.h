#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class InterfazConsola {
public:

    // ANSI colors (mejores que los de Windows)
    static void color(int c) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }

    static void limpiar() {
        system("cls");
    }

    static void titulo(const string& texto) {
        limpiar();
        color(14);
    
        const int width = 62;
        int pad = (width - (int)texto.size()) / 2;
    
        cout << "\n\n";
        cout << "╔══════════════════════════════════════════════════════════════╗\n";
        cout << "║";
    
        if (pad > 0) {
            cout << string(pad, ' ') << texto 
                << string(width - pad - (int)texto.size(), ' ');
        } else {
            // Si el texto es demasiado largo (por emojis), lo mostramos normal
            cout << texto << string(max(0, width - (int)texto.size()), ' ');
        }
    
        cout << "║\n";
        cout << "╚══════════════════════════════════════════════════════════════╝\n";
    
        color(7);
        cout << "\n";
    }

    static void linea() {
        color(8);
        cout << "───────────────────────────────────────────────────────────────\n";
        color(7);
    }

    static void menuOpcion(int numero, string texto) {
        color(11);
        cout << "   [" << numero << "] ";
        color(7);
        cout << texto << "\n";
    }

    static void mensajeOK(const string& texto) {
        color(10);
        cout << " ✅ " << texto << "\n";
        color(7);
    }

    static void mensajeError(const string& texto) {
        color(12);
        cout << " ❌ " << texto << "\n";
        color(7);
    }

    static void mensajeInfo(const string& texto) {
        color(11);
        cout << " 💡 " << texto << "\n";
        color(7);
    }

    static void esperar() {
        color(8);
        cout << "\n Presiona ENTER para continuar...";
        color(7);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Para listas bonitas
    static void itemLista(const string& texto, bool ok = true) {
        if (ok) { color(10); cout << "   ✔ "; }
        else    { color(12); cout << "   ✘ "; }
        color(7);
        cout << texto << "\n";
    }
};
