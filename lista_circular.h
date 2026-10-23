#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

//Dados
typedef struct no_circular {
  int dado;
  struct no_circular *prox;
} NoCircular;
 
//Funções
NoCircular* criar_lista_circular();
void destruir_lista_circular(NoCircular **L);

//Imprimir
void imprimir_lista_circular(NoCircular *L);

//Adicionar
void adicionar_inicio_circular(NoCircular **L, int x);
void adicionar_final_circular(NoCircular **L, int x);

//Remover
void remover_inicio_circular(NoCircular **L);
void remover_final_circular(NoCircular **L);
void remover_valor_circular(NoCircular **L, int x);

//Buscar
int buscar_valor_circular(NoCircular *L, int x);

//Extra
int tamanho_lista_circular(NoCircular *L);
int acessar_primeiro_circular(NoCircular *L);
void avancar_circular(NoCircular **L); // passa a vez para o pr�ximo plantonista


#endif

