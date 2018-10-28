#include "siemens.h"
#include "arduino.h"

Temporizador::Temporizador( )  // Constructor
{
  _tAnterior = 0;
  _tAnterior1 = 0;
  _inAnterior = LOW;
}

bool Temporizador::Ton(long tDeseado, bool in, long &tActual) {
  if (in) {
    if (millis()-_tAnterior < tDeseado){
      tActual = millis()-_tAnterior;
    } else {
      tActual = tDeseado;
    }
    if (millis() >= (_tAnterior + tDeseado)) {
      return(HIGH);
    } else {
      return(LOW);
    }
  } else {
    _tAnterior = millis();
    return(LOW);
  }
}

bool Temporizador::Ton(long tDeseado, bool in) {
  if (in) {
    if (millis() >= (_tAnterior + tDeseado)) {
      return(HIGH);
    } else {
      return(LOW);
    }
  } else {
    _tAnterior = millis();
    return(LOW);
  }
}
    
bool Temporizador::Toff(long tDeseado, bool in, long &tActual) {
  if (in) {
    _tAnterior1 = millis();
    tActual = tDeseado;
    _inAnterior = HIGH;
    return(HIGH);
  } else {
    tActual = (tDeseado + _tAnterior1) - millis();
    if (millis() >= (_tAnterior1 + tDeseado) || _inAnterior == LOW) {
      tActual = 0;
      return(LOW);
    } else {
      return(HIGH);
    }
  }
} 

bool Temporizador::Toff(long tDeseado, bool in) {
  if (in) {
    _tAnterior1 = millis();
    _inAnterior = HIGH;
    return(HIGH);
  } else {
    if (millis() >= (_tAnterior1 + tDeseado) || _inAnterior == LOW) {
      return(LOW);
    } else {
      return(HIGH);
    }
  }
} 

Flanco::Flanco( )  // Constructor
{
  _estadoAnterior = 0;
  _estadoAnterior1 = 0;
}

bool Flanco::Fp(bool in) {
  if (in){
    if (_estadoAnterior == LOW) {
      _estadoAnterior = HIGH;
      return(HIGH);  
    } else {
      return(LOW);
    }
  } else {
    if (_estadoAnterior == HIGH) {
      _estadoAnterior = LOW;
    }
    return(LOW);
  }
}
    
bool Flanco::Fn(bool in) {
  if (in){
    _estadoAnterior1 = HIGH;
    return(LOW);
  } else {
    if (_estadoAnterior1 == HIGH) {
      _estadoAnterior1 = LOW;
      return(HIGH);
    } else {
      return(LOW);
    }
  }
}


