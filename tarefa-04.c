#include <stdio.h>
#include <stdlib.h>
 
void imprime(int *vetor, int n){
  int i;
  for (i = 1; i <= n; i++)
      printf("%d ", vetor[i]);
  printf("\n");
}
 
void swap(int *a, int *b){
  int aux;
  aux = *a;
  *a  = *b;
  *b  = aux;
}
 
void heapify(int *vetor, int i, int n){
  int esquerda = 2 * i, direita = (2 * i) + 1, maior;
  if (vetor[esquerda] > vetor[i] && esquerda <= n)
    maior = esquerda;
  else
    maior = i;
  if (direita <= n && vetor[direita] > vetor[maior])
    maior = direita;
  if (maior != i) {
    swap(&vetor[i], &vetor[maior]);
    heapify(vetor, maior, n);
  }
}
 
void maxheap(int *vetor, int n){
  int i;
  for (i = n / 2; i > 0; i--) {
    heapify(vetor, i, n);
  }
  imprime(vetor, n);
}
 
int extractmax(int *vetor, int n){
  int max;
  if (n < 1)
    return 0;
  max = vetor[1];
  vetor[1] = vetor[n--];
  heapify(vetor, 1, n);
  return max;
}
 
void HeapSort(int *vetor, int n){
  int i, *vetor2 = (int*)malloc(sizeof(int)*(n+1));
 
  maxheap(vetor, n);
  
  for (i = n; i > 0; i--)
    vetor2[i] = extractmax(vetor, i);
 
  imprime(vetor2, n);
  free(vetor2);
}
 
int main(){
 
  int i, n, *vetor;
 
  scanf("%d", &n);
  vetor = (int*)malloc(sizeof(int)*(n+1));
 
  for (i = 1; i < n + 1; i++)
    scanf("%d", &vetor[i]);
 
  HeapSort(vetor, n);
  free(vetor);                                                                                      
  return 0;
}