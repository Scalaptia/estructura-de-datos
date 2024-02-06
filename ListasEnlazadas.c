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
} Tinfo;

typedef struct nodo
{
    struct info datos;
    struct nodo *sig;
} Tnodo;

// Prototipos
void menuInsertar(Tnodo **lista);
void menuEliminar(Tnodo **lista);

void mostrarLista(Tnodo *lista);
Tnodo *crearNodo(Tinfo datos);
Tinfo *leerDatos();

void insertarInicio(Tnodo **lista, Tinfo *datos);
void insertarFinal(Tnodo **lista, Tinfo *datos);
void insertarPos(Tnodo **lista, Tinfo *datos, int pos);

void eliminarInicio(Tnodo **lista);
void eliminarFinal(Tnodo **lista);
void eliminarPos(Tnodo **lista, int pos);

int main()
{
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
        system("CLS");

        switch (opc)
        {
        case 1:
            menuInsertar(&lista);
            break;
        case 2:
            menuEliminar(&lista);
            break;
        case 3:
            mostrarLista(lista);
            system("PAUSE");
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }

        system("CLS");
    } while (opc != 4);

    return 0;
}

// Menus
void menuInsertar(Tnodo **lista)
{
    int opc, pos;
    Tinfo *datos;

    do
    {
        printf("1.- Insertar al inicio\n");
        printf("2.- Insertar al final\n");
        printf("3.- Insertar en posicion especifica\n");
        printf("4.- Atras\n");

        printf("Opcion: ");
        scanf("%d", &opc);
        system("CLS");

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
            system("CLS");

            insertarPos(lista, datos, pos);
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }

        system("CLS");
    } while (opc != 4);
}

void menuEliminar(Tnodo **lista)
{
    int opc, pos;
    Tinfo *datos;
    do
    {
        printf("1.- Eliminar al inicio\n");
        printf("2.- Eliminar al final\n");
        printf("3.- Eliminar en posicion especifica\n");
        printf("4.- Atras\n");

        printf("Opcion: ");
        scanf("%d", &opc);
        system("CLS");

        switch (opc)
        {
        case 1:
            datos = leerDatos();
            eliminarInicio(lista);
            break;
        case 2:
            datos = leerDatos();
            eliminarFinal(lista);
            break;
        case 3:
            datos = leerDatos();
            printf("En que posicion desea eliminar: ");
            scanf("%d", &pos);
            system("CLS");

            eliminarPos(lista, pos);
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }

        system("CLS");
    } while (opc != 4);
}

// Funciones
void mostrarLista(Tnodo *lista)
{
    Tnodo *temp = lista;
    int i = 1;

    while (temp != NULL)
    {
        printf("%d %s %s %s\n", i, temp->datos.nombre, temp->datos.apPat, temp->datos.apMat);
        temp = temp->sig;
        i++;
    }
}

Tnodo *crearNodo(Tinfo datos)
{
    Tnodo *nuevoNodo = (Tnodo *)malloc(sizeof(Tnodo));

    nuevoNodo->datos = datos;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

Tinfo *leerDatos()
{
    Tinfo *datos = (Tinfo *)malloc(sizeof(Tinfo));

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

void insertarInicio(Tnodo **lista, Tinfo *datos)
{
    Tnodo *nodo = crearNodo(*datos);

    nodo->sig = *lista;
    *lista = nodo;
}

void insertarFinal(Tnodo **lista, Tinfo *datos)
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

void insertarPos(Tnodo **lista, Tinfo *datos, int pos)
{
    Tnodo *nuevoNodo = crearNodo(*datos);
    Tnodo *temp = *lista;

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

void eliminarInicio(Tnodo **lista)
{
    Tnodo *temp = *lista;

    *lista = temp->sig;
}

void eliminarFinal(Tnodo **lista)
{
    Tnodo *temp = *lista;
    Tnodo *tempAnt = NULL;

    while (temp->sig != NULL)
    {
        tempAnt = temp;
        temp = temp->sig;
    }
    tempAnt->sig = NULL;
}

void eliminarPos(Tnodo **lista, int pos)
{
    Tnodo *temp = *lista;
    Tnodo *tempAnt = NULL;

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