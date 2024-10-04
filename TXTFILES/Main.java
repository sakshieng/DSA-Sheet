//1st que
// public class learning{
//     private static int staticVar = 1;
//     private int nonStaticVar = 2;
//     public static class StaticInnerClass {
//         public void accessLearningClass(){
//             System.out.println("Accessing static variable from StaticInnerClass: " + staticVar);
//         }
//     }
//     public class NonStaticInnerClass {
//         public void accessLearningClass() {
//             System.out.println("Accessing non-static variable from NonStaticInnerClass: " + nonStaticVar);
//         }
//     }public static void main(String[] args) {
//         learning learn = new learning();
//         learning.StaticInnerClass staticInner = new learning.StaticInnerClass();
        
//         learning.NonStaticInnerClass nonStaticInner = learn.new NonStaticInnerClass();

//         staticInner.accessLearningClass();  
//         nonStaticInner.accessLearningClass();
//     }
    
// }

//2nd que
// class ThreadTest extends Thread {
//     public void run() {
//         for (int i = 0; i < 3; i++) {
//             System.out.println("A");
//             System.out.println("B");
//         }
//     }
// }

// class ThreadDemo extends Thread {
//     public void run() {
//         for (int i = 0; i < 3; i++) {
//             System.out.println("C");
//             System.out.println("D");
//         }
//     }
// }

// public class Main {
//     public static void main(String[] args) {
//         ThreadTest t1 = new ThreadTest();
//         ThreadDemo t2 = new ThreadDemo();

//         t1.start();
//         t2.start();
//     }
// }


//3rd que
// class Base {
//     public void print1() {
//         System.out.println("Good");
//     }
// }

// class Parent extends Base {
//     public void print2() {
//         System.out.println("Evening");
//     }
// }

// public class Main {
//     public static void main(String[] args) {
//         Parent p = new Parent();
//         p.print1();
//         p.print2();
//     }
// }


//for referring to the parent class objects -> use super keyword 
//JDBC has SQL PreparedStatement interface which allows batch processing i 

//4th que
// class Base {
//     void show() {
//         System.out.println("show1()");
//     }
// }

// class Derived extends Base {
//     @Override
//     void show() {
//         super.show();
//         System.out.println("show2()");
//     }
// }

// class Main {
//     public static void main(String[] args) {
//         Base obj = new Derived();
//         obj.show();
//     }
// }

//5th que
//to run this program change file name to Demo.java
class Main implements Runnable {
    public void run() {
        System.out.println("Thread is in Running state");
    }

    public static void main(String[] args) {
        Main obj = new Main();
        Thread tobj = new Thread(obj);
        tobj.start();
        //Integer objects are cached for values in the range of -128 to 127
        //when you create Integer objects with values in this range, Java doesn't create a new object each time
        //Instead, it reuses the same object from the cache
        Integer a = 128;
        Integer b = 128;
        System.out.println(a == b); // false
        // Since 128 is outside the cached range, a and b are two different Integer objects even though they have same value
        Integer x = 1;
        Integer y = 1;
        System.out.println(x == y); // true

        System.out.println(a.equals(b)); // true use this method

    }
}

