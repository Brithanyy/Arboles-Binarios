#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
///ESTRUCTURAS
typedef struct NodoArbol{
    int Dato;
    struct NodoArbol *izquierdo;
    struct NodoArbol *derecho;
} NodoArbol;

typedef struct Persona{
     int Legajo;
     char Nombre[20];
     int Edad;
} Persona;

typedef struct NodoArbolPersona {
     Persona UnaPersona;
     struct NodoArbolPersona * izq;
     struct NodoArbolPersona * der;
} NodoArbolPersona;

typedef struct nodoSimple {
    Persona unaPersona;
    struct nodoSimple *siguiente;
} nodoSimple;

///PROTOTIPADO DE FUNCIONES
NodoArbol *inicArbol(NodoArbol *arbol);
NodoArbol *crearNodoArbol(int dato);
NodoArbol *insertarNodoEnArbol(NodoArbol *arbol, int dato);
void mostrarPREorder(NodoArbol *arbol);
void mostrarINorder(NodoArbol *arbol);
void mostrarPOSTorder(NodoArbol *arbol);
int buscarDato(NodoArbol *arbol, int datoBuscar);
void contarCantidadDeHojas(NodoArbol *arbol, int *contador);
int contarNodosGrado1(NodoArbol *arbol);
///Con estructura persona
NodoArbolPersona *inicArbolPersona(NodoArbolPersona *arbolPersona);
NodoArbolPersona *crearNodoArbolPersona(Persona unaPersona);
NodoArbolPersona *insertarNodoEnArbolPersona(Persona unaPersona, NodoArbolPersona *arbolPersona);
NodoArbolPersona *cargarArbolPersona(NodoArbol *arbolPesona);
Persona cargarUnaPersona();
void mostrarUnaPersona(NodoArbolPersona *arbol);
void mostrarArbolpersonaPreOrden(NodoArbolPersona *arbol);
void mostrarArbolpersonaInOrden(NodoArbolPersona *arbol);
void mostrarArbolpersonaPostOrden(NodoArbolPersona *arbol);
nodoSimple *inicListaSimple();
nodoSimple *crearNodoLista(Persona unaPersona);
nodoSimple *agregarAlFinalListaSimple(nodoSimple *lista, nodoSimple *nodoInsertar);
nodoSimple *agregarPersonaALista(nodoSimple *lista, Persona unaPersona);
nodoSimple *pasarDeArbolAListaSimple(nodoSimple *lista, NodoArbolPersona *arbol);
void mostrarUnaPersonaListaSimple(nodoSimple *lista);
void mostrarListaSimple(nodoSimple *lista);
NodoArbolPersona *buscarNodoArbolLegajo(NodoArbolPersona *arbol, int legajo);
NodoArbolPersona *buscarNodoArbolNombre(NodoArbolPersona *arbol, char nombre[]);
int contarAlturaArbol(NodoArbolPersona *arbol);
void contarHojasArbol(NodoArbolPersona *arbol, int *contador);
int contarNodosArbol(NodoArbolPersona *arbol, int contador);
NodoArbolPersona *encontrarMinimo(NodoArbolPersona *arbol);
NodoArbolPersona *eliminarNodoArbol(NodoArbolPersona *arbol, int legajo);

///MAIN
int main(){
    NodoArbol *arbol = inicArbol(arbol);
//    printf("%p\n", arbol);

    int datosArbol[] = {8,3,1,6,4,7,10,14,13};
    ///Insertando datos en el arbol.
    for(int i = 0; i < 9; i++){
        arbol = insertarNodoEnArbol(arbol, datosArbol[i]);
    }
    mostrarINorder(arbol);
    printf("\n");

///2 a-
    int cantidadDeNodosHojas = 0;
    contarCantidadDeHojas(arbol, &cantidadDeNodosHojas);
    printf("\nLa cantidad de Nodos Hojas son: %i \n", cantidadDeNodosHojas);

///2 b-
    int cantidadNodosGrado1 = contarNodosGrado1(arbol);
    printf("\nLa cantidad de Nodos Grado 1 que hay en el arbol son: %i\n", cantidadNodosGrado1);

///2 c-
    int dato = 11;
    int resultado = buscarDato(arbol,dato);
    if(resultado == 1)printf("\n\nEncontramos el dato buscado.\n");
    else printf("\n\nEl dato buscado no fue encontrado.\n");

///2-d
    printf("\nMostrnado arbol en pre orden: \n");
    mostrarPREorder(arbol);
    printf("\n");

///1)Hacer una función que permita ingresar nuevos nodos manteniendo el árbol ordenado (por legajo)
   NodoArbolPersona *arbolPersona = inicArbolPersona(arbolPersona);
   arbolPersona = cargarArbolPersona(arbolPersona);
   printf("\nArbol con personas ha sido cargado con exito.\n");
///2)Mostrar con las tres opciones el arbol de personas.
   printf("\nMostrando Arbol Personas en orden: \n");
   mostrarArbolpersonaInOrden(arbolPersona);
   printf("\nMostrando Arbol Personas en PRE orden: \n");
   mostrarArbolpersonaPreOrden(arbolPersona);
   printf("\nMostrando Arbol Personas en POST orden: \n");
   mostrarArbolpersonaPostOrden(arbolPersona);
///3)Pasar a una lista simple todas las personas del arbol.
   nodoSimple *lista = inicListaSimple();
   printf("\n%p\n",lista);
   lista = pasarDeArbolAListaSimple(lista, arbolPersona);
   printf("\nMostrando lista simple\n");
   mostrarListaSimple(lista);
///4)Buscar Nodo por legajo y retornarlo
    int legajoBuscar = 2;
    NodoArbolPersona *aux = buscarNodoArbolLegajo(arbolPersona, legajoBuscar);
    if(aux != NULL){
        printf("\nMostrando el legajo encontrado: \n");
        mostrarUnaPersona(aux);
    }
    else printf("No se encontro el numero de legajo %i\n", legajoBuscar);
///5)Buscar nodo por nombre y retornarlo
    char nombre[] = {"paola"};
    NodoArbolPersona *aux2 = buscarNodoArbolNombre(arbolPersona,nombre);
    if(aux2 != NULL) {
        printf("\nMostrando el nombre encontrado: \n");
        mostrarUnaPersona(aux2);
    }else printf("\nNo encontramos la persona con el nombre %s\n", nombre);
///6)Contar la altura del arbol
    int alturaArbol = contarAlturaArbol(arbolPersona);
    printf("\nLa altura del arbol es de: %i\n", alturaArbol);
///7)Hacer una función que calcule la cantidad de nodos del árbol.
    int contadorDeNodos = 0;
    int cantNodosArbol = contarNodosArbol(arbolPersona, contadorDeNodos);
    printf("\nLa cantidad de nodos que tiene el arbol es: %i\n", cantNodosArbol);
///8)Hacer una función que calcule la cantidad de hojas del árbol.
    int contadorHojas = 0;
    contarHojasArbol(arbolPersona, &contadorHojas);
    printf("\nLa cantidad de nodos hojas son: %i\n", contadorHojas);
///9)Hacer una función que borre un nodo de un árbol.
    int legajo = 2;
    arbolPersona = eliminarNodoArbol(arbolPersona, legajo);
    printf("\nMostrando que el legajo %i ha sido eliminado:\n", legajo);
    mostrarArbolpersonaInOrden(arbolPersona);
}
///FUNCIONES
//Inicializar arbol:
NodoArbol *inicArbol(NodoArbol *arbol){
    return NULL;
}

//Crear Nodo Arbol:
NodoArbol *crearNodoArbol(int dato){
    NodoArbol *nodoNuevo = (NodoArbol*)malloc(sizeof(NodoArbol));

    nodoNuevo->Dato = dato;

    nodoNuevo->derecho = NULL;
    nodoNuevo->izquierdo = NULL;

    return nodoNuevo;
}

//Insertar:
NodoArbol *insertarNodoEnArbol(NodoArbol *arbol, int dato){
    if(arbol == NULL) arbol = crearNodoArbol(dato);
    else{
        if(dato > arbol->Dato) arbol->derecho = insertarNodoEnArbol(arbol->derecho, dato);
        else arbol->izquierdo = insertarNodoEnArbol(arbol->izquierdo, dato);
    }
    return arbol;
}

//Mostrar arbol pre order:
void mostrarPREorder(NodoArbol *arbol){
    if(arbol == NULL) return;
    else{
        printf("- %i - ", arbol->Dato);
        mostrarPREorder(arbol->izquierdo);
        mostrarPREorder(arbol->derecho);
    }
}
//Mostrar en orden
void mostrarINorder(NodoArbol *arbol){
    if(arbol == NULL) return;
    else{
        mostrarINorder(arbol->izquierdo);
        printf("- %i - ", arbol->Dato);
        mostrarINorder(arbol->derecho);
    }
}
//Mostrar post orden
void mostrarPOSTorder(NodoArbol *arbol){
    if(arbol == NULL) return;
    else{
        mostrarPOSTorder(arbol->izquierdo);
        mostrarPOSTorder(arbol->derecho);
        printf("- %i - ", arbol->Dato);
    }
}

// buscar dato en un arbol
int buscarDato(NodoArbol *arbol, int datoBuscar){
    if(arbol != NULL){
        return (arbol->Dato == datoBuscar || buscarDato(arbol->izquierdo, datoBuscar) || buscarDato(arbol->derecho, datoBuscar));

    }else{
        return 0;
    }
}
//Contar cantidad de hojas
void contarCantidadDeHojas(NodoArbol *arbol, int *contador){
    if(arbol != NULL){
        if (arbol->izquierdo == NULL && arbol->derecho == NULL) {
        *contador = *contador + 1;
        }
          contarCantidadDeHojas(arbol->izquierdo, contador);
          contarCantidadDeHojas(arbol->derecho, contador);
    }
}

//Contar cantidad de nodos de grado 1
int contarNodosGrado1(NodoArbol *arbol){
    int contador = 0;
    if(arbol != NULL){
        if (arbol->izquierdo != NULL && arbol->derecho == NULL){
            contador++;
        }else if(arbol->izquierdo == NULL && arbol->derecho != NULL){
            contador++;
        }
          contador = contador + contarNodosGrado1(arbol->izquierdo);
          contador = contador + contarNodosGrado1(arbol->derecho);
    return contador;
    }
}


///FUNCIONES BASICAS DE ARBOLES CON UNA ESTRUCTURA PERSONA:
//Inicializar
NodoArbolPersona *inicArbolPersona(NodoArbolPersona *arbolPersona){
    return NULL;;
}
//Crear nodo arbol persona
NodoArbolPersona *crearNodoArbolPersona(Persona unaPersona){
    NodoArbolPersona *nodoNuevo = (NodoArbolPersona*)malloc(sizeof(NodoArbolPersona));
    nodoNuevo->UnaPersona = unaPersona;
    nodoNuevo->der = NULL;
    nodoNuevo->izq = NULL;
    return nodoNuevo;
}
//Insertar en arbol persona por legajo
NodoArbolPersona *insertarNodoEnArbolPersona(Persona unaPersona, NodoArbolPersona *arbolPersona){
    if(arbolPersona == NULL) arbolPersona = crearNodoArbolPersona(unaPersona);
    else{
        if(unaPersona.Legajo > arbolPersona->UnaPersona.Legajo) arbolPersona->der = insertarNodoEnArbolPersona(unaPersona, arbolPersona->der);
        else arbolPersona->izq = insertarNodoEnArbolPersona(unaPersona,arbolPersona->izq);
    }
    return arbolPersona;
}
//cargar Hasta que el usuario quiera
NodoArbolPersona *cargarArbolPersona(NodoArbol *arbolPesona){
    char eleccion = 's';
    Persona unaPersona;
    while(eleccion == 's'){
        unaPersona = cargarUnaPersona();
        arbolPesona = insertarNodoEnArbolPersona(unaPersona,arbolPesona);

        printf("Pulsa 's' si desea agregar otra persona al arbol: ");
        fflush(stdin);
        scanf("%c", &eleccion);
    }
    return arbolPesona;
}
//Printf para cargar una persona en el arbol
Persona cargarUnaPersona(){
    Persona unaPersona;

    printf("\nNombre: ");
    fflush(stdin);
    gets(unaPersona.Nombre);

    printf("Edad: ");
    fflush(stdin);
    scanf("%i", &unaPersona.Edad);

    printf("Legajo: ");
    fflush(stdin);
    scanf("%i", &unaPersona.Legajo);

    return unaPersona;
}
//Printf para mostrar arbol persona
void mostrarUnaPersona(NodoArbolPersona *arbol){
    printf("\n----------------------------------------\n");
    printf("Nombre: %s\n", arbol->UnaPersona.Nombre);
    printf("Edad: %i\n", arbol->UnaPersona.Edad);
    printf("Legajo: %i", arbol->UnaPersona.Legajo);
    printf("\n----------------------------------------\n");
}
//mostrar arbol en pre orden
void mostrarArbolpersonaPreOrden(NodoArbolPersona *arbol){
    if(arbol == NULL) return;
    else{
        mostrarUnaPersona(arbol);
        mostrarArbolpersonaPreOrden(arbol->izq);
        mostrarArbolpersonaPreOrden(arbol->der);
    }
}
//Mostrar arbol en orden
void mostrarArbolpersonaInOrden(NodoArbolPersona *arbol){
    if(arbol == NULL) return;
    else{
        mostrarArbolpersonaInOrden(arbol->izq);
        mostrarUnaPersona(arbol);
        mostrarArbolpersonaInOrden(arbol->der);
    }
}
//Mostrar arbol en post orden
void mostrarArbolpersonaPostOrden(NodoArbolPersona *arbol){
    if(arbol == NULL) return;
    else{
        mostrarArbolpersonaPostOrden(arbol->izq);
        mostrarUnaPersona(arbol);
        mostrarArbolpersonaPostOrden(arbol->der);
    }
}
///Funciones basicas para la lista simple:
nodoSimple *inicListaSimple(){
    return NULL;
}

nodoSimple *crearNodoLista(Persona unaPersona){
    nodoSimple *aux = (nodoSimple*)malloc(sizeof(nodoSimple));
    aux->unaPersona = unaPersona;
    aux->siguiente = NULL;
    return aux;
}

nodoSimple *agregarAlFinalListaSimple(nodoSimple *lista, nodoSimple *nodoInsertar){
    nodoSimple *aux;
    if(lista == NULL) lista = nodoInsertar;
    else{
        aux = lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nodoInsertar;
    }
    return lista;
}

nodoSimple *agregarPersonaALista(nodoSimple *lista, Persona unaPersona){
    nodoSimple *nodoInsertar = crearNodoLista(unaPersona);
    if(lista == NULL) lista = nodoInsertar;
    else{
        lista = agregarAlFinalListaSimple(lista,nodoInsertar);
    }
    return lista;
}

nodoSimple *pasarDeArbolAListaSimple(nodoSimple *lista, NodoArbolPersona *arbol){
    if(arbol != NULL){
        lista = pasarDeArbolAListaSimple(lista,arbol->izq);
        lista = agregarPersonaALista(lista, arbol->UnaPersona);
        lista = pasarDeArbolAListaSimple(lista,arbol->der);
    }
    return lista;
}

//Printf para mostrar arbol persona
void mostrarUnaPersonaListaSimple(nodoSimple *lista){
    printf("\n----------------------------------------\n");
    printf("Nombre: %s\n", lista->unaPersona.Nombre);
    printf("Edad: %i\n", lista->unaPersona.Edad);
    printf("Legajo: %i", lista->unaPersona.Legajo);
    printf("\n----------------------------------------\n");
}

void mostrarListaSimple(nodoSimple *lista){
    if(lista == NULL) return;
    else{
        mostrarListaSimple(lista->siguiente);
        mostrarUnaPersonaListaSimple(lista);
    }
}

//Buscar nodo en arbol por legajo
NodoArbolPersona *buscarNodoArbolLegajo(NodoArbolPersona *arbol, int legajo){
    NodoArbolPersona *aux = NULL;
    if(arbol != NULL){
        if(legajo == arbol->UnaPersona.Legajo){
            aux = arbol; ///Caso de q sea la raiz
        }else{
            if(legajo < arbol->UnaPersona.Legajo){
///Comparamos xq sabemos q los menores estan del lado izquierdo y los mayores del derecho.
                aux = buscarNodoArbolLegajo(arbol->izq, legajo);
            }else
                aux = buscarNodoArbolLegajo(arbol->der,legajo);
        }
    }
    return aux;
}

//buscar nodo por nombre en arbol
NodoArbolPersona *buscarNodoArbolNombre(NodoArbolPersona *arbol, char nombre[]){
    NodoArbolPersona *aux = NULL;
    if(arbol != NULL){
        if(strcmp(nombre,arbol->UnaPersona.Nombre) == 0) aux = arbol;
        else{
///Primero buscamos en izqueirda y luego verificamos que no lo haya encontrado
///Para luego buscarlo por derecha
            aux = buscarNodoArbolNombre(arbol->izq, nombre);
             if (aux == NULL) {///Si es == NULL lo va a seguir buscando
                aux = buscarNodoArbolNombre(arbol->der, nombre);
            }
            //aux = buscarNodoArbolNombre(arbol->der, nombre);
        }
    }
    return aux;
}

//calcular altura arbol
int contarAlturaArbol(NodoArbolPersona *arbol){
    if(arbol == NULL) return 0;
    else{
        int contadorIzq = contarAlturaArbol(arbol->izq);
        int contadorDer = contarAlturaArbol(arbol->der);
        if(contadorIzq > contadorDer) return contadorIzq + 1;
        else return contadorDer + 1;
    }
}

//contar nodos del arbol
int contarNodosArbol(NodoArbolPersona *arbol, int contador){
    if(arbol == NULL) return 0;
    else{
        contador = contarNodosArbol(arbol->izq, contador);
        contador += 1;
        contador = contarNodosArbol(arbol->der, contador);
        contador += 1;
    }
     return contador;
}

//contar nodos hoja arbol
void contarHojasArbol(NodoArbolPersona *arbol, int *contador){
    if(arbol != NULL){
        if(arbol->izq == NULL && arbol->der == NULL){
            *contador = *contador + 1;
        }
            contarHojasArbol(arbol->izq, contador);
            contarHojasArbol(arbol->der, contador);
    }
}

//Encontrar minimo                                                                                          :
NodoArbolPersona *encontrarMinimo(NodoArbolPersona *arbol){
    if (arbol == NULL) return NULL;
    while(arbol->izq != NULL) arbol = arbol->izq;
    return arbol;
}
//Eliminar nodo del arbol
NodoArbolPersona *eliminarNodoArbol(NodoArbolPersona *arbol, int legajo){
    if(arbol == NULL) return arbol;

    if(legajo < arbol->UnaPersona.Legajo){
        arbol->izq = eliminarNodoArbol(arbol->izq, legajo);
    }
    else if(legajo > arbol->UnaPersona.Legajo){
        arbol->der = eliminarNodoArbol(arbol->der, legajo);
    }
    else{
        ///Caso 1: Nodo sin hijos o uno solo (más fácil)
        if(arbol->izq == NULL){
            NodoArbolPersona *aux = arbol->der;
            free(arbol);
            return aux;
        }
        else if(arbol->der == NULL){
            NodoArbolPersona *aux = arbol->izq;
            free(arbol);
            return aux;
        }
        ///Caso 2: Nodo con dos hijos
        /// Encontrar el sucesor inmediato (nodo más a la izquierda en el subárbol derecho)
        NodoArbolPersona *aux = encontrarMinimo(arbol->der);
        /// Copiar el valor del sucesor.
        arbol->UnaPersona.Legajo = aux->UnaPersona.Legajo;
        /// Eliminamos el sucesor
        arbol->der = eliminarNodoArbol(arbol->der, aux->UnaPersona.Legajo);
    }
    return arbol;
}

