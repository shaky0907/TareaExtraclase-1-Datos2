#include <iostream>
#include <cmath>
#pragma once
using namespace std;

//Node list
class Node{
public:
    //Atributes
    int data;
    Node* next;


    //Simple Constructor
    Node() {
        data = NULL;
        next = NULL;

    }
    //Constructor with argument
    Node(int adata) {
        data = adata;
        next = NULL;

    }

    //data setter
    void set_data(int adata) {
        data = adata;
    }

    //data getter
    int get_data() {
        return data;
    }

    //pointer setter
    void set_next(Node* ptr) {
        next = ptr;
    }


    //pointer getter
    Node* get_next() {
        return next;
    }

    


};




