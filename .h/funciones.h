#define PRODUCTOS 10
#define LONGITUD 50


void guardarPalabra(char mensaje[], char destino[], int longitud);
int VerificarNoNumero(char destino []);
void convertirMinusculas(char cadena[]);
int BuscarProducto(char destino[],float precio,char nombreBuscado[]);
float leerFloatMayorQue(char mensaje[], float minimo);
void ingresarDatos(char nombre[][LONGITUD], float precio[], int cantidad);
void VerificarProdutcoEncontrado(char nombre[][LONGITUD], float precio[]);
int leerNumeroEnteroEntre(char mensaje[],int max,int min);
float sumaInventario(float precio[]);
float precioPromedio(float precio[]);
int Menu(char nombre[][LONGITUD],float precio[]);