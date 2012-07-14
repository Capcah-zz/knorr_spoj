#include <stdio.h>
#include <stdlib.h>

int relacoes[1000][1000];
int visitado[1000];

void marcar(int aluno, int size){
  visitado[aluno]=1;
  for (int i=0; i<size; i++){
    if ( relacoes[aluno][i] && ! visitado[i] )
      marcar(i, size);
    }
}

int main(){
  int N, M,a, b,i, j, grupos;
  scanf("%d %d", &N, &M);
  for (i=0; i<N; i++){
    for(i=0; i<N; i++)
      relacoes[i][j]=0;
    visitado[i]=0;
  }
  for (int i=0; i<M; i++){
    scanf("%d %d", &a, &b);
    relacoes[a-1][b-1]=1;
    relacoes[b-1][a-1]=1;
  }
  grupos=0;
  for (i=0; i<N; i++)
    if ( !visitado[i] ){
      marcar(i, N);
      grupos++;
    }
  printf("%d",grupos );
}