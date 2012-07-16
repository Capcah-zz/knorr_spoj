#include <stdio.h>
#include <stdlib.h>

int cidades[100][101];// 0-> tamanho ; 1~100 -> cidades
int depth[2][100];
int LENGHT;

void mark(int cur, int oi){
  for(int i=0; i< cidades[cur][100]; i++)
    depth[!oi][cidades[cur][i]]= depth[oi][cur]+1;
}

void run(int start, int stop, int N){
  depth[0][start]= 0;
  for(int i=0; i< LENGHT; i++)
    for(int j=0; j< N; j++)
      if(depth[(i%2)][j] == i)
        mark(j, (i%2) );

}

int main(){
  int c, l, t1, t2, start, stop, is;
  scanf( "%d %d", &c, &l);
  while ( c != 0 ){
    is=0;
    //inicialização
    for (int i=0; i<100;i++){ //zera o tamanho das cidades
      cidades[i][100]=0;
      depth[0][i]=-1;
      depth[1][i]=-1;    
    }
    //funcional
    for (int i=0; i<l;i++){
      scanf("%d %d",&t1,&t2);// aumenta o tamanho de cidades[vertice] pra os dois pontos e adiciona o lugar certo.
      t2--; t1--;
      cidades[t1][cidades[t1][100]]= t2;
      cidades[t1][100]++;
      cidades[t2][cidades[t2][100]]= t1;
      cidades[t2][100]++;
    }
    scanf("%d %d %d", &start, &stop, &LENGHT);
    start--;
    stop--;
    if(LENGHT>0){
      run(start, stop, c);
      is= depth[LENGHT%2][stop] == LENGHT;
    }
    else
      if (start != stop)
        is= 0;
      else
        is=1;

    if ( is )
      printf("Yes, Teobaldo can travel.\n");
    else
      printf("No, Teobaldo can not travel.\n");
    scanf("%d %d", &c, &l);
  }
}