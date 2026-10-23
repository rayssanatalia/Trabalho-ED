#ifndef FILA_VETOR_H
#define FILA_VETOR_H

//Dados
typedef struct {
  int ini, fim, N, tamanho;
  int *dados;
} Fila;

#define MAX 100
 
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


#endif

