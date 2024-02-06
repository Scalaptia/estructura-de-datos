#include <stdio.h>
#include <stdlib.h>

// Estructuras
typedef struct info
{
    char nombre[30];
    char apPat[30];
    char apMat[30];
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
            break;
        case 3:
            datos = leerDatos();
            printf("En que posicion desea insertar?: ");
            scanf("%d", &pos);
            system("CLS");

            printf("Insertar en posición especifica\n");
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
            break;
        case 2:
            datos = leerDatos();
            break;
        case 3:
            datos = leerDatos();
            printf("En que posicion desea eliminar: ");
            scanf("%d", &pos);
            system("CLS");

            printf("Eliminar en posición especifica\n");
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

    while (temp != NULL)
    {
        printf("%s %s %s\n", temp->datos.nombre, temp->datos.apPat, temp->datos.apMat);
        temp = temp->sig;
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
    Tnodo *nuevoNodo = crearNodo(*datos);

    nuevoNodo->sig = *lista;
    *lista = nuevoNodo;
}