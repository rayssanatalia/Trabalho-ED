#ifndef HISTORICO_H
#define HISTORICO_H

// Modulo do HISTORICO de atendimentos (pilha LIFO)
// Usa a pilha (pilha.h). Cada atendimento guarda o paciente e o medico;
// a pilha guarda o numero do atendimento.

#define MAX_ATENDIMENTOS 200

void historico_iniciar();
void historico_finalizar();

int historico_cheio();
void historico_registrar(int id_paciente, int id_medico);

// Desfaz o ultimo atendimento. Retorna o ID do paciente, ou -1 se nao tem nada
int historico_desfazer();

int historico_tamanho();
void historico_listar();   // do mais recente para o mais antigo

#endif
