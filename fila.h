#ifndef FILA_H
#define FILA_H

#include "lista_com_cabeca.h"

//Dados
typedef struct {
  int tam; 
  No *L;
} Fila;
 
//Funções
Fila* fila_criar();
void fila_destruir(Fila **F);

//Adicionar
void fila_adicionar(Fila **F, int x);

//Acessar
int fila_topo(Fila *F);

//Remover
void fila_remover(Fila **F);

//Extra
int fila_tamanho(Fila *F);
int fila_contem(Fila *F, int x);
void fila_imprimir(Fila *F);


#endif

