#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "List.cpp"
#include "Collector.cpp"
using namespace std;

Collector col;
Collector* colPtr = &col;

List list;
List* listPtr = &list;


void* operator new(size_t size)
{
    cout << "New operator overloading " << endl;


    if (colPtr->empty())
    {
        cout << "Collector Empty" << endl;
        void* p = malloc(size);
        return p;
    }
    else {
        cout << "Collector being used" << endl;
        void* reuse = colPtr->get_last();
        colPtr->deleteLast();
        return reuse;
    }
    
}


void operator delete(void* p)
{
    colPtr->append((Node*)p);
}


//
void appendcout() {
    int num;
    cout << "Número que de desea agregar: " << endl;
    cin >> num;

    listPtr->append(num);
    cout << "======================================" << endl;
    cout << "" << endl;
    cout << "Lista:" << endl;
    cout << "" << endl;
    listPtr->printList();
    cout << "" << endl;
    cout << "======================================" << endl;
}

//
void deletecout() {
    int num;
    cout << "" << endl;
    cout << "Cual numero quiere eliminar? : " << endl;
    cin >> num;

    listPtr->deleteElem(num);

    cout << "======================================" << endl;
    cout << "" << endl;
    cout << "Se elimino el ultimo elemento " << endl;
    cout << "" << endl;
    cout << "Lista:" << endl;
    cout << "" << endl;
    listPtr->printList();
    cout << "" << endl;
    cout << "======================================" << endl;
}


void list_status() {
    cout << "======================================" << endl;
    cout << "" << endl;
    cout << "Lista:" << endl;
    cout << "" << endl;
    listPtr->printList();
    cout << "" << endl;
    cout << "======================================" << endl;
}

void col_status() {
    cout << "======================================" << endl;
    cout << "" << endl;
    cout << "Collector:" << endl;
    cout << "" << endl;
    colPtr->printList();
    cout << "" << endl;
    cout << "======================================" << endl;

}



//
int main() {

    Node xd(10);
    colPtr->append(&xd);
    
    while (true) {

        char op;
        cout << "" << endl;
        cout << "Acciones:" << endl;
        cout << "| a | Agregar elemento" << endl;
        cout << "| e | Eliminar elemento" << endl;
        cout << "| l | Ver estado actual de la lista" << endl;
        cout << "| c | Ver estado actual del collector" << endl;
        cout << "| f | Salir" << endl;
        cout << "Que desea hacer?: " << endl;

        cin >> op;

        switch (op)
        {
        case 'a':
            appendcout();
            break;
        case 'e':
            deletecout();
            break;
        case 'l':
            list_status();
            break;
        case 'c':
            col_status();
            break;
        case 'f':
            exit(1);
            break;
        default:
            cout << "Eliga una opción valida!!" << endl;
            break;
        }
    }

    return 0;
}



