public class Main {

    public static void main(String[] args){
        Vector obj = new Vector(5);

        System.out.println("user size: " + obj.getUserSize());
        System.out.println("user size: " + obj.getAcualSize());

        for (int i = 0, value = 10; i < obj.getUserSize(); ++i, value += 10)
        {
            obj.setIndex(i, value);
        }

        obj.printList();

        obj.findTransPosition(55);

        obj.printList();

        System.out.println("user size: " + obj.getUserSize());
        System.out.println("user size: " + obj.getAcualSize());

    }
}
