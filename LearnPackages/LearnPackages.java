package LearnPackages;
// import java.util.*;


public class LearnPackages {
    
    static class LearnStatic {
        String message = "Hi! I am static class";
    }

    static void static_method() {
        LearnStatic obj = new LearnStatic();
        System.out.println(obj.message);
    }
    
    public static void main(String[] args) {
        // Greeting g = new Greeting();
        // g.name = "Johnny Sins";
        // g.greet();
        LearnPackages.static_method();
    }
}
