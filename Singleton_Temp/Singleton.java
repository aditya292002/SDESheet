package Singleton_Temp;

public class Singleton {
    int a;
    String b;
    private Singleton(){};  // private constructor -- no object of the class can be created
    private static Singleton obj = new Singleton(); // private obj -- can't be accessed directly
    
    public static Singleton getInstance() {  // we need to access this function without creating object. 
        if(obj == null) {                          // Hence "static"
            obj = new Singleton();
        }
        return obj;
    }
}
