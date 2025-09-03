//
// Created by aluno on 02/09/2025.
//
#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdio.h>

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

int desempilhar(pilha_t* pilha) {
    if(pilha->topo < 0) {
        return -1; //erro de pilha vazia
    } else {
        int elemento = pilha->elementos[pilha->topo];
        pilha->topo--;
        return elemento;
    }
}

bool vazia(pilha_t* pilha) {
    if(pilha->topo < 0) {
        return true;
    } else {
        return false;
    }
}

void destroi_pilha(pilha_t* pilha) {
    free(pilha->elementos);
    free(pilha);
}

int topo(pilha_t* pilha) {
    if(pilha->topo < 0) {
        return -1; //erro de pilha vazia
    } else {
        int elemento = pilha->elementos[pilha->topo];
        return elemento;
    }
}

int tamanho(pilha_t* pilha) {
    return pilha->topo + 1;
}

void imprimir(pilha_t* pilha) {
    printf("imprimindo pilha: ");
    for (int i=0; i<=pilha->topo; i++) {
        printf("%d ", pilha->elementos[i]);
    }
}