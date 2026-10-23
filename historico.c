#include <stdio.h>
#include "historico.h"
#include "pilha.h"
#include "paciente.h"
#include "plantao.h"

typedef struct {
  int id_paciente;
  int id_medico;
} Atendimento;

static Pilha *pilha;                                 // guarda o numero do atendimento
static Atendimento atendimentos[MAX_ATENDIMENTOS + 1];  // dados (posicao = numero)

void historico_iniciar() {
  pilha = pilha_criar();
}

void historico_finalizar() {
  pilha_destruir(&pilha);
}

int historico_cheio() {
  return pilha_tamanho(pilha) >= MAX_ATENDIMENTOS;
}

void historico_registrar(int id_paciente, int id_medico) {
  int numero = pilha_tamanho(pilha) + 1;
  atendimentos[numero].id_paciente = id_paciente;
  atendimentos[numero].id_medico = id_medico;
  pilha_adicionar(&pilha, numero);
}

int historico_desfazer() {
  int numero, id_paciente;
  if (pilha_tamanho(pilha) == 0) return -1;

  numero = pilha_topo(pilha);
  id_paciente = atendimentos[numero].id_paciente;
  pilha_remover(&pilha);
  return id_paciente;
}

int historico_tamanho() {
  return pilha_tamanho(pilha);
}

void historico_listar() {
  Pilha *aux;
  int numero;

  if (pilha_tamanho(pilha) == 0) {
    printf("  (nenhum atendimento ainda)\n");
    return;
  }

  aux = pilha_criar();

  // passo tudo pra uma pilha auxiliar mostrando (o topo sai primeiro)...
  while (pilha_tamanho(pilha) > 0) {
    numero = pilha_topo(pilha);
    printf("  Atendimento #%d: ", numero);
    pacientes_imprimir(atendimentos[numero].id_paciente);
    printf("      atendido por: %s\n", plantao_nome(atendimentos[numero].id_medico));
    pilha_adicionar(&aux, numero);
    pilha_remover(&pilha);
  }

  // ...e depois devolvo pra pilha original (a ordem inverte de novo e fica certa)
  while (pilha_tamanho(aux) > 0) {
    numero = pilha_topo(aux);
    pilha_adicionar(&pilha, numero);
    pilha_remover(&aux);
  }

  pilha_destruir(&aux);
}
