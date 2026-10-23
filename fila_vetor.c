#include "fila_vetor.h"
#include <stdlib.h>
#include <stdio.h>

Fila* fila_criar() {
  Fila *F = malloc(sizeof(Fila));
  F->dados = malloc(MAX * sizeof(int));
  F->ini = F->fim = 0;
  F->N = MAX;
  F->tamanho = 0;
return F;
}

void fila_destruir(Fila **p) {// p recebe &F
  free((*p)->dados);
  free(*p);
  *p = NULL;
}

void fila_adicionar(Fila **p, int x) {// p recebe &F
  (*p)->dados[(*p)->fim] = x; 
  (*p)->fim = ((*p)->fim + 1) % (*p)->N; 
  (*p)->tamanho++;
}

int fila_topo(Fila *p){
  return (p->tamanho)?p->dados[p->ini]:-1;
}

void fila_remover(Fila **p) {// p recebe F
  if((*p)->tamanho==0) return;
  (*p)->ini = ((*p)->ini + 1) % (*p)->N;
  (*p)->tamanho--;
}

int fila_tamanho(Fila *p) { // p recebe F
  return p->tamanho;
}
