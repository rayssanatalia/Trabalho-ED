#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

Pilha* pilha_criar() {
  Pilha *p = (Pilha*) malloc(sizeof(Pilha));
  p->L = criar_lista();
return p; 
} 

void pilha_destruir(Pilha **p) {// p recebe &F
  destruir_lista(&((*p)->L));
  free(*p); //testar valgrind!
  *p = NULL;
}

//Inserção

void pilha_adicionar(Pilha **p, int x) {// p recebe &F
  adicionar_inicio((*p)->L, x);
}

//Acessar

int pilha_topo(Pilha *p) {// p recebe F
  return acessar_primeiro(p->L);
}

//Remoção

void pilha_remover(Pilha **p) {// p recebe &L
  remover_inicio((*p)->L);
}

//Tamanho

int pilha_tamanho(Pilha *p) {// p recebe L
  return tamanho_lista(p->L);
}


void pilha_imprimir(Pilha *p) {
  imprimir_lista(p->L);
}
