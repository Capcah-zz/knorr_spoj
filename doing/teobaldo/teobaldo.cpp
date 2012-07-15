#include <stdio.h>
#include <stdlib.h>

#define PRETO -1
#define CINZA 1
#define BRANCO 0

int cidades[100][101];// 0-> tamanho ; 1~100 -> cidades
int visitado[100];
int LENGHT;

bool search_biggest_path( int end, int lenght, int current, int got_end ){
  //printf("%d::%d::%d\n", current, end, lenght );
  if ( current == end ) got_end= 1; 
  if ( visitado[current] != -1 ){
    if ( !(LENGHT%(LENGHT-lenght)) && got_end )// if there is a subloop containing the end

  }
  else{
    if ( lenght == 0 ){
      if ( current == end ) return 1;
      return 0;
    }
    for (int i=1; i < cidades[current][0]; i++)
      if ( search_biggest_path( end, lenght-1, cidades[current][i]), got_end ) return 1;
    visitado[current]= BRANCO;
    return 0;
  }
}

int main(){
  int c, l, t1, t2, start, stop;
  scanf( "%d %d", &c, &l);
  while ( c != 0 ){
    //caso especial, l=0
    if ( l == 0 ){
      printf("No, Teobaldo can not travel.\n");
      scanf("%d %d %d", &start, &stop, &LENGHT);
      scanf("%d %d", &c, &l);
      continue;
    }
    //inicialização
    for (int i=0; i<100;i++){ //zera o tamanho das cidades
      cidades[i][0]=1;
      visitado[i]=-1;
    }
    //funcional
    for (int i=0; i<l;i++){
      scanf("%d %d",&t1,&t2);// aumenta o tamanho de cidades[vertice] pra os dois pontos e adiciona o lugar certo.
      t2--; t1--;
      cidades[t1][cidades[t1][0]]= t2;
      cidades[t2][cidades[t2][0]]= t1;
      cidades[t1][0]++;
      cidades[t2][0]++;
    }
    /*
    for (int i=0; i<c; i++){
      printf("%d:",i );
      for (int j=1; j<cidades[i][0]; j++)
        printf( "%d,", cidades[i][j] );
      printf("\n");
    }*/
    scanf("%d %d %d", &start, &stop, &LENGHT);
    if ( search_biggest_path( stop-1, LENGHT, start-1 ) )
      printf("Yes, Teobaldo can travel.\n");
    else
      printf("No, Teobaldo can not travel.\n");
    scanf("%d %d", &c, &l);
  }
}