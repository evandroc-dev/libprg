#include <tgmath.h>

#include "libprg/libprg.h"
#include <stdlib.h>

typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

lista_linear_t* criar_lista_linear(int capacidade, bool ordenada) {

    lista_linear_t* lista = malloc(sizeof(lista_linear_t));

    lista->elementos = malloc(sizeof(int) * capacidade);

    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->ordenada = ordenada;

    return lista;
}
void inserir_nao_ordenada (lista_linear_t* lista, int  valor) {
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}
void inserir_ordenada(lista_linear_t* lista, int  valor) {
    if (!lista_cheia(lista)) {


        for (int i = lista->tamanho - 1; i>= 0; --i) {
            if (lista->elementos[i] < valor) {
                lista->elementos[i +1] = valor;
                break;
            } else {
                lista->elementos[i + 1] = lista->elementos[i];
            }
        }
        lista->tamanho++;
    }
}


void inserir(lista_linear_t* lista, int valor) {
    if (lista_cheia(lista)) return;

        if (lista->ordenada) {
            inserir_ordenada(lista, valor);
            //algoritmo para lista ordenada
        } else {
            lista->elementos[lista->tamanho] = valor;
            lista->tamanho++;
        }

}

void remover(lista_linear_t* lista, int valor) {

    int indice = busca_linear(lista, valor);

    if (indice > -1) {
        lista->elementos[indice] = lista->elementos[lista->tamanho - 1];
        lista->tamanho--;
    }
}

bool lista_cheia(lista_linear_t* lista) {
    lista->tamanho == lista->capacidade;
}

int buscar(lista_linear_t* lista, int valor) {

    int indice = 0;
    while (indice < lista->tamanho) {
        if (lista->elementos[indice] == valor) {
            return indice;
        }
        indice++;
    }

    return -1;
}

int buscar_na_posicao(lista_linear_t* lista, int posicao) {
    return lista->elementos[posicao];
}

void inserir_na_posicao(lista_linear_t* lista, int valor, int posicao) {

    inserir_nao_ordenada(lista, lista->elementos[posicao]);
    lista->elementos[posicao] = valor;
}

void remover_da_posicao(lista_linear_t* lista, int posicao) {

    int valor = lista->elementos[posicao];
    remover
    }

// remover
// vazia

// destruir