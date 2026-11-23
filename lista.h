#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *cabeca;
    int tamanho;
} Lista;

Lista *lista_criar();
int insert(Lista *l, int pos, int valor);
void show(Lista *l);
int acessar(Lista *l, int pos);
int remover(Lista *l, int pos);
void liberar(Lista *l);

#endif
