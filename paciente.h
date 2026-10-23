#ifndef PACIENTE_H
#define PACIENTE_H

// Modulo dos PACIENTES (cadastro permanente)
// Usa a lista encadeada com cabeca (lista_com_cabeca.h) para guardar os IDs
// dos pacientes cadastrados. O nome e o CPF ficam numa tabela, na posicao do ID.

#define MAX_PACIENTES 100
#define TAM_NOME 60
#define TAM_CPF 12   // 11 digitos + o '\0'

typedef struct {
  int id;
  char nome[TAM_NOME];
  char cpf[TAM_CPF];
} Paciente;

void pacientes_iniciar();
void pacientes_finalizar();

// O paciente e identificado pelo CPF. O numero interno (id) so serve para
// guardar nas estruturas, que trabalham com int, e nunca aparece pro usuario.

// Cadastro: retorna o id interno novo, 0 se estiver cheio, -1 se o CPF ja existe
int pacientes_cadastrar(char nome[], char cpf[]);

// Procura pelo CPF (so com os 11 digitos). Retorna o id interno ou 0 se nao achou
int pacientes_id_por_cpf(char cpf[]);

// Tira pontos e tracos do CPF. Retorna 1 se sobraram exatamente 11 digitos
int pacientes_limpar_cpf(char entrada[], char saida[]);

// Retorna o paciente ou NULL se nao estiver cadastrado
Paciente* pacientes_buscar(int id);

// Retorna 1 se removeu, 0 se nao achou
int pacientes_remover(int id);

void pacientes_imprimir(int id);
void pacientes_listar();
int pacientes_total();

#endif
