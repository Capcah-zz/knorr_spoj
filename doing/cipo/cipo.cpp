#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

int n, m;
int campo[3][SIZE+1][2];
int representatives[1000];

void printm(){
  for(int m=0; m<3; m++)
    for(int j=0; j< campo[m][SIZE][0]; j++)
      printf("%d,%d:>%d\n",campo[m][j][0], campo[m][j][1], m );
}

void push(int a,int b, int weight){
  campo[weight][campo[weight][SIZE][0]][0]= a;
  campo[weight][campo[weight][SIZE][0]][1]= b;
  campo[weight][SIZE][0]++;
}

int main()
{
  int t1, t2, t3;
  long long int cost;
  int count=1;
  while ( scanf( "%d %d", &n, &m) != EOF )
  {
    for(int i=0; i<n; i++){
      representatives[i]=i;
      for(int j=0; j<3; j++)
        campo[j][SIZE][0]=0;
    }
    cost=0;
    for (int i=0; i< m; i++){
      scanf("%d %d %d", &t1, &t2, &t3);
      t1--; t2--;
      if ( t3 == 1235 )
        push(t1,t2,0);
      else if ( t3 == 8977 )
        push(t1,t2,1);
      else
        push(t1,t2,2);
    }
    for(int i=0; i < campo[0][SIZE][0]; i++){
      if( representatives[campo[0][i][0]] != representatives[campo[0][i][1]] ){
        cost+=1235;
          for(int j=0; j<n; j++)
            if (representatives[j] == representatives[campo[0][i][0]])
              representatives[j]= representatives[campo[0][i][1]];
      }
    }
    for(int i=0; i < campo[1][SIZE][0]; i++){
      if( representatives[campo[1][i][0]] != representatives[campo[1][i][1]] ){
        cost+=8977;
        for(int j=0; j<n; j++)
          if (representatives[j] == representatives[campo[1][i][0]])
            representatives[j]= representatives[campo[1][i][1]];
      }
    }
    for(int i=0; i < campo[2][SIZE][0]; i++){
      if( representatives[campo[2][i][0]] != representatives[campo[2][i][1]] ){
        cost+=10923;
      for(int j=0; j<n; j++)
        if (representatives[j] == representatives[campo[2][i][0]])
          representatives[j]= representatives[campo[2][i][1]];
      }
    }
    for(int i=0; i<n; i++)
      printf("%d,",representatives[i] );
    printf("\n");
    printf("Instancia %d\n%lld\n\n", count++, cost);
  }
}
