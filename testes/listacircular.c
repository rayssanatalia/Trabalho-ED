#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main() {
    int i, num, rem;
    No *L = criar_lista();

    printf("=== TESTE DA LISTA CIRCULAR ===\n");
    printf("Digite a quantidade de medicos/elementos: ");
    if (scanf("%d", &num) != 1) return 1;

    // Inserindo elementos na lista circular
    for (i = 1; i <= num; i++) {
        adicionar_final(&L, i * 100); // Ex: IDs dos médicos
    }

    printf("\nEstado atual da escala (Lista Circular):\n");
    imprimir_lista(L);
    printf("Tamanho da lista: %d\n", tamanho_lista(L));

    // Teste de remoção por valor
    printf("\nDigite um ID para remover da escala: ");
    if (scanf("%d", &rem) == 1) {
        remover_valor(&L, rem);
        printf("Apos remocao:\n");
        imprimir_lista(L);
        printf("Novo tamanho: %d\n", tamanho_lista(L));
    }

    // Liberação de memória
    destruir_lista(&L);
    printf("\nMemoria liberada com sucesso!\n");

    return 0;
}