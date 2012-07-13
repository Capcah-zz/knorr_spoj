#include <stdio.h>
#include <stdlib.h>

/*
Algoritmo de FloydWarshall levemente modificado pra salvar cada iteração.
*/
#define INFINITO -1

int MIN ( int a, int b ) 
{
	if ( a == INFINITO ) return b;
	if ( b == INFINITO ) return a;
	if ( a < b ) return a;
	else return b;
}

int add( int a, int b )
{
	if ( a == INFINITO || b == INFINITO ) return INFINITO;
	return a+b;
}

void FloydWarshall( int n, int path[100][100], int storage[100][100][100])
{
	for (int i= n; i--; )
		for (int j= n; j--;)
			storage[0][i][j]= path[i][j];
	for (int k= 1; k<=n; k++ )
		for (int j= 0; j<n; j++)
			for (int i= 0; i<n; i++)
					storage[k][i][j] = MIN(storage[k-1][i][j], add( storage[k-1][i][k-1], storage[k-1][k-1][j]) );
}

int main()
{
	int numero_cidades, numero_escalas;
	int count= 0;
	int i, j, inicial, final, distancia, consultas, origem, destino, quantidade_escalas;
	int rotas[100000][3];
	int path[100][100];
	int stor[100][100][100];
	while ( scanf("%d %d\n", &numero_cidades, &numero_escalas) != EOF )
	{
		count++;
;
		for ( i= numero_cidades; i--; path[i][i]=0; ) for ( j= numero_cidades; j--; path[i][j]= INFINITO );
		for ( i= numero_escalas; i--; if (path[inicial-1][final-1] > distancia || path[inicial-1][final-1] == -1) path[inicial-1][final-1]= distancia )
		{
			scanf( "%d %d %d\n", &inicial, &final, &distancia );
			if (path[inicial-1][final-1] > distancia || path[inicial-1][final-1] == -1)
				path[inicial-1][final-1]= distancia;
		}
		FloydWarshall( numero_cidades, path, stor );
		scanf("%d\n", &consultas);
		printf( "Instancia %d\n",count );
		for (i=consultas; i--; )
		{
			scanf("%d %d %d\n", &origem, &destino, &quantidade_escalas);
			printf( "%d\n", stor[quantidade_escalas][origem-1][destino-1] );
		}	
		printf("\n");
	}
}