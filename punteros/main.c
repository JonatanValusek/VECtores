#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a=18;
    int* punt;
    int* otro;
    punt = &a;

    printf("%p",&a); //muestro direccion de memoria de a.
    printf("\n%p",punt);//muestro el contenido que guarda el puntero.
    printf("\n%p",&punt);//muestro direccion de memoria del puntero.No a donde apunta el puntero

    printf("\n%d",a);//muestro el contenido de a normal.
    printf("\n%d",*punt);//muestro el contenido de la variable donde apunta el puntero.

    *punt= 52;// atravez del puntero tambien puedo modificar el valor de la variable hacia la cual apunta.
              // accedo a la variable por el puntero.
    otro=punt;

    printf("\n%p",otro);

    *otro=25;

    printf("\n%d",a);

    return 0;
}
