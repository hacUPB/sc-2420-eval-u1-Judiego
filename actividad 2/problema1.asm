// Inicialización
@0
D=M         // Cargar el valor de N desde RAM[0]
@i
M=D         // Guardar N en i
@sum
M=0         // Inicializar sum a 0

// Bucle de suma
(LOOP)
  @i
  D=M       // D = i
  @END
  D;JLE     // Si i <= 0, saltar a END
  @sum
  M=M+D     // sum = sum + i
  @i
  M=M-1     // i = i - 1
  @LOOP
  0;JMP     // Repetir bucle

// Fin del programa
(END)
  @END
  0;JMP     // Detener el programa
