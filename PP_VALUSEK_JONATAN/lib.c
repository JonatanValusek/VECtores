#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"
#include "lib.h"

#define MAX_QTY 10


/**
 * \brief Inicializa el status en un array de libros
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */

void setClienteStatus(cliente clienteArray[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        clienteArray[i].status = value;
    }
}



/**
 * \brief Busca la primer ocurrencia de un cliente mediante su codigo
 * \param clienteArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findClienteByCode(cliente clienteArray[],int arrayLenght,int code)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(clienteArray[i].clienteId == code && clienteArray[i].status == 1)
        {
            return (i+1);
        }
    }
    return -1;
}


/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findClienteEmptyPlace(cliente clienteArray[],int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(clienteArray[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}


/*
/**
 * \brief Busca el precio promedio
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay bookos activos (-1) y si lo hay el precio de ese booko
 *

void orderClienteArrayByTitle(cliente clienteArray[],int arrayLenght)
{
    cliente bookAux;
    int i,j;

    for(i=0; i < arrayLenght - 1; i++)
    {
        if(clienteArray[i].status == 0)
        {
            continue;
        }
        for(j=i+1; j < arrayLenght; j++)
        {
            if(clienteArray[j].status == 0)
            {
                continue;
            }
            if(strcmp(clienteArray[j].title,clienteArray[i].title)<0)
            {
                clienteAux = clienteArray[j];
                clienteArray[j] = clienteArray[i];
                clienteArray[i] = clienteAux;
            }
            else if(strcmp(clienteArray[j].title,clienteArray[i].title) == 0)
            {
                if(clienteArray[i].code > clienteArray[j].code)
                {
                    clienteAux = clienteArray[j];
                    clienteArray[j] = clienteArray[i];
                    clienteArray[i] = clienteAux;
                }
            }
        }
    }
}
*/
/**
 * \brief Carga los valores del cliente
 * \param clienteArray Es el array de libros
 * \param freePlaceIndex Indica la posicion a setear
 * \param codeAux ID del cliente
 * \param nombreAux nombre del cliente
 * \param apellidoAux apellido del cliente
 * \param dniAux DNI del cliente
 * \return -
 *
 */
void setCliente(cliente clienteArray[],int freePlaceIndex, int codeAux,char nombreAux[],char apellidoAux[],long int dniAux)
{

    clienteArray[freePlaceIndex].clienteId = codeAux;
    strcpy(clienteArray[freePlaceIndex].nombre,nombreAux);
    strcpy(clienteArray[freePlaceIndex].apellido,apellidoAux);
    clienteArray[freePlaceIndex].dni = dniAux;
    clienteArray[freePlaceIndex].status = 1;
}

/**
 * \brief Muestra los clientes activos por pantalla
 * \param clienteArray Es el array de clientes
 * \param arrayLenght Indica la logitud del array
 * \return -
 */
void showClienteArray(cliente clienteArray[],int arrayLenght)
{

    int i;

    for(i=0;i < arrayLenght; i++)
    {
        if(clienteArray[i].status == 1)
        {
            printf("\n| %d  | %s | %s | %d | ",clienteArray[i].clienteId,clienteArray[i].nombre,clienteArray[i].apellido,clienteArray[i].dni);
        }
    }

    return;
}


/**
 * \brief Carga los clientes por pantalla
 * \param clienteArray Es el array de clientes
 * \return -
 */
void adminCliente(cliente clienteArray[])
{
    // variables auxiliares
    char nombreAux[25];
    char apellidoAux[25];

    int clienteIdAux;
    int codeAux;
    long int dniAux;
    //________________________________________________

    int freePlaceIndex;
    int foundIndex;
    int option = 0,i;

    while(option != 5)
    {
         system("cls");
         printf("\n------------  ABM CLIENTE ------------");
         option = getInt("\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - MOSTRAR CLIENTES\n5 - REGRESAR\n\n\n");
         switch(option)
         {
            case 1: // ALTA DE CLIENTE

                freePlaceIndex = findClienteEmptyPlace(clienteArray,MAX_QTY);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                codeAux = (freePlaceIndex+1);

                dniAux = getValidInt("Ingrese el DNI: ","El DNI deber ser numerico\n", 1, 90000000);

                getValidString("Ingrese el Nombre del Cliente: ","El nombre del Cliente debe estar compuesto solo por letras\n", nombreAux);

                getValidString("Ingrese el Apellido del Cliente: ","El Apellido del Cliente debe estar compuesto solo por letras\n", apellidoAux);

                setCliente(clienteArray,freePlaceIndex,codeAux,nombreAux,apellidoAux,dniAux);

                break;

            case 2: // BAJA CLIENTE

                codeAux = getValidInt("Ingrese el ID cliente a dar de baja: ","El ID del cliente debe ser numerico\n", 1, 15000);
                foundIndex = findClienteByCode(clienteArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                clienteArray[foundIndex].status = 2;
                break;

            case 3: // MODIFICAR CLIENTE

                codeAux = getValidInt("Ingrese el codigo del Cliente a modificar: ","El codigo del Cliente debe ser numerico\n", 1, 15000);
                foundIndex = findClienteByCode(clienteArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                freePlaceIndex=(codeAux-1);

                getValidString("Ingrese el Nombre del Cliente: ","El nombre del Cliente debe estar compuesto solo por letras\n", nombreAux);

                getValidString("Ingrese el Apellido del Cliente: ","El Apellido del Cliente debe estar compuesto solo por letras\n", apellidoAux);

                setCliente(clienteArray,freePlaceIndex,codeAux,nombreAux,apellidoAux,clienteArray[foundIndex].dni);

                break;

                case 4:

                    showClienteArray(clienteArray,10);
                    printf("\n");
                    system("pause");
                    break;




                 }
    }
}
