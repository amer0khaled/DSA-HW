#include <iostream>
#include <cassert>
using namespace std;

class Vector
{

private:
    int *arr;
    int size;     // user size
    int capacity; // actual size

    void swap(int **x, int **y)
    {
        int *temp = *x;
        *x = *y;
        *y = temp;
    }

    void swapElements(int indx1, int indx2){
        int temp = arr[indx1];
        arr[indx1] = arr[indx2];
        arr[indx2] = temp;
    }

    void expandCapacity()
    {
        // 1- doubling the acual array size
        capacity *= 2;

        cout << "Expand capacity to " << capacity << endl;

        // 2- create a new dynamic array of bigger size
        int *arr2 = new int[capacity];

        // 3- copy old data into the new array
        for (int i = 0; i < size; ++i)
            arr2[i] = arr[i];

        // 4- swap the pointers
        swap(&arr, &arr2);

        // 5- delete old array
        delete[] arr2;
    }


    //shifts the elements to right
    void shiftElements(int indx)
    {
        for (int i = size; i > indx; --i)
        {
            arr[i] = arr[i - 1];
        }
    }

    /*shifts specific element to left ,not the 
    whole array*/
    void shiftElementLeft(int index){
        if (index > 0){
            swapElements(index-1, index);
        }
    }

public:
    Vector() : arr(nullptr), size(0), capacity(0) {}

    Vector(int size) : size(size), arr(nullptr), capacity(size * 2)
    {
        if (size < 0)
        {
            size = 1;
            capacity = 2;
        }

        arr = new int[capacity];
    }

    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }

    int get(int indx)
    {
        assert(indx >= 0 && indx < size);
        return arr[indx];
    }

    void set(int indx, int value)
    {
        assert(indx >= 0 && indx < size);
        arr[indx] = value;
    }

    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << "index " << i << "= " << arr[i] << endl;
        }
    }

    int find(int value)
    {
        for (int i = 0; i < size; ++i)
        {
            if (value == arr[i])
            {
                return i;
            }
        }
        return -1;
    }

    int getUsaerSize()
    {
        return size;
    }

    int getAcualSize()
    {
        return capacity;
    }

    void pushBack(int value)
    {
        // 1- check that there is available space
        if (size == capacity)
            expandCapacity();

        arr[size++] = value;
    }

    void insert(int indx, int value)
    {
        // check if indx if valid
        assert(indx >= 0 && indx < size);

        // 1- check that there is available space
        if (size == capacity)
            expandCapacity();

        // 2- shift elements and free the desired index
        shiftElements(indx);

        // 3- set index with value
        set(indx, value);

        // 4- increase size
        size++;
    }

    void rightRotate()
    {
        if (size <= 1)
        {
            return;
        }
        int lastElement = arr[size - 1];

        for (int i = size - 2; i >= 0; --i)
        {
            arr[i + 1] = arr[i];
        }

        arr[0] = lastElement;
    }

    void leftRotate()
    {
        if (size <= 1)
        {
            return;
        }

        int firstElemnt = arr[0];

        for (int i = 0; i < size; ++i)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = firstElemnt;
    }

    bool findTransPosition(int value){
        int valueIndex = find(value);
        if (valueIndex != -1){
            shiftElementLeft(valueIndex);
            return true;
        }
        else{
            return false;
        }
    }



};

int main()
{
    Vector obj(3);

    cout << "user size: " << obj.getUsaerSize() << endl;
    cout << "acual size: " << obj.getAcualSize() << endl;

    for (int i = 0, value = 1; i < obj.getUsaerSize(); ++i, value += 1)
    {
        obj.set(i, value);
    }

    obj.print();

    obj.findTransPosition(3);
    obj.findTransPosition(3);

    obj.print();

    cout << "user size: " << obj.getUsaerSize() << endl;
    cout << "acual size: " << obj.getAcualSize() << endl;

    return 0;
}