// Fernando Haro Calvo 372106
// 23 de febrero de 2024

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

typedef struct pila
{
    struct nodo *tope;
} Tpila;

// Prototipos
void pause();

void mostrarPila(Tpila pila);
Tnodo *crearNodo(Tdatos datos);
Tdatos *leerDatos();

bool vacio(Tpila *pila);
int tamanio(Tpila *pila);
void push(Tpila *pila, Tdatos *datos);
Tnodo pop(Tpila *pila);

int main()
{
    system("clear");
    Tpila pila;
    pila.tope = NULL;

    Tnodo nodoTemp;
    Tdatos datosTemp;

    int opc;
    do
    {
        printf("1.- Push\n");
        printf("2.- Pop\n");
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

            push(&pila, &datosTemp);
            break;

        case 2:
            nodoTemp = pop(&pila);

            if (nodoTemp.datos.numero == -1)
            {
                printf("Pila vacia\n");
                pause();
                break;
            }

            printf("Numero eliminado: %d\n", nodoTemp.datos.numero);
            pause();
            break;

        case 3:
            mostrarPila(pila);
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
void mostrarPila(Tpila pila)
{
    Tnodo *temp = pila.tope;

    while (temp != NULL)
    {
        printf("| %4d |\n", temp->datos.numero);
        temp = temp->sig;
    }

    printf("--------\n");
    printf("Tamanio: %d\n", tamanio(&pila));
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

bool vacio(Tpila *pila)
{
    return pila->tope == NULL;
}

int tamanio(Tpila *pila)
{
    Tnodo *temp = pila->tope;
    int i = 0;

    while (temp != NULL)
    {
        temp = temp->sig;
        i++;
    }

    return i;
}

void push(Tpila *pila, Tdatos *datos)
{
    Tnodo *nuevoNodo = crearNodo(*datos);

    // El nuevo nodo apunta al tope actual
    nuevoNodo->sig = pila->tope;

    // El tope ahora es el nuevo nodo
    pila->tope = nuevoNodo;
}

Tnodo pop(Tpila *pila)
{
    if (vacio(pila))
    {
        Tnodo temp;
        temp.datos.numero = -1;

        return temp;
    }

    // Guardar el nodo superior
    Tnodo *temp = pila->tope;

    // Bajar el tope a uno debajo del actual
    pila->tope = pila->tope->sig;

    return *temp;
}

void pause()
{
    printf("Presione enter para continuar...");
    while (getchar() != '\n')
        ;
    getchar();
}