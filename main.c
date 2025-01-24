// main.c
#include <stdio.h>
#include "funciones.h"

int main() {
    Zona zonas[NUM_ZONAS];
    const char *archivo = "reporte_contaminacion.txt";

    if (!archivoExiste(archivo)) {
        printf("El archivo no existe. Creando con valores iniciales...\n");
        inicializarZonas(zonas);
        guardarZonasEnArchivo(zonas, archivo);
    } else {
        leerDatosDesdeArchivo(zonas, archivo);
    }

    int opcion, indice;
    do {
        printf("\nMenu principal:\n");
        printf("1. Mostrar datos de una zona\n");
        printf("2. Editar parametros de una zona\n");
        printf("3. Emitir alertas\n");
        printf("4. Generar recomendaciones\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el indice de la zona (0 a %d): ", NUM_ZONAS - 1);
                scanf("%d", &indice);
                if (indice >= 0 && indice < NUM_ZONAS) {
                    mostrarDatos(&zonas[indice]);
                } else {
                    printf("Indice invalido.\n");
                }
                break;

            case 2:
                printf("Ingrese el indice de la zona (0 a %d): ", NUM_ZONAS - 1);
                scanf("%d", &indice);
                if (indice >= 0 && indice < NUM_ZONAS) {
                    editarParametros(&zonas[indice]);
                    guardarZonasEnArchivo(zonas, archivo);
                } else {
                    printf("Indice invalido.\n");
                }
                break;

            case 3:
                emitirAlertas(zonas);
                break;

            case 4:
                printf("Ingrese el indice de la zona (0 a %d): ", NUM_ZONAS - 1);
                scanf("%d", &indice);
                if (indice >= 0 && indice < NUM_ZONAS) {
                    generarRecomendaciones(&zonas[indice]);
                } else {
                    printf("Indice invalido.\n");
                }
                break;

            case 5:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 5);

    return 0;
}

