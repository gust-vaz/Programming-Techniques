#include "Arquivo.h"

Arquivo::Arquivo(){
    n_lines = 0;
    n_columns = -1;
    n_ghosts = 0;
}
void Arquivo::free_Arquivo(){
    int i;
    for(i = 0; i < MAX; i++)
        free(base_board[i]);
    free(base_board);
}
void Arquivo::set_nome(char* nome){
    this->nome = nome;
}
void Arquivo::set_base_board(){
    fstream arq;
    int i, j;
    char line[MAX];

    arq.open(nome, ios::in);
    base_board = (char**) malloc(MAX * sizeof(char*));
    for(i = 0; i < MAX; i++)
        base_board[i] = (char*) malloc(MAX * sizeof(char));
    for(i = 0; arq.getline(line, MAX); i++)
        for(j = 0; line[j] != '\0'; j++){
            base_board[i][j] = line[j];
            if(line[j] == 'F')
                n_ghosts++;
        }
    n_lines = i;
    n_columns = j;
    arq.close();
}
int Arquivo::get_n_lines(){
    return n_lines;
}
int Arquivo::get_n_columns(){
    return n_columns;
}
int Arquivo::get_n_ghosts(){
    return n_ghosts;
}
char* Arquivo::get_base_board_line(int i){
    return base_board[i];
}