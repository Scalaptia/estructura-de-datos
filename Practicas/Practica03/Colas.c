// Fernando Haro Calvo 372106
// 08 de marzo de 2024

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estructuras
typedef struct info
{
    int numero;
} Tdatos;

typedef struct nodo
{
    struct info datos;
    struct nodo *sig;
} Tnodo;

typedef struct cola
{
    struct nodo *primero;
    struct nodo *ultimo;
} Tcola;

// Prototipos
void pause();

void mostrarCola(Tcola cola);
Tnodo *crearNodo(Tdatos datos);
Tdatos *leerDatos();

bool vacio(Tcola *cola);
int tamanio(Tcola *cola);
void encolar(Tcola *cola, Tdatos *datos);
Tnodo desencolar(Tcola *cola);

int main()
{
    system("clear");
    Tcola cola;
    cola.primero = NULL;
    cola.ultimo = NULL;

    Tnodo nodoTemp;
    Tdatos datosTemp;

    int opc;
    do
    {
        printf("1.- Encolar\n");
        printf("2.- Desenecolar\n");
        printf("3.- Mostrar\n");
        printf("4.- Salir\n");

        printf("Opcion: ");
        scanf("%d", &opc);
        system("clear");

        switch (opc)
        {
        case 1:
            datosTemp = *leerDatos();

            if (datosTemp.numero == -1)
            {
                pause();
                break;
            }

            encolar(&cola, &datosTemp);
            break;

        case 2:
            nodoTemp = desencolar(&cola);

            if (nodoTemp.datos.numero == -1)
            {
                printf("Cola vacia\n");
                pause();
                break;
            }

            printf("Numero eliminado: %d\n", nodoTemp.datos.numero);
            pause();
            break;

        case 3:
            mostrarCola(cola);
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

// Funciones
void mostrarCola(Tcola cola)
{
    Tnodo *temp = cola.primero;

    printf("--------\n");

    while (temp != NULL)
    {
        if (temp->sig == NULL)
        {
            printf("| %4d | <- ultimo\n", temp->datos.numero);
            break;
        }

        if (temp == cola.primero)
        {
            printf("| %4d | <- primero\n", temp->datos.numero);
            temp = temp->sig;
            continue;
        }

        printf("| %4d |\n", temp->datos.numero);
        temp = temp->sig;
    }

    printf("--------\n");
    printf("Tamanio: %d\n", tamanio(&cola));
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

    printf("Numero entero positivo: ");
    scanf("%d", &datos->numero);

    if (datos->numero < 0)
    {
        printf("Numero invalido\n");
        datos->numero = -1;
    }

    return datos;
}

bool vacio(Tcola *cola)
{
    if (cola->primero == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int tamanio(Tcola *cola)
{
    Tnodo *temp = cola->primero;
    int i = 0;

    while (temp != NULL)
    {
        temp = temp->sig;
        i++;
    }

    return i;
}

void encolar(Tcola *cola, Tdatos *datos)
{
    // Creamos un nodo con los datos
    Tnodo *nodo = crearNodo(*datos);

    bool vacia = vacio(cola);
    if (vacia)
    {
        printf("Cola vacia\n");
        pause();
    }

    if (vacio(cola))
    {
        // Si la cola esta vacia, el nodo sera el primero y el ultimo
        cola->primero = nodo;
        cola->ultimo = nodo;
    }
    else
    {
        // Si la cola no esta vacia, insertamos el nodo al final y actualizamos el ultimo
        cola->ultimo->sig = nodo;
        cola->ultimo = nodo;
    }
}

Tnodo desencolar(Tcola *cola)
{
    // Creamos un nodo temporal con un valor invalido
    Tnodo nodoTemp;
    nodoTemp.datos.numero = -1;

    // Si la cola esta vacia, retornamos el nodo temporal
    if (vacio(cola))
    {
        return nodoTemp;
    }

    // Si la cola tiene un solo elemento, retornamos el primer elemento
    nodoTemp = *cola->primero;
    cola->primero = cola->primero->sig;

    // Si la cola quedo vacia, el ultimo elemento tambien es NULL
    if (cola->primero == NULL)
    {
        cola->ultimo = NULL;
    }

    return nodoTemp;
}

void pause()
{
    printf("Presione enter para continuar...");
    while (getchar() != '\n')
        ;
    getchar();
}