public class Node {
    private int data;
    private Node next;
    private Node prev;

    public Node(){
        this.next = this.prev = null;
        this.data = 0;
    }

    public Node(int data){
        this.data = data;
        this.next = this.prev = null;
    }

    public int getData(){
        return this.data;
    }

    public void setData(int data){
        this.data = data;
    }

    public Node getNext() {
        return this.next;
    }

    public Node getPrev() {
        return this.prev;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public void setPrev(Node prev) {
        this.prev = prev;
    }
}
