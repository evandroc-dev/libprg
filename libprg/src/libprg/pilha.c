//
// Created by aluno on 02/09/2025.
//
#include "libprg/libprg.h"

#include <stdlib.h>

struct pilha {
    int* elementos;
    int topo;
    int capacidade;
};

pilha_t* criar_pilha(int capacidade) {
    pilha_t* p = malloc(sizeof(pilha_t));
    p->elementos = malloc(capacidade * sizeof(int));
    p->capacidade = capacidade;
    p->topo = -1;
    return p;
}

void empilhar(pilha_t* pilha, int elemento) {
    pilha->topo++;
    pilha->elementos[pilha->topo] = elemento;
}