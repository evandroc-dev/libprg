#include <tgmath.h>

#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdio.h>

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

    int indice = buscar(lista, valor);

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
    if (posicao < 0 || posicao >= lista->tamanho) return;

    for (int i = posicao; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }

    lista->tamanho--;
}
void imprimir_lista(lista_linear_t* lista) {
    printf("[");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d", lista->elementos[i]);
        if (i < lista->tamanho - 1) printf(", ");
    }
    printf("]\n");
}

bool lista_vazia(lista_linear_t* lista) {
    return lista->tamanho == 0;
}

void destruir_lista(lista_linear_t* lista) {
    free(lista->elementos);
    free(lista);
}

int primeiro_elemento(lista_linear_t* lista) {
    if (lista_vazia(lista)) {
        printf("Erro: lista vazia.\n");
        return -1; // ou outro valor sentinela
    }
    return lista->elementos[0];
}

int tamanho_atual(lista_linear_t* lista) {
    return lista->tamanho;
}