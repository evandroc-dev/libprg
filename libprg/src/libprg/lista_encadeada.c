//
// Created by aluno on 25/09/25.
//
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct no {
    int valor;
    struct no* proximo;
};no_t;

no_t* criar_lista_encadeada (int valor) {
    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

no_t* adicionar(no_t* inicio, int valor) {

    no_t* novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = inicio;
    inicio = novo_no;

    return inicio;
}
// remover
// destruir
// buscar