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

```text
=============================================================
        SISTEMA INTELIGENTE DE RECOMENDACIONES DE RECETAS
=============================================================

[ MENÚ PRINCIPAL ]
-------------------------------------------------------------
1. Ingresar ingredientes disponibles
2. Ver recetas sugeridas
3. Ver alternativas (sustituciones)
4. Ver pasos de una receta
0. Salir
-------------------------------------------------------------
Seleccione una opción: 1


=============================================================
        INGRESAR INGREDIENTES DISPONIBLES
=============================================================

Ingrese los ingredientes que tiene (uno por línea).
Escriba 'fin' cuando termine.

Ingrediente 1: arroz
Ingrediente 2: pollo
Ingrediente 3: ajo
Ingrediente 4: aceite
Ingrediente 5: fin

[OK] Se han registrado 4 ingredientes.


=============================================================
        RECETAS SUGERIDAS
=============================================================

Ingredientes disponibles: arroz, pollo, ajo, aceite

 1. Arroz con pollo ............... (80% coincidencia)
      Faltan: cebolla

 2. Pollo al horno ................ (75% coincidencia)
      Faltan: limón

 3. Pasta con tomate .............. (40% coincidencia)
      Faltan: pasta, tomate, albahaca

 4. Ensalada César ................ (25% coincidencia)
      Faltan: lechuga, queso, pan

Seleccione una opción: 3


=============================================================
        SUSTITUCIONES E INGREDIENTES ALTERNATIVOS
=============================================================

→ Arroz con pollo
     Ingredientes faltantes: cebolla
     Posibles sustitutos: cebollín

→ Pollo al horno
     Ingredientes faltantes: limón
     Posibles sustitutos: vinagre

→ Pasta con tomate
     Ingredientes faltantes: pasta, tomate, albahaca
     Posibles sustitutos: arroz

Seleccione una opción: 4


=============================================================
        SELECCIONAR RECETA
=============================================================

Recetas disponibles:
 1. Arroz con pollo
 2. Pollo al horno
 3. Pasta con tomate
 4. Ensalada César

Seleccione el número de la receta: 1


=============================================================
        Arroz con pollo
=============================================================

INGREDIENTES NECESARIOS:
  [OK] arroz
  [OK] pollo
  [X] cebolla
  [OK] ajo
  [OK] aceite

PASOS DE PREPARACIÓN:
  1. Cortar el pollo en trozos medianos.
  2. Picar la cebolla y el ajo finamente.
  3. Sofreír el pollo con cebolla y ajo.
  4. Agregar el arroz y agua.
  5. Cocinar hasta que el arroz esté listo.

[OK] Esta receta se ha preparado 1 vez.


=============================================================
        SALIDA DEL SISTEMA
=============================================================

Seleccione una opción: 5

Gracias por preferirnos. ¡Hasta pronto!
```
---

## 🧱 Requisitos técnicos

- **Lenguaje:** C++17 o superior  
- **Compilador recomendado:** `g++`  
- **Sistema operativo:** Windows, Linux o macOS  
- **Entorno sugerido:** Visual Studio Code, Code::Blocks, o cualquier IDE compatible con C++

---

## 👨‍💻 Autores:

- Samuel Correa Velasquez  
- Yan Frank Ríos López   
- Andrés Felipe Eusse Chavarria  
- Julieth Jhosiris Daza Villada


