#include <stdio.h>
#include <stdlib.h>

/*
Danilo Carvalho Martins;
Turma 02;
Usuário do spoj: knorr_ita;
Questão: Minimo

Algoritmos empregados:
  -Floyd-Warshall.
  -Programação Dinâmica.(e greedy)
Resumo do Algorimo:
		Das linhas 65 a 80, é lido o input, e armazenados as arestas
	na matriz path, de tal forma que matriz[i][j] é o peso entre os
	vértices i e j.
		O procedimento FloydWasrshall é o algorimo de Floyd-Warshall
	modificado de tal forma que ele cria vários grafos diferentes,
	um para cada profundidade, e, a partir dos grafos menos profundos,
	o algoritmo constrói os mais profundos, de tal forma que o tempo de
	construção do grafo é o mesmo do algoritmo normal.
		Portanto o tempo de execução é O(|V|³), o mesmo do algoritmo de 
	Floyd-Warshall.
Desempenho no SPOJ:
  0.36 segundos de 1 segundo.
*/

#define INFINITO -1

int MIN ( int a, int b ) 
//Esta operação trata como deve ser uma operação de minimo 
//considerando a existência de um infinito.
{
	if ( a == INFINITO ) return b;
	if ( b == INFINITO ) return a;
	if ( a < b ) return a;
	else return b;
}

int add( int a, int b )
//Analogamente para a soma
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
	int path[100][100];
	int stor[100][100][100];
//Leitura das variáveis.
	while ( scanf("%d %d\n", &numero_cidades, &numero_escalas) != EOF )
	{
		count++;
		for ( i= numero_cidades; i--; )
		{
			for ( j= numero_cidades; j--; path[i][j]= INFINITO );
			path[i][i]=0;
		}
		for ( i= numero_escalas; i--; )
		{
			scanf( "%d %d %d\n", &inicial, &final, &distancia );
			if (path[inicial-1][final-1] > distancia || path[inicial-1][final-1] == -1)
				path[inicial-1][final-1]= distancia;
		}
//Construção do grafo
		FloydWarshall( numero_cidades, path, stor );
//Leitura das consultas e realização delas, seguido da impressão do resultado
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
/*
Preocupado com a atual situação de crise no transporte aéreo, o diretor regional do concurso
do ICPC no Brasil já iniciou seus preparativos para fazer as reservas das passagens aéreas
para as finais mundiais de Banff em 2008. O primeiro passo foi estudar a malha aérea disponível,
em que cada vôo tem um certo preço e liga duas cidades (estamos, na verdade, chamando de vôo
apenas um trecho non stop de um vôo comercial). O objetivo do diretor é fazer várias consultas
nesta malha de vôos.

Em geral desejamos fazer vôos sem escalas, mas estes podem ser muito caros. Para contornar este
fato o diretor deseja permitir algumas escalas possíveis. Assim, ele ordenou as várias cidades
da malha em sua ordem de preferência para fazer escala. Ou seja, a cidade de índice 1 é a que
ele prefere fazer escala, seguida pela cidade 2, e assim por diante.

As consultas que o diretor fará são, então do seguinte tipo. É dada a cidade de partida e de
chegada e um número t de cidades em que o diretor permite que sejam feitas escalas. Seu programa
deverá encontrar o custo de um vôo de custo mínimo entre as cidades que faça, no máximo, escalas
nestas cidades. Por exemplo, se t=1 você deverá encontrar o custo de um vôo de custo mínimo entre
as duas cidades que seja, ou non stop ou que faça uma escala na primeira cidade.
Entrada

A entrada é composta de diversas instâncias. A primeira linha de cada instância consiste em dois
inteiros n (1 <= n <= 100) e m (1 <= m <= 100000), indicando o número de cidades e o número de
escalas. Nas m linhas seguintes temos três inteiros u,v e w (1 <= u,v <= n e 0 <= w <= 100) 
indicando que existe uma escala que vai de u para v com custo w. Em seguida um inteiro c
(1 <= c <= 10000) indicando o número de consultas, e nas c linhas seguintes temos três inteiros
o,d e t (1 <= o,d <= n e 0 <= t <= n) onde o é a cidade de origem, d é a cidade de destino e t
indica que as cidades 1,2,..,t podem ser usadas para escalas.

A entrada termina com final de arquivo.
Saída

Para cada instância, você deverá imprimir um identificador Instancia k, onde k é o número da
instância atual. Para cada consulta, na ordem da entrada, você deve imprimir o custo mínimo ou -1
caso não exista caminho entre as duas cidades.

Após cada instância imprima uma linha em branco.
Exemplo

Entrada:
4 7
4 1 0
2 1 3
1 4 20
2 3 15
4 2 1
3 1 21
1 2 0
3
2 1 0
4 2 2
4 3 1
5 10
4 5 2
2 1 4
1 2 7
2 4 7
5 2 1
4 1 2
4 5 12
5 4 4
5 3 7
3 5 9
4
2 5 0
3 4 5
4 5 1
2 3 2

Saída:

Instancia 1
3
0
-1


Instancia 2
-1
13
2
-1

*/