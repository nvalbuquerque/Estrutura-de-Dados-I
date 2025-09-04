#ifndef LISTA_DINAMICA_ARRAY_H
#define LISTA_DINAMICA_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CAPACIDADE_INICIAL 10

typedef enum {
    DISPONIVEL,
    EMPRESTADO,
    RESERVADO
} Status;

typedef struct {
    char titulo[100];
    char autor[100];
    char isbn[20];
    int ano;
    Status status;
    char nomeUsuario[100];
    char dataEmprestimo[11];
} Livro;

typedef struct {
    Livro *livros;
    int quantidade;
    int capacidade;
} ListaDinamica;

void inicializarLista(ListaDinamica *lista);
void redimensionarLista(ListaDinamica *lista, int novaCapacidade);
int cadastrarLivro(ListaDinamica *lista, Livro livro);
int buscarLivroPorISBN(ListaDinamica *lista, const char *isbn, Livro *resultado);
int emprestarLivro(ListaDinamica *lista, const char *isbn, const char *usuario, const char *data);
int devolverLivro(ListaDinamica *lista, const char *isbn);
void listarLivros(ListaDinamica *lista);
void liberarLista(ListaDinamica *lista);

#endif
