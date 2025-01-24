/*!
 * \brief Function: ehPar;
 * \brief Usage: d = ehPar(x);
 * \brief This function checks the remainder of the input number x by 2. If it is 1, it is odd; otherwise, it is even;
 *
 * \param x: (long long) Number to be checked
 * \return return: (int) 1 if it is even, 0 if it is odd
*/
int ehPar(long long x);

/*!
 * \brief Function: ehPrimo;
 * \brief Usage: d = ehPrimo(x);
 * \brief This function checks if x is divisible by any number. If it is not, x is prime;
 *
 * \param x: (long long) Number to be checked
 * \return return: (int) 1 if there are no divisors up to the square root of x, 0 otherwise
*/
int ehPrimo(long long x);

/*!
 * \brief Function: ehQuadradoPerfeito
 * \brief Usage: d = ehQuadradoPerfeito(x);
 * \brief This function performs a binary search of all integers between 0 and 3037000499, the square root of the largest long long number with a perfect square that does not result in overflow;
 *
 * \param x: (long long) Number to be checked
 * \return return: (int) 1 if it finds a number whose square is equal to x, 0 otherwise
*/
int ehQuadradoPerfeito(long long x);

/*!
 * \brief Function: ehCuboPerfeito
 * \brief Usage: d = ehCuboPerfeito(x);
 * \brief This function performs a binary search of all integers between 0 and 2097151, the cube root of the largest long long number with a perfect cube that does not result in overflow;
 *
 * \param x: (long long) Number to be checked
 * \return return: (int) 1 if it finds a number whose cube is equal to x, 0 otherwise
*/
int ehCuboPerfeito(long long x);

/*!
 * \brief Function: ehFibonacci
 * \brief Usage: d = ehFibonacci(x);
 * \brief This function searches for a number in the Fibonacci sequence by calculating the sequence, i.e., fn+2 = fn+1 + fn, until fn+2 is greater than or equal to x;
 *
 * \param x: (long long) Number to be checked
 * \return return: (int) 1 if fn+2 is equal to x, 0 otherwise
*/
int ehFibonacci(long long x);

/*!
 * \brief Function: ehFatorial
 * \brief Usage: d = ehFatorial(x);
 * \brief This function keeps dividing x by a number i, starting from 2 and incrementing, until x equals 1 or x mod(i) is not equal to 0;
 *
 * \param x: (long long) Number to be checked
 * \return return: (int) 1 if it does not find a number for which x mod(i) is not equal to 0, 0 otherwise
*/
int ehFatorial(long long x);
