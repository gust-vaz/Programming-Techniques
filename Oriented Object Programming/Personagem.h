#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Labirinto.h"

#define BAIXO 0
#define CIMA 1
#define ESQUERDA 2
#define DIREITA 3

/*!
 * \brief A class that defines a Personagem. It is responsible for
 * defining the position, visual representation, and numerical identification of a Personagem
 */
class Personagem{
    protected:
        /*!
         * \brief Row coordinate
         */
        int x;
        /*!
         * \brief Column coordinate
         */
        int y;
        /*!
         * \brief Visual representation of the Personagem (corresponding char)
         */
        char sprite;
        /*!
         * \brief Numerical identification of the Personagem
         */
        int value;
    public:
        /*!
         * \brief Updates the position of a Personagem by moving it to a valid position, that is,
         * one that does not contain a wall and does not exceed the board limits
         * \param direcao: (int) direction in which the Personagem will move
         * \param lab: (Labirinto) Labirinto that may have the characters' Labirinto updated
         * \return return: (int) 1 if there was a valid movement or 0 otherwise
         */
        int move(int direcao, Labirinto lab);
        /*!
         * \brief Sets the position of the Personagem
         * \param x: (int) row coordinate
         * \param y: (int) column coordinate
         */
        void set_position(int x, int y);
        /*!
         * \brief Gets the visual representation (sprite)
         * \return return: (char) corresponding char to the visual representation
         */
        char get_sprite();
        /*!
         * \brief Gets the row coordinate where the Personagem is
         * \return return: (int) row coordinate
         */
        int get_x();
        /*!
         * \brief Gets the column coordinate where the Personagem is
         * \return return: (int) column coordinate
         */
        int get_y();
};
#endif // _PERSONAGEM_H_