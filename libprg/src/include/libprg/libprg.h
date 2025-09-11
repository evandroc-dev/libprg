#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdbool.h>

typedef struct pilha pilha_t;

pilha_t* criar_pilha(int capacidade);
void empilhar(pilha_t* pilha, int elemento);
int desempilhar(pilha_t* pilha);
bool vazia(pilha_t* pilha);
void destroi_pilha(pilha_t* pilha);
int topo(pilha_t* pilha);
int tamanho(pilha_t* pilha);
void imprimir(pilha_t* pilha);


typedef struct fila fila_t;
fila_t criar_fila(int capacidade);
bool cheia(fila_t fila);
int desenfileirar(fila_t* fila);
int tamanho(fila_t* fila);
void destruir_fila(fila_t* fila);
#endif
