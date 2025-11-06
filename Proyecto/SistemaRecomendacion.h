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
       // Receta 1: Arroz con pollo (detallado)
        Receta r1("Arroz con pollo", "plato principal");
        r1.agregarIngrediente("arroz");
        r1.agregarIngrediente("pollo");
        r1.agregarIngrediente("cebolla");
        r1.agregarIngrediente("ajo");
        r1.agregarIngrediente("aceite");
        r1.agregarIngrediente("pimiento");       
        r1.agregarIngrediente("zanahoria");       
        r1.agregarIngrediente("guisantes");       
        r1.agregarIngrediente("sal");
        r1.agregarIngrediente("pimienta");
        // Pasos de Preparacion
        r1.agregarPaso("1. Lavar y cortar el pollo en trozos medianos.");
        r1.agregarPaso("2. Sazonar el pollo con sal y pimienta al gusto y dejar reposar 10 minutos.");
        r1.agregarPaso("3. Picar finamente la cebolla, el ajo, el pimiento y la zanahoria.");
        r1.agregarPaso("4. Calentar aceite en una sartén grande o cazuela y sofreír la cebolla y el ajo hasta que estén transparentes.");
        r1.agregarPaso("5. Agregar el pollo y dorarlo por todos lados, asegurándose de sellar los jugos.");
        r1.agregarPaso("6. Añadir el pimiento y la zanahoria, y cocinar 3-4 minutos más hasta que estén ligeramente tiernos.");
        r1.agregarPaso("7. Incorporar el arroz crudo y mezclar bien con el sofrito y el pollo, dejando que los granos se impregnen del aceite.");
        r1.agregarPaso("8. Verter agua o caldo de pollo caliente hasta cubrir el arroz (aproximadamente el doble del volumen de arroz).");
        r1.agregarPaso("9. Llevar a ebullición, luego reducir el fuego a bajo, tapar y cocinar 15-20 minutos o hasta que el arroz esté tierno y el líquido se haya absorbido.");
        r1.agregarPaso("10. Si se desea, agregar guisantes y mezclar suavemente, dejando que se cocinen 2-3 minutos más.");
        r1.agregarPaso("11. Probar de sal y pimienta, ajustar si es necesario.");
        r1.agregarPaso("12. Apagar el fuego y dejar reposar 5 minutos antes de servir para que los sabores se integren.");
        recetas.insertar(r1);
        
        // Receta 2: Pollo al horno (detallado)
        Receta r2("Pollo al horno", "plato principal");
        r2.agregarIngrediente("pollo");
        r2.agregarIngrediente("limon");
        r2.agregarIngrediente("ajo");
        r2.agregarIngrediente("aceite");
        r2.agregarIngrediente("sal");
        r2.agregarIngrediente("pimienta");
        r2.agregarIngrediente("romero");     // opcional
        r2.agregarIngrediente("paprika");    // opcional
        // Pasos de Preparacion
        r2.agregarPaso("1. Precalentar el horno a 180°C (350°F).");
        r2.agregarPaso("2. Lavar y secar el pollo con papel absorbente.");
        r2.agregarPaso("3. Exprimir el limón y mezclar el jugo con ajo picado, aceite, sal, pimienta y paprika.");
        r2.agregarPaso("4. Untar el pollo con la mezcla, asegurándose de cubrir toda la superficie y el interior si es pollo entero.");
        r2.agregarPaso("5. Colocar el pollo en una bandeja para hornear y dejar marinar mínimo 30 minutos (puede refrigerarse por más tiempo para más sabor).");
        r2.agregarPaso("6. Insertar ramitas de romero en la bandeja o dentro del pollo para aroma (opcional).");
        r2.agregarPaso("7. Hornear el pollo en horno precalentado durante 45-60 minutos, dependiendo del tamaño, rociando con los jugos cada 15-20 minutos.");
        r2.agregarPaso("8. Verificar cocción: el pollo debe alcanzar una temperatura interna de 75°C (165°F) y los jugos deben ser claros.");
        r2.agregarPaso("9. Retirar del horno, dejar reposar 5-10 minutos antes de cortar para que los jugos se distribuyan.");
        r2.agregarPaso("10. Servir caliente acompañado de guarnición de tu preferencia.");
        recetas.insertar(r2);
        
        // Receta 3: Sopa de verduras
        Receta r3("Sopa de verduras", "sopa");
        r3.agregarIngrediente("papa");
        r3.agregarIngrediente("zanahoria");
        r3.agregarIngrediente("cebolla");
        r3.agregarIngrediente("apio");
        r3.agregarIngrediente("calabacín");      
        r3.agregarIngrediente("pimiento");       
        r3.agregarIngrediente("tomate");         
        r3.agregarIngrediente("aceite");
        r3.agregarIngrediente("sal");
        r3.agregarIngrediente("pimienta");
        r3.agregarIngrediente("ajo");           
        r3.agregarIngrediente("perejil");       

         // Pasos de preparación
        r3.agregarPaso("1. Lavar, pelar y cortar todas las verduras en trozos medianos.");
        r3.agregarPaso("2. Calentar un poco de aceite en una olla grande.");
        r3.agregarPaso("3. Sofreír la cebolla y el ajo picados hasta que estén dorados.");
        r3.agregarPaso("4. Agregar las demás verduras (papa, zanahoria, apio, calabacín, pimiento y tomate) y saltear por unos minutos.");
        r3.agregarPaso("5. Añadir suficiente agua para cubrir las verduras y llevar a ebullición.");
        r3.agregarPaso("6. Reducir el fuego y cocinar a fuego lento por 20-25 minutos o hasta que las verduras estén tiernas.");
        r3.agregarPaso("7. Sazonar con sal y pimienta al gusto.");
        r3.agregarPaso("8. Servir caliente y decorar con perejil fresco picado.");

        recetas.insertar(r3);
        
        Receta r4("Ensalada César", "ensalada");

        // Ingredientes
        r4.agregarIngrediente("lechuga");
        r4.agregarIngrediente("pollo");
        r4.agregarIngrediente("queso parmesano");   
        r4.agregarIngrediente("pan");               
        r4.agregarIngrediente("aceite de oliva");
        r4.agregarIngrediente("ajo");               
        r4.agregarIngrediente("sal");
        r4.agregarIngrediente("pimienta");
        r4.agregarIngrediente("aderezo César");    
        r4.agregarIngrediente("limón");            
        
        // Pasos de preparación
        r4.agregarPaso("1. Lavar y escurrir bien la lechuga, luego cortarla en trozos medianos.");
        r4.agregarPaso("2. Cocinar el pollo en una sartén con un poco de aceite, sal y pimienta, luego cortarlo en tiras.");
        r4.agregarPaso("3. Cortar el pan en cubos pequeños y dorarlos en una sartén con aceite y ajo hasta formar crutones crujientes.");
        r4.agregarPaso("4. Rallar el queso parmesano al gusto.");
        r4.agregarPaso("5. En un bol grande, mezclar la lechuga con el pollo, los crutones y el queso.");
        r4.agregarPaso("6. Agregar el aderezo César al gusto y mezclar suavemente para no romper la lechuga.");
        r4.agregarPaso("7. Opcional: añadir unas gotas de limón fresco para dar más sabor.");
        r4.agregarPaso("8. Servir inmediatamente para mantener la frescura y el crujiente de los crutones.");
        
        recetas.insertar(r4);
        
        // Receta 5: Pasta con tomate
        Receta r5("Pasta con tomate", "plato principal");

         // Ingredientes
        r5.agregarIngrediente("pasta");
        r5.agregarIngrediente("tomate");
        r5.agregarIngrediente("ajo");
        r5.agregarIngrediente("aceite de oliva");
        r5.agregarIngrediente("albahaca fresca");
        r5.agregarIngrediente("sal");
        r5.agregarIngrediente("pimienta");
        r5.agregarIngrediente("queso parmesano rallado"); // opcional para servir
        r5.agregarIngrediente("agua");                   // para hervir la pasta

        // Pasos de preparación
        r5.agregarPaso("1. Llenar una olla con agua, agregar sal y llevar a ebullición.");
        r5.agregarPaso("2. Cocinar la pasta en agua hirviendo hasta que esté al dente, luego escurrir y reservar.");
        r5.agregarPaso("3. Lavar y picar los tomates en cubos pequeños.");
        r5.agregarPaso("4. Picar finamente el ajo.");
        r5.agregarPaso("5. En una sartén grande, calentar aceite de oliva y sofreír el ajo hasta que esté dorado.");
        r5.agregarPaso("6. Agregar los tomates y cocinar a fuego medio hasta que se forme una salsa espesa.");
        r5.agregarPaso("7. Sazonar la salsa con sal y pimienta al gusto.");
        r5.agregarPaso("8. Mezclar la pasta con la salsa, asegurándose de que se impregne bien.");
        r5.agregarPaso("9. Servir la pasta en platos individuales, decorar con albahaca fresca y, si se desea, espolvorear queso parmesano rallado.");
        r5.agregarPaso("10. Servir caliente y disfrutar.");
        recetas.insertar(r5);

        // Receta 6: Arepas con queso
        Receta r6("Arepas con queso", "desayuno");

        // Ingredientes
        r6.agregarIngrediente("harina de maíz");
        r6.agregarIngrediente("queso");
        r6.agregarIngrediente("mantequilla");
        r6.agregarIngrediente("sal");
        r6.agregarIngrediente("agua");          
        r6.agregarIngrediente("aceite");        
        r6.agregarIngrediente("mantequilla extra"); 

        // Pasos de preparación
        r6.agregarPaso("1. En un bol grande, mezclar la harina de maíz con una pizca de sal.");
        r6.agregarPaso("2. Agregar agua poco a poco y amasar hasta obtener una masa suave y homogénea.");
        r6.agregarPaso("3. Incorporar mantequilla derretida a la masa y mezclar bien.");
        r6.agregarPaso("4. Dividir la masa en porciones y formar bolas, luego aplastarlas ligeramente para dar forma de arepas.");
        r6.agregarPaso("5. Calentar una plancha o sartén antiadherente y, si se desea, untar un poco de aceite.");
        r6.agregarPaso("6. Cocinar las arepas a fuego medio, unos 5-7 minutos por cada lado, hasta que estén doradas y cocidas por dentro.");
        r6.agregarPaso("7. Abrir las arepas por la mitad y rellenar con queso al gusto.");
        r6.agregarPaso("8. Servir calientes, opcionalmente untadas con mantequilla extra.");
        recetas.insertar(r6);

       // Receta 7: Batido de frutas
        Receta r7("Batido de frutas", "bebida");

        // Ingredientes
        r7.agregarIngrediente("leche");
        r7.agregarIngrediente("banana");
        r7.agregarIngrediente("fresa");
        r7.agregarIngrediente("azúcar");
        r7.agregarIngrediente("miel");          
        r7.agregarIngrediente("hielo");        
        r7.agregarIngrediente("yogur");         

        // Pasos de preparación
        r7.agregarPaso("1. Lavar bien las fresas y retirar los tallos.");
        r7.agregarPaso("2. Pelar la banana y cortarla en rodajas.");
        r7.agregarPaso("3. Colocar las frutas cortadas en la licuadora.");
        r7.agregarPaso("4. Agregar la leche y, si se desea, el yogur para mayor cremosidad.");
        r7.agregarPaso("5. Añadir azúcar o miel al gusto y algunos cubos de hielo si se quiere un batido frío.");
        r7.agregarPaso("6. Licuar todo hasta obtener una mezcla homogénea y cremosa.");
        r7.agregarPaso("7. Servir inmediatamente en vasos altos, decorando con una fresa o rodaja de banana en el borde.");

        recetas.insertar(r7);

       // Receta 8: Omelette de verduras
        Receta r8("Omelette de verduras", "desayuno");

        // Ingredientes
        r8.agregarIngrediente("huevo");
        r8.agregarIngrediente("cebolla");
        r8.agregarIngrediente("pimentón");
        r8.agregarIngrediente("tomate");
        r8.agregarIngrediente("aceite");         
        r8.agregarIngrediente("sal");
        r8.agregarIngrediente("pimienta");       
        r8.agregarIngrediente("queso");          
        r8.agregarIngrediente("hierbas finas");  

        // Pasos de preparación
        r8.agregarPaso("1. Lavar y picar la cebolla, el pimentón y el tomate en cubos pequeños.");
        r8.agregarPaso("2. Batir los huevos en un bol con sal, pimienta y hierbas al gusto.");
        r8.agregarPaso("3. Calentar una sartén con un poco de aceite a fuego medio.");
        r8.agregarPaso("4. Sofreír la cebolla, el pimentón y el tomate hasta que estén tiernos.");
        r8.agregarPaso("5. Verter los huevos batidos sobre las verduras y distribuir uniformemente.");
        r8.agregarPaso("6. Cocinar a fuego medio-bajo hasta que el omelette esté firme pero jugoso.");
        r8.agregarPaso("7. Si se desea, añadir queso rallado encima y doblar el omelette por la mitad.");
        r8.agregarPaso("8. Servir caliente, acompañado de pan o ensalada si se desea.");
        recetas.insertar(r8);

        // Receta 9: Lentejas guisadas
        Receta r9("Lentejas guisadas", "plato principal");

        // Ingredientes
        r9.agregarIngrediente("lentejas");
        r9.agregarIngrediente("zanahoria");
        r9.agregarIngrediente("cebolla");
        r9.agregarIngrediente("ajo");
        r9.agregarIngrediente("tomate");
        r9.agregarIngrediente("aceite");          
        r9.agregarIngrediente("papa");            
        r9.agregarIngrediente("sal");
        r9.agregarIngrediente("pimienta");
        r9.agregarIngrediente("caldo de verduras"); 
        r9.agregarIngrediente("laurel");          

        // Pasos de preparación
        r9.agregarPaso("1. Remojar las lentejas en agua durante al menos 1 hora.");
        r9.agregarPaso("2. Pelar y picar la zanahoria, la cebolla, el ajo, la papa y el tomate.");
        r9.agregarPaso("3. Calentar aceite en una olla grande a fuego medio y sofreír la cebolla y el ajo hasta que estén dorados.");
        r9.agregarPaso("4. Añadir la zanahoria y el tomate, y cocinar unos minutos hasta que se suavicen.");
        r9.agregarPaso("5. Agregar las lentejas escurridas, la papa, sal, pimienta y laurel al gusto.");
        r9.agregarPaso("6. Cubrir con agua o caldo de verduras y llevar a ebullición.");
        r9.agregarPaso("7. Bajar el fuego y cocinar a fuego lento durante 25-30 minutos, hasta que las lentejas estén blandas.");
        r9.agregarPaso("8. Rectificar la sal y pimienta, remover y servir caliente.");
        recetas.insertar(r9);

      // Receta 10: Tostadas francesas
        Receta r10("Tostadas francesas", "desayuno");

        // Ingredientes
        r10.agregarIngrediente("pan");
        r10.agregarIngrediente("huevo");
        r10.agregarIngrediente("leche");
        r10.agregarIngrediente("azucar");
        r10.agregarIngrediente("canela");       
        r10.agregarIngrediente("mantequilla");  
        r10.agregarIngrediente("vainilla");     
        r10.agregarIngrediente("frutas");       
        r10.agregarIngrediente("miel"); 

        // Pasos de preparación
        r10.agregarPaso("1. Batir los huevos en un bol grande con la leche, azucar, canela y un poco de vainilla.");
        r10.agregarPaso("2. Remojar las rebanadas de pan en la mezcla, asegurándose de que absorban bien el líquido.");
        r10.agregarPaso("3. Calentar una sartén a fuego medio y derretir un poco de mantequilla.");
        r10.agregarPaso("4. Dorar las rebanadas de pan por ambos lados hasta que estén doradas y crujientes.");
        r10.agregarPaso("5. Servir calientes, acompañadas de frutas frescas y miel al gusto.");

        recetas.insertar(r10);

        // Receta 11: Caldo de costilla
        Receta r11("Caldo de costilla", "sopa");

        // Ingredientes
        r11.agregarIngrediente("costilla");
        r11.agregarIngrediente("papa");
        r11.agregarIngrediente("cebolla");
        r11.agregarIngrediente("ajo");
        r11.agregarIngrediente("sal");
        r11.agregarIngrediente("zanahoria");      // opcional, para más sabor
        r11.agregarIngrediente("apio");           // opcional
        r11.agregarIngrediente("pimenton");       // opcional
        r11.agregarIngrediente("papa criolla");   // opcional, para variar textura
        r11.agregarIngrediente("agua");           // base del caldo
        r11.agregarIngrediente("cilantro");       // opcional, para decorar

        // Pasos de preparación
        r11.agregarPaso("1. Lavar bien las costillas y ponerlas a hervir en una olla con suficiente agua.");
        r11.agregarPaso("2. Mientras hierve, pelar y cortar las papas, zanahorias, cebolla, ajo, apio y pimenton.");
        r11.agregarPaso("3. Añadir las verduras a la olla y sazonar con sal al gusto.");
        r11.agregarPaso("4. Cocinar a fuego medio durante aproximadamente 1 a 1.5 horas hasta que la carne esté tierna.");
        r11.agregarPaso("5. Rectificar la sal y agregar cilantro picado antes de servir.");
        r11.agregarPaso("6. Servir caliente acompañado de arroz o arepas si se desea.");
        recetas.insertar(r11);
        
        // Receta 12: Arequipe casero
        Receta r12("Arequipe casero", "postre");

        // Ingredientes
        r12.agregarIngrediente("leche");
        r12.agregarIngrediente("azucar");
        r12.agregarIngrediente("bicarbonato de sodio");
        r12.agregarIngrediente("esencia de vainilla"); // opcional, para sabor
        r12.agregarIngrediente("sal");                // opcional, una pizca para resaltar sabor

        // Pasos de preparación
        r12.agregarPaso("1. Verter la leche en una olla grande y agregar el azúcar y el bicarbonato de sodio.");
        r12.agregarPaso("2. Calentar a fuego medio-bajo, removiendo constantemente para evitar que se pegue.");
        r12.agregarPaso("3. Cocinar lentamente hasta que la mezcla adquiera un color dorado/caramelo y espese (aproximadamente 1-2 horas).");
        r12.agregarPaso("4. Agregar una pizca de sal y unas gotas de esencia de vainilla si se desea.");
        r12.agregarPaso("5. Retirar del fuego y dejar enfriar, removiendo ocasionalmente para obtener una textura suave.");
        r12.agregarPaso("6. Guardar en frascos limpios y herméticos. Servir como postre o para untar.");
        recetas.insertar(r12);

        // Receta 13: Bandeja paisa
        Receta r13("Bandeja paisa", "plato principal");

        // Ingredientes
        r13.agregarIngrediente("arroz");
        r13.agregarIngrediente("carne molida");
        r13.agregarIngrediente("frijoles rojos");
        r13.agregarIngrediente("aguacate");
        r13.agregarIngrediente("huevo");
        r13.agregarIngrediente("arepa");
        r13.agregarIngrediente("chicharrón");       
        r13.agregarIngrediente("plátano maduro");   
        r13.agregarIngrediente("sal");
        r13.agregarIngrediente("aceite");
        r13.agregarIngrediente("ají o salsa picante"); 

        // Pasos de preparación
        r13.agregarPaso("1. Lavar y cocinar los frijoles rojos en agua con sal hasta que estén blandos.");
        r13.agregarPaso("2. Cocinar el arroz blanco en agua con un poco de sal y aceite.");
        r13.agregarPaso("3. Freír la carne molida con sal, ajo y cebolla picada al gusto.");
        r13.agregarPaso("4. Freír los huevos individualmente al gusto.");
        r13.agregarPaso("5. Preparar las arepas en una plancha o sartén hasta dorarlas ligeramente.");
        r13.agregarPaso("6. Opcional: freír el chicharrón y el plátano maduro.");
        r13.agregarPaso("7. Montar el plato colocando arroz, frijoles, carne, huevo, aguacate, arepa y los acompañamientos opcionales.");
        r13.agregarPaso("8. Servir caliente, agregando salsa picante al gusto si se desea.");
        recetas.insertar(r13);

        // Receta 14: Chocolate con queso
        Receta r14("Chocolate con queso", "bebida");

        // Ingredientes
        r14.agregarIngrediente("chocolate");
        r14.agregarIngrediente("leche");
        r14.agregarIngrediente("queso");
        r14.agregarIngrediente("azúcar");      
        r14.agregarIngrediente("canela");       

        // Pasos de preparación
        r14.agregarPaso("1. Calentar la leche en una olla a fuego medio, sin que llegue a hervir.");
        r14.agregarPaso("2. Agregar el chocolate troceado y mezclar constantemente hasta que se disuelva por completo.");
        r14.agregarPaso("3. Añadir el queso en cubos pequeños y revolver hasta que se derrita parcialmente y quede cremoso.");
        r14.agregarPaso("4. Opcional: añadir azúcar al gusto y una pizca de canela para sabor extra.");
        r14.agregarPaso("5. Servir caliente en tazas individuales.");
        recetas.insertar(r14);

         // Receta 15: Empanadas de carne
        Receta r15("Empanadas de carne", "pasabocas");
        // Ingredientes
        r15.agregarIngrediente("harina de maiz");
        r15.agregarIngrediente("carne molida");
        r15.agregarIngrediente("papa");
        r15.agregarIngrediente("cebolla");
        r15.agregarIngrediente("ajo");
        r15.agregarIngrediente("aceite");        
        r15.agregarIngrediente("sal");
        r15.agregarIngrediente("pimienta");
        r15.agregarIngrediente("agua");          
        r15.agregarIngrediente("huevo");        

        // Pasos de preparación
        r15.agregarPaso("1. Pelar y picar finamente la cebolla y el ajo.");
        r15.agregarPaso("2. Cocinar la carne molida en un sartén con aceite, sal y pimienta, agregando la cebolla y el ajo hasta que esté dorada.");
        r15.agregarPaso("3. Cocinar las papas, aplastarlas y mezclar con un poco de sal.");
        r15.agregarPaso("4. Preparar la masa con harina de maíz, agua y una pizca de sal hasta obtener una consistencia suave.");
        r15.agregarPaso("5. Formar discos de masa, rellenar con la mezcla de carne y papa, y cerrar formando empanadas.");
        r15.agregarPaso("6. Opcional: pincelar con huevo batido para dorar mejor.");
        r15.agregarPaso("7. Freír las empanadas en aceite caliente hasta que estén doradas y crujientes.");
        r15.agregarPaso("8. Escurrir sobre papel absorbente y servir calientes.");
        recetas.insertar(r15);


        
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
        relacionesIngredientes.agregarRelacion("aceite", "mantequilla");
        relacionesIngredientes.agregarRelacion("sal", "sal marina");
        relacionesIngredientes.agregarRelacion("pimienta", "ají molido");
        relacionesIngredientes.agregarRelacion("agua", "caldo");
        relacionesIngredientes.agregarRelacion("pan", "tortilla");
        relacionesIngredientes.agregarRelacion("pollo", "pavo");
        relacionesIngredientes.agregarRelacion("carne molida", "pollo");
        relacionesIngredientes.agregarRelacion("huevo", "claras de huevo");
        relacionesIngredientes.agregarRelacion("queso", "queso rallado");
        relacionesIngredientes.agregarRelacion("leche", "bebida vegetal");
        relacionesIngredientes.agregarRelacion("chocolate", "cacao");
        relacionesIngredientes.agregarRelacion("arequipe", "dulce de leche");
        relacionesIngredientes.agregarRelacion("harina de maiz", "harina de trigo");
        relacionesIngredientes.agregarRelacion("banana", "mango");
        relacionesIngredientes.agregarRelacion("fresa", "mora");
        relacionesIngredientes.agregarRelacion("pimenton", "ají");
        relacionesIngredientes.agregarRelacion("papa", "yuca");
        relacionesIngredientes.agregarRelacion("arroz", "pasta");
        relacionesIngredientes.agregarRelacion("zanahoria", "calabaza");
        relacionesIngredientes.agregarRelacion("ajo", "cebollin");
        relacionesIngredientes.agregarRelacion("limon", "vinagre");
        relacionesIngredientes.agregarRelacion("aguacate", "mantequilla");
        relacionesIngredientes.agregarRelacion("frijoles rojos", "lentejas");
        relacionesIngredientes.agregarRelacion("costilla", "carne de res");
        relacionesIngredientes.agregarRelacion("bicarbonato", "polvo de hornear");
        relacionesIngredientes.agregarRelacion("mantequilla", "margarina");
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

        if (coincidencia == 100) continue; // Saltar recetas completas

        vector<string> faltantes = receta->obtenerFaltantes(ingredientesDisponibles);

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

            // Mostrar sustituciones indicando qué ingrediente reemplaza
            bool tieneSustitutos = false;
            InterfazConsola::color(11);
            cout << "   🔁 Posibles sustitutos:\n";
            InterfazConsola::color(7);

            for (const auto& f : faltantes) {
                vector<string> subs = relacionesIngredientes.sugerirAlternativas({f});
                if (!subs.empty()) {
                    tieneSustitutos = true;
                    for (const auto& sub : subs) {
                        InterfazConsola::itemLista("✔ " + sub + "  (para " + f + ")", true);
                    }
                }
            }

            if (!tieneSustitutos) {
                InterfazConsola::color(8);
                cout << "   (No se encontraron sustitutos para esta receta)\n";
                InterfazConsola::color(7);
            }

            cout << "\n";
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







