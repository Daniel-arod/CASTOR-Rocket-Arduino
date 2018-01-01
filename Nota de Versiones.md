# CASTOR-Rocket-Arduino
Construccion y automatizacion de cohete mediante Arduino

Notas sobre Versiones:
he estado trabajando en varias modificaciones que no tome como "versiones" el proyecto, que antes era mas sobre la automatización de un cohete hidraulico en su lanzamiento ya fue completado y entregado para su revisión, sin embargo, para el final de esta, que la llamare "version 0.1" el proyecto pasó de ser uno de automatización a uno de poder generar un controlador aéreo que sirviera para cohetes, ya no solo de agua, sino de todos los tipos.

Version 0.1: (COHETE HIDRAULICO)
son las versiones encontradas hasta diciembre de todos los codigos, si alguien solo quiere medir datos esta muy bien, pero es muy lento en determinar una caída libre, por lo que cuando se activaba un servo motor que se suponía que activaba un paracaidas, lo hacia cuando llegaba al suelo.

En cuanto a la automatización, dependiendo de la lanzadera que se haga funcionara o no
, pondre los archivos y las fotos de como se supone que funciona, pero hubo un problema, solo funciona con cohete pequeños, no pude lograr un mecanismo capaz de generar el torque necesario para bajar un seguro en el cohete final, mas que todo porque me vi corriendo por las fechas.


Versión 1.N(COHETE CON MOTOR SOLIDO):
1.01: NOTA: Durante una buena parte de diciembre del 2017 estuve trabajando en la corrección del algoritmo que media los datos, esto con el fin de que sea más efectivo en poder activar un paracaídas, no lo he probado, pero los resultados que esta arrojando en el serial plotter de Arduino son mucho más precisos que el del cohete 
hidráulico, el cual estaba lleno de picos.

Esta será la primera versión porque hasta ahora me decido en publicar un documento formal para tener un registro de los avances del proyecto.

MEJORAS:
-Ya no tiene saltos en sus medidas(no tan grandes).
 -Ya no toma datos negativos (que no tienen sentido porque la condición inicial siempre  sea el suelo).
-El tiempo de toma de datos y realización de operaciones pasó de ser de 200 ms a 8ms (es lo maximo que me deja hacer tomar el Arduino Uno)
-Cambio el nombre de CASTOR ROCKET a Pillar of atumn.
 
DESVENTAJAS:
-Ya no dice la altura máxima (solo quiero que el arduino tome los datos, y hacer una aplicación que determine eso, es para que no haga tantas operaciones en vuelo).
-Por el momento no activa nada, no detecta caída libre, es decir, no esta implementado todavia.

NOTAS TÉCNICAS:
-Intente implementar un control PID, y cree el documento con el archivo .ino que tenia mas o menos el algoritmo funcionando con solo la P del PID, osea  la promedial, pero no quize seguir por ese camino porque como tal solo tiene que tomar una decisión, no hacer un control, pienso que en el futuro podría implementar cuatro o tres servomotores que estén a sus lados, cuya función sea la estabilidad, pero en ese momento lo hare.

-El algoritmo que reduce el “ruido” de los datos es el método de suavizamiento exponencial, trate de hacer un promedio móvil normal, pero los picos eran mas grandes, un profesor que aprecio bastante me sugirió que utilizara el método numérico de ajuste polinomial por mínimos cuadrados, También conocido como anàlisis de regresión y correlación, pero no lo implemente por la cantidad de operaciones que tendria que hacer en vuelo, lo hare cuando este analizando los datos obtenidos, es decir, en la aplicación que los recibió y haciendo esto podrá generar la funcion que, derivando me daría la velocidad y la aceleración.
