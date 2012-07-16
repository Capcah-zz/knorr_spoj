#include <stdio.h>
#include <stdlib.h>

void assing(int vectors[3][3], int a, int b, int c){
  for (int i=0; i< 3; i++){
    vectors[i][0]= a;
    vectors[i][1]= b;
    vectors[i][2]= c;
  }
}

void dif(int vector[3][3]){  
  int a,b,c;
  for (int i=0; i< 3; i++){
    scanf("%d %d %d",&a,&b,&c);
    vector[i][0]-= a;
    vector[i][1]-= b;
    vector[i][2]-= c;
  }
}

double calc_vol(int vectors[3][3]){
  //produto vetorial
  int prod_vet[3];
  prod_vet[0]= (vectors[0][1]*vectors[1][2]-vectors[0][2]*vectors[1][1]);
  prod_vet[1]= (vectors[0][2]*vectors[1][0]-vectors[0][0]*vectors[1][2]);
  prod_vet[2]= (vectors[0][0]*vectors[1][1]-vectors[0][1]*vectors[1][0]);
  int prod_esc;
  //produto escalar
  prod_esc= prod_vet[0]*vectors[2][0]+prod_vet[1]*vectors[2][1]+prod_vet[2]*vectors[2][2];
  //
  return (prod_esc>0)*double(prod_esc)/6-(prod_esc<0)*double(prod_esc)/6;
}

void print_vet(int vector[3]){
  for (int i = 0; i < 3; ++i)
  {
    printf("%d,",vector[i] );
  }
  printf("\n");
}

int main(){
  int instancias,a,b,c;
  int vectors[3][3];
  scanf("%d", &instancias);
  for(int counter=0; counter<instancias; counter++){
    scanf("%d %d %d",&a,&b,&c);
    assing(vectors,a,b,c);
    dif(vectors);

    printf("%.6f\n",calc_vol(vectors) );
  }
}