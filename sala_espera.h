#ifndef SALA_ESPERA_H
#define SALA_ESPERA_H

// Modulo da SALA DE ESPERA (fila FIFO)
// Usa a fila (fila.h) guardando o ID dos pacientes.

void sala_iniciar();
void sala_finalizar();

void sala_entrar(int id_paciente);  // vai pro fim da fila
int sala_proximo();                 // ID de quem esta na frente (-1 se vazia)
void sala_sair();                   // tira quem esta na frente
int sala_contem(int id_paciente);   // 1 se ja esta na fila
int sala_tamanho();
void sala_listar();                 // mostra na ordem de atendimento

#endif
