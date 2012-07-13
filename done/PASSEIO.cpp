#include <stdio.h>
#include <stdlib.h>

int altitutes[150];
int llista[150][151];
int distancias[150];

void push(int a, int b){
  llista[a][llista[a][150]]= b;
  llista[a][150]++;
}

int calcular_maximo(int inicial){
  int tmp;
  int max=0;
  if ( distancias[inicial] )
    return distancias[inicial]+1;
  if (!llista[inicial][150])
    return 1;
  for (int i=0; i< llista[inicial][150]; i++){
      tmp= calcular_maximo(llista[inicial][i]);
      if (tmp>max)
        max=tmp; 
    }
  distancias[inicial]=max;
  return 1+max;
}

int main(){
  int P, L, I, i, a, b, caso;
  scanf("%d %d %d", &P, &L, &I);
  caso=0;
  while(L>0){
    for(i=0; i<P; i++){
      llista[i][150]=0;
      distancias[i]=0;
    }
    I--;
    //reading input
    caso++;
    for(i=0; i< P; i++){
      scanf("%d", &a);
      altitutes[i]= a;
    }
    for(i=0; i<L; i++){
      scanf("%d %d",&a, &b);
      if (altitutes[a-1]>altitutes[b-1])
        push(a-1,b-1);
    }
    //grafico montado.
    printf("Teste %d\n%d\n\n",caso, calcular_maximo(I)-1);
    scanf("%d %d %d", &P, &L, &I);
  }
}