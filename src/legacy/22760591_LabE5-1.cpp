/*
    Realizar un programa en el cual se capturen numeros enteros
    y guardarlos en una lista enlazada. Verificar que los numeros
    que se guarden en la lista no se repitan

    Javier Osvaldo Perez Breatdo - 22760591
*/

#include<iostream>
#include<stdlib.h>
#include<limits>

using namespace std;

// --------------------------------------------------------------------
// ------------------------ ESTRUCTURAS -------------------------------

struct node{
    int data;
    struct node *sig = NULL;
};

// --------------------------------------------------------------------
// -------------------- DEFINICIONES ----------------------------------

// Por el momento se comento esto ya que me causa problemas para visualizar bien el codigo
// typedef struct node nodo;
// typedef nodo *tipoLista;

// --------------------------------------------------------------------
// ------------------------ PROTOTIPOS --------------------------------

void menuRun(struct node*&);
void agregar(struct node*&);
void imprimir(struct node*);
bool existeEnLista(struct node*, int);
void pause();

// --------------------------------------------------------------------
// ------------------------ FUNCION PRINCIPAL -------------------------

int main(){

    struct node *lista = NULL;

    menuRun(lista);

    return 0;
}

// --------------------------------------------------------------------
// ------------------------ FUNCIONES ---------------------------------

void menuRun(struct node*& lista){
    /*
        EDITAR
    */

    char opcion;

    do{
        system("clear");
        cout << "1. Agregar un nodo" << endl;
        cout << "2. Imprimir la lista" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){
            case '1':
                agregar(lista);
                break;
            case '2':
                imprimir(lista);
                break;
            case '3':
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }

        pause();

    }while(opcion!='3');

}

// --------------------------------------------------------------------

bool existeEnLista(struct node* lista_temp, int dato){

    // Se recorre la lista hasta que el puntero temporal sea NULL
    while(lista_temp != NULL){
        if (lista_temp->data == dato){
            return true; // Si el dato existe en la lista se retorna un true
        }
        lista_temp = lista_temp->sig; // Se avanza al siguiente nodo
    }

    return false; // Si el dato no existe en la lista se retorna un false
}

void agregar(struct node*& lista){

    int dato;

    // Pedir el dato que se ingresara
    cout << "Ingresa el numero deseado: ";
    cin >> dato;

    if( !existeEnLista(lista, dato) ){

        if(lista == NULL){ // Verificar si la lista es NULL

            lista = (struct node*) malloc(sizeof(struct node)); // Se asigna memoria para el nodo
            lista->data = dato; // Se asigna el dato al nodo

        }

        else{ // Si la lista no es NULL, tiene un nodo por lo tanto se crea un nodo nuevo que se conecta

        struct node* nodo_nuevo; // Se declara un nodo nuevo

        nodo_nuevo = (struct node*) malloc(sizeof(struct node)); // Se asigna memoria para el nodo nuevo

        nodo_nuevo->data = dato; // Se asigna el dato al nodo nuevo
        nodo_nuevo->sig = lista; // Se conecta el nodo nuevo con la lista
        lista = nodo_nuevo; // Se asigna el nodo nuevo como el primer nodo de la lista

        }
    }
    else{
        cout << "Este valor ya existe en la lista" << endl;
    }

}

void imprimir(struct node* lista){

    struct node* ptr_temp = lista;

    while( lista != NULL){
        cout << lista->data << endl;
        lista = lista->sig;
    }
}


//-------------------------------------------------------
//-------------------------------------------------------

void pause(){
  /*Funcion para hacer un pause en ubuntu*/

  // Limpiar el búfer de entrada
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Presiona Enter para continuar...";
  cin.get();

}