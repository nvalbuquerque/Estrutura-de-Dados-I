#include <stdio.h> 
#include "playlist.h"  

void criarPlaylist(Playlist *p) { 
    p->total = 0; 
}  

int estaVazia(Playlist *p) {
    return (p -> total == 0); 
    
}  

int estaCheia(Playlist *p) {
    return (p->total == MAX); 
    
}  

int adicionarMusica(Playlist *p, int idMusica) {
    if (estaCheia(p)) {
        return 0; 
        
    } else { 
        p->musicas[p->total] = idMusica; p->total++; 
        return 1; 
        
    } 
}  

int removerMusica(Playlist *p, int posicao, int *idMusica) {
    int i; 
    if (estaVazia(p) || posicao < 0 || posicao >= p->total) {
        return 0; 
    }
    *idMusica = p->musicas[posicao]; 
    for (i = posicao; i < p->total - 1; i++) { 
        p->musicas[i] = p->musicas[i+1]; 
    } 
    p->total--; 
    return -1; 
}  

int buscarMusica(Playlist *p, int idMusica) {
    int i; 
    for(i = 0; i < p->total; i++) {
        if (p->musicas[i] == idMusica) return i; 
    } 
    return -1; 
}  

void mostrarPlaylist(Playlist *p) {
    int i; 
    for (i = 0; i < p->total; i++) {
        printf("%d ", p->musicas[i]); 
    } 
    printf("\n"); 
} 
