#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dinamicaArray.h"  


void inicializarLista(ListaDinamica *lista) {
    lista->livros = (Livro*) malloc(CAPACIDADE_INICIAL * sizeof(Livro));
    lista->quantidade = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
}

void redimensionarLista(ListaDinamica *lista, int novaCapacidade) {
    Livro *novoArray = (Livro*) malloc(novaCapacidade * sizeof(Livro));
    
    for (int i = 0; i < lista->quantidade; i++) {
        novoArray[i] = lista->livros[i];
    }
    
    free(lista->livros);
    lista->livros = novoArray;
    lista->capacidade = novaCapacidade;
}

int cadastrarLivro(ListaDinamica *lista, Livro livro) {
    if (lista->quantidade == lista->capacidade) {
        redimensionarLista(lista, lista->capacidade * 2);
    }
    
    lista->livros[lista->quantidade] = livro;
    lista->quantidade++;
    return 1;
}

int buscarLivroPorISBN(ListaDinamica *lista, const char *isbn, Livro *resultado) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->livros[i].isbn, isbn) == 0) {
            *resultado = lista->livros[i];
            return i;
        }
    }
    return -1;
}

int emprestarLivro(ListaDinamica *lista, const char *isbn, const char *usuario, const char *data) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->livros[i].isbn, isbn) == 0) {
            if (lista->livros[i].status != DISPONIVEL) {
                return 0;
            }
            
            lista->livros[i].status = EMPRESTADO;
            strncpy(lista->livros[i].nomeUsuario, usuario, sizeof(lista->livros[i].nomeUsuario) - 1);
            strncpy(lista->livros[i].dataEmprestimo, data, sizeof(lista->livros[i].dataEmprestimo) - 1);
            return 1;
        }
    }
    return 0;
}

int devolverLivro(ListaDinamica *lista, const char *isbn) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->livros[i].isbn, isbn) == 0) {
            if (lista->livros[i].status == EMPRESTADO) {
                lista->livros[i].status = DISPONIVEL;
                lista->livros[i].nomeUsuario[0] = '\0';
                lista->livros[i].dataEmprestimo[0] = '\0';
                return 1;
            }
        }
    }
    return 0;
}

void listarLivros(ListaDinamica *lista) {
    printf("\n=== LIVROS CADASTRADOS (%d/%d) ===\n", lista->quantidade, lista->capacidade);
    for (int i = 0; i < lista->quantidade; i++) {
        printf("\n%d. %s - %s\n", i + 1, lista->livros[i].titulo, lista->livros[i].autor);
        printf("   ISBN: %s, Ano: %d\n", lista->livros[i].isbn, lista->livros[i].ano);
        printf("   Status: ");
        switch (lista->livros[i].status) {
            case DISPONIVEL: printf("Disponível"); break;
            case EMPRESTADO: 
                printf("Emprestado para %s (%s)", lista->livros[i].nomeUsuario, lista->livros[i].dataEmprestimo);
                break;
            case RESERVADO: printf("Reservado"); break;
        }
        printf("\n");
    }
}

void liberarLista(ListaDinamica *lista) {
    free(lista->livros);
    lista->livros = NULL;
    lista->quantidade = 0;
    lista->capacidade = 0;
}
