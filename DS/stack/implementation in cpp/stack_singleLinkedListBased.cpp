#include <iostream>
#include <cassert>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


class Node{

private:
    int data;
    Node *next;

public:

    Node(int val) : data(val), next(nullptr){}

    int getData(){
        return data;
    }

    void setData(int data){
        this->data = data;
    }

    void setNext(Node *node){
        next = node;
    }

    Node* getNext(){
        return next;
    }


};


class Stack_LinkedListBased{
private:
    Node *head {};

public:

    bool isEmpty(){
        return (!head);
    }

    void push(int val){
        //create new node
        Node *node = new Node(val);

        //new node points to it's previous node
        node->setNext(head);

        //update head
        head = node;
    }

    int pop(){
        //if stack is empty
        assert(("stack is empty",!isEmpty()));

        int val = head->getData();
        Node*curr = head;

        head = head->getNext();

        delete curr;

        return val;
    }

    int peek(){
        assert(("stack is empty",!isEmpty()));
        return head->getData();
    }


};



int main(){

    Stack_LinkedListBased stack;

   stack.push(10);
   stack.push(20);
   stack.push(30);
   stack.push(40);
   stack.push(50);

    cout << stack.pop() << "\n";    

    return 0;
}