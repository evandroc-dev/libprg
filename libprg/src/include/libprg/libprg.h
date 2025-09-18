#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdbool.h>

typedef struct pilha pilha_t;
//Pilha
pilha_t* criar_pilha(int capacidade);
void empilhar(pilha_t* pilha, int elemento);
int desempilhar(pilha_t* pilha);
bool pilha_vazia(pilha_t* pilha);
void destroi_pilha(pilha_t* pilha);
int topo(pilha_t* pilha);
int tamanho_pilha(pilha_t* pilha);
void imprimir(pilha_t* pilha);

//Fila

typedef struct fila fila_t;
fila_t criar_fila(int capacidade);
bool cheia(fila_t* fila);
bool fila_vazia(fila_t* fila);
int fila_inicio(fila_t* fila);
int fila_fim(fila_t* fila);
int desenfileirar(fila_t* fila);
int tamanho_fila(fila_t* fila);
void destruir_fila(fila_t* fila);
#endif

//Lista
typedef struct lista_linear lista_linear_t;
lista_linear_t* criar_lista_linear(int capacidade, bool ordenada);
void inserir(lista_linear_t* lista, int valor);
bool lista_cheia(lista_linear_t* lista);