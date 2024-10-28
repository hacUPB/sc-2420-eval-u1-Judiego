// Cargar N
@0
D=M // Guardar N en D

// Inicializar el resultado en 1
@resultado
M=1 

// Bucle para calcular el factorial
(LOOP)
@1
D=D-1 // Restar 1 a N
@resultado
M=M*D // Multiplicar el resultado por el valor actual de N

@LOOP
D;JGT // Si D > 0, seguir el bucle

(END)
@END
0;JMP // Terminar
