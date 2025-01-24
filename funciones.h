// funciones.h

#define NUM_ZONAS 5
#define MAX_NOMBRE 50
#define LIMITE_PM25 25.0
#define LIMITE_NO2 40.0
#define LIMITE_SO2 20.0
#define LIMITE_O3 100.0
#define LIMITE_CO 10.0

typedef struct {
    char nombre[MAX_NOMBRE];
    float pm25;
    float no2;
    float so2;
    float o3;
    float co;
    float temperatura_actual;
    float velocidad_viento_actual;
    float humedad_actual;
    float contaminacion_promedio;
} Zona;

void inicializarZonas(Zona *zonas);
void guardarZonasEnArchivo(Zona *zonas, const char *archivo);
void leerDatosDesdeArchivo(Zona *zonas, const char *archivo);
void mostrarDatos(Zona *zona);
void editarParametros(Zona *zona);
void calcularPromediosHistoricos(Zona *zonas, const char *archivo);
void generarRecomendaciones(Zona *zona);
void prediccionContaminacion(Zona *zona);
int archivoExiste(const char *archivo);
void emitirAlertas(Zona *zonas);
