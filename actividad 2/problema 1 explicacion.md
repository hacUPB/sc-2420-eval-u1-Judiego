# ejercicio 1
Escribe un programa que calcule la suma de los primeros N números naturales. El valor de N estará almacenado en RAM[0].

![intento1ejer1]("C:\Users\User\Downloads\suma_numeros_naturales.asm")

en mi primer intento trate de usar bucles pero me confundi y hice mal la parte que restara y manejara el valor de N lo que me paso por pensar tanto en la logica sino en hacerlo directamente lo que hacia que no se guardara y el bucle se hiciera infinitamente.
Me di cuenta de que ejecutar el código paso a paso y verificar los valores de los registros durante cada iteración me ayudaba a identificar los problemas. Fui ajustando la lógica del bucle y los saltos condicionales y vi como podia usar los registros para almacenar los datos hasta que el codigo me quedo asi como se ve en el archivo de problema 1