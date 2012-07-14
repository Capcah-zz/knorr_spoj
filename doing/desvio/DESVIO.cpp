#include <stdio.h>
#include <stdlib.h>

#define MAX 250

int mapa[250][MAX+1][2];

int distancia[250];

int find(int key){
  for (int i=0; i<distancia[key][250][0]; i++)
    if ( key = distancia[key][i][0])
      return i;
}

void fix_graph(int i, int C){
  if( C-1 == i )
    distancia[i]=0;
  else
    distancia[i]= mapa[i][ find(i+1) ][1] + distancia[i+1];
}

void push(int a, int b, int c, int C){
  rota[a][rota[a][250][0]][0] = b;
  rota[a][rota[a][250][0]][1] = c;
  rota[a][250][0]++; 
  rota[b][rota[b][250][0]][0] = a;
  rota[b][rota[b][250][0]][1] = c;
  rota[b][250][0]++;
}

int main(){
  int N, M, C, K, i,a ,b, c;
  scanf("%d %d %d %d", &N, &M, &C, &K);
  while ( N != 0){
    rota[MAX]=0;
    for(i=0; i<N; i++){
      mapa[i][250][0]= 0;
    }
    for(i=0; i<M; i++){
      scanf("%d %d %d", &a, &b, &c);
      push(a, b, c, C);
    }
    for(i=0; i<C; i++){
      fix_graph(C-i-1,C);
    }

    scanf("%d %d %d %d", &N, &M, &C, &K);
  }
}