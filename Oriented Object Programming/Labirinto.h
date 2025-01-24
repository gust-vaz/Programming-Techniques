#ifndef _LABIRINTO_H_
#define _LABIRINTO_H_

#include "Arquivo.h"

/*!
 * \brief A class that defines the updatable Labirinto. It is a specialization
 * of the Arquivo class for a Labirinto class. It is responsible for
 * generating Labirintos that can be altered and will be used in output operations
 * and character interactions
 */
class Labirinto : public Arquivo{
    private:
        /*!
         * \brief The number of pacdots in the Labirinto
         */
        int n_pacdots;
        /*!
         * \brief A Labirinto without characters
         */
        char **new_board;
        /*!
         * \brief A Labirinto composed only of characters
         */
        int **lab_persona;
    public:
        /*!
         * \brief Constructor of the Labirinto (calls the constructor of Arquivo
         * and sets the number of pacdots to 0)
         */
        Labirinto();
        /*!
         * \brief Frees the allocated memory of new_board and lab_persona
         */
        void free_Labirinto();
        /*!
         * \brief Sets all attributes related to the Labirinto and positions
         * the positions of the Fantasmas in lab_persona as 2
         * \param arq: (Arquivo) File containing the base values for the new Labirinto
         */
        void set_Labirinto(Arquivo arq);
        /*!
         * \brief Updates a cell of the Labirinto, essentially replacing a
         * pacdot with another element
         * \param i: (int) row coordinate
         * \param j: (int) column coordinate
         * \param ch: (char) new character that will take the position
         */
        void att_new_board_celu(int i, int j, char ch);
        /*!
         * \brief Updates a cell of the character Labirinto, essentially 
         * removing or inserting a Personagem in the position
         * \param i: (int) row coordinate
         * \param j: (int) column coordinate
         * \param value: (int) value related to the Personagem
         */
        void att_lab_persona_celu(int i, int j, int value);
        /*!
         * \brief Gets a cell of the Labirinto
         * \param i: (int) row coordinate
         * \param j: (int) column coordinate
         * \return return: (char) character of the element at the position
         */
        char get_new_board_celu(int i, int j);
        /*!
         * \brief Gets the value (numerical identification) of the characters
         * \param i: (int) row coordinate
         * \param j: (int) column coordinate
         * \return return: (int) sum of the value of all characters present at this position
         */
        int get_lab_persona_celu(int i, int j);
        /*!
         * \brief Gets the number of pacdots in the Labirinto
         * \return return: (char) total number of pacdots in the Labirinto
         */
        int get_n_pacdots();
};
#endif // _Labirinto_H_