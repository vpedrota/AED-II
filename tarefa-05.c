#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct palavra{
  char nome[20];
};
 
typedef struct palavra palavra ;
 
void countSort(palavra *a, int tamanho, int coluna){
  int c[28], aux;
  palavra b[tamanho];
  int i;
  
  for (i = 0; i < 28; i++){
    c[i] = 0; 
  }
 
  for ( i = 0; i < tamanho; i++){ 
    if(a[i].nome[coluna] < 97 && a[i].nome[coluna] != 32 && a[i].nome[coluna]!=0)
      a[i].nome[coluna]+=32;
    c[coluna < strlen(a[i].nome) && a[i].nome[coluna] != 32 && a[i].nome[coluna] >= 97? a[i].nome[coluna] - 'a' + 1 :0 ]++;  
  }
 
  for (i = 1; i < 28; i++){
    c[i] += c[i - 1];
  }
 
  for (i = tamanho - 1; i >= 0; i--){
    
    b[c[coluna < strlen(a[i].nome) && a[i].nome[coluna] != 32 && a[i].nome[coluna] >= 97? a[i].nome[coluna] - 'a' + 1 :0 ] - 1] = a[i];
    c[coluna < strlen(a[i].nome) && a[i].nome[coluna] != 32 && a[i].nome[coluna] >= 97? a[i].nome[coluna] - 'a' + 1 :0 ]--;
  }
 
  for(i = 1; i < 28; i++)
    printf("%d ", c[i]);
  printf("\n");
 
  for(i = 0; i < tamanho; i ++){
    a[i] = b[i];
  }
  
}
 
void radixSort(palavra *vetor, int tamanho, int maior){
  int coluna;
  //char **d = (char**)malloc(sizeof(char*)*tamanho);
  for (coluna = maior; coluna > 0; coluna--){
    countSort(vetor, tamanho, coluna - 1);
  }
}
 
int main() {
  int i, n, tam, maior = 0, m, p;
  //char **nomes;
    
  scanf("%d",&n);
  
  //nomes = (char**)malloc(sizeof(char*)*n);
  palavra vetor[n];
 
  for(i = 0; i < n; i++){
    //nomes[i] = (char*)malloc(sizeof(char)*15);
    //scanf("%s", nomes[i]);
    scanf("%s", vetor[i].nome);
    tam = strlen(vetor[i].nome);
    if(tam > maior)
      maior = tam;
  }
  scanf("%d %d", &m, &p);
  radixSort(vetor, n, maior);
 
  for (i = m-1; i < m+p-1; i++) {
    printf("%s\n", vetor[i].nome);
  }
 
  return 0;
}