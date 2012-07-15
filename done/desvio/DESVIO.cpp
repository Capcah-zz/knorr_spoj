#include <stdio.h>
#include <stdlib.h>

#define MAX 250

#define INF -1

typedef struct {
  int id;
  int weight;
} city;

city mapa[MAX][MAX+1];
int visited[MAX];
int distancia[MAX];

void print_graph(int size){
  for(int i=0; i< size; i++){
    for (int j=0; j< mapa[i][MAX].weight; j++)
      printf("(%d:%d),", mapa[i][j].id,mapa[i][j].weight );
    printf("\n");
  }
}

void print_distances(int size){
  for(int i=0; i<size; i++)
    printf("%d..",distancia[i] );
  printf("\n");
}

void push(int a, int b, int c){
  mapa[a][ mapa[a][MAX].weight ].weight= c;
  mapa[a][ mapa[a][MAX].weight ].id= b;
  mapa[a][MAX].weight++;
  mapa[b][ mapa[b][MAX].weight ].weight= c;
  mapa[b][ mapa[b][MAX].weight ].id= a;
  mapa[b][MAX].weight++;
}

int sum(int a, int b){
  return (a+b)*( a!=INF && b!=INF) + INF*(a == INF || b == INF);
}

int bt(int a, int b){
  return (a == INF) || (a>b && b!=INF) ;
}

/*void relax(int a, int b){
  int k= mapa[a][b].weight;
  int j= mapa[a][b].id;
  if ( bt( distancia[j], sum(distancia[a],k) ) ){
    distancia[j]= sum(distancia[a],k);
  }
}*/

void relax(int a, int b, int C){
  int k= mapa[a][b].weight;
  int j= mapa[a][b].id;
  if ( bt( distancia[j], sum(distancia[a],k) ) && C<=j ) 
    distancia[j]= sum(distancia[a],k);
}

int minimum_distance( int N ){
  int min=INF;
  int val= -1;
  for(int i=0; i<N; i++){
    if ( bt(min,distancia[i]) && !visited[i] ){
      min= distancia[i];
      val=i;
    }
  }
  return val;
}

void ds(int N, int C){
  int a;
  for(int i=0; i<N; i++){
    a= minimum_distance(N);
    visited[a]= 1;
    for(int j=0; j<mapa[a][MAX].weight; j++)
      relax(a, j, C);
  }  
}

int find(int current){
  for (int i=0; i< mapa[current][MAX].weight; i++)
    if ( mapa[current][i].id == current+1 )
      return i;
  return -1;
}

/*void fix_graph(int i, int C, int max){
  city temp;
  if ( i == C-1 ){
    distancia[i]=0;
  }
  else{
    temp= mapa[i][find( i )];
    distancia[i]= sum(temp.weight,distancia[i+1]);
    mapa[i][MAX].weight=1;
    mapa[i][0]= temp;
  }
}*/

void fix_cons(int i, int C, int max){
  city temp;
  if ( i == C-1 ){
    distancia[i]=0;
  }
  else{
    temp= mapa[i][find( i )];
    distancia[i]= sum(temp.weight,distancia[i+1]);
  }
}

int main(){
  int N, M, C, K, i,a ,b, c,j;  
  scanf("%d %d %d %d", &N, &M, &C, &K);
  while ( N != 0){
    
    for(i=0; i<N;i++){
      distancia[i]= INF;
      visited[i]=0;
      mapa[i][MAX].weight= 0;
    }

    for(i=0; i<M; i++){
      scanf("%d %d %d", &a, &b, &c);
      push(a,b,c);  
    }
    for(i=0; i<C; i++)
      fix_cons(C-i-1,C, N);

    //print_graph(N);
    //print_distances(N);

    ds(N,C);

    //print_distances(N);

    printf("%d\n",distancia[K] );
    scanf("%d %d %d %d", &N, &M, &C, &K);
  }
}