#define NUM_ZONAS 5
#define MAX_NOMBRE 50

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
int archivoExiste(const char *archivo);

