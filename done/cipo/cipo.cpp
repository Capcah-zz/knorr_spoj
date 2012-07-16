#include <stdio.h>
#include <stdlib.h>

#define SIZE 2000000

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

//    for(int i=0; i < 3; i++ ){
//      for(int j=0; j< campo[i][SIZE][0]; j++)
//        printf(">%d:%d:%d,",i, campo[i][j][0], campo[i][j][1] );
//      printf("\n");
//    }
    for(int k=0; k< 3; k++){
      for(int i=0; i < campo[k][SIZE][0]; i++)
        if( representatives[campo[k][i][0]] != representatives[campo[k][i][1]] ){
//          for(int ij=0; ij<n; ij++)
//            printf("%d,",representatives[ij] );
//          printf("\n");
          cost+=1235*(k== 0)+8977*(k== 1)+10923*(k== 2) ;
          for(int j=0; j<n; j++){
            if (representatives[j] == representatives[campo[k][i][0]] && j != campo[k][i][0]){
//              printf("%d-%d-%d\n",representatives[campo[k][i][0]],representatives[campo[k][i][1]] ,k);
              representatives[j]= representatives[campo[k][i][1]];
            } 
          }
          representatives[campo[k][i][0]]= representatives[campo[k][i][1]];
        }
    }

    //for(int i=0; i<n; i++)
    //  printf("%d,",representatives[i] );
    //printf("\n");
    printf("Instancia %d\n%lld\n\n", count++, cost);
  }
}
