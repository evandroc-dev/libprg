//
// Created by aluno on 25/09/25.
//
#include <stdlib.h>
#include "libprg/libprg.h"
#include <stdio.h>

typedef struct no {
    int valor;
    struct no* proximo;
}no_t;

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

no_t * criar_lista_encadeada_circular(int valor){
    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = no;

    return no;
}
void adicionar_circular(no_t** inicio, int valor) {
    no_t* novo_no = criar_lista_encadeada_circular(valor);
    novo_no->proximo = *inicio;

    no_t* ultimo = *inicio;

    while (ultimo->proximo != *inicio) {
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = *inicio;
}

no_t* buscar_lista_encadeada(no_t** inicio, int valor) {
    no_t* atual = *inicio;

    while (atual != NULL) {
        if (atual->valor == valor)
            return atual;
        atual = atual->proximo;
    }

    return NULL;
}
void remover_lista_encadeada(no_t** inicio, int valor) {
    no_t *atual = *inicio;
    no_t *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            no_t* temp = atual;
            if (anterior)
                anterior->proximo = atual->proximo;
            else
                *inicio = atual->proximo;

            atual = atual->proximo;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

void destruir_lista_encadeada(no_t** inicio) {
    no_t* atual = *inicio;
    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}

void imprimir_lista_encadeada(no_t* inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Elementos da lista: ");
    no_t* atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int primeiro_elemento_lista_encadeada(no_t* inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return -1;
    }
    return inicio->valor;
}

int tamanho_lista_encadeada(no_t* inicio) {
    int contador = 0;
    no_t* atual = inicio;

    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

int buscar_na_posicao_encadeada(no_t* inicio, int posicao) {
    int contador = 0;
    while (inicio != NULL) {
        if (contador == posicao)
            return inicio->valor;

        contador++;
        inicio = inicio->proximo;
    }
    printf("Posição inválida!\n");
    return -1;
}

void inserir_na_posicao_encadeada(no_t** inicio, int valor, int posicao) {
    if (posicao == 0) {
        *inicio = adicionar(*inicio, valor);
        return;
    }

    int contador = 0;
    no_t* atual = *inicio;

    while (atual != NULL && contador < posicao - 1) {
        atual = atual->proximo;
        contador++;
    }

    if (atual == NULL) {
        printf("Posição inválida!\n");
        return;
    }

    no_t* novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

void remover_da_posicao_encadeada(no_t** inicio, int posicao) {
    if (*inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    if (posicao == 0) {
        no_t* temp = *inicio;
        *inicio = (*inicio)->proximo;
        free(temp);
        return;
    }

    int contador = 0;
    no_t* atual = *inicio;
    no_t* anterior = NULL;

    while (atual != NULL && contador < posicao) {
        anterior = atual;
        atual = atual->proximo;
        contador++;
    }

    if (atual == NULL) {
        printf("Posição inválida!\n");
        return;
    }

    anterior->proximo = atual->proximo;
    free(atual);
}