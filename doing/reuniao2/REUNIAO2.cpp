#include <stdio.h>
#include <stdlib.h>

//fazer minimum spanning tree, depois calcular o ponto medio.

int llist[100][101][2];


void push(int a, int b, int c){
  llist[a][ llist[a][100][0] ][0] = b;
  llist[a][ llist[a][100][0] ][1] = c;
  llist[a][100][0]++;
  llist[b][ llist[b][100][0] ][0] = a;
  llist[b][ llist[b][100][0] ][1] = c;
  llist[b][100][0]++;
}

int main(){
  int N, M, i,a,b,c;
  scanf("%d %d", &N, &M);
  for (i = 0; i < N; ++i)
    llist[i][100][0]=0;
  for(i=0; i<M; i++){
    scan("%d %d %d", &a, &b, &c);
    push(a,b,c)
  } 
}