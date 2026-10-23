// Clinica VidaSaudavel
// Trabalho de Estruturas de Dados - 12321ECP017 - Fernanda

#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "plantao.h"
#include "sala_espera.h"
#include "historico.h"


// Funcoes de leitura (so o main conversa com o teclado)


void limpar_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

// Le uma linha inteira (aceita espacos). Retorna 0 se acabou a entrada.
int ler_texto(char msg[], char destino[], int tam) {
  int tamanho;
  printf("%s", msg);
  if (fgets(destino, tam, stdin) == NULL) {
    destino[0] = '\0';
    return 0;
  }
  tamanho = strlen(destino);
  if (tamanho > 0 && destino[tamanho - 1] == '\n') {
    destino[tamanho - 1] = '\0';
  }
  else {
    limpar_buffer();  // a linha era maior que o vetor, joga o resto fora
  }
  return 1;
}

// Retorna o numero digitado, -1 se nao for numero, 0 se acabou a entrada
int ler_inteiro(char msg[]) {
  char linha[50];
  int n;
  if (!ler_texto(msg, linha, 50)) return 0;
  if (sscanf(linha, "%d", &n) != 1) return -1;
  return n;
}

void separador() {
  printf("\n==========================================\n");
}

// Pede o CPF e devolve o id interno do paciente.
// Devolve 0 se o CPF for invalido ou se nao tiver paciente com ele.
int pedir_paciente() {
  char cpf_digitado[40];
  char cpf[TAM_CPF];
  int id;

  ler_texto("CPF do paciente: ", cpf_digitado, 40);
  if (!pacientes_limpar_cpf(cpf_digitado, cpf)) {
    printf("CPF invalido! Precisa ter 11 numeros.\n");
    return 0;
  }
  id = pacientes_id_por_cpf(cpf);
  if (id == 0) {
    printf("Nenhum paciente cadastrado com esse CPF.\n");
  }
  return id;
}


// 1) PACIENTES (lista encadeada)


void tela_cadastrar_paciente() {
  char nome[TAM_NOME];
  char cpf_digitado[40];
  char cpf[TAM_CPF];
  int id;

  ler_texto("Nome do paciente: ", nome, TAM_NOME);
  if (strlen(nome) == 0) {
    printf("O nome nao pode ficar vazio.\n");
    return;
  }

  ler_texto("CPF (11 numeros): ", cpf_digitado, 40);
  if (!pacientes_limpar_cpf(cpf_digitado, cpf)) {
    printf("CPF invalido! Precisa ter 11 numeros.\n");
    return;
  }

  id = pacientes_cadastrar(nome, cpf);
  if (id == 0) printf("Nao cabe mais paciente no cadastro.\n");
  else if (id == -1) printf("Ja existe um paciente com esse CPF.\n");
  else printf("Paciente cadastrado!\n");
}

void tela_buscar_paciente() {
  int id = pedir_paciente();
  if (id == 0) return;
  printf("Encontrado: ");
  pacientes_imprimir(id);
}

void tela_remover_paciente() {
  int id = pedir_paciente();
  if (id == 0) return;
  if (sala_contem(id)) {
    printf("Esse paciente esta na sala de espera. Atenda ele antes de remover.\n");
    return;
  }
  pacientes_remover(id);
  printf("Paciente removido.\n");
}

void menu_pacientes() {
  int opcao = -1;
  while (opcao != 0) {
    separador();
    printf("  PACIENTES (lista encadeada)\n");
    printf("==========================================\n");
    printf("1 - Cadastrar paciente\n");
    printf("2 - Buscar por CPF\n");
    printf("3 - Remover paciente\n");
    printf("4 - Listar pacientes\n");
    printf("0 - Voltar\n");
    opcao = ler_inteiro("Opcao: ");

    if (opcao == 1) tela_cadastrar_paciente();
    else if (opcao == 2) tela_buscar_paciente();
    else if (opcao == 3) tela_remover_paciente();
    else if (opcao == 4) {
      printf("\n--- Pacientes cadastrados (%d) ---\n", pacientes_total());
      pacientes_listar();
    }
    else if (opcao != 0) printf("Opcao invalida!\n");
  }
}

// 2) SALA DE ESPERA (fila)


void tela_entrar_na_fila() {
  int id = pedir_paciente();
  if (id == 0) return;
  if (sala_contem(id)) {
    printf("Esse paciente ja esta na sala de espera.\n");
    return;
  }
  sala_entrar(id);
  printf("Paciente na fila! Posicao: %d\n", sala_tamanho());
}

void menu_sala_espera() {
  int opcao = -1;
  while (opcao != 0) {
    separador();
    printf("  SALA DE ESPERA (fila)\n");
    printf("==========================================\n");
    printf("1 - Colocar paciente na fila\n");
    printf("2 - Ver quem e o proximo\n");
    printf("3 - Listar a fila\n");
    printf("0 - Voltar\n");
    opcao = ler_inteiro("Opcao: ");

    if (opcao == 1) tela_entrar_na_fila();
    else if (opcao == 2) {
      if (sala_tamanho() == 0) printf("A sala de espera esta vazia.\n");
      else {
        printf("Proximo: ");
        pacientes_imprimir(sala_proximo());
      }
    }
    else if (opcao == 3) {
      printf("\n--- Fila de espera (%d) ---\n", sala_tamanho());
      sala_listar();
    }
    else if (opcao != 0) printf("Opcao invalida!\n");
  }
}


// 3) PLANTAO (lista circular)


void tela_inserir_medico() {
  char nome[TAM_NOME_MEDICO];
  int id;

  ler_texto("Nome do medico: ", nome, TAM_NOME_MEDICO);
  if (strlen(nome) == 0) {
    printf("O nome nao pode ficar vazio.\n");
    return;
  }
  id = plantao_inserir(nome);
  if (id == 0) printf("Nao cabe mais medico na escala.\n");
  else printf("Medico entrou na escala!\n");
}

void menu_plantao() {
  int opcao = -1;
  while (opcao != 0) {
    separador();
    printf("  PLANTAO (lista circular)\n");
    printf("==========================================\n");
    printf("1 - Inserir medico na escala\n");
    printf("2 - Avancar (passar a vez)\n");
    printf("3 - Remover medico da vez\n");
    printf("4 - Listar a partir da vez\n");
    printf("0 - Voltar\n");
    opcao = ler_inteiro("Opcao: ");

    if (opcao == 1) tela_inserir_medico();
    else if (opcao == 2) {
      if (plantao_tamanho() == 0) printf("Nao tem medico na escala.\n");
      else {
        plantao_avancar();
        printf("Agora e a vez de: %s\n", plantao_nome(plantao_atual()));
      }
    }
    else if (opcao == 3) {
      if (plantao_tamanho() == 0) printf("Nao tem medico na escala.\n");
      else {
        printf("Removendo: %s\n", plantao_nome(plantao_atual()));
        plantao_remover_atual();
      }
    }
    else if (opcao == 4) {
      printf("\n--- Escala de plantao (%d) ---\n", plantao_tamanho());
      plantao_listar();
    }
    else if (opcao != 0) printf("Opcao invalida!\n");
  }
}

// ---------------------------------------------------------------
// 4) ATENDIMENTO (fila -> pilha) e historico
// ---------------------------------------------------------------

void tela_atender() {
  int id_paciente, id_medico;

  if (sala_tamanho() == 0) {
    printf("Nao tem ninguem na sala de espera.\n");
    return;
  }
  if (plantao_tamanho() == 0) {
    printf("Nao tem medico de plantao!\n");
    return;
  }
  if (historico_cheio()) {
    printf("O historico esta cheio.\n");
    return;
  }

  id_paciente = sala_proximo();
  id_medico = plantao_atual();

  sala_sair();                                   // sai da fila
  historico_registrar(id_paciente, id_medico);   // entra na pilha
  plantao_avancar();                             // passa a vez pro proximo medico

  printf("Atendimento feito!\n");
  printf("Paciente: ");
  pacientes_imprimir(id_paciente);
  printf("Medico: %s\n", plantao_nome(id_medico));
}

void tela_desfazer() {
  int id = historico_desfazer();

  if (id == -1) {
    printf("Nao tem atendimento para desfazer.\n");
    return;
  }
  if (pacientes_buscar(id) == NULL) {
    printf("Atendimento desfeito, mas o paciente foi removido do cadastro.\n");
    return;
  }
  sala_entrar(id);  // volta pro fim da fila
  printf("Atendimento desfeito! O paciente voltou para o fim da fila: ");
  pacientes_imprimir(id);
}

void menu_atendimento() {
  int opcao = -1;
  while (opcao != 0) {
    separador();
    printf("  ATENDIMENTO E HISTORICO (pilha)\n");
    printf("==========================================\n");
    printf("1 - Atender proximo da fila\n");
    printf("2 - Desfazer ultimo atendimento\n");
    printf("3 - Ver historico\n");
    printf("0 - Voltar\n");
    opcao = ler_inteiro("Opcao: ");

    if (opcao == 1) tela_atender();
    else if (opcao == 2) tela_desfazer();
    else if (opcao == 3) {
      printf("\n--- Historico (%d), mais recente primeiro ---\n", historico_tamanho());
      historico_listar();
    }
    else if (opcao != 0) printf("Opcao invalida!\n");
  }
}


// MAIN


int main() {
  int opcao = -1;

  pacientes_iniciar();
  plantao_iniciar();
  sala_iniciar();
  historico_iniciar();

  while (opcao != 0) {
    separador();
    printf("  CLINICA VIDASAUDAVEL\n");
    printf("==========================================\n");
    printf("1 - Pacientes\n");
    printf("2 - Sala de espera\n");
    printf("3 - Plantao dos medicos\n");
    printf("4 - Atendimento e historico\n");
    printf("0 - Sair\n");
    opcao = ler_inteiro("Opcao: ");

    if (opcao == 1) menu_pacientes();
    else if (opcao == 2) menu_sala_espera();
    else if (opcao == 3) menu_plantao();
    else if (opcao == 4) menu_atendimento();
    else if (opcao != 0) printf("Opcao invalida!\n");
  }

  // libera tudo que foi alocado
  historico_finalizar();
  sala_finalizar();
  plantao_finalizar();
  pacientes_finalizar();

  printf("Ate logo!\n");
  return 0;
}
