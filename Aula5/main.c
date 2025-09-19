#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main() {
    ListaCircular* lista = criarListaCircular();

    printf("INSERÇÃO NO INÍCIO\n");
    inserirInicioCircular(lista, 1);
    inserirInicioCircular(lista, 2);
    inserirInicioCircular(lista, 3);
    exibirCircular(lista); 

    printf("INSERÇÃO NO FIM\n");
    inserirFimCircular(lista, 4);
    inserirFimCircular(lista, 5);
    exibirCircular(lista); 

    printf("INSERÇÃO EM POSIÇÃO ESPECÍFICA\n");
    inserirPosicaoCircular(lista, 6, 2);
    exibirCircular(lista); 

    printf("BUSCAR VALOR\n");
    int valor = 4;
    NoCircular* encontrado = buscarCircular(lista, valor);
    if (encontrado) {
        printf("Valor %d encontrado na lista.\n", valor);
    } else {
        printf("Valor %d não encontrado.\n", valor);
    }

    printf("BUSCAR POR POSIÇÃO\n");
    int pos = buscarPosicaoCircular(lista, 6);
    if (pos != -1) {
        printf("Valor encontrado na posicao %d\n", pos);
    } else {
        printf("Valor não encontrado\n");
    }

    printf("REMOÇÃO NO INÍCIO\n");
    int removido = removerInicioCircular(lista);
    printf("Removido: %d\n", removido);
    exibirCircular(lista);

    printf("REMOÇÃO NO FIM\n");
    removido = removerFimCircular(lista);
    printf("Removido: %d\n", removido);
    exibirCircular(lista);

    printf("REMOÇÃO POR POSIÇÃO\n");
    removido = removerPosicaoCircular(lista, 2);
    printf("Removido: %d\n", removido);
    exibirCircular(lista);

    printf("REMOÇÃO POR VALOR\n");
    removido = removerValorCircular(lista, 6);
    if (removido != -1)
        printf("Removido valor: %d\n", removido);
    else
        printf("Valor não encontrado para remocao.\n");
    exibirCircular(lista);

    printf("Tamanho atual da lista: %d\n", tamanhoCircular(lista));

    printf("DESTRUIR LISTA\n");
    destruirListaCircular(lista);

    return 0;
}
