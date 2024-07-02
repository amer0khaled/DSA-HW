public class Main {
    public static void main(String[] args) {

        SingleLinkedList list = new SingleLinkedList();

//        for (int val = 10; val < 60; val += 10){
//            list.insertEnd(val);
//        }

        list.insertEnd(1);
        list.insertEnd(2);
        list.insertEnd(3);
        list.insertEnd(1);
        list.insertEnd(2);
        list.insertEnd(4);
        list.insertEnd(1);
        list.insertEnd(7);
        list.insertEnd(1);

        System.out.println("\nlist before:\n");
        list.print(list.getHead());

        MedChallenges obj = new MedChallenges();

        obj.moveToBack(list, 1);

        System.out.println("\nlist after:\n");
        list.print(list.getHead());
    }


}