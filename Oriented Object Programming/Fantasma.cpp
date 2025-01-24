#include "Fantasma.h"
#include "Arquivo.h"

Fantasma::Fantasma(){
    sprite = 'F';
    value = 2;
}
void Fantasma::mov_ghost(Labirinto lab){
    random_device rd;
    mt19937 rand_generator(rd());
    uniform_int_distribution<int> dist(0, 3);
    while(!move(dist(rand_generator), lab));
}
void Fantasma::set_ghost_position(Arquivo arq, Fantasma *Ghost){
    char *aux;
    int m, n, i, j, k = 0;

    m = arq.get_n_lines();
    n = arq.get_n_columns();
    aux = new char[n];
    for(i = 0; i < m && k < arq.get_n_ghosts(); i++){
        aux = arq.get_base_board_line(i);
        for(j = 0; j < n && k < arq.get_n_ghosts(); j++){
            if(aux[j] == 'F')
                Ghost[k++].set_position(i, j);
        }
    }
}