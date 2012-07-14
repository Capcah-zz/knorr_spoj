#include <stdio.h>
#include <stdlib.h>

#define INF -1

int pontes[1001][1001];
int distances[1001];
int visited[1001]; //set s

int sum(int a, int b){
	return (a+b)*( a!=INF && b!=INF) + INF*(a == INF || b == INF);
}

int bt(int a, int b){
	return (a == INF) || (a>b && b!=INF) ;
}

int take_min(int size){
	int closest, minimum=INF;
	for(int i=0; i<size; i++)
		if (bt(minimum,distances[i]) && !visited[i] ){
			minimum= distances[i];
			closest= i;
		}
	return closest;
}

void relax(int a, int b){
	if ( bt( distances[b], sum(distances[a],pontes[a][b]) ) ){
		distances[b]= sum(distances[a],pontes[a][b]);
	}
}

int main(){
	int N, M, i,j,a,b,c;
	scanf("%d %d", &N, &M);
	for(i=0; i<N+2; i++){
		for (j=0; j<N+2; j++)
			pontes[i][j]=INF;
		distances[i]=INF;
		visited[i]=0;
	}
	distances[0]=0;
	visited[0]=0;
	for(i=0; i<M; i++){
		scanf("%d %d %d", &a, &b, &c);
		pontes[a][b]=c;
		pontes[b][a]=c;
	}
	i=0;
	while (i<N+2){
		a= take_min(N+2);
		visited[a]= 1;
		for (j=0; j<N+2;j++)
			if (pontes[a][j] != INF){
				relax(a,j);
			}
		i++;
	}
	printf("%d", distances[N+1]);
}