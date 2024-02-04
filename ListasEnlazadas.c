#include <stdio.h>
#include <stdlib.h>

struct info
{
    char nombre[30];
    char apPat[30];
    char apMat[30];
};

struct nodo
{
    struct info datos;
    struct nodo *sig;
};

void menuInsertar();

int main()
{
    int opc;
    do
    {
        printf("1.- Insertar\n");
        printf("2.- Mostrar\n");
        printf("3.- Salir\n");

        printf("Opcion: ");
        scanf("%d", &opc);
        system("CLS");

        switch (opc)
        {
        case 1:
            menuInsertar();
            break;
        case 2:
            printf("Mostrar\n");
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }

        system("CLS");
    } while (opc != 3);

    return 0;
}

void menuInsertar()
{
    int opc, pos;
    do
    {
        printf("1.- Insertar al inicio\n");
        printf("2.- Insertar al final\n");
        printf("3.- Insertar en posicion especifica\n");
        printf("4.- Salir\n");

        printf("Opcion: ");
        scanf("%d", &opc);
        system("CLS");

        switch (opc)
        {
        case 1:
            printf("Insertar al inicio\n");
            break;
        case 2:
            printf("Insertar al final\n");
            break;
        case 3:
            printf("En que posicion desea insertar: ");
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
