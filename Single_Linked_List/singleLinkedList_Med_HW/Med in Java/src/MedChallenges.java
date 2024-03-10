public class MedChallenges {

    public void removeDuplicate(SingleLinkedList list){

        int listLen = list.getLength();

        if (listLen <= 1){
            return;
        }

        for (Node curr1 = list.getHead(); curr1 != null; curr1 = curr1.getNext()){
            for (Node curr2 = curr1.getNext(), prev = curr1; curr2 != null; ){

                if (curr1.getData() == curr2.getData()){
                    Node nextOfCurr2 = curr2.getNext();
                    prev.setNext(nextOfCurr2);
                    curr2 = prev.getNext();
                }
                else {
                    prev = curr2;
                    curr2 = curr2.getNext();
                }
            }
        }
    }

    public void removeLastOccurance(SingleLinkedList list, int key){
        if (list.getLength() <= 0){
            return;
        }

        int cnt = 0;
        int lastOccurance = -1;

        for (Node curr = list.getHead(); curr != null; curr = curr.getNext()){
            if (key == curr.getData()){
                lastOccurance = cnt;
            }
            ++cnt;
        }

        if (lastOccurance == -1){
            return;
        }
        list.removeNode(lastOccurance);
    }

    public void moveToBack(SingleLinkedList list, int key){
        int len = list.getLength();

        if (len <= 1){
            return;
        }

        int cnt = 1;
        for (Node curr = list.getHead(); len > 0; len--){
            if (key == curr.getData()){
                curr = curr.getNext();
                list.insertEnd(key);
                --cnt;
                list.removeNode(cnt);
            }
            else {
                curr = curr.getNext();
            }
            ++cnt;
        }
    }


}
