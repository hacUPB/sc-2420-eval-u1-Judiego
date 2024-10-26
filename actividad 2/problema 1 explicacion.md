# ejercicio 1
Escribe un programa que calcule la suma de los primeros N números naturales. El valor de N estará almacenado en RAM[0].

![Descripción de la imagen](C:\Users\User\Downloads\Captura de pantalla 2024-10-26 160809.png)



en mi primer intento trate de usar bucles pero me confundi y hice mal la parte que restara y manejara el valor de N lo que me paso por pensar tanto en la logica sino en hacerlo directamente lo que hacia que no se guardara y el bucle se hiciera infinitamente.
Me di cuenta de que ejecutar el código paso a paso y verificar los valores de los registros durante cada iteración me ayudaba a identificar los problemas. Fui ajustando la lógica del bucle y los saltos condicionales y vi como podia usar los registros para almacenar los datos hasta que el codigo me quedo asi como se ve en el archivo de problema 1


# explicacion de funcionamiento
@0: Se carga la dirección de la RAM donde está almacenado N (en este caso, RAM[0]).
D=M: Se carga el valor de N en el registro D.
@sum: Se establece el registro sum (que representa la suma acumulada) en 0.
@i: Se almacena el valor de N en el registro i, que se utilizará como contador en el bucle.

bucle
(LOOP)
  @i
  D=M        // Cargar el valor de i
  @END
  D;JLE      // Si i <= 0, saltar a END
  @sum
  M=M+D      // Sumar i a la suma
  @i
  M=M-1      // Restar 1 a i
  @LOOP
  0;JMP      // Repetir bucle

fin
(END)
  @END
  0;JMP      // Detener el programa

