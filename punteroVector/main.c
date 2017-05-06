#include <stdio.h>
#include <stdlib.h>
//vec representa la direccion de memopria del primer elemento

int main()
{
    int vec[5]={5,8,1,9,6};
    int* pvec;

    pvec=vec;

    printf("%d\n",*(pvec+3));

    //mostrar el vector entero recorrido por un puntero

    for(int i =0; i < 5; i++)
    {
        printf("%d\n",*(pvec+i));
    }

    for(int i =0; i < 5; i++)
    {
        printf("INGRESE UN NUMERO");
        scanf("%d\n",*(pvec+i));
    }

    return 0;
}
