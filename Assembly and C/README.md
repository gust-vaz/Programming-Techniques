# EP1 - (Assembly and C)

## DESCRIPTION:
This is the EP1 for the **Programming Techniques 1** course. The **Assembly** program performs two secondary functions: it reads a string and converts it, through the ASCII table, into an integer; and prints the results of the following operations to the screen, converting from integer to string.

As with the C program, the main function is to provide solutions for two possible operations:
1. **Mode 0**: Identified by the first value of the input as 0. The goal is to return the next prime number after the second input value.
2. **Mode 1**: Identified by the first value as 1. If it exists, the program returns the two prime numbers that, when multiplied, result in the second input value.

## HOW TO COMPILE:
**Note**: The `-o` flag will prevent the executable from having a default name like "a.out".

### For the Assembly program, use the following commands:

```bash
nasm -f elf64 EP1_S.s -o EP1_S.o
ld -o EP1_S EP1_S.o
```

### For the C program, use the command:

```bash
gcc -ansi -Wall -o EP1_C EP1_C.c
```

## HOW TO RUN:
### To run the Assembly program, use:

```bash
./EP1_S
```

### To run the C program, use:

```bash
./EP1_C
```

In both programs, the input works the same way: there are two numbers separated by a space. The first number refers to the **mode**, i.e., the type of operation the user wants to perform, and the second number is the object of the operation. 

- If the mode is `0`, the output will be the next prime number after the input object.
- If the mode is `1`, and the object is the result of multiplying two prime numbers, the output will be those two numbers, separated by a space. Otherwise, the program will terminate without producing any output.

## TEST CASES:
| Test Case | Input        | Output       |
|-----------|--------------|--------------|
| **1**     | `0 10000000` | `10000019`   |
| **2**     | `0 999999936`| `999999937`  |
| **3**     | `0 4613`     | `4621`       |
| **4**     | `0 31`       | `37`         |
| **5**     | `1 210931`   | `7 30133`    |
| **6**     | `1 333222761`| `2287 145703`|
| **7**     | `1 15`       | `3 5`        |
| **8**     | `1 9`        | `3 3`        |
| **9**     | `1 908646421`| (no output)  |

## DEPENDENCIES:
The programs were developed and tested on a Debian-based system. The following versions were used:
- **Assembler version**: NASM version 2.14.02
- **C compiler version**: GCC 8.3.0
- **Linker version**: GNU ld (GNU Binutils for Debian) 2.31.1
- **OS**: 64Bit - Debian
- **Architecture**: X86_64