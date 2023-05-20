#include "../include/aplicaciones.h"

TPilaPersona menoresQueElResto(TPersonasLDE lista)
{

    TPilaPersona menores = crearTPilaPersona();

    while (cantidadTPersonasLDE(lista) > 0)
    {

        while ((cantidadEnTPilaPersona(menores) > 0) && (edadTPersona(cimaDeTPilaPersona(menores)) > edadTPersona(obtenerInicioDeTPersonasLDE(lista))))
        {
            desapilarDeTPilaPersona(menores);
        }

        apilarEnTPilaPersona(menores, obtenerInicioDeTPersonasLDE(lista));
        eliminarInicioTPersonasLDE(lista);
    }

    return menores;
}

bool sumaPares(nat k, TConjuntoIds c)
{

    bool aux[cantMaxTConjuntoIds(c) + 1];

    for (nat i = 1; i <= cantMaxTConjuntoIds(c); i++)
    {
        aux[i] = false;
    }

    for (nat i = 1; i <= cantMaxTConjuntoIds(c); i++)
    {

        if (perteneceTConjuntoIds(i, c))
        {
            if (k - i > 0 && k - i <= cantMaxTConjuntoIds(c) && aux[k - i])
            {
                return true;
            }

            aux[i] = true;
        }
    }

    return false;
}