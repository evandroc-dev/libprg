//
// Created by aluno on 09/09/25.
//
#include "libprg/libprg.h"
#include  <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct fila {
    int *elementos;
    int tamanho;
    int inicio;
    int fim;
    int capacidade;
} fila_t;

fila_t* criar_fila(int capacidade) {
    fila_t *f = malloc(sizeof(fila_t));

    f->elementos = malloc(capacidade * sizeof(int));

    f->inicio = 0;
    f->fim = 0;
    f->tamanho = capacidade;
    //desafio tirar a capacidade
    f->capacidade = capacidade;

    return f;
}

void enfileirar(fila_t* fila, int valor) {
    if (cheia(fila)) {
        exit(EXIT_FAILURE);
    }

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

int desenfileirar(fila_t* fila) {
    if (fila_vazia(fila)) {
        exit(EXIT_FAILURE);
    }
    int valor = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return valor;
}

int tamanho_fila(fila_t* fila) {
    return fila->tamanho;
}

int fila_inicio(fila_t* fila) {
    return fila->inicio;
}

int fila_fim(fila_t* fila) {
    return fila->fim;
}
bool fila_vazia(fila_t* fila) {
    return fila->tamanho == 0;
}



bool cheia(fila_t* fila) {
    return fila->tamanho >= fila->capacidade;
}

// destruir_fila
void destruir_fila(fila_t* fila) {
    if (fila) {
        free(fila->elementos);
        free(fila);
    }
}
