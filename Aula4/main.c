#include <stdio.h>
#include <stdlib.h>
#include "lista-dupla.h"

void testarOperacoesBasicas(ListaDupla* lista) {

    inserirInicio(lista, 1);
    inserirInicio(lista, 2);
    inserirInicio(lista, 3);
    printf("Lista frente: ");
    exibirFrente(lista);
    
    inserirFim(lista, 4);
    inserirFim(lista, 5);
    printf("Lista frente: ");
    exibirFrente(lista);
    printf("Tamanho: %d\n", tamanho(lista));
}

void testarInsercaoPosicao(ListaDupla* lista) {

    exibirFrente(lista);
    
    inserirPosicao(lista, 150, 2);
    exibirFrente(lista);
    
    inserirPosicao(lista, 5, 0);
    exibirFrente(lista);
    
    inserirPosicao(lista, 999, tamanho(lista));
    exibirFrente(lista);
    
    printf("Tamanho atual: %d\n", tamanho(lista));
}

void testarRemocao(ListaDupla* lista) {

    exibirFrente(lista);
    
    printf("Removendo início (%d):\n", removerInicio(lista));
    exibirFrente(lista);
    
    printf("Removendo final (%d):\n", removerFim(lista));
    exibirFrente(lista);
    
    printf("Removendo posição (%d):\n", removerPosicao(lista, 2));
    exibirFrente(lista);
    
    printf("Removendo valor (%d):\n", removerValor(lista, 150));
    exibirFrente(lista);
    
    printf("Tamanho atual: %d\n", tamanho(lista));
}

void testarBusca(ListaDupla* lista) {

    inserirFim(lista, 70);
    inserirFim(lista, 80);
    inserirFim(lista, 90);
    exibirFrente(lista);
    
    No* no = buscar(lista, 88);
    if (no != NULL) {
        printf("Encontrado: %d\n", no->dado);
    } else {
        printf("Não encontrado\n");
    }
    
    printf("Buscando posição do valor 77: ");
    int pos = buscarPosicao(lista, 77);
    printf("%d\n", pos);
    
    printf("Buscando valor inexistente 100: ");
    no = buscar(lista, 100);
    if (no == NULL) {
        printf("Não encontrado\n");
    }
}

int main() {

    ListaDupla* lista = criarListaDupla();
    
    testarOperacoesBasicas(lista);
    testarInsercaoPosicao(lista);
    testarRemocao(lista);
    testarBusca(lista);

    printf("Tamanho final: %d\n", tamanho(lista));
    printf("Lista frente: ");
    exibirFrente(lista);
    
    destruirListaDupla(lista);
    printf("\nLista destruída. Testes concluídos!\n");
    
    return 0;
}
