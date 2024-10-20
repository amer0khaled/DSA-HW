#include <algorithm>
#include <iostream>
#include <cassert>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stack>
#include <vector>

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

string reverse_str(string s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
        char temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
    return s;
}

string removeDuplicates(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (st.empty())
            st.push(s[i]);
        else {
            if (st.top() == s[i])
                    st.pop();
            else
                st.push(s[i]);
        }
    }
    string res = "";
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }

    return res;
}

bool opposite_dir(int i, int j) {
    return (i & (1 << 31)) != (j & (1 << 31));
}

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for (int i = 0; i < asteroids.size(); i++) {
        if (st.empty())
            st.push(asteroids[i]);
        else {

            if (opposite_dir(st.top(), asteroids[i])) {
                while (opposite_dir(st.top(), asteroids[i]) && st.top() <= abs(asteroids[i]))
                    st.pop();
            }
            else
                st.push(asteroids[i]);
        }
    }
    vector<int> res {};
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}


int main(){

    vector<int> asteroids = {5, 10, -5};
    auto res = asteroidCollision(asteroids);

    for (int)

    return 0;
}