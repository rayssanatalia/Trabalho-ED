#include "lista_circular.h"
#include <stdlib.h>
#include <stdio.h>

NoCircular* criar_lista_circular() {
  return NULL; 
} 

void destruir_lista_circular(NoCircular **p) {//verso iterativa
  if(*p == NULL) return;// lista vazia
  NoCircular *q = (*p)->prox, *aux;
  while(q != *p){
    aux = q;
    q = q->prox;
    free(aux);
  }
  free(*p);
  *p = NULL;
}

//Inserção

void adicionar_inicio_circular(NoCircular** p, int x){//p recebe |$\&$|L
  NoCircular *q = (NoCircular*) malloc(sizeof(NoCircular));
  q->dado = x;
  if(*p == NULL){ //lista vazia
    *p = q;
    q->prox = q;
  }
  else{
    q->prox = (*p)->prox;
    (*p)->prox = q;
  }
}

void adicionar_final_circular(NoCircular** p, int x) {// p recebe L
  NoCircular *q = (NoCircular*) malloc(sizeof(NoCircular));
  q->dado = x;
  if(*p == NULL){ //lista vazia
    *p = q;
    q->prox = q;
  }
  else{
    q->prox = (*p)->prox;
    (*p)->prox = q;
    *p = q;
  }
}

//Imprimir

void imprimir_lista_circular(NoCircular *p) { // p recebe L
  NoCircular* q, *aux = p;
  if(p!=NULL){
    for (q = p->prox; q != aux; q = q->prox) printf("%d -> ", q->dado);
    printf("%d -> ", q->dado);
  }
  printf("NULL\n");
}

//Buscar
int buscar_valor_circular(NoCircular *p, int x) {// q recebe L
  if(p==NULL) return -1; //lista vazia
  NoCircular *q = p;
  p = p->prox;
  while(p != q){
    if(p->dado == x) return 1; //true!
      p = p->prox;
  }
  if(p->dado == x) return 1; //true!
  return 0;//false == no encontrou
}

//Remoção

void remover_inicio_circular(NoCircular **p) {// p recebe L
  if(*p==NULL) return; //lista vazia
  NoCircular* q = *p; 
  if(q->prox==q){//1 unico n
    free(q); *p = NULL;
    return;
  }    
  q = q->prox;  
  (*p)->prox = q->prox;
  free(q);
}
  
void remover_final_circular(NoCircular **p) {// p recebe L
  if(*p==NULL) return; //lista vazia
  NoCircular* q = *p; 
  if(q->prox==q){//1nico n
    free(q); *p = NULL;
    return;
  }    
  NoCircular *aux = q;
  while(q->prox != aux) q = q->prox;  
  q->prox = aux->prox;
  *p = q;
  free(aux);
}

void remover_valor_circular(NoCircular **p, int x) {// p recebe |$\&$|L
  if(*p==NULL) return; //lista vazia
  NoCircular *q = *p;
  if(q->prox == q && q->dado == x){//1 unico n
    free(q); *p = NULL;
    return;
  }
  while(q->prox != *p && (q->prox)->dado != x) q = q->prox;
  if((q->prox)->dado == x){//encontrou
    NoCircular *aux = q->prox;
    q->prox = aux->prox;
    if(*p == aux)//último elemento
      *p = q;
    free(aux);
  }
}

int tamanho_lista_circular(NoCircular *p){
  if(p==NULL) return 0; //lista vazia
  NoCircular *q = p; 
  int tam=1;
  for(p = p->prox; p != q; p = p->prox) tam++;
return tam;
}

void avancar_circular(NoCircular **p){
  if(*p==NULL) return; //lista vazia
  *p = (*p)->prox;
}

int acessar_primeiro_circular(NoCircular *p){
  if(p==NULL) return -1; //lista vazia
  NoCircular *q = p->prox; 
return q->dado;
}
























//
