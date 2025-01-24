#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "vetoraleatorio.h"
#include "propriedadesnumericas.h"

/*!
 * \brief Function: tempo;
 * \brief Usage: tempo(&tempo_s, &tempo_ms);
 * \brief This function updates the time in seconds and milliseconds when it was called;
 *
 * \param tempo_s: (long long int *) Number in seconds representing when this function was called
 * \param tempo_ms: (long long int *) Number in milliseconds representing when this function was called
*/
void tempo(long long int *tempo_s, long long int *tempo_ms){
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    *tempo_s = current_time.tv_sec;
    *tempo_ms = current_time.tv_usec;
}

/*!
 * \brief Function: imprime_tempo;
 * \brief Usage: imprime_tempo(antes_s, antes_ms, depois_s, depois_ms);
 * \brief This function prints the time difference between the end and start of an operation in the main function, providing the execution time of that operation;
 *
 * \param antes_s: (long long int) Number in seconds representing when an operation started
 * \param antes_ms: (long long int) Number in milliseconds representing when an operation started
 * \param depois_s: (long long int) Number in seconds representing when an operation ended
 * \param depois_ms: (long long int) Number in milliseconds representing when an operation ended
*/
void imprime_tempo(long long int antes_s, long long int antes_ms, long long int depois_s, long long int depois_ms){
    double antes, depois, a = antes_ms, b = depois_ms;
    while(antes_ms > 0){
        antes_ms = antes_ms / 10;
        depois_ms = depois_ms / 10;
        a = a / 10;
        b = b / 10;
    }
    antes = antes_s + a;
    depois = depois_s + b;
    printf("\nTempo de execução: %lf", depois - antes);
}

/*!
 * \brief Main program: main
 * Tests the functions from the libraries propriedadesnumericas.h and vetoraleatorio.h for a given size and seed
 * 
 * \return return: (int) There are no careful error checks in this program. Generally, it will always return zero. Of course, there are situations where it may return another value to the OS, in cases where unrecoverable errors occur that cause the program to abort execution (segfault, for example)
*/
int main(){
    long long *v;
    long long tamanho = 10, semente = 5499134, i;
    long long antes_s, depois_s, antes_ms, depois_ms;

    printf("\n\nFunção criaVetorAleatorio:\n");
    tempo(&antes_s, &antes_ms);
    v = criaVetorAleatorio(semente, tamanho);
    tempo(&depois_s, &depois_ms);
    imprime_tempo(antes_s, antes_ms, depois_s, depois_ms);

    printf("\n\n\nValores do vetor:\n|");
    for(i = 0; i < tamanho; i++){
        printf(" %lld |", v[i]);
    }

    printf("\n\nFunção ehPar:\n|");
    tempo(&antes_s, &antes_ms);
    for(i = 0; i < tamanho; i++){
        printf(" %d |", ehPar(v[i]));
    }
    tempo(&depois_s, &depois_ms);
    imprime_tempo(antes_s, antes_ms, depois_s, depois_ms);

    printf("\n\nFunção ehPrimo:\n|");
    tempo(&antes_s, &antes_ms);
    for(i = 0; i < tamanho; i++){
        printf(" %d |", ehPrimo(v[i]));
    }
    tempo(&depois_s, &depois_ms);
    imprime_tempo(antes_s, antes_ms, depois_s, depois_ms);

    printf("\n\nFunção ehQuadradoPerfeito:\n|");
    tempo(&antes_s, &antes_ms);
    for(i = 0; i < tamanho; i++){
        printf(" %d |", ehQuadradoPerfeito(v[i]));
    }
    tempo(&depois_s, &depois_ms);
    imprime_tempo(antes_s, antes_ms, depois_s, depois_ms);

    printf("\n\nFunção ehCuboPerfeito:\n|");
    tempo(&antes_s, &antes_ms);
    for(i = 0; i < tamanho; i++){
        printf(" %d |", ehCuboPerfeito(v[i]));
    }
    tempo(&depois_s, &depois_ms);
    imprime_tempo(antes_s, antes_ms, depois_s, depois_ms);

    printf("\n\nFunção ehFibonacci:\n|");
    tempo(&antes_s, &antes_ms);
    for(i = 0; i < tamanho; i++){
        printf(" %d |", ehFibonacci(v[i]));
    }
    tempo(&depois_s, &depois_ms);
    imprime_tempo(antes_s, antes_ms, depois_s, depois_ms);

    printf("\n\nFunção ehFatorial:\n|");
    tempo(&antes_s, &antes_ms);
    for(i = 0; i < tamanho; i++){
        printf(" %d |", ehFatorial(v[i]));
    }
    tempo(&depois_s, &depois_ms);
    imprime_tempo(antes_s, antes_ms, depois_s, depois_ms);
    printf("\n");
    
    free(v);
    return 0;
}