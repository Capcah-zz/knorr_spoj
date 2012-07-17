#include <stdio.h>
#include <stdlib.h>

#define SIZE 6000

int color[SIZE];
int mapa[SIZE][SIZE+1];

int colorize(int city, int parent ){
  int val=0;
  int paint=1;
  if( mapa[city][SIZE]> 1 || parent == -1){
    for(int i=0; i<mapa[city][SIZE]; i++){
      if (mapa[city][i] != parent)
        val+=colorize( mapa[city][i], city);
      paint= paint && !color[mapa[city][i]];
    }
    if (paint){
      val++;
      color[city]=1;
    }
  }
  else{
    color[city]=1;
    return 1;
  }
  return val;
}

int main(){
  int instancias, cidades,a,b;
  scanf("%d", &instancias);
  for(int counter=0; counter< instancias; counter++ ){
    scanf("%d", &cidades);
    for(int i=0; i<cidades; i++){
      mapa[i][SIZE]=0;
      color[i]= 0;
    }
    for(int i=0; i< cidades-1; i++){
      scanf("%d %d",&a, &b);a--;b--;
      mapa[a][mapa[a][SIZE]]= b;
      mapa[a][SIZE]++;
      mapa[b][mapa[b][SIZE]]= a;
      mapa[b][SIZE]++;
    }
    printf("%d\n", colorize(0, -1));
  }
}