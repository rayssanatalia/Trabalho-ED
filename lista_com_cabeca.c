#include "lista_com_cabeca.h"
#include <stdlib.h>
#include <stdio.h>

No* criar_lista() {
  No *q = (No*) malloc(sizeof(No));
  q->dado = 0;
  q->prox = NULL;
return q; 
} 

void destruir_iterativo(No **p) { //vers�o iterativa
  No *q;
  while(*p != NULL){
    q = *p;
    *p = (*p)->prox;
    free(q);
  }
}

void destruir_recursivo(No *p) { //vers�o recursiva
  if (p != NULL) {
    destruir_recursivo(p->prox);
    free(p);
  }
}

void destruir_lista(No **p){
  destruir_iterativo(p);
  //destruir_recursivo(*p); *p = NULL;
}

//Inserção

void adicionar_inicio(No *p, int x) {// p recebe L
  No* q = (No*) malloc(sizeof(No));
  q->dado = x;
  q->prox = p->prox;
  p->prox = q;
  p->dado++;
}

void adicionar_final(No *p, int x) {// p recebe L
  No *q, *aux;
  q = (No*) malloc(sizeof(No));
  q->dado = x;
  q->prox = NULL;
  aux = p;
  while (aux->prox != NULL) aux = aux->prox;
  aux->prox = q;
  p->dado++;
}

//Imprimir

void imprimir_lista(No *p) { //vers�o iterativa
  No* q;
  for (q = p->prox; q != NULL; q = q->prox) printf("%d -> ", q->dado);
  printf("NULL\n");
}

//Buscar
int buscar_valor(No *p, int x) {// q recebe L
  p = p->prox;
  while(p != NULL){
    if(p->dado == x) return 1; //true!
      p = p->prox;
  }
  return 0;//false == n�o encontrou
}

//Remoção

void remover_inicio(No *p) {// p recebe L
  No* q = p->prox; 
  if(q==NULL) return; //lista vazia    
  p->prox = q->prox;  
  free(q);
  p->dado--;
}
  
void remover_final(No *p) {// p recebe L
  No* q = p;
  if(q->prox!=NULL){
    while (q->prox->prox != NULL)
      q = q->prox;
    No* aux = q->prox;
    q->prox = NULL;
    free(aux);
    p->dado--;
  }
}

void remover_valor(No *p, int v) {// p recebe |$\&$|L
  No* q = p;  
  while (q->prox != NULL){
    if(q->prox->dado==v) break;
    q = q->prox;
  }
  if(q->prox==NULL) return; //n�o encontrou o dado
  No* tmp = q->prox;
  q->prox = tmp->prox;
  free(tmp);
  p->dado--;
}

int tamanho_lista(No *p){
  return p->dado;
}

int acessar_primeiro(No *p){
  if(p->prox==NULL) return -1; //lista vazia 
  return (p->prox)->dado;
}
