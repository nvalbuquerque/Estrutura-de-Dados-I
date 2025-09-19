#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

// Função para criar uma nova lista circular
ListaCircular* criarListaCircular() {
    // Aloca memória para a estrutura da lista
    ListaCircular* novaLista = (ListaCircular*)malloc(sizeof(ListaCircular));

    if (novaLista != NULL) {
        novaLista->ultimo = NULL;
        novaLista->tamanho = 0;
    }

    return novaLista;
}

// Função para destruir lista circular e liberar toda a memória
void destruirListaCircular(ListaCircular* lista) {
    if (lista == NULL || lista->ultimo == NULL) {
        free(lista);
        return;
    }

    // Como a lista é circular, começamos pelo próximo do último (é o primeiro)
    NoCircular* primeiro = lista->ultimo->proximo;
    NoCircular* atual = primeiro;
    NoCircular* proximo;

    // Remover todos os nós da lista circular
    do {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    } while (atual != primeiro);

    // Libera a estrutura da lista
    free(lista);
}

// Função para verificar se a lista circular está vazia
int estaVaziaListaCircular(ListaCircular* lista) {
    if (lista == NULL) {
        return 1;
    }

    return (lista->ultimo == NULL);
}

// Função para obter o tamanho da lista circular
int tamanhoCircular(ListaCircular* lista) {
    if (lista == NULL) {
        return 0;
    }

    return lista->tamanho;    
}

// Função para inserir um elemento no início da lista circular
void inserirInicioCircular(ListaCircular* lista, int valor) {
    if (lista == NULL) {
        return;
    }

    // Cria um novo nó
    NoCircular* novoNo = (NoCircular*)malloc(sizeof(NoCircular));
    if (novoNo == NULL) {
        printf("ERRO! Falha na alocação de memória\n");
        return;
    }

    // Inicializa o novo nó
    novoNo->dado = valor;

    // Se a lista estiver vazia
    if (estaVaziaListaCircular(lista)) {
        novoNo->proximo = novoNo; // O nó aponta para si mesmo
        lista->ultimo = novoNo; // O único nó é tanto o primeiro quanto o último
    } else {
        // Insere o novo nó entre o último e o primeiro
        novoNo->proximo = lista->ultimo->proximo; // Novo nó aponta para o primeiro atual
        lista->ultimo->proximo = novoNo; // Último aponta para o novo primeiro
    }

    lista->tamanho++;
}

// Operações de inserção
void inserirFimCircular(ListaCircular* lista, int valor) {
    if (lista == NULL) return;

    NoCircular* novoNo = (NoCircular*)malloc(sizeof(NoCircular));
    if (novoNo == NULL) {
        printf("ERRO! Falha na alocação de memória\n");
        return;
    }

    novoNo->dado = valor;

    if (estaVaziaListaCircular(lista)) {
        novoNo->proximo = novoNo;
        lista->ultimo = novoNo;
    } else {
        novoNo->proximo = lista->ultimo->proximo; 
        lista->ultimo->proximo = novoNo;         
        lista->ultimo = novoNo;                 
    }

    lista->tamanho++;
}

//inserir em posicao especifica
void inserirPosicaoCircular(ListaCircular* lista, int valor, int posicao) {
    if (lista == NULL || posicao < 0 || posicao > lista->tamanho) {
        printf("Posição inválida!\n");
        return;
    }

    if (posicao == 0) {
        inserirInicioCircular(lista, valor);
        return;
    }
    if (posicao == lista->tamanho) {
        inserirFimCircular(lista, valor);
        return;
    }

    NoCircular* novoNo = (NoCircular*)malloc(sizeof(NoCircular));
    novoNo->dado = valor;

    NoCircular* atual = lista->ultimo->proximo; 
    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;

    lista->tamanho++;
}

// Operações de remoção
int removerInicioCircular(ListaCircular* lista){
    if (lista == NULL || estaVaziaListaCircular(lista)) {
        printf("ERRO: lista vazia ou inexistente\n");
        return -1;
    }

    NoCircular* primeiro = lista->ultimo->proximo;
    int valor = primeiro->dado;

    if (lista->tamanho == 1) {
        free(primeiro);
        lista->ultimo = NULL;
    } else {
        lista->ultimo->proximo = primeiro->proximo;
        free(primeiro);
    }

    lista->tamanho--;
    return valor;
}

// Função para remover o elemento do final da lista circular
int removerFimCircular(ListaCircular* lista) {
    if (lista == NULL || estaVaziaListaCircular(lista)) {
        printf("ERRO: lista vazia ou inexistente\n");
        return -1;
    }

    // Se há apenas uma elemento na lista
    if (lista->tamanho == 1) {
        return removerInicioCircular(lista);
    }

    // Encontra o penúltimo nó
    NoCircular* penultimo = lista->ultimo->proximo;
    while (penultimo->proximo != lista->ultimo) {
        penultimo = penultimo->proximo;
    }

    int valor = lista->ultimo->dado;

    // Atualiza os ponteiros
    penultimo->proximo = lista->ultimo->proximo; // Penúltimo aponta para o primeiro;
    free(lista->ultimo);
    lista->ultimo = penultimo;

    lista->tamanho--;

    return valor;
}

int removerPosicaoCircular(ListaCircular* lista, int posicao) {
    if (lista == NULL || estaVaziaListaCircular(lista) || posicao < 0 || posicao >= lista->tamanho) {
        printf("Posição inválida!\n");
        return -1;
    }

    if (posicao == 0) return removerInicioCircular(lista);
    if (posicao == lista->tamanho - 1) return removerFimCircular(lista);

    NoCircular* atual = lista->ultimo->proximo;
    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    NoCircular* removido = atual->proximo;
    int valor = removido->dado;
    atual->proximo = removido->proximo;
    free(removido);

    lista->tamanho--;
    return valor;
}

int removerValorCircular(ListaCircular* lista, int valor) {
    if (lista == NULL || estaVaziaListaCircular(lista)) return -1;

    NoCircular* atual = lista->ultimo->proximo;
    NoCircular* anterior = lista->ultimo;

    do {
        if (atual->dado == valor) {
            if (atual == lista->ultimo->proximo) { // primeiro
                return removerInicioCircular(lista);
            } else if (atual == lista->ultimo) { // último
                return removerFimCircular(lista);
            } else { // no meio
                anterior->proximo = atual->proximo;
                free(atual);
                lista->tamanho--;
                return valor;
            }
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != lista->ultimo->proximo);

    return -1; // valor não encontrado
}

// Operações de busca

// Função para buscar um nó com um valor específico
NoCircular* buscarCircular(ListaCircular* lista, int valor) {
    if (lista == NULL || estaVaziaListaCircular(lista)) {
        return NULL;
    }

    NoCircular* primeiro = lista->ultimo->proximo;
    NoCircular* atual = primeiro;

    // Procurar o valor na lista
    do {
        if (atual->dado == valor) {
            return atual;
        }
        atual = atual->proximo;
    } while (atual != primeiro);

    return NULL; 
}

int buscarPosicaoCircular(ListaCircular* lista, int valor) {
    if (lista == NULL || estaVaziaListaCircular(lista)) return -1;

    NoCircular* atual = lista->ultimo->proximo;
    int pos = 0;

    do {
        if (atual->dado == valor) return pos;
        atual = atual->proximo;
        pos++;
    } while (atual != lista->ultimo->proximo);

    return -1; // não encontrado
}

// Operação de exibição
void exibirCircular(ListaCircular* lista) {
    if (lista == NULL || estaVaziaListaCircular(lista)) {
        printf("Lista vazia!\n");
        return;
    }

    NoCircular* atual = lista->ultimo->proximo; // primeiro
    printf("Lista circular: ");

    do {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    } while (atual != lista->ultimo->proximo);

    printf("\n");
}
