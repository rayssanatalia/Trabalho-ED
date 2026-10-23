#include <stdio.h>
#include "sala_espera.h"
#include "fila.h"
#include "paciente.h"

static Fila *fila;

void sala_iniciar() {
  fila = fila_criar();
}

void sala_finalizar() {
  fila_destruir(&fila);
}

void sala_entrar(int id_paciente) {
  fila_adicionar(&fila, id_paciente);
}

int sala_proximo() {
  return fila_topo(fila);
}

void sala_sair() {
  fila_remover(&fila);
}

int sala_contem(int id_paciente) {
  return fila_contem(fila, id_paciente);
}

int sala_tamanho() {
  return fila_tamanho(fila);
}

void sala_listar() {
  int n = fila_tamanho(fila);
  int i, id;

  if (n == 0) {
    printf("  (sala de espera vazia)\n");
    return;
  }

  // a fila nao deixa olhar o meio, entao tiro da frente, mostro
  // e coloco no fim. Depois de n vezes ela volta na mesma ordem.
  for (i = 0; i < n; i++) {
    id = fila_topo(fila);
    fila_remover(&fila);
    printf("  %d. ", i + 1);
    pacientes_imprimir(id);
    fila_adicionar(&fila, id);
  }
}
