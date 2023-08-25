package Singleton_Temp;

public class Main {
    public static void main(String[] args) {
        Singleton obj = Singleton.getInstance();
        obj.a = 8;
        Singleton obj1 = Singleton.getInstance();
        System.out.println(obj1.a);
    }
}
