#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea
{
    int TareaID; //Numerico autoincremental comenzando en 1000
    char * Descripcion; 
    int Duracion; // entre 10 - 100
} Tarea;
typedef struct Nodo
{
    Tarea T;
    struct Nodo * Siguiente;
}Nodo;

//Nodo * crearNodo();
Nodo * cargarTareas();


int main()
{
    // int cantidad;
    // printf("Ingrese la cantidad de tareas pendientes a cargar:\n");
    // scanf("%d", &cantidad);
    // struct Nodo *tareasPendientes = (struct Nodo *)malloc(cantidad * sizeof(struct Nodo));
    // for (int i = 0; i < cantidad; i++)
    // {
    //     if (i == 0) //auto incrementativo desde 1000 en adelante
    //     {
    //         tareasPendientes[i].T.TareaID = 1000;
    //         tareasPendientes[i].Siguiente = NULL;
    //     }else
    //     {
    //         tareasPendientes[i].T.TareaID = tareasPendientes[i-1].T.TareaID + 1; //funciona bien
    //         tareasPendientes[i-1].Siguiente = &tareasPendientes[i]; //funciona bien
    //         tareasPendientes[i].Siguiente = NULL; //funciona bien
    //     }
    //     char *buff;
    //     buff = (char *)malloc(100 * sizeof(char));
    //     fflush(stdin);
    //     gets(buff);
    //     int tamanioCadena;
    //     tamanioCadena = strlen(buff);
    //     tareasPendientes[i].T.Descripcion = (char *)malloc(tamanioCadena+1 * sizeof(char));
    //     strcpy(tareasPendientes[i].T.Descripcion,buff);
    //     tareasPendientes[i].T.Duracion = rand() % 100 + 11;
    // }
    //struct Nodo *Inicio;
    // int respuesta;
    // Nodo * tarea = (Nodo *)malloc(sizeof(Nodo));
    // Nodo * inicio = tarea;
    // int ID = 1000;
    // // puts("Ingrese la descripcion:");
    // // scanf("");
    // int contador = 0;
    // do
    // {
    //     if (contador == 0)
    //     {
    //         tarea->T.TareaID = ID;
    //     }
    //     else
    //     {
    //         //aux->Siguiente = &tarea;
    //         //aux = &tarea;
    //         tarea->T.TareaID = ID+1;
    //     }
    //     puts("Ingrese la descripcion:");
    //     scanf("\n");
        
    //     tarea->Siguiente = NULL;
    //     contador++;
    //     puts("1 para ingresar otra tarea, 0 para finalizar:");
    //     scanf("%d", &respuesta);
    //     Nodo * tarea = (Nodo *)malloc(sizeof(Nodo));
    // } while (respuesta == 0);

    Nodo * Start;
    Start = NULL;
    Start = cargarTareas(); //retorna un puntero
    //cargarTareas(Start);
    //printf("El nodo inicial es: %p", Start);

    return 0;
}

// Nodo * crearNodo(){
//     Nodo * nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
//     nuevoNodo->Siguiente = NULL;
//     return nuevoNodo;
// }

Nodo * cargarTareas(){
    // Nodo nuevoNodo;
    // Nodo primerNodo = nuevoNodo;
    // Nodo * Nodo = &nuevoNodo;
    // Nodo * aux = Nodo;
    // int ID = 1000, contador = 0;
    // char respuesta;

    // do
    // {
    //     if (contador == 0)
    //     {
    //         Nodo->Siguiente = NULL;
    //         Nodo->T.TareaID = ID;
    //     }
    //     else
    //     {
    //         //nuevoNodo->Siguiente = aux; // revisar el orden
    //         aux->Siguiente = &nuevoNodo;
    //         Nodo->T.TareaID = ID + contador;
    //     }
    //     aux = Nodo;
    //     Nodo * Nodo = (Nodo *)malloc(sizeof(Nodo));
    //     contador++;
    //     puts("Desea ingresar otra tarea? Ingrese S para SI o N para NO");
    //     scanf("%s", &respuesta);
    // } while (respuesta == 's' || respuesta == 'S');
    Nodo * primerNodo = (Nodo *)malloc(sizeof(Nodo)); //bien
    Nodo * aux = NULL;
    //primerNodo = nuevoNodo; //bien
    aux = primerNodo;
    int id = 1000, contador = 0;
    int respuesta, tamanio;
    do
    {
        if (contador == 0)
        {
            aux->T.TareaID = id;
        }
        else
        {
            Nodo * nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
            aux->Siguiente = nuevoNodo;
            aux = nuevoNodo;
            aux->T.TareaID = id + contador;
        }
        aux->Siguiente = NULL;
        printf("Tarea n° %d\nIngrese una descripcion de la tarea:", aux->T.TareaID);
        char * buff = (char *)malloc(50 * sizeof(char));
        fflush(stdin);
        gets(buff);
        tamanio = strlen(buff);
        aux->T.Descripcion = (char *)malloc(tamanio+1 * sizeof(char));
        strcpy(aux->T.Descripcion,buff);
        aux->T.Duracion = rand() % 91 + 10; 
        //printf("El nodo es %p\n", aux);
        puts("Ingrese 1 para cargar otra tarea, ingrese cualquier otro numero para finalizar:");
        scanf("%d", &respuesta);
        contador++;
    } while (respuesta == 1);
    
    return primerNodo;
}