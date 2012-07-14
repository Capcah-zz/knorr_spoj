#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int adjacency_list[MAX][MAX+1]; 

struct dnode{
	int node;
	int distance;
};

struct dnode ds( int node, int prev ){
	struct dnode tmp, max;
	max.distance=0;
	for (int i=0; i<adjacency_list[node][MAX]; i++)
		if ( i != prev){
			tmp= ds( i, node);
			if ( tmp.distance > max.distance )
				max= tmp;
		}
	if (adjacency_list[node][MAX] == 0){
		max.node= node;
		max.distance= 0;
	}
	max.distance++;
	return max;
}

int main(){
	int i, j, k,n;
	//This represents to which city the city j connects to, the MAX element represents the lenght of the list
	scanf("%d", &n);
	for(i=0; i<n; i++)
		adjacency_list[i][MAX]=0;
	for(i=0; i<n; i++){
		scanf("%d %d", &j, &k);
		adjacency_list[i-1][adjacency_list[i-1][MAX]]=j-1;
		adjacency_list[i-1][MAX]++;
		adjacency_list[j-1][adjacency_list[j-1][MAX]]=i-1;
		adjacency_list[j-1][MAX]++;
	}
	//Always start with 0
	int res= ds( ds( 0, -1 ).node,-1).distance;
	printf("%d\n", res);
}




