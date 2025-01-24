#include <stdio.h>
#include <stdlib.h>
#include "propriedadesnumericas.h"

int ehPar(long long x){
    return !(x % 2);
}

int ehPrimo(long long x){
    long long i;
    if(x == 1 || x == 0){
        return 0;
    }
    for(i = 2; i * i <= x; i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}

int ehQuadradoPerfeito(long long x){
    long long ini = 0, meio;
    long long fim = 3037000499; // square root of the largest long long number with a perfect square that does not result in overflow
    while(ini < fim){
        meio = (ini + fim) / 2;
        if(meio * meio < x)
            ini = meio + 1;
        else if(meio * meio > x)
            fim = meio - 1;
        else
            fim = meio;
    }
    meio = (ini + fim) / 2;
    return (x == meio * meio);
}

int ehCuboPerfeito(long long x){
    long long ini = 0, meio;
    long long fim = 2097151; // square root of the largest long long number with a perfect cube that does not result in overflow
    while(ini < fim){
        meio = (ini + fim) / 2;
        if(meio * meio * meio < x)
            ini = meio + 1;
        else if(meio * meio * meio > x)
            fim = meio - 1;
        else
            fim = meio;
    }
    meio = (ini + fim) / 2;
    return (x == meio * meio * meio);
}

int ehFibonacci(long long x){
    long long n1 = 0, n2 = 1, aux;
    while(x > n2){
        aux = n1 + n2;
        n1 = n2;
        n2 = aux;
    }
    if(x == n2){
        return 1;
    }
    return 0;
}

int ehFatorial(long long x){
    long long i;
    for(i = 2; x > 1; i++){
        if(x % i != 0){
            return 0;
        }
        x = x / i;
    }
    return 1;
}