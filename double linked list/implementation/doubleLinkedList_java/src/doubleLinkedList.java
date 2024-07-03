public class doubleLinkedList {
    private Node head;
    private Node tail;
    private int length;

    public doubleLinkedList(){
        this.head = this.tail = null;
        this.length = 0;
    }
    public Node getHead() {
        return this.head;
    }

    public Node getTail() {
        return this.tail;
    }

    public int getLength() {
        return this.length;
    }

    public void setHead(Node head) {
        this.head = head;
    }

    public void setTail(Node tail) {
        this.tail = tail;
    }

    public void printReversed(){
        for (Node curr = this.tail; curr != null; curr = curr.getPrev()){
            System.out.println(curr.getData());
        }
    }

    public void print(){
        for (Node curr = this.head; curr != null; curr = curr.getNext()){
            System.out.println(curr.getData());
        }
    }

    private void linkNode(Node node1, Node node2){
        if (node1 != null)
            node1.setNext(node2);
        if (node2 != null)
            node2.setPrev(node1);
    }
    public void insertEnd(int data){
        //create node
        Node node = new Node(data);

        //if list is empty
        if (this.length == 0){
            this.head = this.tail = node;
            this.length++;
            return;
        }

        //if list is not empty
        linkNode(this.tail, node);
        this.tail = node;
        this.length++;
    }

    public void insertFront(int data){
        //if list is empty
        if (this.length == 0){
            insertEnd(data);
            return;
        }

        //create node
        Node node = new Node(data);

        //if list is not empty
        linkNode(node, this.head);
        this.head = node;
        this.length++;

    }

    private void insertAfter(Node prevNode, int data){
        Node node = new Node(data);
        Node nextNode = prevNode.getNext();
        linkNode(node, nextNode);
        linkNode(prevNode, node);
        this.length++;
    }
    public void insertSorted(int data){
        //if list is empty or head node bigger than my node
        if (this.length == 0 || head.getData() >= data){
            insertFront(data);
            return;
        }

        //if tail node is less than my node
        if (tail.getData() < data){
            insertEnd(data);
            return;
        }

        //find node bigger than my node
        for (Node curr = head; curr != null; curr = curr.getNext()){
            if (curr.getData() >= data){
                Node prevNode = curr.getPrev();
                insertAfter(prevNode, data);
                return;
            }
        }

    }

    public void removeFront(){
        //if list is empty
        if (this.length == 0){
            return;
        }

        //if list has one node
        if (this.length == 1){
            this.head = this.tail = null;
            this.length--;
            return;
        }
        setHead(head.getNext());
        head.setPrev(null);
        this.length--;
    }

    public void removeEnd(){
        //if list is empty
        if (this.length == 0){
            return;
        }

        //if list has only one node
        if (this.length == 1){
            this.head = this.tail = null;
            this.length--;
            return;
        }

        setTail(tail.getPrev());
        tail.setNext(null);
        this.length--;
    }

    public void removeAndLink(Node node){
        if (node == this.head){
            removeFront();
            return;
        }

        if (node == this.tail){
            removeEnd();
            return;
        }

        linkNode(node.getPrev(), node.getNext());
        this.length--;
    }

    //returns the first desired value in the list
    public Node searchByValue(int value){
        for (Node curr = this.head; curr != null; curr = curr.getNext()){
            if (curr.getData() == value){
                return curr;
            }
        }
        return null;
    }

    public Node searchByIndex(int index){
        if (index >= this.length){
            return this.tail;
        }
        int cnt = 0;
        for (Node curr = this.head; curr != null; curr = curr.getNext()){
            if (cnt == index){
                return curr;
            }
            cnt++;
        }
        return null;
    }

    public void removeWithKey(int value){
        Node node = searchByValue(value);

        //check if node is found or not
        if (node == null){
            return;
        }
        removeAndLink(node);
    }

}
