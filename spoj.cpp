#include <stdio.h>
#include <stdlib.h>

#define MAX 101

int main(){
	int n_a, n_c,i, j, k, a, b, e, max;
	int entr[MAX][MAX];
	scanf("%d %d", &n_a, &n_c);
	for (i=0; i<n_a; i++)
		for(j=0; j<n_a; j++)
			entr[i][j]=0;
	for (i= 0; i<n_c; i++){
		scanf("%d %d %d", &a, &b, &e);
		entr[a-1][b-1]= e;
		entr[b-1][a-1]= e;
	}
	max=-1;
	for (i=0; i< n_a; i++){
		// Put later a condition that if the connection between two gals are 0, it should not propagate.
		// this is reasonable, since there should the maximum should not be composed of someone with zero connection.
		// This is an edge case, though.
		for (j=0; j<n_a; j++)
			for (k=0; k<n_a; k++)
				if ( entr[i][j]+entr[j][k]+entr[k][i]> max
					&& ( i!=j && j!=k && k!=i) 
					){
					max= entr[i][j]+entr[j][k]+entr[k][i];
					a=i;b=j;e=k;
				}
	}
	printf("%d %d %d", a+1, b+1, e+1);
	//O(E³ complexity), might be able to bring it down to O(E²)
}
