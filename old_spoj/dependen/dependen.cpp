#include <stdio.h>
#include <stdlib.h>
/*
Danilo Carvalho Martins;
Turma 02;
Usuário do spoj: knorr_ita;
Questão: DEPENDEN

Algoritmos empregados:
  -Travessia de grafo.
Resumo do Algorimo:
    As linhas 55 à 61 tratam de um caso especial. Das
  linhas 61 à 76, são inicializadas as variáveis, 
  com a distances representando a quantidade de
  dependências e relations[i][100], o tamanho da "lista"
  relations[i], pois como a quantidade de elementos é
  limitada, essa implementação é mais eficiente e mais
  simples.
    O algoritimo, da 76 à 89, consiste em realizar DFS,
  marcando a maior dependencia obtida até então, repetindo
  várias vezes para aqueles pontos que não foram percorridos
  anteriormente, para o caso em que o gráfico é "disjoint"
    Ao se realizar as sucessivas buscas, se percorrerá todo
  vértice um numero pequeno de vezes e toda aresta exatamente
  uma vez, o que resulta em uma complexidade O(|E|+|V|)
Desempenho no SPOJ:
  0.05 segundos de 1 segundo.
*/

int distances[100];
int N;

int search_for_biggest_path(int graph[100][101], int start, int marcado[100]){
  int d= 1;
  for(int i=0; i<graph[start][100]; i++)
    if ( !marcado[graph[start][i]] )
      d+= search_for_biggest_path( graph, graph[start][i], marcado);
  distances[start]= d;
  marcado[start]= 1;
  return d;
}

void procurar( int graph[100][101], int start ){
  int marcado[100];
  for(int i=0; i<N; i++)
    marcado[i]=0;
  search_for_biggest_path(graph,start, marcado);
}

main(){
  int safe, T, temp, k, t2;
  int relations[100][101]; //a depende de b
  scanf("%d", &N);
  while ( N != 0 ){
//Caso especial
    if ( N == 1){
      printf("1\n");
      scanf("%d", &N);
      continue;
    }
//Inicialização
    safe=0;
    for (int i=0; i<N; i++){
      scanf("%d", &T);
      if ( T!=0 )
        safe=1;
      distances[i]=1;
      relations[i][100]=0;
      for (int j=0; j<T; j++){
        scanf("%d", &temp);
        temp--;
        relations[i][relations[i][100]]= temp;
        relations[i][100]++;
      }
    }
//Algoritmo
    k=0;
    t2=101;
    for (int i=0; i<N; i++){
      procurar(relations, i);
      temp=distances[i];
      if (temp > k){
        t2= i;
        k= temp;
      }
    }
    if (safe == 0)
      t2= 0;
//Imprimir
    printf("%d\n", t2+1);
    scanf("%d", &N);
  }
}
/*
Neste problema você precisa descobrir qual é a tarefa que possui 
o maior número de dependências. Uma tarefa A depende de outra tarefa
B se B é uma dependência direta ou indireta de A.

Por exemplo, se A depende de B e B depende de C, então A possui
duas dependências, um direta e outra indireta.

Você pode assumir que não existem dependências cíclicas na entrada.
Entrada

A entrada consiste de um conjunto de cenários. Cada cenário começa
com um inteiro N, 0 < N ≤ 100, em uma linha indicando quantas tarefas
esse cenário possui. Haverá então N linhas, uma para cada tarefa. Cada
linha contém um inteiro 0 ≤ T ≤ N-1, o número de dependências diretas
daquela tarefa, mais T inteiros, os identificadores daquelas dependências. 
Tarefas são numeradas de 1 até N.

A entrada terminada com um cenário onde N = 0.
Saída

Para cada cenário, imprima em uma linha o número da tarefa que possui
o maior número de dependências. Em caso de empate, mostre a tarefa com
o menor identificador.
Exemplo

Entrada:
3
1 2
1 3
0
4
2 2 4
0
2 2 4
0
0

Saída:
1
1

*/