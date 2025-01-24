#ifndef _PACMAN_H_
#define _PACMAN_H_

#include "Personagem.h"

/*!
 * \brief A class that defines a Pacman. It is a specialization
 * of the Personagem class for a Pacman class. It is responsible for
 * moving the Pacman and setting its initial position
 */
class Pacman : public Personagem {
    public:
        /*!
         * \brief Pacman constructor (sets the sprite as 'C', the value
         * as 1 and the initial position as the middle of the Labirinto)
         * \param lab: (Labirinto) Labirinto that will have the lab_persona updated with
         * the new Personagem
         */
        Pacman(Labirinto lab);
        /*!
         * \brief Translates the direction from input values into char and updates the Pacman's position,
         * calling the move from the superclass Personagem
         * \param direcao: (char) direction in which the Pacman will move
         * \param lab: (Labirinto) Labirinto that may have the Labirinto of characters updated
         * \return retorno: (int) 1 if there was a valid movement or 0 otherwise
         */
        int mov_pac(char direcao, Labirinto lab);
};
#endif // _PACMAN_H_