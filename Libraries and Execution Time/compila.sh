#!/bin/bash

# Removing possible residues from past executions
rm -rf *.o *.a *so testa

# Compiling the dynamic library
gcc -c -fPIC -o vetoraleatorio.o vetoraleatorio.c
if [ $? -ne 0 ]; then
    echo "Dynamic library compilation failed"
    exit 1
else
    gcc -o libvetoraleatorio.so -shared vetoraleatorio.o
    if [ $? -ne 0 ]; then
        echo "Dynamic library compilation failed"
        exit 1
    else
        # Editing the LD_LIBRARY_PATH environment variable (for temporary use)
        export LD_LIBRARY_PATH=/path/to/libs:$LD_LIBRARY_PATH
        if [ $? -ne 0 ]; then
            echo "Dynamic library compilation failed"
            exit 1
        fi
    fi
fi

# Compiling the static library
gcc -Wall -c -o propriedadesnumericas.o propriedadesnumericas.c
if [ $? -ne 0 ]; then
    echo "Static library compilation failed"
    exit 1
else
    # Packing the objects into a single file with .a extension
    ar -rcv libpropriedadesnumericas.a propriedadesnumericas.o > /dev/null
    if [ $? -ne 0 ]; then
        echo "Static library compilation failed"
        exit 1
    fi
fi

# Compiling testa.c
gcc -Wall -L${PWD} testa.c -lvetoraleatorio -o testa -L${PWD} libpropriedadesnumericas.a
if [ $? -ne 0 ]; then
    echo "testa.c compilation failed"
    exit 1
fi

# Generating the Doxyfile, configuration document for documentation
doxygen -g > /dev/null
if [ $? -ne 0 ]; then
    echo "Documentation process failed"
    exit 1
else
    # Changing the project name
    sed -i -e 's/My Project/EP3 - Gustavo Vaz/g' Doxyfile
    if [ $? -ne 0 ]; then
        echo "Documentation process failed"
        exit 1
    else
        # Disabling the creation of documentation in Latex
        sed -i -e 's/GENERATE_LATEX         = YES/GENERATE_LATEX         = NO/g' Doxyfile
        if [ $? -ne 0 ]; then
            echo "Documentation process failed"
            exit 1
        else
            # Changing the documentation language to PT-BR
            sed -i -e 's/OUTPUT_LANGUAGE        = English/OUTPUT_LANGUAGE        = Brazilian/g' Doxyfile
            if [ $? -ne 0 ]; then
                echo "Documentation process failed"
                exit 1
            else
                # Enabling optimization for C
                sed -i -e 's/OPTIMIZE_OUTPUT_FOR_C  = NO/OPTIMIZE_OUTPUT_FOR_C  = YES/g' Doxyfile
                if [ $? -ne 0 ]; then
                    echo "Documentation process failed"
                    exit 1
                else
                    # Enabling the generation of graphs to facilitate visualization of the connection between libraries
                    sed -i -e 's/GENERATE_TREEVIEW      = NO/GENERATE_TREEVIEW      = YES/g' Doxyfile
                    if [ $? -ne 0 ]; then
                        echo "Documentation process failed"
                        exit 1
                    else
                        # Allowing function documentation
                        sed -i -e 's/EXTRACT_ALL            = NO/EXTRACT_ALL            = YES/g' Doxyfile
                        if [ $? -ne 0 ]; then
                            echo "Documentation process failed"
                            exit 1
                        else
                            # Defining the files to be documented
                            sed -i -e 's/INPUT                  =/INPUT                  = testa.c propriedadesnumericas.h vetoraleatorio.h/' Doxyfile
                            if [ $? -ne 0 ]; then
                                echo "Documentation process failed"
                                exit 1
                            else
                                # Generating the documentation
                                doxygen Doxyfile > /dev/null
                                if [ $? -ne 0 ]; then
                                    echo "Documentation process failed"
                                    exit 1
                                fi
                            fi
                        fi
                    fi
                fi
            fi
        fi
    fi
fi
exit 0