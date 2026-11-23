#include <stdio.h>
#include "lista.h"

int main() {
    Lista *l = lista_criar();
    printf("=== 1. TESTANDO INSERCOES ===\n");
    
    insert(l, 0, 20);
    show(l);

    insert(l, 0, 10);
    show(l);

    insert(l, 2, 40);
    show(l);

    insert(l, 2, 30);
    show(l);

    insert(l, -1, 99);
    insert(l, 10, 99);

    printf("\n=== 2. TESTANDO ACESSO ===\n");
    printf("Elemento na pos 0: %d\n", acessar(l, 0));
    printf("Elemento na pos 2: %d\n", acessar(l, 2));
    printf("Elemento na pos 3: %d\n", acessar(l, 3));

    printf("\n=== 3. TESTANDO REMOCOES ===\n");
    
    printf("Removendo pos 1...\n");
    remover(l, 1);
    show(l);

    printf("Removendo pos 0...\n");
    remover(l, 0);
    show(l);

    printf("Removendo pos 1...\n");
    remover(l, 1);
    show(l);

    remover(l, 5);

    printf("\n=== 4. LIBERANDO MEMORIA ===\n");
    liberar(l);
    printf("Memoria liberada com sucesso.\n");

    return 0;
}
