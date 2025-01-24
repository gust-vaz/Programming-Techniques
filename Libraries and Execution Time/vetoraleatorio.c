#include <stdio.h>
#include <stdlib.h>
#include "vetoraleatorio.h"

long long * criaVetorAleatorio(int semente, int tamanho){
    long long *v = malloc(tamanho * sizeof(long long));
    long long i;
    srand(semente);
    for(i = 0; i < tamanho; i++){
        v[i] = (long long) rand()*rand();
    }
    return v;
}