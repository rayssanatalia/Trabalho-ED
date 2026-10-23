#include <stdio.h>
#include <stdlib.h>
#include "lista_com_cabeca.h" 

int main() {
    int i, num, busca, rem;
    No *L = criar_lista();

    printf("=== TESTE DA LISTA ENCADEADA ===\n");
    printf("Digite quantos elementos deseja inserir: ");
    if (scanf("%d", &num) != 1) return 1;

    // Inserindo elementos na lista
    for (i = 1; i <= num; i++) {
        adicionar_final(L, i * 10);
    }

    printf("\nEstado atual da lista:\n");
    imprimir_lista(L);
    printf("Tamanho total da lista: %d\n", tamanho_lista(L));

    // Teste de busca
    printf("\nDigite um valor para buscar na lista: ");
    if (scanf("%d", &busca) == 1) {
        if (buscar_valor(L, busca)) {
            printf("Valor %d ENCONTRADO na lista!\n", busca);
        } else {
            printf("Valor %d NAO encontrado na lista.\n", busca);
        }
    }

    // Teste de remoção
    printf("\nDigite um valor para remover da lista: ");
    if (scanf("%d", &rem) == 1) {
        remover_valor(L, rem);
        printf("Estado apos remocao:\n");
        imprimir_lista(L);
        printf("Novo tamanho: %d\n", tamanho_lista(L));
    }

    // Liberação de memória
    destruir_lista(&L);
    printf("\nMemoria liberada com sucesso!\n");

    return 0;
}