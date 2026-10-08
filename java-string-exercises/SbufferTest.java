public class SbufferTest {
    public static void main(String[] args) {
        StringBuffer str = new StringBuffer("Sun & Moon");
        System.out.println("length=" + str.length());
        System.out.println(str.replace(6, 10, "Star"));
        System.out.println(str.reverse());
        System.out.println(str);
    }
}
