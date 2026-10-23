#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

Fila* fila_criar() {
  Fila *p = (Fila*) malloc(sizeof(Fila));
  p->tam = 0;
  p->L = criar_lista();
return p; 
} 

void fila_destruir(Fila **p) {// p recebe &F
  destruir_lista(&((*p)->L));
  free(*p);
  *p = NULL;
}

//Inserção

void fila_adicionar(Fila **p, int x) {// p recebe &F
  adicionar_final((*p)->L, x);
  (*p)->tam++;
}

//Acessar

int fila_topo(Fila *p) {// p recebe F
  return acessar_primeiro(p->L);
}

//Remoção

void fila_remover(Fila **p) {// p recebe &L
  if((*p)->tam == 0) return; //fila vazia
  remover_inicio((*p)->L);
  (*p)->tam--;
}

//Tamanho

int fila_tamanho(Fila *p) {// p recebe L
  return p->tam;
}

int fila_contem(Fila *p, int x) {
  return buscar_valor(p->L, x);
}

void fila_imprimir(Fila *p) {
  imprimir_lista(p->L);
}
