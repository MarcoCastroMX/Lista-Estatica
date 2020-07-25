#include "Menu.h"
#include <string.h>
#include <windows.h>

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}
bool Menu::Agregar(Libro libro){
     if(!Llena()){
        l[contador++] = libro;
        return true;}
    else
        return false;
}

bool Menu::Vacia(){
    if(contador == 0)
        return true;
    else
        return false;
}

bool Menu::Llena(){
    if(contador == 99)
        return true;
    else
        return false;
}

bool Menu::Elimina(string _isbn){
    int pos;
    pos=compararISBN(_isbn);
    if (pos >= 0 && pos < contador) {
        for (pos; pos < contador-1; pos++) {
            l[pos] = l[pos+1];
        }
        contador--;
        return true;
    }
    return false;
}

Libro Menu::Primer(){
    return l[0];
}

Libro Menu::Ultimo(){
    return l[contador-1];
}

Libro Menu::Anterior(int pos){
    return l[pos-1];
}

Libro Menu::Siguiente(int pos){
    return l[pos+1];
}

int Menu::Localiza(string buscado){
    for(int i=0; i<contador;i++){
        if(buscado == l[i].getNombre()){
            return i;
        }
        else if(buscado== l[i].getAutor()){
            return i;
        }
        else if(buscado == l[i].getIsbn()){
            return i;
        }
    }
    return -1;

}

Libro Menu::Recupera(int pos){
    return l[pos];

}

void Menu::Imprimir(){
    for (int i = 0; i<contador; i++){
        cout<<l[i].toString()<<endl;
    }
    system("pause");
}

void Menu::Borra()
{
    setContador(0);
}

int Menu::MenuPrincipal(){
    int respuesta;
    cout<<"\t\tLIBRERIA\n_______________________________________"<<endl;
    cout<<"[1] Agregar Nuevo\n[2] Lista Vacia?\n[3] Lista Llena?\n[4] Eliminar Libro\n[5] Mostrar Primer Libro\n[6] Mostrar Ultimo Libro\n[7] Mostrar Libro Anterior\n[8] Mostrar Libro Siguiente\n[9] Localizar Libro\n[10] Recuperar Libro\n[11] Imprimir Catalogo\n[12] Borrar Todo\n[0] Salir"<<endl;
    cout<<"Opcion: ";
    cin>>respuesta;
    return respuesta;
}

void Menu::setContador(int numero){
    contador=numero;
}

int Menu::getContador(){
    return contador;
}

int Menu::compararISBN(string _isbn){
    for(int i=0;i<contador;i++){
        if(_isbn==l[i].getIsbn())
            return i;
    }
    return -1;
}
