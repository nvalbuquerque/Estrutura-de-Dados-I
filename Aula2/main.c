#include <stdio.h>  

#include "playlist.h"  
  
int main(void) {  
    Playlist p;  
    int idMusica;
    int opcao;
    int idRemovido;
    int posicao;

    criarPlaylist(&p); 
    
    do {

        printf("\n ===== Minha Playlist ===== \n 1. Adicionar música \n 2. Remover música \n 3. Buscar música \n 4. Mostrar playlist \n 5. Sair \n Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o ID da música a ser adicionada: ");
                scanf("%d", &idMusica);
                if (adicionarMusica(&p, idMusica)) {
                    printf("Música com ID %d adicionada com sucesso!");
                     
                } else {
                    printf("Erro: Playlist cheia!\n");
                }
                break;
            case 2:
                printf("Digite a posição da música a ser removida: ");
                scanf("%d", &posicao);
                if (removerMusica(&p, posicao, &idRemovido)) {
                    printf("Música na posição %d removida com sucesso!");
                } else {
                printf("Erro: Posição inválida ou playlist vazia!\n");
                }
                break;
            case 3:
                printf("Digite o ID da música a ser buscada: ");
                scanf("%d", &idMusica);
                if (buscarMusica(&p, idMusica)) {
                    printf("Música com ID %d encontrada!");
                } else {
                printf("Erro: ID inválido ou playlist vazia!\n");
                }
                break;
            case 4:
                if (estaVazia(&p)) {
                    printf ("Playlist vazia.");
                } else {
                    printf("Playlist: \n");
                    mostrarPlaylist(&p);
                }
                break;
            case 5:
                break;
        }
    } while (opcao != 5);
    
    return 0;  
}  
