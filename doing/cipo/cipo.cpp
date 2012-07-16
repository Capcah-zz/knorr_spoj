#include <stdio.h>
#include <stdlib.h>

#define COUNTER 500000
#define SIZE 500001

int n, m;
int *campo[3];
int representatives[1000];
int adjacent_vertex[1000][1001];

bool check_marks(){
  for(int i=1; i< n; i++)
    if (representatives[0] != representatives[i])
      return true;
  return false;
}

void mark_set( int m1, int m2 ){
  for(int i=0; i<n; i++)
    if (representatives[i] == m1)
      representatives[i]= m2;
}

int main()
{
  int t1, t2, t3, cost;
  int count=1;
  for(int i=0; i<3; i++){
    campo[i]=(int*)malloc(SIZE*2*sizeof(int));
  }
  while ( scanf( "%d %d", &n, &m) != EOF )
  {
    for(int i=0; i<n; i++)
      representatives[i]=i;
    for(int i=0; i<3; i++)
      campo[i][2*COUNTER]=0;
    cost=0;
    for (int i=0; i< m; i++){
      scanf("%d %d %d", &t1, &t2, &t3);
      if ( t3 == 1235 ){
        campo[0][campo[0][COUNTER*2]  ]= --t1;
        campo[0][campo[0][COUNTER*2]+1]= --t2;
        campo[0][COUNTER*2]++;
      }
      else if ( t3 == 8977 ){
        campo[1][campo[1][COUNTER*2]  ]= --t1;
        campo[1][campo[1][COUNTER*2]+1]= --t2;
        campo[1][COUNTER*2]++;
      }
      else{
        campo[2][campo[2][COUNTER*2]  ]= --t1;
        campo[2][campo[2][COUNTER*2]+1]= --t2;
        campo[2][COUNTER*2]++;
      }
    }
    for(int i=0; i < campo[0][COUNTER*2]; i++){
      if( representatives[campo[0][2*i]] != representatives[campo[0][2*i+1]] ){
        cost+=1235;
          for(int j=0; j<n; j++)
            if (representatives[j] == campo[0][j*2])
              representatives[j]= campo[0][j*2+1];
      }
    }
    //if(check_marks(//representatives,
    //  ))
    //{
      for(int i=0; i < campo[1][COUNTER*2]; i++){
        if( representatives[campo[1][i*2]] != representatives[campo[1][2*i+1]] ){
          cost+=8977;
          for(int j=0; j<n; j++)
            if (representatives[j] == campo[1][j*2])
              representatives[j]= campo[1][j*2+1];
        }
      }
      //if ( check_marks(//representatives, 
      //   ))
        for(int i=0; i < campo[2][COUNTER*2]; i++){
          if( representatives[campo[2][i*2]] != representatives[campo[2][2*i+1]] ){
            cost+=10923;
          for(int j=0; j<n; j++)
            if (representatives[j] == campo[2][j*2])
              representatives[j]= campo[2][j*2+1];
          }
        }
    //}
    printf("Instancia %d\n%d\n\n", count++, cost);
  }
}
