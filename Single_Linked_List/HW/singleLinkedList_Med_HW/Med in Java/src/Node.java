public class Node {

    private int data = 0;
    private Node next = null;

    public Node(){
        this.data = 0;
        this.next = null;
    }
    public Node(int data){
        this.data = data;
        this.next = null;
    }


    public int getData() {
        return data;
    }

    public Node getNext() {
        return next;
    }

    public void setData(int data) {
        this.data = data;
    }

    public void setNext(Node next) {
        this.next = next;
    }


}
