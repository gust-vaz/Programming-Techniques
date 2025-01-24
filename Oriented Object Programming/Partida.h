#ifndef _PARTIDA_H_
#define _PARTIDA_H_

#include "Pacman.h"
#include "Labirinto.h"

/*!
 * \brief A class that defines the Partida. It is responsible for
 * checking if the game is over and if the player scored
 */
class Partida{
    private:
        /*!
         * \brief number of pacdots the player obtained
         */
        int score;
    public:
        /*!
         * \brief Partida constructor (sets the score to 0)
         */
        Partida();
        /*!
         * \brief If the player's position is the same as a pacdot, this
         * method increments the score and updates this cell of the new_board to ' '
         * \param lab: (Labirinto) Labirinto new_board that can be updated
         * \param player: (Pacman) player that will provide the position
         */
        void scored(Labirinto lab, Pacman player);
        /*!
         * \brief If the player's position in lab_persona is greater than 1,
         * it means there is a Fantasma in that position, as the Fantasma's value is 2.
         * Thus, this position in the new_board will receive the character 'X'.
         * \param lab: (Labirinto) Labirinto new_board that can be updated and lab_persona accessed
         * \param player: (Pacman) player that will provide the position
         * \return return: (int) 1 if the Fantasma and Pacman occupy the same position, 0 otherwise
         */
        int collision(Labirinto lab, Pacman player);
        /*!
         * \brief Checks if the score reached the number of pacdots, defining the victory or not
         * \param lab: (Labirinto) Labirinto in which the number of pacdots will be accessed
         * \return return: (int) 1 if won, 0 otherwise
         */
        int win(Labirinto lab);
        /*!
         * \brief Gets the score of the Partida
         * \return return: (int) score obtained so far
         */
        int get_score();
};
#endif // _Partida_H_