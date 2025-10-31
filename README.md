# 🍽️ Sistema Inteligente de Recomendación de Recetas

## 📋 Descripción general
Este proyecto implementa un **sistema inteligente de recomendaciones de recetas** basado en los ingredientes que el usuario tiene en casa.  
Su objetivo es **optimizar el tiempo de decisión en la cocina** y **reducir el desperdicio de alimentos**, utilizando **estructuras de datos** vistas en el curso de *Estructura de Datos y Algoritmos*.

El sistema permite:
- Ingresar los ingredientes disponibles en casa.  
- Consultar recetas posibles según los ingredientes disponibles.  
- Ver alternativas de sustitución si faltan ingredientes.  
- Ver los pasos detallados para preparar cada receta.  

---

## 🧠 Objetivo del proyecto
Desarrollar una aplicación por consola que integre estructuras de datos dinámicas para resolver un problema real de optimización y búsqueda:

> “¿Qué puedo cocinar con lo que tengo?”

---

## ⚙️ Estructuras de datos utilizadas

| Estructura | Uso en el sistema |
|-------------|------------------|
| **Lista enlazada** | Almacena dinámicamente los ingredientes que el usuario tiene disponibles. |
| **Árbol binario de búsqueda (BST)** | Organiza las recetas por nombre y permite buscar coincidencias eficientemente según los ingredientes del usuario. |
| **Grafo no dirigido** | Representa relaciones entre ingredientes para sugerir sustitutos o alternativas. |

---

## 🧩 Componentes principales del código

1. **Clase `Ingrediente`**  
   Representa un ingrediente con nombre y categoría.

2. **Clase `ListaEnlazada`**  
   Implementa una lista simple para guardar los ingredientes ingresados por el usuario.

3. **Clase `Receta`**  
   Contiene nombre, lista de ingredientes, pasos y categoría.

4. **Clase `NodoArbol` y `ArbolBST`**  
   Implementan el árbol binario de búsqueda para almacenar las recetas y calcular coincidencias.

5. **Clase `Grafo`**  
   Contiene las relaciones de sustitución entre ingredientes.

6. **Clase `SistemaRecomendacion`**  
   Integra todos los módulos, maneja el menú principal y la lógica de interacción con el usuario.

---

## 🖥️ Funcionalidades principales

1. **Ingresar ingredientes disponibles**  
   El usuario ingresa uno por uno los ingredientes que tiene.  
   Se almacenan en una **lista enlazada dinámica**.

2. **Ver recetas sugeridas**  
   El sistema busca recetas en el **árbol BST** y calcula el porcentaje de coincidencia con los ingredientes disponibles.

3. **Ver alternativas**  
   Si una receta tiene ingredientes faltantes, el sistema utiliza el **grafo** para sugerir sustitutos posibles.

4. **Ver pasos de una receta**  
   Permite ver el paso a paso detallado de una receta seleccionada.

---

## 🧪 Ejemplo de uso

====== MENU PRINCIPAL ======

1. Ingresar ingredientes disponibles
2. Ver recetas sugeridas
3. Ver alternativas
4.Ver pasos de una receta
5.Salir

Seleccione una opción: 1

Ingrese los ingredientes que tiene (uno por línea)
Escriba 'fin' cuando termine.

Ingrediente 1: arroz
Ingrediente 2: pollo
Ingrediente 3: fin

[OK] Se han registrado 2 ingredientes.

====== MENU PRINCIPAL ======
Seleccione una opción: 2
Receta sugerida: Arroz con pollo (100% coincidencia)

---

## 🧱 Requisitos técnicos

- **Lenguaje:** C++17 o superior  
- **Compilador recomendado:** `g++`  
- **Sistema operativo:** Windows, Linux o macOS  
- **Entorno sugerido:** Visual Studio Code, Code::Blocks, o cualquier IDE compatible con C++

---

## 🚀 Compilación y ejecución

1. Compila el código:
   ```bash
   g++ main.cpp -o recetas

---

## 👨‍💻 Autores:

Samuel Correa Velasquez
Yan Frank Ríos López

