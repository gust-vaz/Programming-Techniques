#include <iostream>
#include "Fantasma.h"
#include "Partida.h"
#include <gtest/gtest.h>
using namespace std;

/*!
 * \brief Tests if the file is correctly saving the maze input into the matrix.
 * Also checks if the file is correctly getting the number of rows, columns, and ghosts in the maze.
 */
TEST(Arquivo, set_base_board){
    Arquivo arq;
    int i;
    char *teste = (char*) malloc(9 * sizeof(char));
    teste = (char*) "gtest.txt";
    arq.set_nome(teste);
    arq.set_base_board();

    ASSERT_EQ(9, arq.get_n_lines());
    ASSERT_EQ(7, arq.get_n_columns());
    ASSERT_EQ(2, arq.get_n_ghosts());

    char v[7] = {'*', '.', '.', '.', ' ', 'F', '*'};
    char *aux = (char*) malloc((arq.get_n_columns()) * sizeof(char));
    aux = arq.get_base_board_line(2);
    for(i = 0; i < arq.get_n_columns(); i++)
        ASSERT_EQ(v[i], aux[i]);
    arq.free_Arquivo();
}
/*!
 * \brief Tests if the maze is saving the new_board with the character ' ' instead of 'F',
 * and also checks if in the same position, the lab_persona matrix saved the ghost by assigning the value 2 to the cell.
 * Also analyzes if the methods for updating the cells of these matrices work correctly.
 */
TEST(Labirinto, set_e_att_Labirinto){
    Arquivo arq;
    Labirinto lab;
    int i;
    char *teste = (char*) malloc(9 * sizeof(char));
    teste = (char*) "gtest.txt";
    arq.set_nome(teste);
    arq.set_base_board();

    lab.set_Labirinto(arq);
    char teste_new_board[7] = {'*', '.', '.', '.', ' ', ' ', '*'};
    int teste_lab_persona[7] = {0, 0, 0, 0, 0, 2, 0};

    for(i = 0; i < lab.get_n_columns(); i++){
        ASSERT_EQ(teste_new_board[i], lab.get_new_board_celu(2, i));
        ASSERT_EQ(teste_lab_persona[i], lab.get_lab_persona_celu(2, i));
    }
    lab.att_lab_persona_celu(2, 5, -2);
    lab.att_new_board_celu(2, 3, ' ');

    ASSERT_EQ(0, lab.get_lab_persona_celu(2, 5));   
    ASSERT_EQ(' ', lab.get_new_board_celu(2, 3));
    ASSERT_EQ(3, lab.get_n_pacdots());

    arq.free_Arquivo();
    lab.free_Labirinto();
}
/*!
 * \brief Tests if the ghost moved.
 */
TEST(Fantasma, mov_ghost){
    Arquivo arq;
    Labirinto lab;
    int x_ant, x_dps, y_ant, y_dps, moveu = 0;
    char *teste = (char*) malloc(9 * sizeof(char));
    teste = (char*) "gtest.txt";
    arq.set_nome(teste);
    arq.set_base_board();
    lab.set_Labirinto(arq);

    Fantasma *Ghost;
    Ghost = new Fantasma[arq.get_n_ghosts()];
    Ghost->set_ghost_position(arq, Ghost);
    x_ant = Ghost[1].get_x();
    y_ant = Ghost[1].get_y();
    Ghost[1].mov_ghost(lab);
    x_dps = Ghost[1].get_x();
    y_dps = Ghost[1].get_y();

    if(x_ant != x_dps || y_ant != y_dps){
        moveu = 1;
    }
    ASSERT_EQ(moveu, 1);

    arq.free_Arquivo();
    lab.free_Labirinto();
    delete[] Ghost;
}
/*!
 * \brief Tests if the pacman moved according to the given command and if its initial position is correct.
 */
TEST(Pacman, mov_e_constroi_pac){
    Arquivo arq;
    Labirinto lab;
    int x_ant, x_dps, y_ant, y_dps;
    char *teste = (char*) malloc(9 * sizeof(char));
    teste = (char*) "gtest.txt";
    arq.set_nome(teste);
    arq.set_base_board();
    lab.set_Labirinto(arq);

    Pacman player(lab);
    x_ant = player.get_x();
    y_ant = player.get_y();
    ASSERT_EQ(lab.get_n_lines()/2, x_ant);
    ASSERT_EQ(lab.get_n_columns()/2, y_ant);
    ASSERT_EQ(lab.get_lab_persona_celu(x_ant, y_ant), 1);

    // test movement to the right
    player.mov_pac('d', lab);
    x_dps = player.get_x();
    y_dps = player.get_y();
    ASSERT_EQ(x_ant, x_dps);
    ASSERT_NE(y_ant, y_dps);
    y_ant = y_dps;

    // test movement down
    player.mov_pac('s', lab);
    player.mov_pac('s', lab);
    x_dps = player.get_x();
    y_dps = player.get_y();
    ASSERT_EQ(y_ant, y_dps);
    ASSERT_NE(x_ant, x_dps);
    x_ant = x_dps;

    // test movement to the left
    player.mov_pac('a', lab);
    x_dps = player.get_x();
    y_dps = player.get_y();
    ASSERT_EQ(x_ant, x_dps);
    ASSERT_NE(y_ant, y_dps);
    y_ant = y_dps;

    // test movement up
    player.mov_pac('w', lab);
    x_dps = player.get_x();
    y_dps = player.get_y();
    ASSERT_EQ(x_ant, x_dps);
    ASSERT_EQ(y_ant, y_dps);

    arq.free_Arquivo();
    lab.free_Labirinto();
}
/*!
 * \brief Tests if the player scores when pacman is in the same position as a pacdot, and therefore, also tests if
 * this position has the pacdot replaced by a ' '. Also analyzes if after collecting all pacdots the win method
 * returns if the player indeed won.
 */
TEST(Partida, scored_e_win){
    Arquivo arq;
    Labirinto lab;
    Partida game;
    char *teste = (char*) malloc(9 * sizeof(char));
    teste = (char*) "gtest.txt";
    arq.set_nome(teste);
    arq.set_base_board();
    lab.set_Labirinto(arq);

    Pacman player(lab);
    player.mov_pac('w', lab);
    game.scored(lab, player);
    player.mov_pac('w', lab);
    game.scored(lab, player);

    ASSERT_EQ(game.get_score(), 1);
    ASSERT_EQ(lab.get_new_board_celu(player.get_x(), player.get_y()), ' ');
    
    player.mov_pac('a', lab);
    game.scored(lab, player);
    player.mov_pac('a', lab);
    game.scored(lab, player);

    ASSERT_EQ(game.win(lab), 1);
    arq.free_Arquivo();
    lab.free_Labirinto();
}
/*!
 * \brief Tests if, when pacman and a ghost occupy the same position, the collision method returns that there was
 * a collision and that it replaced the collision position with an 'X'.
 */
TEST(Partida, collision){
    Arquivo arq;
    Labirinto lab;
    Partida game;
    char *teste = (char*) malloc(9 * sizeof(char));
    teste = (char*) "gtest.txt";
    arq.set_nome(teste);
    arq.set_base_board();
    lab.set_Labirinto(arq);

    Pacman player(lab);
    player.mov_pac('w', lab);
    player.mov_pac('w', lab);
    player.mov_pac('w', lab);

    ASSERT_EQ(game.collision(lab, player), 1);
    ASSERT_EQ('X', lab.get_new_board_celu(player.get_x(), player.get_y()));

    arq.free_Arquivo();
    lab.free_Labirinto();
}

/*!
 * \brief If the file is compiled with the TESTS definition, the program is executed to run the tests,
 * otherwise, the game is initialized.
 */
int main(int argc, char **argv){
    #ifdef TESTS
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    #endif
    int i, j, aux;
    char direcao;
    Arquivo arq;
    Labirinto lab;
    Fantasma *Ghost;
    Partida game;

    // Initializing the Maze
    arq.set_nome(argv[1]);
    arq.set_base_board();
    lab.set_Labirinto(arq);

    // Initializing characters
    Ghost = new Fantasma[arq.get_n_ghosts()];
    Ghost->set_ghost_position(arq, Ghost);
    Pacman player(lab);

    while(!game.win(lab) && !game.collision(lab, player)){
        // Printing the Maze
        for(i = 0; i < lab.get_n_lines(); i++){
            for(j = 0; j < lab.get_n_columns(); j++){
                aux = lab.get_lab_persona_celu(i, j);
                if((aux > 0) && (aux % 2 == 0))
                    cout << Ghost->get_sprite();
                else if((aux > 0) && (aux % 2 == 1))
                    cout << player.get_sprite();
                else
                    cout << lab.get_new_board_celu(i, j);
            }
            cout << endl;
        }
        // Waiting for a valid user input
        cout << "Direction (a - left, d - right, w - up, s - down): ";
        cin >> direcao;
        cout << endl;
        while(!player.mov_pac(direcao, lab)){
            cout << "Direction (a - left, d - right, w - up, s - down): ";
            cin >> direcao;
            cout << endl;
        }

        // Checking if this movement caused Pacman to collide with a Ghost
        if(game.collision(lab, player))
            break;
        // If not collided, check if he collected a pacdot
        game.scored(lab, player);
        
        // Moving all Ghosts
        for(i = 0; i < arq.get_n_ghosts(); i++)
            Ghost[i].mov_ghost(lab);

        // Returning to the loop to see if there was any collision or if the player won
    }

    // If the loop ended due to a collision, print the Maze with the collision position
    if(game.collision(lab, player)){
        for(i = 0; i < lab.get_n_lines(); i++){
            for(j = 0; j < lab.get_n_columns(); j++){
                aux = lab.get_lab_persona_celu(i, j);
                if((aux > 0) && (aux % 2 == 0))
                    cout << Ghost->get_sprite();
                else
                    cout << lab.get_new_board_celu(i, j);
            }
            cout << endl;
        }
        cout << endl << "Game over! Points = " << game.get_score() << endl;
    }
    // Otherwise, the user won and their score is shown
    else
        cout << endl << "Congratulations! Points = " << game.get_score() << endl;
    
    // Clearing the memory of the Mazes and Ghosts
    lab.free_Labirinto();
    arq.free_Arquivo();
    delete[] Ghost;
    return 0;
}