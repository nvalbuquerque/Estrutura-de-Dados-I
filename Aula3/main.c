#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "lista_dinamicaArray.h"

int main() {
    ListaDinamica biblioteca;
    inicializarLista(&biblioteca);

    clock_t inicio, fim;
    double tempo;
    Livro l, resultado;

    int testes[] = {5, 500, 5000};  

    for (int t = 0; t < 3; t++) {
        int n = testes[t];
        printf("\n=== Teste com %d livros ===\n", n);

        liberarLista(&biblioteca);
        inicializarLista(&biblioteca);

        inicio = clock();
        for (int i = 1; i <= n; i++) {
            sprintf(l.titulo, "Livro %d", i);
            sprintf(l.autor, "Autor %d", i);
            sprintf(l.isbn, "ISBN%05d", i);  // Ajustado para 5 dígitos
            l.ano = 2000 + (i % 100);
            l.status = DISPONIVEL;
            l.nomeUsuario[0] = '\0';
            l.dataEmprestimo[0] = '\0';

            cadastrarLivro(&biblioteca, l);
        }
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para cadastrar %d livros: %.6f segundos\n", n, tempo);

        char isbnBusca[20];
        sprintf(isbnBusca, "ISBN%05d", n);

        inicio = clock();
        int pos = buscarLivroPorISBN(&biblioteca, isbnBusca, &resultado);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para buscar o ultimo livro: %.6f segundos\n", tempo);
        printf("Livro encontrado na posição: %d\n", pos);

        inicio = clock();
        int success = emprestarLivro(&biblioteca, isbnBusca, "UsuarioTeste", "30/08/2025");
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para emprestar o ultimo livro: %.6f segundos\n", tempo);
        printf("Empréstimo %s\n", success ? "bem-sucedido" : "falhou");

        inicio = clock();
        success = devolverLivro(&biblioteca, isbnBusca);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para devolver o ultimo livro: %.6f segundos\n", tempo);
        printf("Devolução %s\n", success ? "bem-sucedida" : "falhou");
    }

    liberarLista(&biblioteca);
    return 0;
}
