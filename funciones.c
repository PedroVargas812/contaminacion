#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarZonas(Zona *zonas) {
    for (int i = 0; i < NUM_ZONAS; i++) {
        sprintf(zonas[i].nombre, "Zona %d", i + 1);
        zonas[i].pm25 = 15.0 + i * 5;
        zonas[i].no2 = 30.0 + i * 10;
        zonas[i].so2 = 10.0 + i * 5;
        zonas[i].o3 = 50.0 + i * 10;
        zonas[i].co = 5.0 + i * 1.0;
        zonas[i].temperatura_actual = 20.0 + i * 2.0;
        zonas[i].velocidad_viento_actual = 15.0 + i * 1.0;
        zonas[i].humedad_actual = 60.0 + i * 5.0;
        zonas[i].contaminacion_promedio = (zonas[i].pm25 + zonas[i].no2 + zonas[i].so2 + zonas[i].o3 + zonas[i].co) / 5.0;
    }
}

void guardarZonasEnArchivo(Zona *zonas, const char *archivo) {
    FILE *fp = fopen(archivo, "w");
    if (fp == NULL) {
        perror("Error al crear el archivo");
        return;
    }

    for (int i = 0; i < NUM_ZONAS; i++) {
        fprintf(fp, "Zona %d %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",
                i + 1, zonas[i].pm25, zonas[i].no2, zonas[i].so2, zonas[i].o3, zonas[i].co,
                zonas[i].temperatura_actual, zonas[i].velocidad_viento_actual, zonas[i].humedad_actual,
                zonas[i].contaminacion_promedio);
    }

    fclose(fp);
}

void leerDatosDesdeArchivo(Zona *zonas, const char *archivo) {
    FILE *fp = fopen(archivo, "r");
    if (fp == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    for (int i = 0; i < NUM_ZONAS; i++) {
        if (fscanf(fp, "Zona %*d %f %f %f %f %f %f %f %f %f",
                   &zonas[i].pm25,
                   &zonas[i].no2,
                   &zonas[i].so2,
                   &zonas[i].o3,
                   &zonas[i].co,
                   &zonas[i].temperatura_actual,
                   &zonas[i].velocidad_viento_actual,
                   &zonas[i].humedad_actual,
                   &zonas[i].contaminacion_promedio) != 9) {
            sprintf(zonas[i].nombre, "Zona %d", i + 1);
        }
    }

    fclose(fp);
}

void mostrarDatos(Zona *zona) {
    printf("\nDatos de %s:\n", zona->nombre);
    printf("PM2.5: %.2f\n", zona->pm25);
    printf("NO2: %.2f\n", zona->no2);
    printf("SO2: %.2f\n", zona->so2);
    printf("O3: %.2f\n", zona->o3);
    printf("CO: %.2f\n", zona->co);
    printf("Temperatura Actual: %.2f\n", zona->temperatura_actual);
    printf("Velocidad del Viento Actual: %.2f\n", zona->velocidad_viento_actual);
    printf("Humedad Actual: %.2f\n", zona->humedad_actual);
    printf("Contaminacion Promedio: %.2f\n", zona->contaminacion_promedio);
}

void editarParametros(Zona *zona) {
    printf("Editando parametros de %s:\n", zona->nombre);
    printf("Nuevo PM2.5: ");
    scanf("%f", &zona->pm25);
    printf("Nuevo NO2: ");
    scanf("%f", &zona->no2);
    printf("Nuevo SO2: ");
    scanf("%f", &zona->so2);
    printf("Nuevo O3: ");
    scanf("%f", &zona->o3);
    printf("Nuevo CO: ");
    scanf("%f", &zona->co);
    printf("Nueva Temperatura: ");
    scanf("%f", &zona->temperatura_actual);
    printf("Nueva Velocidad del Viento: ");
    scanf("%f", &zona->velocidad_viento_actual);
    printf("Nueva Humedad: ");
    scanf("%f", &zona->humedad_actual);

    zona->contaminacion_promedio = (zona->pm25 + zona->no2 + zona->so2 + zona->o3 + zona->co) / 5.0;
}

int archivoExiste(const char *archivo) {
    FILE *fp = fopen(archivo, "r");
    if (fp == NULL) {
        return 0;
    }
    fclose(fp);
    return 1;
}
