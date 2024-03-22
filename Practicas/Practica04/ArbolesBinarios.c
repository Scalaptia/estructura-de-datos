#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
};

struct Nodo *crearNodo(int dato)
{
    struct Nodo *nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

void Insertar(struct Nodo *arbol, int dato)
{
    if (dato > arbol->dato)
    {
        if (arbol->der == NULL)
        {
            arbol->der = crearNodo(dato);
        }
        else
        {
            Insertar(arbol->der, dato);
        }
    }
    else
    {
        if (arbol->izq == NULL)
        {
            arbol->izq = crearNodo(dato);
        }
        else
        {
            Insertar(arbol->izq, dato);
        }
    }
}

void Inorden(struct Nodo *arbol)
{
    if (arbol != NULL)
    {
        Inorden(arbol->izq);
        printf("%d, ", arbol->dato);
        Inorden(arbol->der);
    }
}

void Preorden(struct Nodo *arbol)
{
    if (arbol != NULL)
    {
        printf("%d, ", arbol->dato);
        Preorden(arbol->izq);
        Preorden(arbol->der);
    }
}

void Postorden(struct Nodo *arbol)
{
    if (arbol != NULL)
    {
        Postorden(arbol->izq);
        Postorden(arbol->der);
        printf("%d, ", arbol->dato);
    }
}

int main()
{
    int i, n = 8;
    int datos[9] = {8, 3, 1, 20, 5, 10, 7, 4};

    struct Nodo *arbol = crearNodo(datos[0]);

    for (i = 1; i < n; i++)
        Insertar(arbol, datos[i]);

    printf("\nInorden: ");
    Inorden(arbol);

    printf("\nPreorden: ");
    Preorden(arbol);

    printf("\nPostorden: ");
    Postorden(arbol);
}