/*!
 * \brief Function: criaVetorAleatorio;
 * \brief Usage: v = criaVetorAleatorio(semente, tamanho);
 * \brief This function creates an array with random integer values up to 64 bits, using the rand function;
 *
 * \param semente: (int) seed used to set the srand parameter and consequently the rand values
 * \param tamanho: (int) size of the array to be created
 * \return return: (long long *) array with random integer values.
*/
long long * criaVetorAleatorio(int semente, int tamanho);