#include "../include/pilaPersona.h"
#include "../include/personasLDE.h"

struct rep_pilaPersona
{
  TPersonasLDE pilaPersonas;
};

TPilaPersona crearTPilaPersona()
{
  TPilaPersona pila = new rep_pilaPersona;
  pila->pilaPersonas = crearTPersonasLDE();

  return pila;
}

void liberarTPilaPersona(TPilaPersona &p)
{
  liberarTPersonasLDE(p->pilaPersonas);
  delete p;
}

nat cantidadEnTPilaPersona(TPilaPersona p)
{
  return cantidadTPersonasLDE(p->pilaPersonas);
}

void apilarEnTPilaPersona(TPilaPersona &p, TPersona persona)
{
  insertarInicioDeTPersonasLDE(p->pilaPersonas, copiarTPersona(persona));
}

TPersona cimaDeTPilaPersona(TPilaPersona p)
{
  return obtenerInicioDeTPersonasLDE(p->pilaPersonas);
}

void desapilarDeTPilaPersona(TPilaPersona &p)
{
  eliminarInicioTPersonasLDE(p->pilaPersonas);
}
