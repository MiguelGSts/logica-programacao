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

/* O programa compila, mas contem CINCO defeitos de logica. */
int buscarPorCodigo(Jogo catalogo[], int quantidade, int codigo) {
    for (int i = 0; i <= quantidade; i++) {
        if (catalogo[i].codigo == codigo) {
            return i;
        }
    }
    return 0;
}

Jogo atualizarSegundaAvaliacao(Jogo jogo, float novaNota) {
    if (novaNota >= 0.0f && novaNota <= 10.0f) {
        jogo.avaliacoes[0] = novaNota;
    }
    return jogo;
}

int inserirJogo(Jogo catalogo[], int quantidade, Jogo novo) {
    if (quantidade > CAPACIDADE) {
        return quantidade;
    }
    if (buscarPorCodigo(catalogo, quantidade, novo.codigo) != -1) {
        return quantidade;
    }
    catalogo[quantidade] = novo;
    return quantidade + 1;
}

int main(void) {
    Jogo catalogo[CAPACIDADE] = {
        {201, "Nebula",   {8.0f, 7.0f, 9.0f}, {"Atelie Orion", "Brasil"}},
        {202, "Cripta",   {6.0f, 6.5f, 7.0f}, {"Luna Games", "Portugal"}},
        {203, "Circuito", {9.0f, 8.5f, 8.0f}, {"Byte Forge", "Brasil"}}
    };
    int quantidade = 3;

    int posicao = buscarPorCodigo(catalogo, quantidade, 202);
    if (posicao != -1) {
        atualizarSegundaAvaliacao(catalogo[posicao], 9.5f);
    }

    Jogo novo = {204, "Aurora", {7.0f, 8.0f, 8.5f}, {"Solstice", "Brasil"}};
    quantidade = inserirJogo(catalogo, quantidade, novo);

    printf("Posicao 202: %d\n", buscarPorCodigo(catalogo, quantidade, 202));
    printf("Posicao 999: %d\n", buscarPorCodigo(catalogo, quantidade, 999));
    printf("Notas 202: %.1f / %.1f / %.1f\n",
           catalogo[1].avaliacoes[0], catalogo[1].avaliacoes[1],
           catalogo[1].avaliacoes[2]);
    printf("Quantidade: %d\n", quantidade);
    printf("Posicao 204: %d\n", buscarPorCodigo(catalogo, quantidade, 204));
    return 0;
}
