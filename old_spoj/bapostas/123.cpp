#include <stdio.h>
#include <stdlib.h>

int quantidade, soma, validation, fsum, max;
//int storage[2][10000];

int main()
{
  scanf("%d", &quantidade);
  while ( quantidade != 0 )
  {
    soma= 0; validation= 0; max= 0;
    for(int i= 0; i < quantidade; i++ )
    {
      scanf( "%d", &soma);
      /*if ( storage[0][i] > 0 )
        validation++;
      if ( storage[0][i] > max)
        max= storage[0][i];
      fsum+= storage[0][i];
      storage[1][i]= storage[0][i];
      if ( storage[1][i] > soma )
        soma= storage[1][i];*/
    }
    scanf( "%d", &quantidade);
}}