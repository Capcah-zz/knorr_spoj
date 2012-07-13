#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

/*
Danilo Carvalho Martins;
Turma 02;
Usuário do spoj: knorr_ita;
Questão: REDOTICA

Algoritmos empregados:
  -Kruskal;
  -Quicksort(ordenar a lista de vertices em Kruskal, 
    usei a implementação do quicksort em std por 
    simplicidade e tamanho do código, caso o senhor 
    queria, posso fazer uma implementaçao a parte do
    quicksort);

Resumo do Algorimo:
    Das linhas 59 à 91, acontece a leitura do input do
  problema, seguido do seu processamento, transformando
  o input em uma espécie de lista de arestas(edges), onde o
  ultimo elemento dessa lista contém o tamanho da mesma+1.
  O array repr contém os representantes de cada vértice,
  por simplicidade, escolhi inicialmente cada representante
  sendo o próprio vértice.;
    Das linhas 91 à 100, primeiramente ordenamos a lista de
  edges, em seguida iteramos essa lista, checando se dois 
  pontos ja foram previamente ligados pelo algoritmo, e se
  não, ligando-os. O procedimento de integração, consiste em
  procurar na lista repr os representates iguais aos de um vértice
  e mudar seu valor para os representantes do outro.
    O tempo de execução do código iguala-se ao tempo de execução
  do algoritmo de kurskal, que é O(|E|log|E|)
Desempenho no SPOJ:
  0.11 segundos com máximo em 1 segundo.
*/

int comp( const void * a, const void * b ){
  int** c= (int**)a;
  int** d= (int**)b;
  if ( *(*(c)+2) > *(*(d)+2) )
    return 1;
  if ( *(*(c)+2) == *(*(d)+2) ){
    if ( **c > **d )
      return 1;
    if ( **c == **d )
      if ( *(*(c)+1) > *(*(d)+1) )
        return 1;
  }
  return 0;
}

int comp2( const void * a, const void * b){
  int** c= (int **)a;
  int** d= (int **)b;
  if ( **c > **d )
    return 1;
  else if ( **c == **d )
    if ( *(*(c)+1) > *(*(d)+1) )
      return 1;
  return 0;
}

void append_trees( int r1, int r2, int repr[100], int size){
  for (int i = 0; i < size; ++i)
    if ( repr[i] == repr[r2] && i != r2 ) repr[i]= repr[r1];
  repr[r2]=repr[r1];
}

int main(){
//Declaração de variáveis.
  int N,M,t1,t2,t3,count;
  int * resposta[10001];
  int * edge_list[10001];
  int *ptr;
  int repr[100];
//Iniciação
  for(int i=0; i<10000; i++){
    edge_list[i]= (int*) malloc(3*sizeof(int));
    resposta[i]= (int*) malloc(2*sizeof(int));
  }
  edge_list[10000]= (int*) malloc(sizeof(int));
  resposta[10000]= (int*) malloc(sizeof(int));
  count=0;
  scanf("%d %d", &N, &M);
  while (N!=0){
    resposta[10000][0]= 0;
    edge_list[10000][0]= 0;
    for (int i = 0; i < N; ++i){
      repr[i]= i; //each vertex is it's own representative
    }
    for(int i=0; i<M; i++){
      scanf("%d %d %d",&t1,&t2,&t3);
      t1--;t2--;
      edge_list[edge_list[10000][0]][0]= t1;
      edge_list[edge_list[10000][0]][1]= t2;
      edge_list[edge_list[10000][0]][2]= t3;
      edge_list[10000][0]++;
    }
//Kruskal
    std::qsort(edge_list, edge_list[10000][0], sizeof(ptr), comp);//quicksort
    for (int i=0; i < edge_list[10000][0]; i++)
      if ( repr[edge_list[i][0]] != repr[edge_list[i][1]] ){
        resposta[ resposta[10000][0] ][ edge_list[i][0] > edge_list[i][1] ]= edge_list[i][0];
        resposta[ resposta[10000][0] ][ edge_list[i][0] < edge_list[i][1] ]= edge_list[i][1];
        resposta[10000][0]++;
        append_trees( edge_list[i][0], edge_list[i][1], repr, N);
      }
//Imprimindo o resultado
    printf("Teste %d\n", ++count );
    for (int i = 0; i < resposta[10000][0]; ++i)
      printf("%d %d\n", resposta[i][0]+1, resposta[i][1]+1);
    printf("\n");
    scanf("%d %d",&N,&M);
  }
}
/*
Os caciques da região de Tutuaçu pretendem integrar suas tribos à chamada “aldeia global”.
A primeira providência foi a distribuição de telefones celulares a todos os pajés. Agora,
planejam montar uma rede de fibra ótica interligando todas as tabas. Esta empreitada requer
que sejam abertas novas picadas na mata, passando por reservas de flora e fauna. Conscientes
da necessidade de preservar o máximo possível o meio ambiente, os caciques encomendaram um
estudo do impacto ambiental do projeto. Será que você consegue ajudá-los a projetar a rede
de fibra ótica?
Tarefa

Vamos denominar uma ligação de fibra ótica entre duas tabas de um ramo de rede. Para
possibilitar a comunicação entre todas as tabas é necessário que todas elas estejam interligadas,
direta (utilizando um ramo de rede) ou indiretamente (utilizando mais de um ramo). Os caciques
conseguiram a informação do impacto ambiental que causará a construção dos ramos. Alguns ramos,
no entanto, nem foram considerados no estudo ambiental, pois sua construção é impossível.

Sua tarefa é escrever um programa para determinar quais ramos devem ser construídos, de forma
a possibilitar a comunicação entre todas as tabas, causando o menor impacto ambiental possível.
Entrada

A entrada é composta de vários conjuntos de teste. A primeira linha de um conjunto de teste
contém dois números inteiros positivos N e M que indicam, respectivamente, o número de tabas e o
número de ramos de redes possíveis. As tabas são numeradas de 1 a N. As M linhas seguintes contêm
três inteiros positivos X, Y e Z, que indicam que o ramo de rede que liga a taba X à taba Y tem
impacto ambiental Z. Com os conjuntos de teste dados sempre é possível interligar todas as tabas.
O final da entrada é indicado quando N = 0.
Saída

Para cada conjunto de teste da entrada seu programa deve produzir uma lista dos ramos de redes
que devem ser construídos. A lista deve ser precedida de uma linha que identifica o conjunto de
teste, no formato "Teste n", onde n é numerado a partir de 1. A lista é composta por uma sequência
de ramos a serem construídos, um ramo por linha. Um ramo é descrito por um par de tabas X e Y ,
com X < Y. Os ramos de rede podem ser listados em qualquer ordem, mas não deve haver repetição.
Se houver mais de uma solução possível, imprima apenas uma delas. O final de uma lista de ramos
deve ser marcado com uma linha em branco. A grafia mostrada no Exemplo de Saída, abaixo, deve ser
seguida rigorosamente.
Exemplo

Entrada:
3 3
1 2 10
2 3 10
3 1 10
5 6
1 2 15
1 3 12
2 4 13
2 5 5
3 2 6
3 4 6
0 0

Saída:
Teste 1
1 2
1 3

Teste 2
1 3
2 3
2 5
3 4

*/