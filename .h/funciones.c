#include ".\funciones.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void guardarPalabra(char mensaje[], char destino[], int longitud) {
    int esValido = 0;
    while (esValido == 0){
        printf("%s", mensaje);
        if (fgets(destino, longitud, stdin) != NULL) {
            size_t len = strlen(destino);
            if (len > 0 && destino[len - 1] == '\n') {
                destino[len - 1] = '\0'; // Elimina el salto de línea
            }
            // Verificar que no contenga números
            esValido = VerificarNoNumero(destino);
        }else 
            {
            printf("Error al leer la entrada.\n");
            }
    }
    convertirMinusculas(destino);
}

void ingresarDatos(char nombre[][LONGITUD], float precio[], int cantidad) {
    char mensaje[LONGITUD];
    for (int i = 0; i < cantidad; i++) {
        printf("---------------------------------------------\n");
        sprintf(mensaje, "Ingrese el nombre del producto %d: ", i + 1);
        guardarPalabra(mensaje, nombre[i], LONGITUD);
        sprintf(mensaje, "Ingrese el precio del producto %d: ", i + 1);
        precio[i] = leerFloatMayorQue(mensaje, 0);
        printf("---------------------------------------------\n");
    }
}

int VerificarNoNumero(char destino []){
    for (size_t i = 0; i < strlen(destino); i++) {
                if (isdigit(destino[i])) { // Si hay un número
                    printf("Error: No se permiten numeros. Intente de nuevo.\n");
                    i = strlen(destino);
                    return 0;
                }
            }
        return 1;
}

void VerificarProdutcoEncontrado(char nombre[][LONGITUD], float precio[]){
    int encontrado = 0;
    char nombreBuscado[LONGITUD];
    guardarPalabra("Ingrese el nombre del producto que desea buscar: ", nombreBuscado, LONGITUD);
    for (int i = 0; i < PRODUCTOS; i++) {
            if (BuscarProducto(nombre[i], precio[i], nombreBuscado) == 0) {
                encontrado = 1;
            }
        }
        if (!encontrado) {
            printf("Producto no encontrado.\n");
        }
}

void convertirMinusculas(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = tolower(cadena[i]);
    }
}

int BuscarProducto(char destino[],float precio,char nombreBuscado[]){
        if (strcmp(destino, nombreBuscado) == 0) {
            printf("---------------------------------------------\n");
            printf("Producto encontrado:\n");
            printf("Nombre: %s\n", destino);
            printf("Precio: %.2f\n",precio);
            printf("---------------------------------------------\n");
            return 0;
        }else{
            return 1;
        }
    }

float leerFloatMayorQue(char mensaje[], float minimo){
    float valor = 0;
    printf("%s",mensaje);
    while (scanf("%f",&valor) != 1 ||valor < minimo)
    {
        printf("Dato mal ingresado\n");
        printf("Valores mayores a 0\n");
        while ((getchar()) != '\n'); 
        printf("%s",mensaje);
    }
    while ((getchar()) != '\n'); 
    return valor;
}

int leerNumeroEnteroEntre(char mensaje[],int max,int min){
    int valor = 0;
    printf("%s",mensaje);
    while(scanf("%d",&valor) != 1 || valor > max ||valor < min)
    {
        printf("Dato mal ingresado\n");
        printf("Minutos entre 1 y 4\n");
        while ((getchar()) != '\n'); 
        printf("%s",mensaje);
    }
    while ((getchar()) != '\n');
    return valor;
}

float sumaInventario(float precio[]){
    float suma = 0;
    for (int i = 0; i < PRODUCTOS; i++)
    {
        suma += precio[i];
    }
    return suma;
}

float precioPromedio(float precio[]){
    float promedio = 0;
    promedio = (sumaInventario(precio) / PRODUCTOS);
    return promedio;
}

void mostrarProductoMasCaro(float precio[],char nombre[][LONGITUD]){
    float maximo = precio[0];
    int posicion = 0;
    for (int i = 1; i < PRODUCTOS; i++)
    {
        if (precio[i] > maximo)
        {
            maximo = precio[i];
            posicion = i;
        }
    }
    printf("---------------------------------------------\n");
    printf("El producto mas caro es %s con un precio de %.2f\n",nombre[posicion],maximo);
}

void mostrarProductoMasBarato(float precio[],char nombre[][LONGITUD]){
    float minimo = precio[0];
    int posicion = 0;
    for (int i = 1; i < PRODUCTOS; i++)
    {
        if (precio[i] < minimo)
        {
            minimo = precio[i];
            posicion = i;
        }
    }
    printf("El producto mas barato es %s con un precio de %.2f\n",nombre[posicion],minimo);
    printf("---------------------------------------------\n");
}

void mostrarProductoMasCaroYBarato(float precio[],char nombre[][LONGITUD]){
    mostrarProductoMasCaro(precio,nombre);
    mostrarProductoMasBarato(precio,nombre);
}

int Menu(char nombre[][LONGITUD],float precio[]){
    int eleccion = 0;
    printf("\n");
    printf("Menu\n");
    printf("Elija la opcion:\n");
    printf("1. Calcular el precio total del inventario\n");
    printf("2. Encontrar el producto mas caro y el mas barato\n");
    printf("3. Calcular el precio promedio de todos los productos\n");
    printf("4. Buscar un producto por su nombre y mostrar su precio\n");
    printf("5. Salir...");
    printf("\n");
    eleccion = leerNumeroEnteroEntre("Ingrese el numero de su eleccion: ",5,1);
    switch (eleccion)
    {
    case 1:
        printf("---------------------------------------------\n");
        printf("El precio total del inventario es de %.2f$\n",sumaInventario(precio));
        printf("---------------------------------------------\n");
        break;
    case 2:
        mostrarProductoMasCaroYBarato(precio,nombre);
        break;
    case 3:
        printf("---------------------------------------------\n");
        printf("El valor promedio es de %.2f$\n",precioPromedio(precio));
        printf("---------------------------------------------\n");
        break;
    case 4:
        VerificarProdutcoEncontrado(nombre,precio);
        break;
    case 5:
        printf("saliendo....");
        return 0;
        break;
    default:
        break;
    }
    return 1;
}


 