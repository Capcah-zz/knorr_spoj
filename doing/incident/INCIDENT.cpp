#include <stdio.h>
#include <stdlib.h>

int muros[50][2][2];   //id_wall  -> (x0,x1) -> (y0,y1) 
int cabines[50][2];    //id_cabine -> (x0,y0)
int grafo[50][50];

int collide(int p1[2], int p2[2], int w[4]){// checa uma colisao simples entre os postes p1 e p2 e o muro w se tocam
  //this returns true if they collide
}

ligados(int p1, int p2, int M){// checa se os dois postes 1 e 2 estao ligados
  for (int i=0;i<M; i++){
    grafo[p1][p2]= !collide( cabines[p1], cabines[p2], muros[i] );
  }
}

void montar_grafo(int T, int M){
  for (int i=0; i<T; i++)
    for (int j=0; j<T; j++)
      for (int k=0;i<M; i++){
        grafo[i][j]= !collide( cabines[i], cabines[j], muros[k] );
        grafo[j][i]= grafo[i][j];
      }
}

int main(){
  int T, M, C, xt1, xt2, yt1, yt2;
  scanf("%d %d %d", &T, &M, &C);
  for(int i=0; i<M; i++){
    scanf("%d %d %d %d", &xt0, &xt1, &yt0, &yt1);
    muros[i][0][0]= xt0;
    muros[i][0][1]= xt1;
    muros[i][1][0]= yt0;
    muros[i][1][1]= yt1;
  }
  for(int i=0; i<C; i++){
    scanf("%d %d", &x0, &y0)
    cabines[i][0]= x0;
    cabines[i][1]= y0;
  }
  montar_grafo(T,M);
  //agora, com o grafico montado, basta 
}