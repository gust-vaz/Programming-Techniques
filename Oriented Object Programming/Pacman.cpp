#include "Pacman.h"
#include <iostream>

Pacman::Pacman(Labirinto lab){
    sprite = 'C';
    value = 1;
    x = lab.get_n_lines() / 2;
    y = lab.get_n_columns() / 2;
    lab.att_lab_persona_celu(x, y, 1);
}
int Pacman::mov_pac(char direcao, Labirinto lab){
    if(direcao == 's') {direcao = BAIXO;}
    else if(direcao == 'w') {direcao = CIMA;}
    else if(direcao == 'a') {direcao = ESQUERDA;}
    else {direcao = DIREITA;}
    return(move(direcao, lab));
}