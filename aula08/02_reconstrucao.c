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
        {202, "Cripta",   {6.0f, 6.5f, 7.0f}, {"Luna Games",   "Portugal"}},
        {203, "Circuito", {9.0f, 8.5f, 8.0f}, {"Byte Forge",   "Brasil"}}
    };
    int quantidade = 3;

    /* MISSÃO A: listar somente os jogos cadastrados, mostrando
       codigo, titulo, nome do estudio e pais. */

    /* MISSÃO B: atualizar a segunda avaliacao de Cripta para 9.5,
       sem alterar a primeira ou a terceira. */

    /* MISSÃO C: calcular e mostrar a media das tres avaliacoes
       de Nebula (codigo 201). */

    printf("Jogos cadastrados: %d\n", quantidade);
    return 0;
}
