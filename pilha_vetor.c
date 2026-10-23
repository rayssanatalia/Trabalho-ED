#include "pilha_vetor.h"
#include <stdlib.h>
#include <stdio.h>

Pilha* pilha_criar() {
  Pilha *P = malloc(sizeof(Pilha));
  P->dados = malloc(MAX * sizeof(int));
  P->topo = 0;
  P->N = MAX;
return P;
}

void pilha_destruir(Pilha **p) {// p recebe &P
  free((*p)->dados);
  free(*p); //testar valgrind!
  *p = NULL;
}

void pilha_adicionar(Pilha **p, int x) {// p recebe &P
  (*p)->dados[(*p)->topo] = x; 
  (*p)->topo++;
}

int pilha_topo(Pilha *p){
  return (p->topo)?p->dados[p->topo-1]:-1;
}

void pilha_remover(Pilha **p) {// p recebe P
  if((*p)->topo==0) return;
  (*p)->topo--;
}

int pilha_tamanho(Pilha *p) { // p recebe P
  return p->topo;
}
