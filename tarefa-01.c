#include "stdio.h"
#include "stdlib.h"
 
int* aloca_vetor(int n){
  int *vetor;
  vetor = (int *)calloc(sizeof(int) , n);
  return vetor;
}
 
int retorna_votos(int *aux, int *vetor, int votantes, int candidatos){
  int i, j, validos = 0;
 
  for (i = 0; i < candidatos; i++) {
    aux[i] = 0;
  }
 
  for (j = 0; j < votantes; j++){
    if(vetor[j] > 0 && vetor[j] <= candidatos){
      aux[vetor[j]-1]++;
      validos++;
    }
  }
 
  return validos;
}
 
int segundo_turno(int *vetor1, int* vetor2, int votantes, int candidatos, int maior, int seg_maior){
  int i, validos = 0;
  for (i = 0; i < votantes; i++) {
    if(vetor1[i] != maior && vetor1[i] != seg_maior){
      vetor1[i] = vetor2[i];
    }
    if(vetor1[i] == maior || vetor1[i] == seg_maior)
      validos++;
  }
  return validos;
}
 
int main(int argc, char const *argv[]) {
  int votantes, candidatos, i, maior, seg_maior, validos = 0;
  int *vetor1, *vetor2, *vetor3, *votos1;
  float porcentagem;
 
 
  scanf("%d", &votantes);
  scanf("%d", &candidatos);
 
  vetor1 = aloca_vetor(votantes);
  vetor2 = aloca_vetor(votantes);
  vetor3 = aloca_vetor(votantes);
  votos1 = aloca_vetor(candidatos);
 
  for (i = 0; i < votantes; i++) {
    scanf("%d %d %d", &vetor1[i], &vetor2[i], &vetor3[i]);
  }
 
  validos = retorna_votos(votos1, vetor1, votantes, candidatos);
 
  if(validos == 0){
    printf("0\n");
    return 0;
  }
 
  maior = 0;
  seg_maior = 0;
 
  for (i = 0; i < candidatos; i++) {
    if(votos1[i] > votos1[maior]){
      maior = i;
    }
  }
 
  porcentagem = (votos1[maior]*100.00)/validos;
  printf("%d %.2f\n", maior+1, porcentagem);
 
  if(porcentagem >= 50.00)
    return 0;
 
  for (i = 0; i < candidatos; i++) {
    if(i == maior && maior == 0){
      seg_maior = 1;
    }
    else if(votos1[i] > votos1[seg_maior] &&  i != maior) {
      seg_maior = i;
    }
  }
 
  segundo_turno(vetor1, vetor2, votantes, candidatos, maior+1, seg_maior+1);
  validos = segundo_turno(vetor1, vetor3, votantes, candidatos, maior+1, seg_maior+1);
  retorna_votos(votos1, vetor1, votantes, candidatos);
 
 
  if((votos1[seg_maior] > votos1[maior]) || (votos1[maior] == votos1[seg_maior] && seg_maior < maior))
    maior = seg_maior;
 
  porcentagem = (votos1[maior]*100.00)/validos;
 
  printf("%d %.2f\n", maior+1, porcentagem);
 
  free(vetor1);
  free(vetor2);
  free(vetor3);
  free(votos1);
 
  return 0;
}