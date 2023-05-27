#include "../include/conjuntoIds.h"

struct rep_conjuntoIds
{
	bool* conjunto;
	int cantidad;
	nat cantMax;
};

TConjuntoIds crearTConjuntoIds(nat cantMax)
{
	TConjuntoIds x = new rep_conjuntoIds;

	x->cantidad = 0;
	x->conjunto = new bool[cantMax + 1];
	x->cantMax = cantMax;

	for (nat i = 0; i <= cantMax; i++)
	{
		x->conjunto[i] = false;
	}

	return x;
};

bool esVacioTConjuntoIds(TConjuntoIds c)
{
	return (c->cantidad == 0);
};

void insertarTConjuntoIds(nat id, TConjuntoIds &c)
{
	if ((id > 0) && (id <= c->cantMax))
	{
		c->conjunto[id] = true;
		c->cantidad++;
	}
};

void borrarTConjuntoIds(nat id, TConjuntoIds &c)
{
	if ((id > 0) && (id <= c->cantMax))
	{
		c->conjunto[id] = false;
		c->cantidad--;
	}
};

bool perteneceTConjuntoIds(nat id, TConjuntoIds c)
{
	return ((id > 0) && ((id <= c->cantMax) && (c->conjunto[id] != false)));
};

nat cardinalTConjuntoIds(TConjuntoIds c)
{
	return c->cantidad;
};

nat cantMaxTConjuntoIds(TConjuntoIds c)
{
	return c->cantMax;
};

void imprimirTConjuntoIds(TConjuntoIds c)
{
	for (nat i = 0; i <= c->cantMax; i++)
		if (c->conjunto[i] != false)
		{
			 printf("%d ", i);
		}
	printf("\n");
};

void liberarTConjuntoIds(TConjuntoIds &c)
{
	
	delete []c->conjunto;
	delete c;
	c = NULL;
	
};

TConjuntoIds unionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2)
{
	TConjuntoIds resultado = crearTConjuntoIds(c1->cantMax);

	for (nat i = 0; i <= c1->cantMax; i++){
		if( c1->conjunto[i] || c2->conjunto[i]){
			resultado->conjunto[i] = true;
			resultado->cantidad ++;
		}
	}

	return resultado;
};

TConjuntoIds interseccionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2)
{
	TConjuntoIds resultado = crearTConjuntoIds(c1->cantMax);

	for (nat i = 0; i <= c1->cantMax; i++){

		if(c1->conjunto[i] && c2->conjunto[i]){
			resultado->conjunto[i] = true;
			resultado->cantidad ++;

		}
	}

	return resultado;
};

TConjuntoIds diferenciaTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2)
{
	TConjuntoIds resultado = crearTConjuntoIds(c1->cantMax);

	for (nat i = 0; i <= c1->cantMax; i++){

		if(c1->conjunto[i] && !(c2->conjunto[i])){
			resultado->conjunto[i] = true;
			resultado->cantidad ++;

		}
	}

	return resultado;
};
