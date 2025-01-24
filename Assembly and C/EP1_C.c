#include <stdio.h>
int primo(long int n);

int primo(long int n){
    long int div = 2;
    int verifica = 1;
    while (div * div <= n && verifica){
        if (n % div == 0){
            verifica = 0 ;
        }
        else {
            div++;
        }
    }
    return verifica;
}

int main(){
    long int n, p, q = 0;
    int eh_primo, mod, achamo;

    scanf("%d %ld", &mod, &n);

    if(mod == 0){
        eh_primo = 0;
        for(p = n + 1; !eh_primo; p++){
            if(primo(p)){
                eh_primo = 1;
                p--;
            }
        }
        printf("%ld\n", p);
    }
    else{
        p = 2; achamo = 0;
        while(!achamo && p*p <= n){
            if(n % p == 0){
                q = n/p;
                if(primo(q)){
                    achamo = 1;
                }
                /*find the next prime p*/
                else{
                    eh_primo = 0;
                    for(p++; !eh_primo; p++){
                        if(primo(p)){
                            eh_primo = 1;
                            p--;
                        }
                    }
                }
            }
            else{
                /*find the next prime p*/
                eh_primo = 0;
                for(p++; !eh_primo; p++){
                    if(primo(p)){
                        eh_primo = 1;
                        p--;
                    }
                }
            }
        }
        if(achamo){
            printf("%ld %ld\n", p, q);
        }
    }
    return 0;
}