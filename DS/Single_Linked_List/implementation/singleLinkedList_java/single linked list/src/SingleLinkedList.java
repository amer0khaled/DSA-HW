import java.util.*;

public class SingleLinkedList{
    private Node head;
    private Node tail;
    private int length = 0;

    public SingleLinkedList(){
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    /******************for testing******************/
    private List<Node> debugData = new ArrayList<>();

    private void debugAddNode(Node node){
        debugData.add(node);
    }

    private void debugRemoveNode(Node node){
        if (debugData.contains(node))
            System.out.println("Node does not exist");
        else
            debugData.remove(node);
    }

    /***********************************************/

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
        debugAddNode(node);
    }

    public void insertInIndx(int data, int indx){

        //invalid index
        if (indx < 0){
            return;
        }

        //index at tail
        if (indx >= this.length){
            insertEnd(data);
            return;
        }

        Node node = new Node(data);

        //insert at head
        if (indx == 0){
            node.setNext(this.head);
            this.head = node;
            this.length++;
            debugAddNode(node);
            return;
        }

        //insert before tail
        Node prev = getNthNode(indx - 1);
        if (indx == this.length - 1){
            prev.setNext(node);
            node.setNext(this.tail);
            this.length++;
            debugAddNode(node);
            return;
        }

        //insert at middle
        Node next = getNthNode(indx);
        prev.setNext(node);
        node.setNext(next);
        debugAddNode(node);
        this.length++;
    }

    //returns the first node have the wanted data.
    public int searchNodeByIndex(int data){
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
        debugVerifyDataIntegrity();
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
        debugVerifyDataIntegrity();
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
            debugVerifyDataIntegrity();
            return;
        }

        //remove first node in multi node list
        if (this.length > 1 && indx == 0){
            this.head = head.getNext();
            this.length--;
            debugVerifyDataIntegrity();
            return;
        }

        //delete last node in multi node list
        if (indx == this.length - 1 && this.length > 1){
            Node prev = getNthNode(indx - 1);
            prev.setNext(null);
            this.length--;
            debugVerifyDataIntegrity();
            return;
        }

        //delete from middle
        Node prev = getNthNode(indx - 1);
        Node next = getNthNode(indx + 1);
        prev.setNext(next);
        this.length--;
        debugVerifyDataIntegrity();

    }

    public int recursiveMax(Node curr) {
        if (curr == null)
            return Integer.MIN_VALUE;
        return Math.max(curr.getData(), recursiveMax(curr.getNext()));
    }

    public void moveBack(int key) {

        int len = this.length;
        if (len <= 1) return;
        int indx = 0;
        while(len-- != 0) {

            //get node
            indx = searchNodeByIndex(key);
            Node node = getNthNode(indx);

            //node at head
            if (node == head) {
                tail.setNext(node);
                head = node.getNext();
                node.setNext(null);
                tail = node;
            }
            //node at middle
            else if (node != tail) {
                Node prev = getNthNode(indx - 1);
                prev.setNext(node.getNext());
                tail.setNext(node);
                node.setNext(null);
                tail = node;
            }
        }
        debugVerifyDataIntegrity();
    }

    public Node deleteDuplicates(Node head) {
        if (head == null) return null;
        HashSet<Integer> visited = new HashSet<>();
        Node cur = head, prev = null;
        while (cur != null) {
            if (visited.contains(cur.getData()))
                // Skip the duplicate node
                prev.setNext(cur.getNext());
            else {
                // add node to visited
                visited.add(cur.getData());
                prev = cur; // move prev
            }
            cur = cur.getNext();
        }
        return head;
    }

    public Node getIntersectionNode(Node headA, Node headB) {
        Node t1 = headA, t2 = headB;
        while (t1 != t2) {
            t1 = t1.getNext();
            t2 = t2.getNext();

            if (t1.equals(t2)) return t1;
            if (t1.equals(null)) t1 = headB;
            if (t2.equals(null)) t2 = headA;
        }
        return t1;
    }

    ////////////////////////for debugging////////////////////////////////

    // Debug method to print node addresses and data
    public void debugPrintAddress() {
        for (Node cur = head; cur != null; cur = cur.getNext()) {
            System.out.print(cur + "," + cur.getData() + "\t");
        }
        System.out.println();
    }

    // Debug method to print details of a specific node
    public void debugPrintNode(Node node, boolean isSeparate) {
        if (isSeparate)
            System.out.print("Sep: ");
        if (node == null) {
            System.out.println("null");
            return;
        }
        System.out.print(node.getData() + " ");
        if (node.getNext() == null)
            System.out.print("X ");
        else
            System.out.print(node.getNext().getData() + " ");

        if (node == head)
            System.out.println("head");
        else if (node == tail)
            System.out.println("tail");
        else
            System.out.println();
    }

    // Debug method to print the entire list with an optional message
    public void debugPrintList(String msg) {
        if (!msg.isEmpty())
            System.out.println(msg);
        for (Node node : debugData) {
            debugPrintNode(node, false);
        }
        System.out.println("************");
    }

    // Convert list to a string representation
    public String debugToString() {
        if (length == 0)
            return "";
        StringBuilder sb = new StringBuilder();
        for (Node cur = head; cur != null; cur = cur.getNext()) {
            sb.append(cur.getData());
            if (cur.getNext() != null)
                sb.append(" ");
        }
        return sb.toString();
    }

    // Verify the integrity of the list
    public void debugVerifyDataIntegrity() {
        if (length == 0) {
            assert head == null;
            assert tail == null;
            return;
        }
        assert head != null;
        assert tail != null;
        assert tail.getNext() == null;

        if (length == 1) {
            assert head == tail;
        } else {
            assert head != tail;

            if (length == 2) {
                assert head.getNext() == tail;
            } else if (length == 3) {
                assert head.getNext().getNext() == tail;
            }
        }

        int len = 0;
        Node prev = null;

        for (Node curr = head; curr != null; prev = curr, curr = curr.getNext()) {
            assert len < 10000; // Infinity cycle prevention
            ++len;
        }

        assert length == len;
        assert prev == tail;
    }

    // Add other necessary methods for your linked list here, like insertion, deletion, etc.



}
