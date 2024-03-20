public class Main {
    public static void main(String[] args) {

        doubleLinkedList list = new doubleLinkedList();

        for (int val = 10; val  < 60; val += 10){
            list.insertEnd(val);
        }

        System.out.println("before: ");
        list.print();

        list.removeWithKey(10);

        System.out.println("after: ");
        list.print();

        System.out.println("No Run Time Error");
    }
}