@0              // Cargar el valor de N desde RAM[0]
D=M             // Guardar el valor de N en D

@numero         // Contador
M=D             // Asignar el valor de N a la posición de número

@suma           // Acumulador
M=0             // Inicializar suma en cero

(LOOP)
@END            // Comprobar si el contador ha llegado a cero
D;JEQ           // Si el contador es igual a cero, saltar a END

@suma           // Acceder a la suma
M=D+M           // Sumar el valor de número a suma

@numero         // Acceder al contador
MD=M-1          // Decrementar el contador y guardar el nuevo valor en número

@LOOP           // Volver al inicio del bucle
0;JMP           // Repetir el bucle

(END)
@END            // Dirección de END
0;JMP           // Detener el programa
