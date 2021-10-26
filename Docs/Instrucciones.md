# Arduino
Sketch creado con el entorno de desarrollo *Arduino IDE* para grabar en una tarjeta MicroSD la lectura de dos sensores **DS18B20** y el dato de humedad del **DHT11**. Se utiliza el microcontrolador del *Arduino Uno* limitando el tiempo a 301 observaciones y al terminar la secuencia se inicia el parpadeo de un led, siendo este espacio de tiempo configurable en el sketch.  
    
![Fig. Foto del prototipo](https://github.com/juanselastra/Arduino/blob/master/Docs/IMG_01.jpg?raw=true "Foto del prototipo")  
  
  
La parte de la configuración del Sketch para los sensores *DS18B20* se ha obtenido del canal de YouTube *Programar facil* [^1] y para la configuración de la MicroSD, del canal de YouTube *Bitwise Ar* [^2]  
  
[^1]: Video *DS18B20 y Arduino cómo medir la temperatura del agua*  
[^2]: Video *Arduino desde cero en Español capítulo 37 Lector de tarjeta MicroSD*  
  
La tarjeta de memoria se encuentra en formato FAT32 y almacena los datos en un archivo con extensión *.txt*, que puede abrirse en Excel o LibreOffice en formato de hoja de cálculo y crear facilmente un gráfico.  
  
![Fig. Esquema gráfico del prototipo](https://github.com/juanselastra/Arduino/blob/master/Docs/ConexProtoboard.png?raw=true "Esquema gráfico del prototipo")  
  