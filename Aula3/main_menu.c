#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_dinamicaArray.h"

int main() {
    ListaDinamica biblioteca;
    inicializarLista(&biblioteca);

    int opcao;
    char isbnBusca[20];
    char usuario[100];
    char data[11];
    Livro livroResultado;
    Livro novoLivro;

    do {
        printf("\n=== Sistema de Biblioteca ===\n");
        printf("1. Cadastrar livro\n");
        printf("2. Consultar livro por ISBN\n");
        printf("3. Emprestar livro\n");
        printf("4. Devolver livro\n");
        printf("5. Listar todos os livros\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Titulo: ");
                fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
                novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = '\0';

                printf("Autor: ");
                fgets(novoLivro.autor, sizeof(novoLivro.autor), stdin);
                novoLivro.autor[strcspn(novoLivro.autor, "\n")] = '\0';

                printf("ISBN: ");
                fgets(novoLivro.isbn, sizeof(novoLivro.isbn), stdin);
                novoLivro.isbn[strcspn(novoLivro.isbn, "\n")] = '\0';

                printf("Ano: ");
                scanf("%d", &novoLivro.ano);
                getchar();

                novoLivro.status = DISPONIVEL;
                novoLivro.nomeUsuario[0] = '\0';
                novoLivro.dataEmprestimo[0] = '\0';

                if (cadastrarLivro(&biblioteca, novoLivro)) {
                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Erro ao cadastrar livro.\n");
                }
                break;

            case 2:
                printf("Digite o ISBN do livro: ");
                fgets(isbnBusca, sizeof(isbnBusca), stdin);
                isbnBusca[strcspn(isbnBusca, "\n")] = '\0';

                if (buscarLivroPorISBN(&biblioteca, isbnBusca, &livroResultado) != -1) {
                    printf("\n=== LIVRO ENCONTRADO ===\n");
                    printf("Título: %s\n", livroResultado.titulo);
                    printf("Autor: %s\n", livroResultado.autor);
                    printf("ISBN: %s\n", livroResultado.isbn);
                    printf("Ano: %d\n", livroResultado.ano);
                    printf("Status: ");
                    switch (livroResultado.status) {
                        case DISPONIVEL: printf("Disponível\n"); break;
                        case EMPRESTADO: 
                            printf("Emprestado para %s (%s)\n", 
                                   livroResultado.nomeUsuario, livroResultado.dataEmprestimo);
                            break;
                        case RESERVADO: printf("Reservado\n"); break;
                    }
                } else {
                    printf("Livro não encontrado.\n");
                }
                break;

            case 3:
                printf("Digite o ISBN do livro a emprestar: ");
                fgets(isbnBusca, sizeof(isbnBusca), stdin);
                isbnBusca[strcspn(isbnBusca, "\n")] = '\0';

                printf("Nome do usuario: ");
                fgets(usuario, sizeof(usuario), stdin);
                usuario[strcspn(usuario, "\n")] = '\0';

                printf("Data do emprestimo (dd/mm/aaaa): ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = '\0';

                if (emprestarLivro(&biblioteca, isbnBusca, usuario, data)) {
                    printf("Livro emprestado com sucesso!\n");
                } else {
                    printf("Erro: livro não encontrado ou não disponível.\n");
                }
                break;

            case 4:
                printf("Digite o ISBN do livro a devolver: ");
                fgets(isbnBusca, sizeof(isbnBusca), stdin);
                isbnBusca[strcspn(isbnBusca, "\n")] = '\0';

                if (devolverLivro(&biblioteca, isbnBusca)) {
                    printf("Livro devolvido com sucesso!\n");
                } else {
                    printf("Erro: livro não encontrado ou não estava emprestado.\n");
                }
                break;

            case 5:
                listarLivros(&biblioteca);
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 6);

    liberarLista(&biblioteca);
    return 0;
}
