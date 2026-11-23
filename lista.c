#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *lista_criar() {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l != NULL) {
        l->cabeca = NULL;
        l->tamanho = 0;
    }
    return l;
}

int insert(Lista *l, int pos, int valor) {
    if (l == NULL || pos < 0 || pos > l->tamanho) {
        printf("Erro: Posicao %d invalida para insercao.\n", pos);
        return 0;
    }

    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) return 0;
    novo->valor = valor;

    if (pos == 0) {
        novo->proximo = l->cabeca;
        l->cabeca = novo;
    } else {
        No *anterior = l->cabeca;
        for (int i = 0; i < pos - 1; i++) {
            anterior = anterior->proximo;
        }
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }

    l->tamanho++;
    return 1;
}

void show(Lista *l) {
    if (l == NULL) return;
    
    No *atual = l->cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL (tamanho: %d)\n", l->tamanho);
}

int acessar(Lista *l, int pos) {
    if (l == NULL || pos < 0 || pos >= l->tamanho) {
        printf("Erro: Posicao %d nao existe na lista.\n", pos);
        exit(1);
    }

    No *atual = l->cabeca;
    for (int i = 0; i < pos; i++) {
        atual = atual->proximo;
    }
    return atual->valor;
}

int remover(Lista *l, int pos) {
    if (l == NULL || pos < 0 || pos >= l->tamanho) {
        printf("Erro: Posicao %d invalida para remocao.\n", pos);
        return 0;
    }

    No *removido;

    if (pos == 0) {
        removido = l->cabeca;
        l->cabeca = removido->proximo;
    } else {
        No *anterior = l->cabeca;
        for (int i = 0; i < pos - 1; i++) {
            anterior = anterior->proximo;
        }
        removido = anterior->proximo;
        anterior->proximo = removido->proximo;
    }

    free(removido);
    l->tamanho--;
    return 1;
}

void liberar(Lista *l) {
    if (l == NULL) return;

    No *atual = l->cabeca;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(l);
}
