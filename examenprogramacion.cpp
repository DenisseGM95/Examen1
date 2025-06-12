#include <stdio.h>

void menu() {
    printf("1- Categor�a1 \n");
    printf("2- Categor�a2 \n");
    printf("3- Categor�a3 \n");
    printf("4- Cantidad vendida \n");
    printf("5- Monto recaudado por categor�a \n");
    printf("6- Salir \n");
}

int main() {
    char nombre[50];
    int categoria, cantidad, cantidadMaximaCompra = 10;
    float preciocategoria1 = 98.50, preciocategoria2 = 125.10, preciocategoria3 = 150.60;
    float montototal = 0;
    int contador = 0;
    int cantidadVendidaCategoria1 = 0, cantidadVendidaCategoria2 = 0, cantidadVendidaCategoria3 = 0;
    float montoRecaudadoCategoria1 = 0.0, montoRecaudadoCategoria2 = 0.0, montoRecaudadoCategoria3 = 0.0;

    printf("Ingrese nombre completo: ");
    scanf(" %[^\n]", nombre);

    do {
        menu();
        printf("Seleccione una opci�n (1-6): ");
        scanf("%i", &categoria);

        if (categoria >= 1 && categoria <= 3) {
            printf("Ingrese la cantidad de boletos (m�ximo %i): ", cantidadMaximaCompra);
            scanf("%i", &cantidad);

            if (cantidad > 0 && cantidad <= cantidadMaximaCompra) {
                switch (categoria) {
                    case 1:
                        cantidadVendidaCategoria1 += cantidad;
                        montoRecaudadoCategoria1 += preciocategoria1 * cantidad;
                        break;
                    case 2:
                        cantidadVendidaCategoria2 += cantidad;
                        montoRecaudadoCategoria2 += preciocategoria2 * cantidad;
                        break;
                    case 3:
                        cantidadVendidaCategoria3 += cantidad;
                        montoRecaudadoCategoria3 += preciocategoria3 * cantidad;
                        break;
                }
                printf("Ha comprado %d boletos de Categor�a %d por un total de %.2f colones \n",
                       cantidad, categoria,
                       (categoria == 1 ? preciocategoria1 :
                        categoria == 2 ? preciocategoria2 : preciocategoria3) * cantidad);
            } else {
                printf("Cantidad no v�lida. Debe ser entre 1 y %i.\n", cantidadMaximaCompra);
            }
        } else if (categoria == 4) {
            printf("Cantidad de boletos vendidos por categor�a:\n");
            printf("Categor�a 1: %i boletos\n", cantidadVendidaCategoria1);
            printf("Categor�a 2: %i boletos\n", cantidadVendidaCategoria2);
            printf("Categor�a 3: %i boletos\n", cantidadVendidaCategoria3);
        } else if (categoria == 5) {
            printf("Monto recaudado por categor�a:\n");
            printf("Categor�a 1: %.2f colones\n", montoRecaudadoCategoria1);
            printf("Categor�a 2: %.2f colones\n", montoRecaudadoCategoria2);
            printf("Categor�a 3: %.2f colones\n", montoRecaudadoCategoria3);
        } else if (categoria == 6) {
            printf("Gracias por su visita.\n");
        } else {
            printf("Opci�n no v�lida. Por favor, seleccione una opci�n entre 1 y 6.\n");
        }
    } while (categoria != 6);

    return 0;
}
