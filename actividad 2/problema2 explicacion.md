# ejercicio 2
Escribe un programa que calcule la suma de los primeros N números naturales. El valor de N estará almacenado en RAM[0].

imagen

comence el programa tratando de implementar un bucle simple para realizar la suma. espraba cargar el valor de N desde RAM[0] y usar un contador para ir sumando cada número.
me falto inicializar el valor de suma antes de entrar en el bucle Además no tenía claro cómo detener el bucle cuando el contador llegaba a cero.

imagen 2

realice el cambio para que inicie en cero pero tenia un error de logica que continuaba reealizandose cuando llegaba a cero el contador porque no se verificaba bien entonces entendí que tenía que usar correctamente la instrucción de salto condicional para verificar si el contador había llegado a cero

# como lo solucione
me di cuenta del error al ejecutar el programa vi los registros y la memoria y note que la variable suma no se estaba inicializando correctamente lo que hacía que el programa no funcionara como queria

me aseguré de que suma comenzara en cero antes del bucle.
Luego, ajusté el código para que verificara correctamente cuándo el contador llegaba a cero, utilicé la instrucción de salto condicional (D;JEQ), que me dejo salir del bucle cuando N llegaba a cero.
También me di cuenta de que debía controlar bien el decremento de N para de que se redujera después de cada iteración, lo que me permitió detener el bucle cuando era.