#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

#include <fstream>
#include <iostream>
using namespace std;

#define MAX 256

/*!
 * \brief A class that defines the Arquivo. It is responsible for getting all
 * the information from the input that will be used in the program.
 */
class Arquivo{
    protected:
        /*!
         * \brief The number of lines in the Labirinto
         */
        int n_lines;
        /*!
         * \brief The number of columns in the Labirinto
         */
        int n_columns;
        /*!
         * \brief The number of Fantasma in the Labirinto
         */
        int n_ghosts;
        /*!
         * \brief The name of the Arquivo
         */
        char *nome;
        /*!
         * \brief The Labirinto that will serve as a base for further operations
         */
        char **base_board;
    public:
        /*!
         * \brief Constructor of the Arquivo (will only set the number of lines,
         * columns, and Fantasma to 0)
         */
        Arquivo();
        /*!
         * \brief Frees the allocated memory of base_board
         */
        void free_Arquivo();
        /*!
         * \brief Sets the name in this class
         * \param nome: (char*) name of the input Arquivo passed in the command line
         */
        void set_nome(char* nome);
        /*!
         * \brief Sets the base Labirinto through a second reading of the Arquivo,
         * also setting the dimensions and the number of Fantasma.
         */
        void set_base_board();
        /*!
         * \return return: (int) the number of lines
         */
        int get_n_lines();
        /*!
         * \return return: (int) the number of columns
         */
        int get_n_columns();
        /*!
         * \return return: (int) the number of Fantasma
         */
        int get_n_ghosts();
        /*!
         * \brief Gets a line from the base Labirinto
         * \param i: (int) the line to be obtained
         * \return return: (char*) a line from the base Labirinto
         */
        char *get_base_board_line(int i);
};
#endif // _Arquivo_H_