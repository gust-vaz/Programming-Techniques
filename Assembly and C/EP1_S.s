section .text
; This is a subroutine responsible for printing the integer in rax. The r8 register
; stores a digit counter initialized to 0 and incremented in each loop of pushing those
; digits onto the stack. Its purpose is to serve as the stop condition for the popping.
impressao_num:
    mov r8, 0

; This is a loop that takes a digit from the input and converts it from integer to its ASCII
; character equivalent, storing it on the stack so that, for example, the first digit to enter, the units,
; will be the last to be printed when popped. The integer is divided by 10, obtaining the remainder as the 
; digit, in addition to updating the integer in rax.
empilha_num:
    ; stop condition
    cmp rax, 0              ; rax != 0?, that is, while there are digits
    je desempilha_num

    ; rax is constantly updated as the quotient of the division by 10
    mov rdx, 0              ; clearing the upper part of the dividend
    mov rbx, 10             ; preparing the divisor
    div rbx
    add rdx, 48             ; the remainder will be converted into an ASCII number
    push rdx                ; store the digit on the stack
    inc r8
    jmp empilha_num

; This is the loop that pops the characters from the stack and prints them through the syscall write
desempilha_num:
    ; stop condition
    cmp r8, 0               ; are there no digits left to print?
    je sai_num

    pop rbx
    mov [x], rbx
    ; sys_write(stdout, message, size)
    mov rax, STDOUT         ; syscall sys_write
    mov rdi, STDOUT         ; stdout
    mov rsi, x              ; address of the message
    mov rdx, 1              ; message string size
    syscall
    dec r8                  ; updates the number of digits left

    jmp desempilha_num

sai_num:
    ret

; Subroutine responsible for printing a space between the outputs of mode_1
impressao_space:
    mov qword [x], 32       ; value of space in ASCII

    ; sys_write(stdout, message, size)
    mov rax, STDOUT         ; syscall sys_write
    mov rdi, STDOUT         ; stdout
    mov rsi, x              ; address of the message
    mov rdx, 1              ; message string size
    syscall

    ret

; Subroutine responsible for printing a newline
impressao_linha:
    mov qword [x], 10       ; value of newline in ASCII

    ; sys_write(stdout, message, size)
    mov rax, STDOUT         ; syscall sys_write
    mov rdi, STDOUT         ; stdout
    mov rsi, x              ; address of the message
    mov rdx, 1              ; message string size
    syscall

    ret

; This is a subroutine responsible for checking if the number in rax is prime.
; The result is stored in rbx, which will be 1 if the input is prime or 0 otherwise.
; We initialize rbx as 1, because the goal is to find a divisor of x, with a loop that, while
; no divisor is found, increments the divisor (divi) until it reaches the square root of the input.
primo:
    mov [x], rax            ; storing the input in rax for future comparisons
    mov rax, 2              ; initializing the divisor with the first valid number
    mov rbx, 1              

loop_p:
    mov [divi], rax         ; saving the incremented divisor
    mov rcx, rax
    mul rcx                 ; divi * divi

    ; stop condition
    ; divi * divi <= x?
    cmp rdx, [x]            ; comparing the upper part of the multiplication
    jnle fim_p
    cmp rax, [x]            ; comparing the lower part of the multiplication
    jnle fim_p
    ; found a divisor for x?
    cmp rbx, 1          
    jne fim_p

    ; checking if x is divisible by the new divisor divi
    ; is the remainder of the division 0?
    mov rdx, 0              ; clearing the upper part of the dividend
    mov rax, [x]            ; preparing the dividend
    div qword [divi]        
    cmp rdx, 0
    jne senao_p

se_p:
    mov rbx, 0              ; found that it's not prime
    jmp loop_p              ; continue the loop to exit

senao_p:
    ; searching for a new possible divisor of x
    mov rax, [divi]
    inc rax                 
    jmp loop_p

fim_p:
    ret

global _start

_start:
leitura:
    ; reading the input, which is currently in the form of a string
    ; int read(int fd, void *buf, size_t count);
    mov rdi, STDIN          ; file descriptor to be read
    mov rsi, input          ; pointer to the input where the content will be stored
    mov rdx, 256            ; number of bytes to read
    mov rax, STDIN          ; syscall read number
    syscall

    mov rcx, input          ; rcx now points to the string

    cmp byte [rcx], '0'     ; is the first digit, i.e., the mode, equal to '0'?
    je se_l

senao_l:
    mov dword [modo], 1     ; set the mode
    inc rcx                 ; move to the next character
    inc rcx                 ; skip the space and point to the start of the number
    jmp transforma_l

se_l:
    mov dword [modo], 0     ; set the mode
    inc rcx                 ; move to the next character
    inc rcx                 ; skip the space and point to the start of the number
    
; This loop is responsible for transforming the string into an integer by subtracting '0' (value 48).
; This new value is added to num and multiplied by 10, so the next addition will contain only the 
; corresponding digit, without changing the intended value. The stop condition is checking if
; the byte that rcx points to is smaller than the string of a number, which would indicate the 
; end of the line.
transforma_l:
    cmp byte [rcx], '0'     ; is the end of the input less than '0'? i.e., is it the end of the line?
    jl corrige_l
    
    mov bl, byte [rcx]      ; get the digit rcx is pointing to
    sub bl, 48              ; convert from ASCII to integer
    add [num], bl           ; insert the digit into num
    ; num * 10
    mov rax, 10              
    mul qword [num]         
    mov [num], rax

    inc rcx                 ; move to the next digit
    jmp transforma_l

; Since num is multiplied by 10 to wait for the entry of a new digit, at the end of the loop, there is a factor
; of correction that divides num by 10.
corrige_l:
    mov rdx, 0              ; clearing the upper part of the dividend
    mov rbx, 10
    mov rax, [num]
    div rbx
    mov [num], rax

; Based on the value of mode, it proceeds to the corresponding operation
escolha:
    mov rax, [modo]
    cmp rax, 0
    jne modo_1

; Block of operations to find the next prime number from num.
modo_0:
    mov dword [eh_primo], 0
    ; p = num + 1
    mov rax, [num]         
    inc rax                
    mov [p], rax

; This loop checks, using the subroutine "primo", if p is prime, and if not, increments p and goes back
; to the loop for another check.
loop_0:
    ; stop condition
    ; eh_primo is 0?
    mov rbx, [eh_primo]
    cmp rbx, 0
    jne fim_0               ; eh_primo = 1, we found the next prime

    mov rax, [p]            ; input for the subroutine
    call primo              ; check if the number in rax is prime
    cmp rbx, 1              ; is it prime?
    jne senao_0

se_0:
    mov dword [eh_primo], 1 
    dec qword [p]           ; structure similar to C code, correction factor
    inc qword [p]           ; structure similar to C code
    jmp loop_0

senao_0:
    inc qword [p]   
    jmp loop_0

; printing the desired prime number
fim_0:
    mov rax, [p]
    call impressao_num
    call impressao_linha
    jmp exit

; Block of operations to find, if any, the two prime numbers that multiplied result in num
modo_1:
    mov qword [p], 2        ; initializing the first possible divisor of num
    mov dword [achamo], 0   ; variable that will be 1 if we find the multiples of num requested
    mov rdx, 0              ; clearing the upper part of the dividend

; This loop finds, starting from a possible prime divisor p, if the other divisor q (q = n/p) is prime, and 
; if not, looks for the next prime p, checking if it divides num. Its stop conditions are: p being less than or 
; equal to the square root of num and we have indeed found the desired p and q.
loop_1:
    ; stop condition
    ; achamo is 0?
    mov rax, [achamo]
    cmp rax, 0
    jne fim_1
    ; p * p <= n?
    mov rdx, 0              ; clearing the upper part
    mov rax, [p]            ; initializing lower part
    mov rcx, [p]
    mul rcx                 ; p*p
    cmp rax, [num]
    jg fim_1

    ; start of loop operations
    mov rax, [num]          ; initializing lower part
    mov rdx, 0              ; clearing the upper part
    div qword [p]           ; rdx is the remainder of the division
    ; is num divisible by p?
    cmp rdx, 0     
    jne senao_1             ; num % p != 0

se_1:
    mov qword [q], rax      ; q = num / p
    call primo              ; check if the number in rax (q) is prime
    ; is q prime?
    cmp rbx, 1              
    jne senao_1             

    mov dword [achamo], 1   ; verified that it's prime
    jmp loop_1              ; return the loop to exit

; This block of operations is responsible for finding the next prime p, similar to what's done in mode_0,
; but initializing with the incremented p.
senao_1:
    mov dword [eh_primo], 0
    inc qword [p]           ; initializing the incremented p

loop_1.1:
    ; stop condition
    ; eh_primo is 0?
    mov rbx, [eh_primo] 
    cmp rbx, 0              
    jne loop_1              ; eh_primo = 1, we found the next prime

    mov rax, [p]            ; input for the subroutine
    call primo              ; check if the number in rax is prime
    cmp rbx, 1              ; is it prime? 
    jne senao_1.1

se_1.1:
    mov dword [eh_primo], 1       ; eh_primo = 1
    dec qword [p]           ; structure similar to C code, correction factor
    inc qword [p]           ; structure similar to C code
    jmp loop_1.1

senao_1.1:
    inc qword [p]           ; new p to be checked 
    jmp loop_1.1

fim_1:
    ; did we find the desired multiples?
    mov rax, [achamo]
    cmp rax, 0    
    je exit
    
    ; print p
    mov rax, [p]
    call impressao_num
    call impressao_space
    ; print q
    mov rax, [q]
    call impressao_num
    call impressao_linha

; program exit
exit:
    mov rdi, 0        
    mov rax, 60          
    syscall



section .data
; to make the code more readable
STDIN:  EQU 0               ; parameter for system call to read
STDOUT: EQU 1               ; parameter for system call to print

section .bss
; input variables
input:      resb 256        ; where the input string will be stored
modo:       resb 1000       ; where the chosen mode will be stored
num:        resb 10         ; input variable for use in operations

; variables for the subroutine "primo"
x:          resq 10000000   ; stores the input, also used for output
divi:       resq 10000000   ; stop condition for loop_p and also the possible divisor of the input x

; variables for "modo_0" and "modo_1"
eh_primo:   resb 100        ; control variable for the loops responsible for finding the next prime p
p:          resq 10000000   ; stores the output for modes 0 and 1
achamo:     resb 100        ; control variable for loop in mode_1
q:          resq 10000000   ; stores the output for mode 1