#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define CAVALOS 100
#define SOLDADOS 100

bool compare_soldiers( int first[2], int second[2] ){ return (first[0]<second[0]); }

int find_new( int relacao[CAVALOS], int posicao_anterior, int tamanho ){
  for ( int i= 0; i < tamanho; i++)
    if ( relacao[i][1] == posicao_anterior ) 
      return i; 
  }

int main()
{
  int soldados, cavalos, numero_relacoes;
  int temp[2];
  int relacao[CAVALOS][2];//antigo->novo
  int dummy[CAVALOS];
  int relacoes[SOLDADOS][CAVALOS+1];//no primeiro elemento, estará guardado o tamanho do array
  int capacidade_cavalos[CAVALOS][2];//0->capacidade 1-> cavalo
  int quantidade_opcoes[SOLDADOS][2];// 0-> somatorio do numero de possibilidades 1-> soldado
  while ( scanf("%d %d %d", &cavalos, &soldados, &numero_relacoes) != EOF ){
    for ( int i= 0; i < SOLDADOS; i++){
      relacoes[i][0]= 0;
      quantidade_opcoes[i][0]= 0;
      quantidade_opcoes[i][1]= i;
    }
    for ( int i= 0; i < cavalos; i++ )
    {
      scanf("%d", capacidade_cavalos + i );
      
    
    for ( int i= 0; i < numero_relacoes; i++ ){
      scanf("%d %d", temp, temp+1);
      relacoes[temp[1]][0]++;
      relacoes[ temp[1] ][ relacoes[temp[1]][0] ]= temp[0];
      quantidade_opcoes[temp[1]][0]+= capacidade_cavalos[temp[0]];
    }
    std::sort( quantidade_opcoes, quantidade_opcoes + 2*soldados, compare_soldiers);
}