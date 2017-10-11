#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "lib.h"

#define MAX_QTY 10

int main()
{
    // arrays de clientes
    cliente clienteArray[MAX_QTY];
    setClienteStatus(clienteArray,MAX_QTY,0);
    //________________________________________________



    // Alta de datos para testing
    setCliente(clienteArray,0,1,"Jonatan","Valusek",34759521);
    setCliente(clienteArray,1,2,"Jessica","Garcia",33526398);
    setCliente(clienteArray,2,3,"Micaela","Chavez",15236847);
    setCliente(clienteArray,3,4,"Jimena","Gomez",40258637);


    int option = 0;

    while(option != 4)
    {
        system("@cls||clear");
        printf("\n------------  MENU PRINCIPAL ------------");
        option = getInt("\n1 - ABM CLIENTE \n2 - NUEVO ALQUILER \n3 - FIN ALQUILER\n4 - INFORMAR\n5 - SALIR\n\n\n");
        switch(option)
        {
            case 1: // ABM LIBROS
                adminCliente(clienteArray);
                break;
            case 2: // NUEVO ALQUILER

                break;

            case 3: // FIN ALQUILER

                break;

            case 4: // INFORMAR

                break;

        }
    }
    return 0;
}
