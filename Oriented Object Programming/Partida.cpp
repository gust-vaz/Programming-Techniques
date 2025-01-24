#include "Partida.h"

Partida::Partida(){
    score = 0;
}
int Partida::collision(Labirinto lab, Pacman player){
    int aux = lab.get_lab_persona_celu(player.get_x(), player.get_y());
    if(aux > 1){
        lab.att_new_board_celu(player.get_x(), player.get_y(), 'X');
        return 1;
    }
    return 0;
}
void Partida::scored(Labirinto lab, Pacman player){
    int aux = lab.get_new_board_celu(player.get_x(), player.get_y());
    if(aux == '.'){
        score++;
        lab.att_new_board_celu(player.get_x(), player.get_y(), ' ');
    }
}
int Partida::win(Labirinto lab){
    if(score == lab.get_n_pacdots())
        return 1;
    return 0;
}
int Partida::get_score(){
    return score;
}