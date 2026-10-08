public class Example2 {
    String str = new String("good");
    char[] ch = {'a', 'b', 'c'};

    public static void main(String[] args) {
        Example2 ex = new Example2();
        ex.change(ex.str, ex.ch);
        System.out.println(ex.str);
        System.out.println(ex.ch);
    }

    public void change(String str, char[] ch) {
        str = str.toUpperCase();
        ch = new char[]{'m', 'n'};
    }
}
