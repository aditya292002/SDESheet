
// public class A {
//     public static void main(String[] args) {
//         Employee emp1 = new Manager();
//         emp1.opinion("Aditya");
//     }
// }

// class Employee {
//     String name;
//     int salary;
    
//     Employee() {
//         System.out.println("I am an Employee");
//     }

//     void opinion(String your_opinion) {
//         System.out.println("Employee's opinion");
//         // return "This is Employee's Opinion";
//     }
// }

// class Manager extends Employee {
//     String department;
    
//     Manager() {
//         System.out.println("I am a Manager");i
//     }

//     void opinion() {
//         System.out.println("Manager's opinion");
//     }
// }


class A {
    public static void main(String[] args) {
        Parent p = new Child();
        // p.greeting();
        System.out.println(p.a);
        System.out.println(p.b);

    }
}
class Parent {
    int a;
    int b;
    Parent () {
        a = 10;
        b = 20;
    }
    void greeting() {
        System.out.println("This is Parent");
    }    
}

class Child extends Parent{
    // void greeting() {
    //     System.out.println("This is child");
    // }
    Child() {
        a = 30;
    }
}