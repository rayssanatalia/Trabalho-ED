#include <stdio.h>
#include "pilha_vetor.h"

int main(){
  int i, num;
  Pilha *F = pilha_criar();
  scanf("%d", &num);
  for(i=1; i<=num; i++) pilha_adicionar(&F, i);
  while(pilha_tamanho(F) > 0){
    printf("%d\n", pilha_topo(F));
    pilha_remover(&F);
  }
  pilha_destruir(&F); //testar valgrind!! 
return 0;
}
