#include "Labirinto.h"

Labirinto::Labirinto(){
    n_pacdots = 0;
}
void Labirinto::free_Labirinto(){
    int i;
    for(i = 0; i < n_lines; i++){
        delete[] new_board[i];
        delete[] lab_persona[i];
    }
    delete[] new_board;
    delete[] lab_persona;
}
void Labirinto::set_Labirinto(Arquivo arq){
    int i, j;
    char *aux;
    n_lines = arq.get_n_lines();
    n_columns = arq.get_n_columns();
    n_ghosts = arq.get_n_ghosts();
    
    aux = (char*) malloc((n_columns) * sizeof(char));
    
    lab_persona = new int*[n_lines];
    new_board = new char*[n_lines];

    for(i = 0; i < n_lines; i++){
        lab_persona[i] = new int[n_columns];
        new_board[i] = new char[n_columns];
        aux = arq.get_base_board_line(i);

        for(j = 0; j < n_columns; j++){
            if(aux[j] == 'F'){
                lab_persona[i][j] = 2;
                new_board[i][j] = ' ';
            }
            else if(aux[j] == '.'){
                lab_persona[i][j] = 0;
                new_board[i][j] = '.';
                n_pacdots++;
            }
            else{
                new_board[i][j] = aux[j];
                lab_persona[i][j] = 0;
            }
        }
    }
}
void Labirinto::att_new_board_celu(int i, int j, char ch){
    new_board[i][j] = ch;
}
void Labirinto::att_lab_persona_celu(int i, int j, int value){
    lab_persona[i][j] += value;
}
int Labirinto::get_n_pacdots(){
    return n_pacdots;
}
char Labirinto::get_new_board_celu(int i, int j){
    return new_board[i][j];
}
int Labirinto::get_lab_persona_celu(int i, int j){
    return lab_persona[i][j];
}