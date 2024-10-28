# Escribe un programa que calcule el factorial de un número entero positivo.
Empecé a resolver el problema intentando pensar en cómo calcular el factorial en pasos, Sé que el factorial de N es el producto de todos los números desde N hasta 1 y pensé que podría implementar un bucle comenzando en N y restando 1 en cada iteración.

Primero trate de cargar un valor N desde la RAM[0] y almacenarlo en un registro, luego inicializar el valor resultante a 1 porque cualquier número multiplicado por 1 siempre es igual.
A continuación, queria crear un bucle que reste 1 de N en cada iteración y multiplique este nuevo valor por el resultado, actualizando así el valor resultante en cada paso. Tenía la idea de que la lógica del bucle debería controlar el decremento de N y al mismo tiempo asegurarse de que el programa se detuviera una vez que el valor llegara a 1

cometí el error de no asignarlo correctamente a un registro antes de empezar las multiplicaciones. Además, no estaba manejando bien cómo hacer la multiplicación.

Hack no tiene una operación de multiplicación directa, así que tendría que implementar una rutina de multiplicación de manera manual, usando sumas repetitivas o desplazamientos



