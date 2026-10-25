#include <stdio.h>

#define CAPACIDADE 40

typedef struct {
    char nome[50];
    char pais[30];
} Estudio;

typedef struct {
    int codigo;
    char titulo[60];
    float avaliacoes[3];
    Estudio estudio;
} Jogo;

int main(void) {
    Jogo catalogo[CAPACIDADE] = {
        {201, "Nebula",   {8.0f, 7.0f, 9.0f}, {"Atelie Orion", "Brasil"}},
        {202, "Cripta",   {6.0f, 6.5f, 7.0f}, {"Luna Games", "Portugal"}},
        {203, "Circuito", {9.0f, 8.5f, 8.0f}, {"Byte Forge", "Brasil"}}
    };
    int quantidade = 3;
    float mediaNebula = 0.0;

    for(int cont = 0; cont < quantidade; cont++){
        printf("%d - %s | %s (%s)\n", 
        catalogo[cont].codigo, 
        catalogo[cont].titulo, 
        catalogo[cont].estudio.nome, 
        catalogo[cont].estudio.pais);
    }

    catalogo[1].avaliacoes[1] = 9.5f;
    printf("\n== Avaliacoes de Cripta ==\n");
    printf("Primeira avaliacao: %.1f\n", catalogo[1].avaliacoes[0]);
    printf("Segunda avaliacao: %.1f\n", catalogo[1].avaliacoes[1]);
    printf("Terceira avaliacao: %.1f\n\n", catalogo[1].avaliacoes[2]);

    for(int cont = 0; cont < 3; cont++){
        mediaNebula += catalogo[0].avaliacoes[cont];
    }
    printf("=> Media de Nebula: %.1f\n\n", (mediaNebula/3));

    printf("Jogos cadastrados: %d\n", quantidade);
    return 0;
}
