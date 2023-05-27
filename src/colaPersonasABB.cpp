#include "../include/colaPersonasABB.h"
#include "../include/personasLDE.h"

typedef struct rep_nodoColaPersonasABB *nodo;

struct rep_nodoColaPersonasABB
{
  TPersonasABB persona;

  rep_nodoColaPersonasABB *sig;
};

struct rep_colaPersonasABB
{
  rep_nodoColaPersonasABB *ini;
  rep_nodoColaPersonasABB *fin;

  nat tamanio;
};

TColaPersonasABB crearTColaPersonasABB()
{
  TColaPersonasABB esCasiUnLDEperoNo = new rep_colaPersonasABB;
  esCasiUnLDEperoNo->fin = NULL;
  esCasiUnLDEperoNo->ini = NULL;
  esCasiUnLDEperoNo->tamanio = 0;

  return esCasiUnLDEperoNo;
}

void liberarTColaPersonasABB(TColaPersonasABB &c)
{
  nodo elementoAEliminar;

  while (c->ini != NULL)
  {
    elementoAEliminar = c->ini;

    c->ini = c->ini->sig;

    delete elementoAEliminar;
  }

  delete c;
  c = NULL;
}

nat cantidadEnTColaPersonasABB(TColaPersonasABB c)
{
  return c->tamanio;
}

void encolarEnTColaPersonasABB(TPersonasABB t, TColaPersonasABB &c)
{
  nodo nuevoNodo = new rep_nodoColaPersonasABB;
  nodo actual;

  nuevoNodo->persona = t;
  nuevoNodo->sig = NULL;

  actual = c->ini;

  if (actual == NULL)
  {
    c->ini = nuevoNodo;
    c->fin = nuevoNodo;
  }
  else
  {
    c->fin->sig = nuevoNodo;
    c->fin = c->fin->sig;
  }

  c->tamanio++;
}

TPersonasABB frenteDeTColaPersonasABB(TColaPersonasABB c)
{
  return c->ini->persona;
}

void desencolarDeTColaPersonasABB(TColaPersonasABB &c)
{
  nodo aEliminar;

  aEliminar = c->ini;
  c->ini = c->ini->sig;

  c->tamanio--;

  delete aEliminar;
}
