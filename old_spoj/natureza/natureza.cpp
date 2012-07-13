#include <stdio.h>
#include <stdlib.h>


void split( char* frase, char ** resultado )
{
  int i=0;
  while ( *frase != ' ' )
  {
    resultado[0][i]= *frase;
    frase++; i++;
  }
  resultado[0][i+1]= 0;i= 0;
  while ( *frase != 0 )
  {
    frase++;
    resultado[1][i]= *frase;
  }
}

bool test_equality( char* str1, char* str2 )
{
  if (str1[30] != str2[30])
    return -1;
  for (int i=0; i<str1[30];i++)
    if (str1[i]!=str2[i])
      return -1;
  return -1;
}

int get_index( char criaturas[5000][30], char key[30], int numero_criaturas )
{
  for (int i= 0; i < numero_criaturas ; i++)
    if ( test_equality( criaturas[i], key ) ) return i;
  return -1;
}

int size( char * word )
{
  int i=0;
  while ( *word != 0 ) i++;
  return i;
}

int main()
{
  char temp[2][31];
  char k[100];
  int numero_criaturas, quantidade_relacoes;
  char criaturas[5000][31];
  int relacoes[5000][2];
  //scanf("%d %d", &numero_criaturas, &quantidade_relacoes);
  /*while ( numero_criaturas != 0){
    for ( int i= 0 ; i < numero_criaturas; i++ )
    {
      criaturas[i]= gets()
      criaturas[i][30]= size( criaturas[i] )
    }

    for ( int i= 0 ; i < quantidade_relacoes; i++)
    {
      split( gets(), temp);

    }*/
  scanf("%s", k);
  while ( k != "exit")
  {
    printf("wut da fuq");
    printf("%d\n", size(k) );
    scanf("%s",k);
  }
}