#include <stdio.h>
#include <stdlib.h>

int polenta[1000][2];

int main(){
 int N, i, x, y;
 scanf("%d", &N);
 for (i=0; i< N; i++){
  scanf("%d %d", &x, &y);
  polenta[i][0]=x;
  polenta[i][1]=y;
 }
   
}