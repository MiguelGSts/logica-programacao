#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char titulo[60];
    float avaliacoes[3];
} Jogo;

int main(void) {
    Jogo jogo = {201, "Nebula", {8.0f, 7.0f, 9.0f}};

    strcpy(jogo.titulo, "Nebula: Edicao Final");
    jogo.avaliacoes[1] = 9.5f; 

    printf("Codigo: %d\n", jogo.codigo); 
    printf("Titulo: %s\n", jogo.titulo);
    printf("Segunda avaliacao: %.1f\n", jogo.avaliacoes[1]);
    printf("Terceira avaliacao: %.1f\n", jogo.avaliacoes[2]); 

    return 0;
}
