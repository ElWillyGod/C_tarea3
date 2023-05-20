#include "../include/aplicaciones.h"

TPilaPersona menoresQueElResto(TPersonasLDE lista)
{

    TPilaPersona menores = crearTPilaPersona();

    while (cantidadTPersonasLDE(lista) > 0)
    {
        TPersona inicio = obtenerInicioDeTPersonasLDE(lista);

        while ((cantidadEnTPilaPersona(menores) > 0) && (edadTPersona(cimaDeTPilaPersona(menores)) >= edadTPersona(inicio)))
        {
            desapilarDeTPilaPersona(menores);
        }

        apilarEnTPilaPersona(menores, inicio);
        eliminarInicioTPersonasLDE(lista);
    }

    return menores;
}

bool sumaPares(nat k, TConjuntoIds c)
{

    bool hash[cantMaxTConjuntoIds(c) + 1];

    for (nat i = 1; i <= cantMaxTConjuntoIds(c); i++)
    {
        hash[i] = false;
    }

    for (nat i = 1; i <= cantMaxTConjuntoIds(c); i++)
    {
        if (perteneceTConjuntoIds(i, c))
        {

            nat complemento = k - i;

            if (complemento > 0 && complemento <= cantMaxTConjuntoIds(c) && hash[complemento])
            {
                return true;
            }

            hash[i] = true;
        }
    }

    return false;
}
/*if (k > conjunto.cantMax || k < 1) {
        return false;
    }

    for (int i = 1; i <= k / 2; i++) {
        if (conjunto.conjunto[i] && conjunto.conjunto[k - i]) {
            return true;
        }
    }

    return false;
}

    TConjuntoIds comp = crearTConjuntoIds(cantMaxTConjuntoIds(c));
    nat i =1;

    while (cardinalTConjuntoIds(c) > 0)
    {
        if(perteneceTConjuntoIds(i,comp)){
            liberarTConjuntoIds(comp);
            return true;
        }else{
            insertarTConjuntoIds(k-i, comp);
        }

    }

    liberarTConjuntoIds(comp);
    return false;
*/