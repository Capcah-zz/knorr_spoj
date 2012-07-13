#include <stdio.h>
#include <stdlib.h>

int dados[10000][6];

int calculate_maximum(int dice, int cur, int size){
  int face_up;
  if(cur == size)
    return 0;
  for (int i=0; i<6 ; i++)
    if (dados[cur][i] == dice)
      face_up= 5-i;
  int max=0;
  for (int i=0; i<6; i++)
    if (i!= face_up && i!=(5 - face_up) && dados[cur][i] > max )
      max= dados[cur][i];
  return (max+1 + calculate_maximum( dados[cur][face_up], cur+1,size ));
}

int main(){
  float dorgas;
  int N,i,a,b,c,d,e,f, tmp, max;
  scanf("%d",&max);
  for (i=0; i<max; i++){
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    dados[i][0]=a-1;
    dados[i][1]=b-1;
    dados[i][2]=c-1;
    dados[i][3]=e-1;
    dados[i][4]=d-1;
    dados[i][5]=f-1;
  }
  N=max;
  max=0;
  for (i=0; i<6; i++){
    tmp= calculate_maximum(i,0, N);
    if (tmp>max)
      max=tmp;
  }
  printf("%d", max);
}