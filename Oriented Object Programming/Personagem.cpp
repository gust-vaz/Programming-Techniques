#include "Personagem.h"

void Personagem::set_position(int x, int y){
    this->x = x;
    this->y = y;
}
int Personagem::move(int direcao, Labirinto lab){
    int n_lin = lab.get_n_lines();
    int n_col = lab.get_n_columns();
    int aux;
    if(direcao == BAIXO){
        aux = (x+1) % n_lin;
        if(lab.get_new_board_celu(aux, y) != '*'){
            lab.att_lab_persona_celu(x, y, -value);
            x = aux;
        }
        else{return 0;}
    }
    else if(direcao == CIMA){
        if(x-1 < 0) {aux = n_lin - 1;}
        else {aux = (x-1) % n_lin;}
        if(lab.get_new_board_celu(aux, y) != '*'){
            lab.att_lab_persona_celu(x, y, -value);
            x = aux;
        }
        else {return 0;}
    }
    else if(direcao == ESQUERDA){
        if(y-1 < 0) aux = n_col - 1;
        else aux = (y-1) % n_col;
        if(lab.get_new_board_celu(x, aux) != '*'){
            lab.att_lab_persona_celu(x, y, -value);
            y = aux;
        }
        else {return 0;}
    }
    else{ //direcao = DIREITA
        aux = (y+1) % n_col;
        if(lab.get_new_board_celu(x, aux) != '*'){
            lab.att_lab_persona_celu(x, y, -value);
            y = aux;
        }
        else {return 0;}
    }
    lab.att_lab_persona_celu(x, y, value);
    return 1;
}
char Personagem::get_sprite(){
    return sprite;
}
int Personagem::get_x(){
    return x;
}
int Personagem::get_y(){
    return y;
}