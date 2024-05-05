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

Nodo * crearListaVacia();
//void cargarTareas(Nodo ** tareasPendientes);
Nodo * crearTarea(int id, char *descripcion, int duracion);
void insertarTarea(Nodo ** tareasPendienes);
void sacarTarea(Nodo ** tareasPendientes, Nodo ** tareasRealizadas);
void listarTareas(Nodo ** tareasPendientes, Nodo ** tareasRealizadas);

int main()
{
    Nodo * tareasPendientes; //cabecera
    tareasPendientes = crearListaVacia();
    Nodo * tareasRealizadas;
    tareasRealizadas = crearListaVacia();
    //tareasPendientes = (Nodo **)malloc(sizeof(Nodo *));
    //cargarTareas(tareasPendientes);
    //char letras[] = "hola";
    //Nodo * nuevaTarea = crearTarea(1000, letras, 100);
    //char respuesta;
    int opcion;
    //printf("Se esta ejecutando");
    do
    {
        puts("Ingrese una opcion numerica:\n1 para agregar una tarea\n2 para marcar una tarea pendiente como realizada\n3 para listar tareas pendientes y tareas realizadas");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            insertarTarea(&tareasPendientes);
            break;
        case 2:
            sacarTarea(&tareasPendientes,&tareasRealizadas);
            break;
        case 3:
            listarTareas(&tareasPendientes,&tareasRealizadas);
            break;
        default:
            puts("Opcion incorrecta");
            break;
        }
        
    } while (opcion != 0);
    

    return 0;
}

Nodo * crearListaVacia(){
    return NULL;
}

// void cargarTareas(Nodo ** tareasPendientes){
    
// }

Nodo * crearTarea(int id, char *descripcion, int duracion){
    Nodo * nuevaTarea = (Nodo *)malloc(sizeof(Nodo));
    nuevaTarea->T.TareaID = id;
    int tamanio;
    tamanio = strlen(descripcion);
    nuevaTarea->T.Descripcion = (char *)malloc(tamanio+1 * sizeof(char));
    strcpy(nuevaTarea->T.Descripcion,descripcion);
    nuevaTarea->T.Duracion = duracion;
    nuevaTarea->Siguiente = NULL;
    return nuevaTarea;
}

void insertarTarea(Nodo ** tareasPendienes){
    Nodo * nuevaTarea;
    nuevaTarea = crearListaVacia();
    int id = 1000;
    char * buff = (char *)malloc(50 * sizeof(char));
    int duracion;
    puts("Ingrese la descripcion de la tarea:");
    fflush(stdin);
    gets(buff);
    puts("Ingrese la duracion de la tarea:");
    scanf("%d", &duracion);
    if (*tareasPendienes == NULL)
    {
        nuevaTarea = crearTarea(id, buff, duracion);
        *tareasPendienes = nuevaTarea;
    }
    else
    {
        int posicion;
        Nodo * aux = *tareasPendienes;
        posicion = aux->T.TareaID;
        while (aux->Siguiente)
        {
            aux = aux->Siguiente;
            posicion = aux->T.TareaID;
        }
        nuevaTarea = crearTarea(posicion+1, buff, duracion);
        aux->Siguiente = nuevaTarea;
    }
    free(buff);
}

void sacarTarea(Nodo ** tareasPendientes, Nodo ** tareasRealizadas){
    Nodo * listaTareas = *tareasPendientes;
    //Nodo * tareaLista;
    int id;
    if (*tareasPendientes ==  NULL)
    {
        puts("No se han cargado todavia tareas pendientes");
    }
    else
    {
        puts("Ingrese el ID de la tarea que desee marcar como realizada");
        printf("ID: %d - DESCRIPCION: %s\n", listaTareas->T.TareaID, listaTareas->T.Descripcion);
        while (listaTareas->Siguiente)
        {
            listaTareas = listaTareas->Siguiente;
            printf("ID: %d - DESCRIPCION: %s\n", listaTareas->T.TareaID, listaTareas->T.Descripcion);
        }
        scanf("%d", &id);
        listaTareas = *tareasPendientes;
        
        Nodo * tareaHecha = crearListaVacia();
        Nodo * liberar;
        if (listaTareas->T.TareaID == id)
        {
            tareaHecha = crearTarea(listaTareas->T.TareaID, listaTareas->T.Descripcion, listaTareas->T.Duracion);
            liberar = listaTareas;
            *tareasPendientes = listaTareas->Siguiente;
            free(liberar);
        }
        else
        {
            while (listaTareas->Siguiente)
            {
                if (listaTareas->Siguiente->T.TareaID == id)
                {
                    tareaHecha = crearTarea(listaTareas->Siguiente->T.TareaID, listaTareas->Siguiente->T.Descripcion, listaTareas->Siguiente->T.Duracion);
                    liberar = listaTareas->Siguiente;
                    listaTareas->Siguiente = listaTareas->Siguiente->Siguiente;
                    free(liberar);
                }
                // else
                // {
                //     puts("El ID no corresponde con una tarea cargada.");
                // }
                
                if (listaTareas->Siguiente)
                {
                    listaTareas = listaTareas->Siguiente;
                }
            }
        }

        if (tareaHecha == NULL)
        {
            puts("El ID no corresponde con una tarea cargada.");
        }
        else
        {
            if (*tareasRealizadas == NULL)
            {
                *tareasRealizadas = tareaHecha;
                //puts("if");
            }
            else
            {
                Nodo * aux = *tareasRealizadas;
                while (aux->Siguiente)
                {
                    aux = aux->Siguiente;
                }
                aux->Siguiente = tareaHecha;
            }
            //free(tareaHecha);
        }
        
        
    }
    
}

void listarTareas(Nodo ** tareasPendientes, Nodo ** tareasRealizadas){
    Nodo * lista;
    lista = crearListaVacia();
    if (*tareasPendientes == NULL)
    {
        puts("No hay tareas pendientes para listar.");
    }
    else
    {
        lista = *tareasPendientes;
        printf("Tareas pendientes\nID: %d - DESCRIPCION: %s\n", lista->T.TareaID, lista->T.Descripcion);
        while (lista->Siguiente)
        {
            lista = lista->Siguiente;
            printf("ID: %d - DESCRIPCION: %s\n", lista->T.TareaID, lista->T.Descripcion);
        }
    }
    lista = crearListaVacia();
    if (*tareasRealizadas == NULL)
    {
        puts("No hay tareas realizadas para listar.");
    }
    else
    {
        lista = *tareasRealizadas;
        printf("Tareas realizadas\nID: %d - DESCRIPCION: %s\n", lista->T.TareaID, lista->T.Descripcion);
        while (lista->Siguiente)
        {
            lista = lista->Siguiente;
            printf("ID: %d - DESCRIPCION: %s\n", lista->T.TareaID, lista->T.Descripcion);
        }
    }
    //free(lista);
}