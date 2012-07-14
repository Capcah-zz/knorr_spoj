#include <stdio.h>
#include <stdlib.h>

#define MAX 250

int mapa[MAX][MAX];

int distancia[MAX];

int sum(int a, int b){
  return (a+b)*( a!=INF && b!=INF) + INF*(a == INF || b == INF);
}

int bt(int a, int b){
  return (a == INF) || (a>b && b!=INF) ;
}

/*int find(int key){
  for (int i=0; i<distancia[key][MAX][0]; i++)
    if ( key = distancia[key][i][0])
      return i;
}*/

void relax(int a, int b){
  if ( bt( distances[b], sum(distances[a],mapa[a][b]) ) ){
    distances[b]= sum(distances[a],mapa[a][b]);
  }
}

void bf(int N){
  for (int i=0; i< N; i++){
    for (int j=0; j<N; j++){
      relax(i, j)
    }
  }
}

void fix_graph(int i, int C, int max){
  if ( i == C-1 )
    distancia[i]=0;
  else{
    distancia[i]= mapa[i][j]+distancia[i+1];
    for(int j=0; j++; j< max)
      mapa[i][j]= INF;
    mapa[i][i+1]= mapa[i+1][i];
  }
}

/*
void fix_graph(int i, int C){
  if( C-1 == i )
    distancia[i]=0;
  else
    distancia[i]= mapa[i][ find(i+1) ][1] + distancia[i+1];
}

void push(int a, int b, int c, int C){
  rota[a][rota[a][MAX][0]][0] = b;
  rota[a][rota[a][MAX][0]][1] = c;
  rota[a][MAX][0]++; 
  rota[b][rota[b][MAX][0]][0] = a;
  rota[b][rota[b][MAX][0]][1] = c;
  rota[b][MAX][0]++;
}*/

int main(){
  int N, M, C, K, i,a ,b, c;
  scanf("%d %d %d %d", &N, &M, &C, &K);
  while ( N != 0){
    /*for(i=0; i<N; i++){
      mapa[i][MAX][0]= 0;
    }
    for(i=0; i<M; i++){
      scanf("%d %d %d", &a, &b, &c);
      push(a, b, c, C);
    }*/
    for(i=0; i<N;i++)
      for(j=0; j<N; j++){
        mapa[i][j]= INF;
        mapa[j][i]= INF;
      }
    for(i=0; i<M; i++){
      scanf("%d %d %d", &a, &b, &c);
      mapa[a][b]=c;
      mapa[b][a]=c;
    }
    for(i=0; i<C; i++){
      fix_graph(C-i-1,C);
    }
    bf(N);
    scanf("%d %d %d %d", &N, &M, &C, &K);
  }
}