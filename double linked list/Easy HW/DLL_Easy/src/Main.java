public class Main {
    public static void main(String[] args) {

        doubleLinkedList list = new doubleLinkedList();
        list.insertEnd(1);
        list.insertEnd(15);
        list.insertEnd(99);
        list.insertEnd(1);


        System.out.println("List Before:");
        list.print();

        DoubleLinkedListMed obj = new DoubleLinkedListMed();
        obj.swapForwardBackward(list, 1);


        System.out.println("List After:");
        list.print();

        System.out.println("\nNo Run Time Error\n");
    }
}