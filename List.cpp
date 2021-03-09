#include <iostream>
#include <cmath>
#include "Node.cpp"
using namespace std;

//List class
class List {
public:
    //Atributes
    Node* start;
    int size;

    //Constructor
    List() {
        start = NULL;
        size = 0;
    }

    //Append element to list
    void append(int data) {

        if (start == NULL)
        {
            start = new Node(data);
            size++;
        }
        else
        {    
            Node* newNode = new Node(data);
            newNode->set_next(start);
            start = newNode;
            size++;
        }


    }


    //Delete element from list
    void deleteElem(int num) {
        
        if (size == 0)
        {
            cout << "Lista esta vacia!!" << endl;
        }
        else if (size == 1 )
        {
            
            if (start->get_data() == num)
            {    
                
                delete start;
                start = NULL;
                size--;
            }
            else {
                cout << "Elemento no esta en la lista" << endl;
            }
        
        }
        else {
            Node* tmp = start;

            if (tmp->get_data() == num)
            {
                start = tmp->get_next();
                delete tmp;
                size--;
            }
            else {
                while (tmp != NULL)
                {
                    if (tmp->get_next()->get_data() == num)
                    {
                        Node* del = tmp->get_next();
                        tmp->set_next(del->get_next());
                        delete del;
                        size--;
                        break;
                    }
                    else {
                        tmp = tmp->get_next();

                    }
                }
                
            }
        }
    }

    //Delete last element
    void deleteLast() {
        if (size == 0)
        {
            cout << "" << endl;
        }
        else if (size == 1)
        {
            delete start;
            start = NULL;
            size--;

        }
        else {
            Node* tmp = start;

            while (tmp->get_next()->get_next() != NULL)
            {
                tmp = tmp->get_next();
            }

            Node* del = tmp->get_next();
            tmp->set_next(NULL);
            delete del;
            size--;
        }

    }


    //first node getter
    Node* get_first() {
        return start;
    }

    //Last node getter
    Node* get_last() {
        if (size == 1)
        {
            return start;
        }
        else {
            Node* tmp = start;

            while (tmp->get_next() != NULL)
            {
                tmp = tmp->get_next();
            }
            return tmp;
        }
    }

    //return if list is empty
    bool empty() {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //Size getter
    int get_size() {
        return size;
    }

    //print list
    void printList() {

        if (size == 0)
        {
            cout << "Lista Vacia" << endl;

        }
        else {

            Node* tmp = start;

            while (tmp != NULL)
            {
                cout << "|" << tmp->get_data() << " : "<< tmp << "|-->";
                tmp = tmp->get_next();
            }
            cout << " " << endl;

        }
    }
};

