#include <iostream>
#include <cassert>

using namespace std;

class Stack_ArrayBased{

private:
    int size {}; // size of stack
    int top {}; // index of top element in stack'
    int *arr {};

public:

     Stack_ArrayBased(int size) : size(size), top(-1), arr(new int[size]){}

    int getTop() {
        return top;
    }

    int getSize() {
        return size;
    }

    bool isFull() {
        return (top >= size - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void displayStack() {
        for (int i = top; i >= 0; --i){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
    void push(int val) {

        //check if array full
        assert(("stack is full",!isFull()));

        //increase top then insert the new element
        arr[++top] = val;
        
    }

    int pop() {
        //check if array is empty
        assert(("stack is empty",!isEmpty()));

        //get element then decrease top
        int val = arr[top--];
        return val;
    }
};

/*
int main() {

    Stack_ArrayBased stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    stack.displayStack();

    cout << stack.pop();
    cout << stack.pop();
    cout << stack.pop();
    cout << stack.pop();
    cout << stack.pop();


    return 0;
}
*/