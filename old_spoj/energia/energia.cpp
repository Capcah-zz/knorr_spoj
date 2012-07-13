#include <stdio.h>
#include <stdlib.h>
/*
Danilo Carvalho Martins;
Turma 02;
Usuário do spoj: knorr_ita;
Questão: ENERGIA

Algoritmos empregados:
  -Travessia de grafo.
Resumo do Algorimo:
    Das linhas 36 à 48, é lido o input e inicializadas
  as variáveis, linhas[i] é uma "lista", com o seu tamanho+1
  sendo marcado pelo ultimo elemento, formando uma lista de
  adjacência.
    Na linha 60, é percorrido o grafo, marcando-se os 
  vértices percorridos, tendo cuidado pra não percorrer o
  mesmo vértice duas vezes, para isso usando a marcação
  BRANCO e CINZA. Das linhas 62 a 64 é checado se todos
  os vértices foram visitados
    O tempo de execução equivale ao tempo de execução de 
  uma travessia de grafo, O(|E|+|V|). 
Desempenho no SPOJ:
  0.06 segundos de 1 segundo.
*/
#define BRANCO 0
#define CINZA 1

bool traverse_graph( int graph[100][101],int start,int marcacao[100] ){
  if ( marcacao[start] == CINZA )
    return false;
  else{
    marcacao[start]= CINZA;
    for ( int i=0; i < graph[start][100]; i++ ){
      traverse_graph( graph, graph[start][i], marcacao);
    }
  }
}

int main(){
  int estacoes, numero_linhas, t1, t2, i, count;
  int linhas[100][101];
  int marcacao[100];
//Inicialização de variáveis
  scanf("%d %d", &estacoes, &numero_linhas);
  count=1;
  while( estacoes !=0 ){
    for (i=0; i<estacoes; i++){
      linhas[i][100]= 0;
      marcacao[i]= 0;
    }
    for (i=0; i<numero_linhas; i++){
      scanf("%d %d", &t1, &t2);
      t2--;t1--;
      linhas[t1][linhas[t1][100]]= t2;
      linhas[t2][linhas[t2][100]]= t1;
      linhas[t1][100]++;
      linhas[t2][100]++;
    }
//Travessia de grafo
    traverse_graph( linhas, 0, marcacao );
//Checagem se todos os elementos foram visitados
    for (i=0; i<estacoes; i++)
      if ( marcacao[i] == 0)
        break;
//Imprimir a resposta
    printf("Teste %d\n", count );
    count++;
    if ( i == estacoes )
      printf("normal\n\n" );
    else
      printf("falha\n\n");
    scanf("%d %d", &estacoes, &numero_linhas);
  }
}
/*
A distribuição de energia para as diversasregiões do país exige
um investimento muito grande em linhas de transmissão e estações
transformadoras. Uma linha de transmissão interliga duas estações
transformadoras. Uma estação transformadora pode estar interligada
a uma ou mais outras estações transformadoras, mas devido ao alto
custo não pode haver mais de uma linha de transmissão interligando
duas estações.

As estações transformadoras são interconectadas de forma a garantir
que a energia possa ser distribuída entre qualquer par de estações.
Uma rota de energia entre duas estações e1 e ek é deﬁnida como uma
sequência (e1 , l1 , e2 , l2 , ...ek−1 , lk−1 , ek ) onde cada ei
é uma estação transformadora e cada li é uma linha de transmissão
que conecta ei ei+1.

Os engenheiros de manutenção do sistema de transmissão de energia
consideram que o sistema está em estado normal se há pelo menos uma
rota entre qualquer par de estações, e em estado de falha caso contrário.

Um grande tornado passou pelo país daniﬁcando algumas das linhas
de transmissão, e os engenheiros de manutenção do sistema de transmissão
de energia necessitam de sua ajuda.
Tarefa

Dada a conﬁguração atual do sistema de transmissão de energia,
descrevendo as interconexões existentes entre as estações, escreva
um programa que determine o estado do sistema.
Entrada

A entrada é composta de vários casos de teste. A primeira linha de
um caso de teste contém dois números inteiros E e L indicando
respectivamente o número de estações (3 ≤ E ≤ 100) e o número de
linhas de transmissão do sistema (E − 1 ≤ L ≤ E × (E − 1)/2) que
continuam em funcionamento após o tornado. As estações são identiﬁcadas
por números de 1 a E. Cada uma das L linhas seguintes contém dois
inteiros X e Y que indicam que existe uma linha de transmissão
interligando a estação X à estação Y. O ﬁnal da entrada é indicado por E = L = 0.

A entrada deve ser lida do dispositivo de entrada padrão.
Saída

Para cada caso de teste seu programa deve produzir três linhas na saída.
A primeira identiﬁca o conjunto de teste no formato “Teste n”, onde n é
numerado a partir de 1. A segunda linha deve conter a palavra “normal”,
se, para cada par de estações, houver uma rota que as conecte, e a palavra
“falha” caso não haja uma rota entre algum par de estações. A terceira linha
deve ser deixada em branco. A graﬁa mostrada no Exemplo de Saída, abaixo,
deve ser seguida rigorosamente.

A saída deve ser escrita no dispositivo de saída padrão.
Exemplos

Entrada:
6 7
1 2
2 3
3 4
4 5
5 6
6 2
1 5
4 3
1 2
4 2
1 4
0 0

Saida:
Teste 1
normal

Teste 2
falha

*/