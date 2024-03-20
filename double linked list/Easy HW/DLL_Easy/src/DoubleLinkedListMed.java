public class DoubleLinkedListMed {
    public int findMiddle(doubleLinkedList list){
        Node front = list.getHead(), back = list.getTail();

        while (front != back && front.getNext() != back){
            front = front.getNext();
            back = back.getPrev();
        }
        return back.getData();
    }

}
