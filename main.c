#include ".h\funciones.h"
#include <stdio.h>
#include <string.h>

/*
Una tienda desea implementar un programa en C que permita gestionar su inventario de productos. 
El programa debe recibir los nombres de los productos y sus precios, 
para luego realizar varias operaciones, tales como:

•	Calcular el precio total del inventario.
•	Encontrar el producto más caro y el más barato.
•	Calcular el precio promedio de todos los productos.
•	Buscar un producto por su nombre y mostrar su precio.
*/


int main()
{
    char nombre[PRODUCTOS][LONGITUD];
    float precio[PRODUCTOS];
    int seguir = 1;
    ingresarDatos(nombre, precio, PRODUCTOS);
    while (seguir == 1)
    {
        seguir = Menu(nombre,precio);
    }  
}
