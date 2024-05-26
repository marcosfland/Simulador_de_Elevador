#include <stdio.h>
#include <locale.h>

#define NUM_ANDARES 10

typedef struct {
    int andar_atual;
    int capacidade;
    int ocupacao;
} Elevador;

void inicializar_elevador(Elevador *elevador) {
    elevador->andar_atual = 1;
    elevador->capacidade = 10;
    elevador->ocupacao = 0;
}

void entrar_elevador(Elevador *elevador) {
    if (elevador->ocupacao < elevador->capacidade) {
        elevador->ocupacao++;
        printf("Uma pessoa entrou no elevador. Ocupacao atual: %d\n", elevador->ocupacao);
    } else {
        printf("O elevador esta cheio. Nao é possivel entrar.\n");
    }
}

void sair_elevador(Elevador *elevador) {
    if (elevador->ocupacao > 0) {
        elevador->ocupacao--;
        printf("Uma pessoa saiu do elevador. Ocupacao atual: %d\n", elevador->ocupacao);
    } else {
        printf("O elevador esta vazio. Não é possavel sair.\n");
    }
}

void mover_elevador(Elevador *elevador, int andar_destino) {
    if (andar_destino >= 1 && andar_destino <= NUM_ANDARES) {
        printf("Movendo o elevador do andar %d para o andar %d\n", elevador->andar_atual, andar_destino);
        elevador->andar_atual = andar_destino;
    } else {
        printf("Andar invalido. O elevador nao se moveu.\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Elevador elevador;
    inicializar_elevador(&elevador);

    entrar_elevador(&elevador);
    entrar_elevador(&elevador);
    sair_elevador(&elevador);
    mover_elevador(&elevador, 5);
    entrar_elevador(&elevador);
    sair_elevador(&elevador);
    mover_elevador(&elevador, 10);

    return 0;
}