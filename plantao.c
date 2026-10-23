#include <stdio.h>
#include <string.h>
#include "plantao.h"
#include "lista_circular.h"

static NoCircular *escala;                              // lista circular dos plantonistas
static char nomes[MAX_MEDICOS + 1][TAM_NOME_MEDICO];    // nome de cada medico (posicao = ID)
static int proximo_id = 1;

void plantao_iniciar() {
  escala = criar_lista_circular();
  proximo_id = 1;
}

void plantao_finalizar() {
  destruir_lista_circular(&escala);
}

int plantao_inserir(char nome[]) {
  if (proximo_id > MAX_MEDICOS) return 0;

  strncpy(nomes[proximo_id], nome, TAM_NOME_MEDICO - 1);
  nomes[proximo_id][TAM_NOME_MEDICO - 1] = '\0';

  adicionar_final_circular(&escala, proximo_id);  // entra no fim da fila de plantao
  proximo_id++;
  return proximo_id - 1;
}

int plantao_atual() {
  if (escala == NULL) return -1;
  return acessar_primeiro_circular(escala);
}

char* plantao_nome(int id) {
  return nomes[id];
}

void plantao_avancar() {
  avancar_circular(&escala);
}

void plantao_remover_atual() {
  remover_inicio_circular(&escala);
}

int plantao_tamanho() {
  return tamanho_lista_circular(escala);
}

void plantao_listar() {
  int n = tamanho_lista_circular(escala);
  int i, id;

  if (n == 0) {
    printf("  (nenhum medico na escala)\n");
    return;
  }

  // da uma volta completa na lista circular, avancando um por vez.
  // Depois de n avancos ela volta pro mesmo lugar onde estava.
  for (i = 0; i < n; i++) {
    id = acessar_primeiro_circular(escala);
    printf("  %d. %s", i + 1, nomes[id]);
    if (i == 0) printf("   <-- da vez");
    printf("\n");
    avancar_circular(&escala);
  }
}
