/*
  Ejemplo de utilización de flancos
  En este programa se detecta tanto el flanco de subida como el de bajada
  de una señal digital (p.e. un pulsador).
  Métodos:
  bool zzz.Fp(bool x) => Devuelve TRUE cuando detecta un flanco POSITIVO de x 
  bool zzz.Fn(bool x) => Devuelve TRUE cuando detecta un flanco NEGATIVO de x  
 */

#include <siemens.h>

const int buttonPin = 0; // Poner la entrada digital deseada

// creamos los "flancos"
Flanco Fl1;
Flanco Fl2;
Flanco Fl3;
//Flanco .....
//Flanco .....
//Flanco .....

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Precaución a la hora de leer la entrada digital:
  // Puede ser una entrada PULLUP (invierto la señal mediante "!"), es mi caso.
  // Puede ser una entrada PULLDOWN (se elimina la negación "!").
  bool entrada = !digitalRead(buttonPin);
  if (Fl1.Fp(entrada)) { 
    Serial.println("Se ha detectado un FLANCO POSITIVO por la entrada digital");
  }
  if (Fl1.Fn(entrada)) {
    Serial.println("Se ha detectado un FLANCO NEGATIVO por la entrada digital");
  }
}
