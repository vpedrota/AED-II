#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
 
struct Pessoa{
  int idade;
  int pos_inicial;
  char nome[20];
};
 
void imprimi_vetor(struct Pessoa **vetor, int pessoas){
  int i;
  for (i = 0; i < pessoas; i++) {
    printf("/%d  %s/ -", vetor[i]->idade, vetor[i]->nome);
  }
  printf("\n");
}
 
void imprimi(struct Pessoa **vetor, int p, int m){
  int i;
  for (i = p-1; i < p+m-1; i++) {
    printf("%s %d\n", vetor[i]->nome, vetor[i]->idade);
  }
}
 
void trocar(struct Pessoa **vetor, int pos1, int pos2){
  struct Pessoa *aux;
 
  aux = vetor[pos1];
  vetor[pos1] = vetor[pos2];
  vetor[pos2] = aux;
}
 
void cadastra_pessoa(struct Pessoa **vetor, int i, int idade, char *nome){
  vetor[i] = (struct Pessoa*)malloc(sizeof(struct Pessoa));
  vetor[i]->idade = idade;
  strcpy(vetor[i]->nome, nome);
  vetor[i]->pos_inicial = i;
}
 
void ve_estabilidade(struct Pessoa **vetor, int pessoas){
  int i;
  for (i = 0; i < pessoas-1; i++) {
    if(vetor[i]->pos_inicial > vetor[i+1]->pos_inicial && vetor[i]->idade == vetor[i+1]->idade){
      printf("no\n");
      return;
    }
  }
  printf("yes\n");
}
 
void retorna_mediana(struct Pessoa **vetor, int primeiro, int ultimo){
  int mediana, meio = (primeiro+ultimo)/2, a, b, c;
 
  a = vetor[primeiro]->idade;
  b = vetor[meio]->idade;
  c = vetor[ultimo]->idade;
 
  if(a < b && b < c)
    mediana = meio;
  else if(a < c && c <= b)
    mediana = ultimo;
  else if(c <= a && a < b)
    mediana = primeiro;
  else if(c < b && b <= a)
    mediana = meio;
  else if(b <= c && c < a)
    mediana = ultimo;
  else if(b <= a && a <= c)
    mediana = primeiro;
 
  trocar(vetor, mediana, ultimo);
}
 
int partition (struct Pessoa **vetor, int primeiro, int ultimo){
 
  retorna_mediana(vetor, primeiro, ultimo);
 
  int pivot = vetor[ultimo]->idade;
  int i = (primeiro - 1), j;
 
  for (j = primeiro; j < ultimo; j++){
    if (vetor[j]->idade <=  pivot){
      i++;
      trocar(vetor, i, j);
    }
  }
 
  trocar(vetor, i+1, ultimo);
  return (i + 1);
}
 
void quickSort(struct Pessoa **vetor, int primeiro, int ultimo){
  int pi;
  if (primeiro < ultimo){
    pi = partition(vetor, primeiro, ultimo);
    quickSort(vetor, primeiro, pi - 1);
    quickSort(vetor, pi + 1, ultimo);
  }
}
 
int main(int argc, char const *argv[]) {
  int pessoas, i, idade, p, m, aux, inicio;
  char nome[20];
  struct Pessoa **vetor;
  //clock_t t  = clock(); //armazena tempo
 
  scanf("%d", &pessoas);
  vetor = (struct Pessoa**)malloc(sizeof(struct Pessoa*)*pessoas);
 
 
  for (i = 0; i < pessoas; i++) {
    scanf("%s %d", nome, &idade);
    cadastra_pessoa(vetor, i, idade, nome);
  }
 
  scanf("%d %d", &p, &m);
 
  quickSort(vetor, 0, pessoas-1);
 
  //ve a estabilidade
  ve_estabilidade(vetor, pessoas);
  imprimi(vetor, p, m);
 
  //desalocando
  for (i = 0; i < pessoas; i++) {
    free(vetor[i]);
  }
 
  free(vetor);
  //t = clock() - t; //tempo final - tempo inicial
  //printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double
  return 0;
}