public class SingleLinkedList{
    private Node head;
    private Node tail;
    private int length = 0;

    public SingleLinkedList(){
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    public Node getHead() {
        return head;
    }

    public Node getTail() {
        return tail;
    }

    public int getLength() {
        return length;
    }

    public void setHead(Node head) {
        this.head = head;
    }

    public void setTail(Node tail) {
        this.tail = tail;
    }

    public void insertEnd(int data){
        Node node = new Node(data);

        //if list is empty
        if (this.length == 0){
            setHead(node);
            setTail(node);
        }
        else {
            tail.setNext(node);
            tail = node;
            tail.setNext(null);
        }
        ++this.length;

    }

    public void insertInIndx(int data, int indx){

        //index at tail
        if (indx >= this.length){
            insertEnd(data);
            return;
        }

        //invalid index
        if (indx < 0){
            return;
        }

        Node node = new Node(data);

        //insert at head
        if (indx == 0){
            node.setNext(this.head);
            this.head = node;
            this.length++;
            return;
        }

        //insert before tail
        Node prev = getNthNode(indx - 1);
        if (indx == this.length - 1){
            prev.setNext(node);
            node.setNext(this.tail);
            this.length++;
            return;
        }

        //insert at middle
        Node next = getNthNode(indx);
        prev.setNext(node);
        node.setNext(next);
        this.length++;
    }

    //returns the first node have the wanted data.
    public int searchNode(int data){
        int nodeIndx = 0;
        for (Node curr = this.head; curr != null; curr = curr.getNext()){
            if (curr.getData() == data){
                return nodeIndx;
            }
            ++nodeIndx;
        }
        return -1;
    }

    private void swapNode(Node node1, Node node2){
        int temp = node1.getData();
        node1.setData(node2.getData());
        node2.setData(temp);
    }
    public int improveSearch(int data){
        int nodeIndx = 0;
        for (Node curr = this.head, prev = null; curr != null; prev = curr, curr = curr.getNext()){
            if (curr.getData() == data){

                //if the wanted node found on the head of list, then the prev = null
                if (prev == null && curr == this.head){
                    return nodeIndx;
                }
                swapNode(curr, prev);
                return nodeIndx - 1;

            }
            ++nodeIndx;
        }
        return -1;
    }

    //note that list is zero index
    public Node getNthNode(int nodeIndx){

        if (nodeIndx < 0 || nodeIndx >= this.length){
            return null;
        }
        int cnt = 0;
        for (Node curr = this.head; curr != null; curr = curr.getNext()){
            if (cnt == nodeIndx){
                return curr;
            }
            ++cnt;
        }
        return null;
    }

    public void print(Node curr){
        if (curr == null){
            return;
        }
        System.out.println(curr.getData());
        print(curr.getNext());
    }

    public void printReversed(Node curr){
        if (curr == null){
            return;
        }
        printReversed(curr.getNext());
        System.out.println(curr.getData());
    }

    public void removeNode(int indx){
        //invalid index or empty list
        if (indx >= this.length || this.length == 0){
            return;
        }

        //remove the only node in list
        if (this.length == 1 && indx == 0){
            this.head = this.tail = null;
            this.length--;
            return;
        }

        //remove first node in multi node list
        if (this.length > 1 && indx == 0){
            this.head = head.getNext();
            this.length--;
            return;
        }

        //delete last node in multi node list
        if (indx == this.length - 1 && this.length > 1){
            Node prev = getNthNode(indx - 1);
            prev.setNext(null);
            this.length--;
            return;
        }

        //delete from middle
        Node prev = getNthNode(indx - 1);
        Node next = getNthNode(indx + 1);
        prev.setNext(next);
        this.length--;

    }


}
