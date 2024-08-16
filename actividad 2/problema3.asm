@2 //va a la posicion de memoria 2
M=0 //resetea el valor a 0

@1
D=M
@END
D;JEQ //si lo que está almacenado en 1 es un cero, salta a END y no cambia el valor de la posicion 2

(LOOP)
@0 //va a la posicion de memoria 0
D=M //D es igual al contenido de 0
@2 //posicion de memoria 2
M=D+M //se suma el valor de la D y se guarda en 2
@1
MD=M-1 //se le resta una unidad al valor de la posición 1 
//este valor se le asigna tanto a M como a D la cantidad de veces que debe repetirse el ciclo
@LOOP
D;JGT //mientras que D sea más grande que cero, salta a LOOP

(END)
@END
0;JMP