#ifndef _FANTASMA_H_
#define _FANTASMA_H_

#include <random>
#include <iostream>
#include "Personagem.h"
#include "Labirinto.h"

/*!
 * \brief A class that defines a Fatasma. It is a specialization
 * of the Personagem class for a Fatasma class. It is responsible for
 * moving the Fatasmas in a pseudo-random manner and defining their positions
 */
class Fantasma : public Personagem {
    public:
        /*!
         * \brief Fatasma constructor (sets the sprite as 'F' and the value
         * as 2)
         */
        Fantasma();
        /*!
         * \brief Sets the position for a series of Fatasmas in the Labirinto
         * \param arq: (Arquivo) use of the base Labirinto to obtain the positions
         * \param Ghost: (Fantasma*) vector of pointers to each Fantasma in the Labirinto
         */
        void set_ghost_position(Arquivo arq, Fantasma *Ghost);
        /*!
         * \brief Generates a pseudo-random number for the direction and calls the 
         * move method of the superclass Personagem until the Fantasma moves to
         * a valid position
         * \param lab: (Labirinto) Labirinto that may have the characters' Labirinto updated
         */
        void mov_ghost(Labirinto lab);
};
#endif // _FANTASMA_H_INCLUDED__