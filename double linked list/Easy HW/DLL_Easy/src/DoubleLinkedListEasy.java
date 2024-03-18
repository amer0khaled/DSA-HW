public class DoubleLinkedListEasy {
    public void deleteAllNodesWithKey(doubleLinkedList list, int value){
        for (Node curr = list.getHead(); curr != null; curr = curr.getNext()){
            if (curr.getData() == value){
                list.removeAndLink(curr);
            }
        }
    }

    public void deleteEvenPositions(doubleLinkedList list){
        int cnt = 1;
        for (Node curr = list.getHead(); curr != null; curr = curr.getNext()){
            if (cnt % 2 == 0){
                list.removeAndLink(curr);
            }
            cnt++;
        }
    }

    public void deleteOddPositions(doubleLinkedList list){
        int cnt = 1;
        for (Node curr = list.getHead(); curr != null; curr = curr.getNext()){
            if (cnt % 2 != 0){
                list.removeAndLink(curr);
            }
            cnt++;
        }
    }

    public boolean isPalindrome(doubleLinkedList list){
        for (Node front = list.getHead(), back = list.getTail(); front != back; front = front.getNext(), back = back.getPrev()){
            if (front.getData() != back.getData()){
                return false;
            }
        }
        return true;
    }
}
