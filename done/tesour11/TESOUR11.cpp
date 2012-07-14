#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main(){
	int dimensao, dicas,i, x, y,d,j,k, count, res, xf, yf ;
	int mapa[100][100][100];
	res=0;
	scanf("%d %d", &dimensao, &dicas);
	for (i=0; i<dicas; i++){//distancia eh x+y
		scanf("%d %d %d",&x, &y, &d);
		for(j= 0; j< dimensao; j++)
			for (k = 0; k < dimensao; ++k)
				mapa[i][j][k]= ( abs(j-x) + abs(k-y) - d );
	}
	for(j= 0; j< dimensao && res<2; j++)
		for (k = 0; k < dimensao; ++k){
			count=0;
			for (i=0; i<dicas; i++)
				count= count || mapa[i][j][k];
			if (!count){
				res++;
				xf= j; yf= k;
			}
		}
	if (res == 1)
		printf("%d %d",xf, yf );
	else
		printf("-1 -1");
}