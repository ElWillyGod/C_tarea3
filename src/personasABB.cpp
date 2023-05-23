#include "../include/personasABB.h"
#include "../include/colaPersonasABB.h"

///////////////////////////////////
////// PEGAR CÓDIGO TAREA 2 //////
///////////////////////////////////

struct rep_personasAbb
{
    TPersona persona;
    nat clave;
    TPersonasABB left, right;
};

TPersonasABB crearTPersonasABB()
{
    TPersonasABB arbol = NULL;

    return arbol;
}

bool esVacioTPersonasABB(TPersonasABB personasABB)
{
    return personasABB == NULL;
}

void insertarTPersonasABB(TPersonasABB &personasABB, TPersona p)
{
    if (personasABB == NULL)
    {

        personasABB = new rep_personasAbb;

        personasABB->clave = idTPersona(p);
        personasABB->persona = p;
        personasABB->left = personasABB->right = NULL;
    }
    else if (idTPersona(p) < personasABB->clave)
    {
        insertarTPersonasABB(personasABB->left, p);
    }
    else if (idTPersona(p) > personasABB->clave)
    {
        insertarTPersonasABB(personasABB->right, p);
    }
}

void liberarTPersonasABB(TPersonasABB &personasABB)
{
    if (personasABB != NULL)
    {

        liberarTPersonasABB(personasABB->left);
        liberarTPersonasABB(personasABB->right);

        // Liberar memoria de las personas

        liberarTPersona(personasABB->persona);

        // Liberar memoria del nodo del árbol
        delete personasABB;
        personasABB = NULL;
    }
}

void imprimirTPersonasABB(TPersonasABB personasABB)
{
    if (personasABB != NULL)
    {
        imprimirTPersonasABB(personasABB->left);

        imprimirTPersona(personasABB->persona);

        imprimirTPersonasABB(personasABB->right);
    }
}

nat cantidadTPersonasABB(TPersonasABB personasABB)
{
    if (personasABB == NULL)
        return 0;
    else
    {
        return 1 + cantidadTPersonasABB(personasABB->left) + cantidadTPersonasABB(personasABB->right); // probar con parentecis
    }
}

TPersona maxIdPersona(TPersonasABB personasABB)
{
    while (personasABB->right != NULL)
    {
        personasABB = personasABB->right;
    }

    return personasABB->persona;
}

void removerTPersonasABB(TPersonasABB &personasABB, nat id)
{
    if (id < personasABB->clave)
    {
        removerTPersonasABB(personasABB->left, id);
    }
    else if (id > personasABB->clave)
    {
        removerTPersonasABB(personasABB->right, id);
    }
    else if (personasABB->clave == id)
    {
        if (personasABB->right == NULL)
        {

            TPersonasABB aBorrar = personasABB;
            personasABB = personasABB->left;

            liberarTPersona(aBorrar->persona);
            delete aBorrar;
        }
        else if (personasABB->left == NULL)
        {
            TPersonasABB aBorrar = personasABB;
            personasABB = personasABB->right;

            liberarTPersona(aBorrar->persona);
            delete aBorrar;
        }
        else
        {
            liberarTPersona(personasABB->persona);
            TPersona maximio = maxIdPersona(personasABB->left);

            personasABB->clave = idTPersona(maximio);
            personasABB->persona = copiarTPersona(maximio);

            removerTPersonasABB(personasABB->left, personasABB->clave);
        }
    }
}

bool estaTPersonasABB(TPersonasABB personasABB, nat id)
{
    if (personasABB == NULL)
        return false;

    if (personasABB->clave == id)
        return true;

    if (personasABB->clave > id)
    {
        return estaTPersonasABB(personasABB->left, id);
    }

    return estaTPersonasABB(personasABB->right, id);
}

TPersona obtenerDeTPersonasABB(TPersonasABB personasABB, nat id)
{
    if (personasABB->clave == id)
    {
        return personasABB->persona; // dara error si el nodo personaABB es NULL
    }

    if (personasABB->clave > id)
    {
        return obtenerDeTPersonasABB(personasABB->left, id);
    }

    return obtenerDeTPersonasABB(personasABB->right, id);
}

nat alturaTPersonasABB(TPersonasABB personasABB)
{
    if (personasABB == NULL)
    {
        return 0;
    }
    nat alturaLeft = alturaTPersonasABB(personasABB->left);
    nat alturaRight = alturaTPersonasABB(personasABB->right);

    return 1 + (alturaLeft > alturaRight ? alturaLeft : alturaRight);
}
bool esPerfectoElNodo(TPersonasABB nodo, nat nivel, nat altura)
{

    if (nodo == NULL)
    { // si esta todo vacio
        return nivel == altura;
    }

    if (nodo->left == NULL && nodo->right == NULL)
    { // si los sigientes son NULL

        return nivel == altura + 1;
    }

    if (nodo->left == NULL || nodo->right == NULL)
    { // si solamente uno es nulo no es perfecto

        return false;
    }
    return esPerfectoElNodo(nodo->left, nivel, altura + 1) && esPerfectoElNodo(nodo->right, nivel, altura + 1);
}

bool esPerfectoTPersonasABB(TPersonasABB personasABB)
{
    nat nivel = alturaTPersonasABB(personasABB);

    return esPerfectoElNodo(personasABB, nivel, 0);
}

TPersonasABB mayoresTPersonasABB(TPersonasABB personasABB, nat edad)
{
    TPersonasABB resultado = NULL;

    if (personasABB == NULL)
    {
        return resultado;
    }
    else
    {

        TPersonasABB left = mayoresTPersonasABB(personasABB->left, edad);
        TPersonasABB right = mayoresTPersonasABB(personasABB->right, edad);

        TPersona raiz = personasABB->persona;

        if (edadTPersona(raiz) > edad)
        {

            resultado = new rep_personasAbb;

            resultado->persona = copiarTPersona(raiz);
            resultado->clave = idTPersona(raiz);
            resultado->left = left;
            resultado->right = right;
        }
        else if (left == NULL)
        {

            resultado = right;
        }
        else if (right == NULL)
        {

            resultado = left;
        }
        else
        {

            TPersona mayor = maxIdPersona(left);

            resultado = new rep_personasAbb;

            resultado->persona = copiarTPersona(mayor);
            resultado->clave = idTPersona(mayor);
            resultado->left = left;
            resultado->right = right;

            removerTPersonasABB(left, idTPersona(mayor));
        }
    }
    return resultado;
}
void aplanarEnLista(TPersonasABB arbol, TPersonasLDE &lista)
{
    if (arbol != NULL)
    {
        aplanarEnLista(arbol->right, lista);
        insertarTPersonasLDE(lista, copiarTPersona(arbol->persona), 1);
        aplanarEnLista(arbol->left, lista);
    }
}

TPersonasLDE aTPersonasLDE(TPersonasABB personasABB)
{
    TPersonasLDE lista = crearTPersonasLDE();

    aplanarEnLista(personasABB, lista);
    return lista;
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
int contarNodosEnNivel(TPersonasABB raiz, int nivel, int nivelActual)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (nivelActual == nivel)
    {
        return 1;
    }

    return contarNodosEnNivel(raiz->left, nivel, nivelActual + 1) + contarNodosEnNivel(raiz->right, nivel, nivelActual + 1);
}

nat amplitudTPersonasABB(TPersonasABB personasABB)
{
    int nivelMax = alturaTPersonasABB(personasABB) - 1;

    int amplitudMax = 0;
    int nivel;

    for (nivel = 0; nivel <= nivelMax; nivel++)
    {

        int nodosEnNivel = contarNodosEnNivel(personasABB, nivel, 0);

        amplitudMax = (amplitudMax > nodosEnNivel) ? amplitudMax : nodosEnNivel;
    }
    return amplitudMax;
}

TPilaPersona serializarTPersonasABB(TPersonasABB personasABB)
{
    TPilaPersona pila = crearTPilaPersona();
    TColaPersonasABB cola = crearTColaPersonasABB();

    if (personasABB != NULL) // recorrida por niveles 
    {

        encolarEnTColaPersonasABB(personasABB, cola);

        while (cantidadEnTColaPersonasABB(cola) > 0)
        {
            TPersonasABB x = frenteDeTColaPersonasABB(cola);

            if (x->left != NULL)
            {
                encolarEnTColaPersonasABB(x->left, cola);
            }
            if (x->right != NULL)
            {
                encolarEnTColaPersonasABB(x->right, cola);
            }

            apilarEnTPilaPersona(pila, x->persona);
            desencolarDeTColaPersonasABB(cola);
        }
        liberarTColaPersonasABB(cola);
    }

    TPilaPersona pilInversa = crearTPilaPersona();

    while (cantidadEnTPilaPersona(pila) > 0) // invertir la cola 
    {
        apilarEnTPilaPersona(pilInversa, cimaDeTPilaPersona(pila));
        desapilarDeTPilaPersona(pila);
    }

    liberarTPilaPersona(pila);

    return pilInversa;
}

TPersonasABB deserializarTPersonasABB(TPilaPersona &pilaPersonas)
{
    TPersonasABB arbol = NULL;

    while (cantidadEnTPilaPersona(pilaPersonas) >= 1)
    {

        insertarTPersonasABB(arbol, copiarTPersona(cimaDeTPilaPersona(pilaPersonas)));
        desapilarDeTPilaPersona(pilaPersonas);
    }

    liberarTPilaPersona(pilaPersonas);
    return arbol;
}

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
