#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "paciente.h"
#include "lista_com_cabeca.h"

static No *lista;                           // lista encadeada com os IDs cadastrados
static Paciente tabela[MAX_PACIENTES + 1];  // dados dos pacientes (posicao = ID)
static int proximo_id = 1;                  // o ID nunca se repete

void pacientes_iniciar() {
  lista = criar_lista();
  proximo_id = 1;
}

void pacientes_finalizar() {
  destruir_lista(&lista);
}

int pacientes_limpar_cpf(char entrada[], char saida[]) {
  int i, qtd = 0;
  for (i = 0; entrada[i] != '\0'; i++) {
    if (isdigit((unsigned char) entrada[i])) {
      if (qtd == 11) return 0;  // digitos demais
      saida[qtd] = entrada[i];
      qtd++;
    }
    else if (entrada[i] != '.' && entrada[i] != '-' && entrada[i] != ' ') {
      return 0;  // tem letra ou simbolo estranho
    }
  }
  saida[qtd] = '\0';
  return qtd == 11;
}

Paciente* pacientes_buscar(int id) {
  if (id < 1 || id >= proximo_id) return NULL;
  if (!buscar_valor(lista, id)) return NULL;  // foi removido
  return &tabela[id];
}

int pacientes_id_por_cpf(char cpf[]) {
  int i;
  for (i = 1; i < proximo_id; i++) {
    if (buscar_valor(lista, i) && strcmp(tabela[i].cpf, cpf) == 0) return i;
  }
  return 0;  // nao encontrou
}

int pacientes_cadastrar(char nome[], char cpf[]) {
  if (proximo_id > MAX_PACIENTES) return 0;  // tabela cheia

  // nao deixa cadastrar o mesmo CPF duas vezes
  if (pacientes_id_por_cpf(cpf) != 0) return -1;

  tabela[proximo_id].id = proximo_id;
  strncpy(tabela[proximo_id].nome, nome, TAM_NOME - 1);
  tabela[proximo_id].nome[TAM_NOME - 1] = '\0';
  strncpy(tabela[proximo_id].cpf, cpf, TAM_CPF - 1);
  tabela[proximo_id].cpf[TAM_CPF - 1] = '\0';

  adicionar_final(lista, proximo_id);
  proximo_id++;
  return proximo_id - 1;
}

int pacientes_remover(int id) {
  if (pacientes_buscar(id) == NULL) return 0;
  remover_valor(lista, id);
  return 1;
}

void pacientes_imprimir(int id) {
  Paciente *p = pacientes_buscar(id);
  if (p == NULL) {
    printf("(paciente removido do cadastro)\n");
    return;
  }
  printf("%s | CPF %.3s.%.3s.%.3s-%.2s\n",
         p->nome, p->cpf, p->cpf + 3, p->cpf + 6, p->cpf + 9);
}

void pacientes_listar() {
  int i;
  if (tamanho_lista(lista) == 0) {
    printf("  (nenhum paciente cadastrado)\n");
    return;
  }
  // percorre os IDs possiveis e mostra so os que ainda estao na lista
  for (i = 1; i < proximo_id; i++) {
    if (buscar_valor(lista, i)) {
      printf("  ");
      pacientes_imprimir(i);
    }
  }
}

int pacientes_total() {
  return tamanho_lista(lista);
}
