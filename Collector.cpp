#include <iostream>
#include <cmath>
#include "Node.cpp"
using namespace std;



class Collector {

public:
    int size;
    Node* start;

    Collector() {
        size = 0;
        start = NULL;
    }

    void append(Node* node) {

        
        node->set_next(start);
        start = node;
        size++;
        
    }

    void deleteLast() {
        if (size == 0)
        {
            cout << "" << endl;
        }
        else if (size == 1)
        {
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
                cout << "|" << tmp << "|-->";
                tmp = tmp->get_next();
            }
            cout << " " << endl;

        }
    }






};

