#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct pilha pilha_t;

pilha_t* criar_pilha(int capacidade);
void empilhar(pilha_t* pilha, int elemento);
int desempilhar(pilha_t* pilha);
bool vazia(pilha_t* pilha);

#endif
