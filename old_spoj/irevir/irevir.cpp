#include "stdio.h"
#include "stdlib.h"

/*
Danilo Carvalho Martins;
Turma 02;
Usuário do spoj: knorr_ita;
Questão: IREVIR

Algoritmos empregados:
  -Travessia de grafo.
Resumo do Algorimo:
    Das linhas 50 a 72, o programa carrega as variáveis e, 
  considerando se as ruas são de mão única ou dupla, inicializam
  a matriz ruas, de tal forma que ruas[i] é a "lista" de adjacência
  da rua i, da mesma forma que as outras "listas de adjancências"
  foram implementadas nas outras questões, e se inicializa marcou
  e marcado para todos seus elementos serem 0.
    O algoritimo da linha 72 à 83 percorre o gráfico marcando
  os vértices que incidem sobre alguém e os vértices que algum
  outro incidiu nele pois, se todo vértice incidir sobre e for 
  incidido por algum outro, isso afirma que você pode chegar a 
  qualquer ponto do gráfico a partir daquele vértice, 
  repetindo para todos os vértices, checa-se que a partir de qualquer
  ponto, pode-se chegar em qualquer outro.
    Como o gráfico é percorrido |V| vezes, a complexidade do algoritmo
  é O(|V|+|V|*|E|)= O(|V|*|E|).
Desempenho no SPOJ:
  2.61 segundos de 3 segundos.
*/

bool marcacao[2000];
bool marcou[2000];
int ruas[2000][2000]; //1->2

void percorrer( int start, bool comeco ){
  if (marcacao[start])
    return;
  if ( !comeco ) marcacao[start]= true;
  for (int i=0; i<ruas[start][1999]; i++){
    percorrer( ruas[start][i], false );
    marcou[start]= true;
  }
}

int main(){
  int N,M, t1,t2,t3;
  bool ref;
  scanf("%d %d", &N, &M);
//Montar o grafo
  while ( N!= 0){
    ref=true;
    for(int i=0; i<N; i++){
      ruas[i][1999]=0;
      marcacao[i]=false;
      marcou[i]=false;
    }
    for(int i=0; i<M; i++){
      scanf("%d %d %d", &t1, &t2, &t3);
      t2--; t1--;
      if ( t3 == 2 ){
        ruas[t1][ruas[t1][1999]]= t2;
        ruas[t2][ruas[t2][1999]]= t1;
        ruas[t1][1999]++;
        ruas[t2][1999]++;
      }
      else{
        ruas[t1][ruas[t1][1999]]= t2;
        ruas[t1][1999]++;
      }
    }
//Percorrer o grafo
    for(int k=0; k<N; k++){
      for(int i=0; i<N; i++){
        marcacao[i]=false;
        marcou[i]=false;
      }
      percorrer( k, true );
      for(int i=0; i<N; i++ )
        if ( !marcacao[i] || !marcou[i] )
          ref=false;
    }
//Imprimir a resposta
    printf("%d\n", ref);
    scanf("%d %d", &N, &M);
  }
}
/*Numa certa cidade há N intersecções ligadas por ruas
de mão única e ruas com mão dupla de direcão. É uma cidade
moderna, de forma que muitas ruas atravessam túneis ou
têm viadutos. Evidentemente é necessário que se possa viajar
entre quaisquer duas intersecções, isto é, dadas duas
intersecções V e W, deve ser possível viajar de V para W e de W para V.

Sua tarefa é escrever um programa que leia a descrição do
sistema de tráfego de uma cidade e determine se o requisito de
conexidade é satisfeito ou não.
Entrada

A entrada contém vários casos de teste. A primeira linha de um
caso de teste contém dois números inteiros N e M, separados por
um espaço em branco, indicando respectivamente o número de intersecções
(2 ≤ N ≤ 2000) e o número de ruas (2 ≤ M ≤ N(N−1)/2). O caso de teste
tem ainda mais M linhas, que contêm, cada uma, uma descrição de cada
uma das M ruas. A descrição consiste de três inteiros V, W e P,
separados por um espaço em branco, onde V e W são identificadores
distintos de intersecções (1 ≤ V, W ≤ N , V ≠ W ) e P pode ser 1 ou
2; se P = 1 então a rua é de mão única, e vai de V para W; se P = 2
então a rua é de mão dupla, liga V e W. Não existe duas ruas ligando
as mesmas intersecções.

O ultimo caso de teste é seguido por uma linha que contém apenas dois
números zero separados por um espaço em branco.
Saída

Para cada caso de teste seu programa deve imprimir uma linha contendo
um inteiro G, onde G é igual a 1 se o requisito de conexidade está
satisfeito, ou G é igual a 0, caso contrário.
Exemplo

Entrada:
4 5
1 2 1
1 3 2
2 4 1
3 4 1
4 1 2
3 2
1 2 2
1 3 2
3 2
1 2 2
1 3 1
4 2
1 2 2
3 4 2
0

Saída:
1
1
0
0
*/