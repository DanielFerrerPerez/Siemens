/*
  Ejemplo de utilización de temporizadores
  En este programa se muestra el uso de los temporizadores al estilo "Siemens"
  Hay dos tipos:
    Retardo a la conexión    -> Ton
    Retardo a la desconexión -> Toff

  Nota: Tiempos expresados en ms tipo de dato long
    
  Métodos:  
  bool zzz.Ton(long TiempoDeseado, bool bitDeEntrada, "long tiempoActual") => Devuelve HIGH cuando ha pasado "TiempoDeseado" si la señal de "bitDeEntrada" se ha mantenido en HIGH.
  La señal de salida se pone a HIGH pasado el tiempo si la entrada se mantiene a HIGH. En el momento que la entrada pasa a LOW, la salida también.
  
  bool zzz.Toff(long TiempoDeseado, bool bitDeEntrada, "long tiempoActual") => Mantiene HIGH durante "TiempoDeseado" si la señal de "bitDeEntrada" ha pasado de HIGH a LOW.
  Mientras la señal de entrada "bitDeEntrada" se mantiene a HIGH, la salida es HIGH. Cuando la entrada pasa a LOW, comienza el temporizador a contar.
  Mientras el temporizador cuenta, la salida se mantiene a HIGH. Cuando termina el tiempo, pasa a LOW.
 */

#include <siemens.h>

const int buttonPin = 0; // Poner la entrada digital deseada

// creamos los "temporizadores"
Temporizador Te1;
Temporizador Te2;
Temporizador Te3;
//Temporizador .....
//Temporizador .....
//Temporizador .....

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Precaución a la hora de leer la entrada digital:
  // Puede ser una entrada PULLUP (invierto la señal mediante "!"), es mi caso.
  // Puede ser una entrada PULLDOWN (se elimina la negación "!").
  bool entrada = !digitalRead(buttonPin); // Puando pulso, entrada = HIGH;

  if (Te1.Ton(2000,entrada)) {
    Serial.println("Han transcurrido 2 segundos o más desde que pulsate el botón");
  }

}
