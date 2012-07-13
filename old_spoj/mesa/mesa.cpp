#include <stdio.h>
#include <stdlib.h>

/*
Danilo Carvalho Martins;
Turma 02;
Usuário do spoj: knorr_ita;
Questão: MESA

Algoritmos empregados:
  -Colorir grafo.
Resumo do Algorimo:
		Incialmente, o programa monta um grafo com as relacões
	dos convidados, armazenando-os em tabela_relacões, 
	tabela_relacões[i][j] diz se i e j estão ligados, sendo 1
	se forem ligados e 0 caso contrário.
		Em seguida, trata-se o caso empecial em que só há um
	convidado à mesa.
		Então, percorre-se o grafo, pintando-o de duas cores,
	essas cores ficam armazenadas em marcação, e o algoritmo
	procura se existem duas cores que estão conectadas, pois
	a existência de tal aresta indica a existência de um 
	ímpar-ciclo, e se existe um ímpar-ciclo, não há como dispor
	os convidados ao redor da mesa. O algoritmo procura por
	elementos de não tenham sido percorridos ainda, para o caso
	de o grafo ser disjunto.
		Como todos os vértices e arestas são percorridos um número
	de vezes que independe da quantidade de vértices ou arestas,
	o tempo de execução desse algoritmo é O(|E|+|V|).
Desempenho no SPOJ:
  1.82 segundos de 2 segundos.
*/

int buscar(int start, int colour, int marcacao[100], int campo[100][100], int size )
{
	if ( marcacao[start] != 0)
	{
		if ( colour != marcacao[start] ) return 0;
	}
	else
	{
		marcacao[start]= colour;
		for (int i=0; i<size; i++)
			if ( campo[start][i] == 1 )
				if ( buscar (i, colour*(-1), marcacao, campo, size) == 0 )
					return 0;
	}
	return 1;
}

int main()
{
	int convidados, relacoes, r1,r2,count, res, i, j,temp;
	int contador= 0;
	int tabela_relacoes[100][100];
	int marcacao[100];
//Montar o grafo de relacões
	while ( scanf("%d %d\n",&convidados,&relacoes) != EOF)
	{
		contador++;
		if ( convidados == 1 )
		res = 1;
		for (i=0; i<convidados; i++)
		{
			marcacao[i]= 0;
			for (j=0; j<convidados; j++)
				tabela_relacoes[i][j]= 0;
		}
		for ( i=0; i<relacoes; i++)
		{
			scanf("%d %d\n", &r1, &r2);
			tabela_relacoes[r1-1][r2-1]= 1;
			tabela_relacoes[r2-1][r1-1]= 1;
		}
//Caso especial
		if ( convidados == 1 )
		{
			printf("Instancia %d\n",contador);
			printf("sim\n\n");
			continue;
		}
//Pintar o grafo
		for ( i=0; i<convidados; i++)
		{
			if ( marcacao[i] == 0 )
				if ( 0 == (res = buscar( i, 1, marcacao, tabela_relacoes, convidados ) ) )
					break; 
		}
//Imprimir a resposta
		printf("Instancia %d\n",contador);
		if ( !res ) printf("nao\n\n");
		else printf("sim\n\n");
	}
}
/*
Já comentamos as festas da Sra. Montagny à beira do
Lake Louise em Banff. Nas suas festas ela se compromete
a resolver um outro problema que faz tremer organizadores
de jantares em todo o mundo: onde sentar os convidados.
A magnata simplifica bastante o problema pedindo aos convidados,
no mesmo questionário já comentado, que anote na lista dos
convidados aqueles que desejariam ter à sua frente na mesa do jantar. 
A idéia é ter seus amigos sempre à sua frente, para que a conversa
possa fluir melhor. A habilidade da socialite é tamanha que ela
foi contratada pelo Fairmont Banff Springs hotel (hotel em que vão
ocorrer as finais mundiais do ICPC em 2008: Hotel) para trabalhar
no arranjo de mesas de banquete.

Sua tarefa neste problema é auxiliar novamente a magnata. Dados os
desejos dos convidados, seu programa deve decidir se é possível dispô-los
numa mesa de forma que cada convidado tenha todos os seus amigos no lado
oposto da mesa.

Entrada

A entrada é composta de diversas instâncias. A primeira linha de cada
instância contém dois inteiros n (1 <= n <= 100) e m (0 <= m <= n(n-1)/2),
onde n é o número de convidados e m é o número de relações de amizade.
Cada uma das m linhas seguintes contém dois inteiros u e v indicando que
u é amigo de v e v é amigo de u, onde 1 <= u,v <= n.

A entrada termina com final de arquivo.
Saída

Para cada instância, você deverá imprimir um identificador Instancia k,
onde k é o número da instância atual. Na linha seguinte imprima sim se
é possível e nao caso contrário.

Após cada instância imprima uma linha em branco.
Exemplo

Entrada:
3 3
1 2
2 3
1 3
4 3
1 2
1 3
1 4

Saída:
Instancia 1
nao

Instancia 2
sim
*/