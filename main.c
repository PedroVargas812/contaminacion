#include <stdio.h>
#include "funciones.h"

int main() {
    Zona zonas[NUM_ZONAS];
    const char *archivo = "C:\\Users\\reporte_contaminacion.txt";

    if (!archivoExiste(archivo)) {
        printf("El archivo no existe. Creando con valores iniciales...\n");
        inicializarZonas(zonas);
        guardarZonasEnArchivo(zonas, archivo);
        printf("\nDatos exportados a %s\n", archivo);
    } else {
        leerDatosDesdeArchivo(zonas, archivo);
    }

    int opcion, indice;
    do {
        printf("\nMenu principal:\n");
        printf("1. Mostrar datos de una zona\n");
        printf("2. Editar parametros de una zona\n");
        printf("3. Salir\n");
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
                    zonas[indice].contaminacion_promedio =
                        (zonas[indice].pm25 + zonas[indice].no2 + zonas[indice].so2 + zonas[indice].o3 + zonas[indice].co) / 5.0;
                    guardarZonasEnArchivo(zonas, archivo);
                    printf("\nDatos exportados a %s\n", archivo);
                } else {
                    printf("Indice invalido.\n");
                }
                break;

            case 3:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 3);

    return 0;
}
