//
// Created by aluno on 09/09/25.
//
#include "libprg/libprg.h"
#include  <stdlib.h>
#include <stdbool.h>
typedef struct fila {
    int* elementos;
    int tamanho;
    int inicio;
    int fim;
    int capacidade;
}; fila_t;

fila_t criar_fila(int capacidade) {

    fila_t* f = malloc(sizeof(fila_t));

    f->elementos = malloc(capacidade *sizeof(int));

    f->inicio = 0;
    f->fim = 0;
    f->tamanho = capacidade;
    f->capacidade = capacidade;

    return f;
}

void enfileirar(fila_t*, int valor) {

    if (cheia(fila)) {
        exit(exit_failure);
    }

    fila.elementos[fila.fim] = valor;
    fila.fim++;
    fila.tamanho++;
}

// enfileirar
// desenfileirar
// inicio
// fim
// tamanho
// vazia
bool cheia(fila_t fila) {
    return fila.tamanho >= fila.capacidade;

}
// destruir_fila

