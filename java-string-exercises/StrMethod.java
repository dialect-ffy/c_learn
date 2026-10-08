public class StrMethod {
    public static void main(String[] args) {
        String str = "Hello World!";
        System.out.println("charAt(6)=" + str.charAt(6));
        System.out.println("length=" + str.length());
        System.out.println("sub string=" + str.substring(6));
        System.out.println("start with \"He\"=" + str.startsWith("He"));
        System.out.println("upper case=" + str.toUpperCase());
        System.out.println("\"World\" appares at " + str.indexOf("World", 0)
                + " in \"" + str + "\"");
    }
}
