# EP3 - (Libraries and Execution Time)

## DESCRIPTION

Among the programs, we have the static library (`propriedadesnumericas.h`) and the dynamic library (`vetoraleatorio.h`), which perform the task of checking if the input number matches certain properties such as being even, prime, a perfect square, a perfect cube, part of the Fibonacci sequence, and factorial. Additionally, it generates a vector with random values.

The `compila.sh` script is responsible for compiling the libraries and the test program, as well as generating all the documentation via Doxygen by creating and modifying its configuration file (`Doxyfile`).

In the `testa.c` file, the functions of the libraries are tested, and their execution times are recorded.

## HOW TO RUN

In the directory containing the files, execute the following commands in order:
```bash
chmod 777 compila.sh
./compila.sh
./testa
```

**Note:** If you encounter the error "error while loading shared libraries" when running `testa`, use the following command:
```bash
export LD_LIBRARY_PATH=/path/to/libs:$LD_LIBRARY_PATH
```
Then, try running `./testa` again.

## TEST CASES

The `testa.c` file uses the libraries `propriedadesnumericas.h` and `vetoraleatorio.h` to test whether their functions are working properly and to record their execution times. Therefore, the `sys/time.h` library is required.

In the `tempo` function, the system time (in seconds and milliseconds) is recorded when it is called. The variables storing the time before and after the function execution are updated, and the `imprime_tempo` function outputs the difference between these variables, which represents the execution time of the main function.

In the `main` function, the vector whose values are used in the static library functions has a size of 10 and a seed of `5499134`, but the user can modify these values as needed, as long as they do not exceed the maximum values for a `long long`. Then, the screen output will display the vector values and their respective results for the numeric properties: 1 if the property is satisfied, and 0 otherwise.

## DEPENDENCIES

- Bash version: GNU bash, version 5.0.16(1)-release
- OS version: Ubuntu 20.04 LTS - 64Bits
- Doxygen version: 1.8.17