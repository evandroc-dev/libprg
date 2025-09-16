#include <tgmath.h>

#include "libprg/libprg.h"


typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
};lista_linear_t;

lista_linear_t* criar_lista_linear(int capacidade) {

    lista_linear_t* lista = malloc(sizeof(lista_linear_t));

    lista->elementos = malloc(sizeof(int) * capacidade);

    lista->tamanho = 0;
    lista->capacidade = capacidade;

    return lista;
}
void inserir(lista_linear_t* lista, int valor) {
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
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


// remover
// vazia

// destruir