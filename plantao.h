#ifndef PLANTAO_H
#define PLANTAO_H

// Modulo do PLANTAO (escala rotativa dos medicos)
// Usa a lista circular (lista_circular.h) com os IDs dos medicos.
// O medico "da vez" e o primeiro da lista circular.

#define MAX_MEDICOS 20
#define TAM_NOME_MEDICO 60

void plantao_iniciar();
void plantao_finalizar();

// Retorna o ID do medico, ou 0 se a tabela estiver cheia
int plantao_inserir(char nome[]);

int plantao_atual();            // ID do medico da vez (-1 se vazio)
char* plantao_nome(int id);     // nome do medico pelo ID
void plantao_avancar();         // passa a vez para o proximo
void plantao_remover_atual();   // tira o medico da vez da escala
int plantao_tamanho();
void plantao_listar();          // lista comecando pelo medico da vez

#endif
