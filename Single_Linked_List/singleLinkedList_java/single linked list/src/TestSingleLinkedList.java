public class TestSingleLinkedList {

    public static void main(String[] args) {

        SingleLinkedList list = new SingleLinkedList();

        for (int val = 10; val < 60; val += 10){
            list.insertEnd(val);
        }

        System.out.println("\nlist before:\n");
        list.print(list.getHead());

        list.removeNode(3);

        System.out.println("\nlist after:\n");
        list.print(list.getHead());

        System.out.println("length = "+ list.getLength());

        System.out.println("\n\nNo Run Time Error\n\n");

    }
}