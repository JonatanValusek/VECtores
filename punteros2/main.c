#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a=18;
    int* punt;
     punt = &a;

     printf("\n%p",punt);
     printf("\n%p",punt++);
     printf("\n%p",punt+1);
      printf("\n%p",punt+2);
      printf("\n%p",punt-1);

    return 0;
}
