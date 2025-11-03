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
fila_t* criar_fila(int capacidade);
bool cheia(fila_t* fila);
bool fila_vazia(fila_t* fila);
int fila_inicio(fila_t* fila);
int fila_fim(fila_t* fila);
void enfileirar(fila_t* fila, int elemento);
int desenfileirar(fila_t* fila);
int tamanho_fila(fila_t* fila);
void destruir_fila(fila_t* fila);
#endif

//Lista linear
typedef struct lista_linear lista_linear_t;
lista_linear_t* criar_lista_linear(int capacidade, bool ordenada);
void inserir_nao_ordenada (lista_linear_t* lista, int  valor);
void inserir_ordenada(lista_linear_t* lista, int  valor);
void inserir(lista_linear_t* lista, int valor);
bool lista_cheia(lista_linear_t* lista);
void remover(lista_linear_t* lista, int valor);
int buscar(lista_linear_t* lista, int valor);
int buscar_na_posicao(lista_linear_t* lista, int posicao);
void inserir_na_posicao(lista_linear_t* lista, int valor, int posicao);
void remover_da_posicao(lista_linear_t* lista, int posicao);
bool lista_vazia(lista_linear_t* lista);
void destruir_lista(lista_linear_t* lista);
void imprimir_lista(lista_linear_t* lista);
int primeiro_elemento(lista_linear_t* lista);
int tamanho_atual(lista_linear_t* lista);

//Lista encadeada
typedef struct no no_t;
no_t* criar_lista_encadeada (int valor);
no_t* adicionar(no_t* inicio, int valor);
no_t* buscar_lista_encadeada(no_t** inicio, int valor);
void remover_lista_encadeada(no_t** inicio, int valor);
