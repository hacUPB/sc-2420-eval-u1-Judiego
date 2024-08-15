@0
D=M

@1
M=0

@2
M=0

(LOOP_START)
// Cargar índice en D
@2
D=M

// Comparar índice con N
@0
D=D-M

// Saltar al final si índice > N
@END
D;JGT

// Comprobar si el número es par
@2
D=M
@CHECK_PARITY
D=D&1 // D = M % 2

// Saltar si impar
@INCREMENT_INDEX
D;JNE

// Agregar número par a la suma
@2
D=M
@1
M=M+D

(INCREMENT_INDEX)
// Incrementar índice
@2
M=M+1

// Volver al inicio del bucle
@LOOP_START
0;JMP