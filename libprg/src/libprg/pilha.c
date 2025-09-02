//
// Created by aluno on 02/09/2025.
//
#include "header/lab_2.h"

#include <stdlib.h>

struct pilha {
    int* elementos;
    int topo;
    int capacidade;
};

pilha_t* criar_pilha(int capacidade) {

    pilha_t* p = malloc(sizeof(pilha_t));


    p->elementos = malloc(capacidade * sizeof(int));

    return p;
}