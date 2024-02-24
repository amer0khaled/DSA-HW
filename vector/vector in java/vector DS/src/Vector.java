public class Vector {

    private int[] arr;
    private int size;
    private int capacity;

    public Vector(){
        size = 0;
        capacity = 0;
    }

    public Vector(int size){
        if (size < 0){
            this.size = 1;
            this.capacity = 2;
        }
        this.size = size;
        this.capacity = size * 2;
        arr = new int[capacity];
    }

    public int getUserSize(){
        return this.size;
    }

    public void setUserSize(int size){
        if (size > 0){
            this.size = size;
            this.capacity = size * 2;
        }
        else {
            System.out.println("Invalid Size");
        }

    }

    public int getAcualSize(){
        return this.capacity;
    }


    public int getIndex(int indx){
        return this.arr[indx];
    }

    public void setIndex(int indx, int value) {
        this.arr[indx] = value;
    }

    public void printList(){
        for (int i = 0; i < this.capacity; ++i){
            System.out.println("index "+ i +"= " + this.arr[i]);
        }
        System.out.println();
    }

    public int findValue(int value){
        for (int i = 0; i < this.size; ++i){
            if (value == this.arr[i]){
                return value;
            }
        }

        return -1;
    }

    public void pushBack(int value){

        //check if there is available space
        if (this.size == this.capacity){
            expanCapacity();
        }
        this.arr[this.size++] = value;
    }

    private void expanCapacity(){
        // 1- doubling acual size(capacity)
        this.capacity *= 2;
        System.out.println("Expand capacity to " + this.capacity);

        // 2- create a new array
        int[] arr2 = new int[this.capacity];

        //3- copy data into the new array
        for (int i = 0; i < this.size; ++i){
            arr2[i] = this.arr[i];
        }

        //swap arrays
        swap(arr2);

        //delete old array
        arr2 = null;
    }

    private void swap(int[] arr2){
        int[] temp = arr2;
        arr2 = this.arr;
        this.arr = temp;

    }

    public void insertElement(int indx, int value){

        // 1- check if index is valid

        // 2- check for free space
        if (this.size == this.capacity){
            expanCapacity();
        }

        // 3- shift elements to right and free the desired index
        shiftElements(indx);

        // 4- set the desired index with the value
        setIndex(indx, value);

        // 5- increase size
        this.size++;
    }

    private void shiftElements(int indx){
        for (int i = this.size; i > indx; --i){
            arr[i] = arr[i-1];
        }
    }

    public void rightRotate(){
        int lastElement = arr[size - 1];

        for (int i = size - 2; i >= 0; --i){
            arr[i+1] = arr[i];
        }
        arr[0] = lastElement;
    }

    public void leftRotate(){
        int firstElement = arr[0];

        for (int i = 1; i < size; ++i){
            arr[i-1] = arr[i];
        }
        arr[size - 1] = firstElement;
    }

    public void rightRotateWithSteps(int steps){
        int lastElement = 0;

        for (int i = 0; i < steps; ++i){

            lastElement
            for (int j = size-2; j >= 0; --j){
                arr[j+1] = arr[j];
            }
        }


    }



}

