#ifndef siemens_h
#define siemens_h
#include "arduino.h"

class Temporizador
{
  public:
    Temporizador( );  // Constructor
    bool Ton(long tDeseado, bool in, long &tActual);
    bool Ton(long tDeseado, bool in); 
    bool Toff(long tDeseado, bool in, long &tActual);
    bool Toff(long tDeseado, bool in);

  private:
    long _tAnterior;
    long _tAnterior1;
    bool _inAnterior;
};

class Flanco
{   
  public:
    Flanco( );  // Constructor
    bool Fp(bool in);
    bool Fn(bool in);

  private:
    bool _estadoAnterior;
    bool _estadoAnterior1;
};

#endif
