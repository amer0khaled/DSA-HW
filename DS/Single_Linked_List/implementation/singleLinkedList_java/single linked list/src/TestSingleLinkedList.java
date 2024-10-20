import java.util.LinkedList;
import java.util.Scanner;
import java.util.TreeSet;

public class TestSingleLinkedList {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        SingleLinkedList list = new SingleLinkedList();

        for (int i = 0; i < 5; ++i ) {
            int val = scanner.nextInt();
            list.insertEnd(val);
        }

        list.debugPrintList("list before");
        System.out.println("length: " + list.getLength());


        list.deleteDuplicates(list.getHead());


        list.debugPrintList("\nlist after");
        System.out.println("length: " + list.getLength());

        System.out.println("\n\nNo Run Time Error\n\n");

    }
}