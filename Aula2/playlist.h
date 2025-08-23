#include <stdio.h>  

#define MAX 20  

typedef struct { int musicas[MAX]; int total; } Playlist;  

void criarPlaylist(Playlist *p); 

int estaVazia(Playlist *p); 

int estaCheia(Playlist *p); 

int adicionarMusica(Playlist *p, int idMusica); 

int removerMusica(Playlist *p, int posicao, int *valor); 

int buscarMusica(Playlist *p, int idMusica); 

void mostrarPlaylist(Playlist *p); 

 
