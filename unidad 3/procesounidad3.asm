primero habia empezado el codigo pero despues me di cuenta que lo mejor era crear primero el diagrama, luego elaboré el diagrama de clases que representaba las clases del juego. Esto me ayudó a ver cómo se relacionaban los diferentes componentes del juego. En el diagrama, decidí crear una clase base llamada GameObject para almacenar los atributos comunes, como la posición (x, y) y el tamaño (width, height). Así, tanto el jugador como el obstáculo podían heredar de esta clase, lo que hizo el código más simple

Luego trate de pasar a POO el código. Definí las estructuras de Player y Obstacle que ahora heredan de GameObjec lo que hace que en lugar de tener atributos duplicados, ambos objetos compartían los mismos atributos de posición y tamaño, lo que redujo la repetición de código.

Implementé funciones para manejar la inicialización de la ventana, el procesamiento de la entrada del usuario, la actualización de las posiciones de los objetos y el renderizado en la pantalla. También añadí una función para destruir la ventana al finalizar el juego.

Al principio me aparecieron varios errores. Uno fue de la variable global game_is_running, que se necesitaba para controlar el ciclo del juego. la variable no estaba correctamente declarada en los archivos donde se usaba, lo que causaba que el programa no compilará. Después de cambiar el código y que la variable fuera accesible en las funciones adecuadas, el problema se solucionó.
También tuve problemas de renderizado de que la ventana se mostraba en negro.se arreglo revisando el flujo de renderizado