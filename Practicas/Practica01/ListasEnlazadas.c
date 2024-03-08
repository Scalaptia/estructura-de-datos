// Fernando Haro Calvo 372106
// 05 de febrero de 2024

#include <stdio.h>
#include <stdlib.h>

// Estructuras
typedef struct info
{
    int matricula;
    char apPat[30];
    char apMat[30];
    char nombre[30];
} Tdatos;

typedef struct nodo
{
    struct info datos;
    struct nodo *sig;
} Tnodo;

// Prototipos
void pause();
int largoLista(Tnodo *lista);

void menuInsertar(Tnodo **lista);
void menuEliminar(Tnodo **lista);

void mostrarPila(Tnodo *lista);
Tnodo *crearNodo(Tdatos datos);
Tdatos *leerDatos();

void insertarInicio(Tnodo **lista, Tdatos *datos);
void insertarFinal(Tnodo **lista, Tdatos *datos);
void insertarPos(Tnodo **lista, Tdatos *datos, int pos);

void eliminarInicio(Tnodo **lista);
void eliminarFinal(Tnodo **lista);
void eliminarPos(Tnodo **lista, int pos);

int main()
{
    system("clear");
    Tnodo *lista = NULL;

    int opc;
    do
    {
        printf("1.- Insertar elemento\n");
        printf("2.- Eliminar elemento\n");
        printf("3.- Mostrar lista\n");

        printf("4.- Salir\n");

        printf("Opcion: ");
        scanf("%d", &opc);
        system("clear");

        switch (opc)
        {
        case 1:
            menuInsertar(&lista);
            break;
        case 2:
            menuEliminar(&lista);
            break;
        case 3:
            mostrarPila(lista);
            pause();
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }

        system("clear");
    } while (opc != 4);

    return 0;
}

// Menus
void menuInsertar(Tnodo **lista)
{
    int opc, pos;
    Tdatos *datos;

    do
    {
        printf("1.- Insertar al inicio\n");
        printf("2.- Insertar al final\n");
        printf("3.- Insertar en posicion especifica\n");
        printf("4.- Atras\n");

        printf("Opcion: ");
        scanf("%d", &opc);
        system("clear");

        switch (opc)
        {
        case 1:
            datos = leerDatos();
            insertarInicio(lista, datos);
            break;
        case 2:
            datos = leerDatos();
            insertarFinal(lista, datos);
            break;
        case 3:
            datos = leerDatos();
            printf("En que posicion desea insertar?: ");
            scanf("%d", &pos);
            system("clear");

            insertarPos(lista, datos, pos);
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }

        system("clear");
    } while (opc != 4);
}

void menuEliminar(Tnodo **lista)
{
    int opc, pos;
    Tdatos *datos;
    do
    {
        printf("1.- Eliminar al inicio\n");
        printf("2.- Eliminar al final\n");
        printf("3.- Eliminar en posicion especifica\n");
        printf("4.- Atras\n");

        printf("Opcion: ");
        scanf("%d", &opc);
        system("clear");

        switch (opc)
        {
        case 1:
            eliminarInicio(lista);
            break;
        case 2:
            eliminarFinal(lista);
            break;
        case 3:
            printf("En que posicion desea eliminar: ");
            scanf("%d", &pos);
            system("clear");

            eliminarPos(lista, pos);
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }

        system("clear");
    } while (opc != 4);
}

// Funciones
int largoLista(Tnodo *lista)
{
    Tnodo *temp = lista;
    int i = 0;

    while (temp != NULL)
    {
        temp = temp->sig;
        i++;
    }

    return i;
}

void mostrarPila(Tnodo *lista)
{
    Tnodo *temp = lista;
    int i = 1;

    while (temp != NULL)
    {
        printf("%d %d %s %s %s\n", i, temp->datos.matricula, temp->datos.nombre, temp->datos.apPat, temp->datos.apMat);
        temp = temp->sig;
        i++;
    }
}

Tnodo *crearNodo(Tdatos datos)
{
    Tnodo *nuevoNodo = (Tnodo *)malloc(sizeof(Tnodo));

    nuevoNodo->datos = datos;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

Tdatos *leerDatos()
{
    Tdatos *datos = (Tdatos *)malloc(sizeof(Tdatos));

    printf("Matricula: ");
    scanf("%d", &datos->matricula);
    printf("Nombre: ");
    scanf("%s", datos->nombre);
    printf("Apellido paterno: ");
    scanf("%s", datos->apPat);
    printf("Apellido materno: ");
    scanf("%s", datos->apMat);

    return datos;
}

void insertarInicio(Tnodo **lista, Tdatos *datos)
{
    Tnodo *nodo = crearNodo(*datos);

    nodo->sig = *lista;
    *lista = nodo;
}

void insertarFinal(Tnodo **lista, Tdatos *datos)
{
    Tnodo *nuevoNodo = crearNodo(*datos);
    Tnodo *temp = *lista;

    if (*lista == NULL)
    {
        *lista = nuevoNodo;
    }
    else
    {
        while (temp->sig != NULL)
        {
            temp = temp->sig;
        }
        temp->sig = nuevoNodo;
    }
}

void insertarPos(Tnodo **lista, Tdatos *datos, int pos)
{
    Tnodo *nuevoNodo = crearNodo(*datos);
    Tnodo *temp = *lista;

    int largo = largoLista(*lista);

    if (pos > largo)
    {
        insertarFinal(lista, datos);
        return;
    }

    if (pos == 1)
    {
        insertarInicio(lista, datos);
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->sig;
        }

        nuevoNodo->sig = temp->sig;
        temp->sig = nuevoNodo;
    }
}

void insertarPosicion(Tnodo **lista, Tdatos *info, int pos)
{
    Tnodo *nuevoNodo = crearNodo(*info);

    if (*lista == NULL)
    {
        *lista = nuevoNodo;
    }
    else
    {
        Tnodo *puntero;
    }
}

void eliminarInicio(Tnodo **lista)
{
    if (*lista == NULL)
    {
        return;
    }

    Tnodo *temp = *lista;

    *lista = temp->sig;
}

void eliminarFinal(Tnodo **lista)
{
    if (*lista == NULL)
    {
        return;
    }

    Tnodo *temp = *lista;
    Tnodo *tempAnt = NULL;
    int largo = largoLista(*lista);

    if (largo == 1)
    {
        *lista = NULL;
        return;
    }

    while (temp->sig != NULL)
    {
        tempAnt = temp;
        temp = temp->sig;
    }
    tempAnt->sig = NULL;
}

void eliminarPos(Tnodo **lista, int pos)
{
    if (*lista == NULL)
    {
        return;
    }

    Tnodo *temp = *lista;
    Tnodo *tempAnt = NULL;

    int largo = largoLista(*lista);

    if (pos > largo)
    {
        eliminarFinal(lista);
        return;
    }

    if (pos == 1)
    {
        eliminarInicio(lista);
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            tempAnt = temp;
            temp = temp->sig;
        }

        tempAnt->sig = temp->sig;
    }
}

void pause()
{
    printf("Presione enter para continuar...");
    while (getchar() != '\n')
        ;
    getchar();
}