import java.util.*;
import java.lang.*;
import java.io.*;

class classOne {
    int rollNo;
    String Name;
    String City;

    classOne(int rollno, String name, String city) {
        this.rollNo = rollno;
        this.Name = name;
        this.City = city;
    }

    public String toString() { // overriding the toString() method
        return rollNo + " " + Name + " " + City;
    }
}

class classTwo {
    void inhertExample() {
        System.out.println("I'm displaying from parent class.");
    }
}

class InheritTwo extends classTwo {
    @Override
    void inhertExample() {
        System.out.println("I'm displaying from child class.");
    }
}


class classThree implements Comparable<classThree> {
    private double rating;
    private String name;
    private int year;

    // Used to sort movies by year
    public int compareTo(classThree m) {
        return this.year - m.year;
    }

    // Constructor
    public classThree(String nm, double rt, int yr) {
        this.name = nm;
        this.rating = rt;
        this.year = yr;
    }

    // Getter methods for accessing private data
    public double getRating() {
        return rating;
    }

    public String getName() {
        return name;
    }

    public int getYear() {
        return year;
    }
}


abstract class abstClass {
    abstract void disp();
}

class classFour extends abstClass {
    void disp() {
        System.out.println("I'm in Class Four");
    }
}

class classFive extends abstClass {
    void disp() {
        System.out.println("I'm in class Five");
    }
}


interface interOne {
    final int a = 10;
    static void display() {
        System.out.println("Interface Saying Hello");
    }
}


public class Main {
    public static void main(String args[]) {
        classOne o1 = new classOne(001, "Harry", "HYD");

        // clone
        System.out.println("Name before clone: " + o1.Name);
        classOne oo1 = o1;
        oo1.Name = "Harry Potter";
        System.out.println("Name after clone: " + oo1.Name);

        /*
         3. Show inheritance examples and overriding/overloading of any method you like 
         4. Give example of runtime polymorphism.
        */
         
        // Inheritance, overiding and method and RUN TIME POLYMORPHISM
         
        // If a Parent type reference refers to a Parent object, then Parent's show is called.
        classTwo ob2 = new classTwo();
        ob2.inhertExample();
         
        // If a Parent type reference refers to a Child object Child's show() is called. 
        // This is called RUN TIME POLYMORPHISM. 
        classTwo obb2 = new InheritTwo();
        obb2.inhertExample();
          

        //Interface Example:
        interOne.display();


        //Abstract Class Example
        abstClass ab = new classFive();
        ab.disp();

        /*
         5. Implement Comparable interface and write 1 comparator. For what will you use it? 
         Ans: Java provides two interfaces to sort objects using data members of the class:
                1.Comparable
                2.Comparator
            A comparable object is capable of comparing itself with another object. 
            The class itself must implements the java.lang.Comparable interface to compare its instances. 
            This method is used to compare the given object with the current object. 
            The compareTo() method returns an int value. The value can be either positive, negative, or zero. 
            So now we are well acquainted with the theoretical knowledge of Comparable interface in Java and compareTo method.
        */
        
        ArrayList<classThree> list = new ArrayList<classThree>();
        list.add(new classThree("Force Awakens", 8.3, 2015));
        list.add(new classThree("Star Wars", 8.7, 1977));
        list.add(new classThree("Empire Strikes Back", 8.8, 1980));
        list.add(new classThree("Return of the Jedi", 8.4, 1983));

        Collections.sort(list);

        System.out.println("Movies after sorting : ");
        for (classThree movie : list) {
            System.out.println(movie.getName() + " " + movie.getRating() + " " + movie.getYear());
        }

        /*
        6. Give 1 example for dependency, aggregation, composition, generalization, realization associations?
        Association: Association is a relationship between two objects. 
                     In other words, association defines the multiplicity between objects.
                     You may be aware of one-to-one, one-to-many, many-to-one, many-to-many all these words define an association between objects.
        Example: A Student and a Faculty are having an association.
        
        Aggregation: Aggregation is a special case of association. A directional association between objects.
                     When an object "has-a" another object, then you have got an aggregation between them. 
                     Direction between them specified which object contains the other object. 
                     Aggregation is also called a "Has-a" relationship.
         
        Composition: Composition is a special case of aggregation. In a more specific manner, a restricted aggregation is called composition.
                     When an object contains the other object, if the contained object cannot exist without the existence of container object, 
                     then it is called composition.
        Example: A class contains students. A student cannot exist without a class. There exists composition between class and students.
        
        Realization: Realization is a relationship between the blueprint class and the object containing its respective implementation level details. 
                     This object is said to realize the blueprint class. 
                     In other words, you can understand this as the relationship between the interface and the implementing class.
        Example: A particular model of a car "GTB Fiorano" that implements the blueprint of a car realizes the abstraction.
        
        Dependancy: Change in structure or behaviour of a class affects the other related class, 
                    then there is a dependency between those two classes. 
                    It need not be the same vice-versa. When one class contains the other class it this happens.
        Example: Relationship between shape and circle is dependency.
        
        Generalization: Generalization uses a "is-a" relationship from a specialization to the generalization class.
                        Common structure and behaviour are used from the specializtion to the generalized class.
                        At a very broader level you can understand this as inheritance.
                        why I take the term inheritance is, you can relate this term very well.
                        Generalization is also called a "is-a" relationship.
        Example: Consider there exists a class named Person. A student is a person. A faculty is a person.
                 Therefore here the relationship between student and person, similarly faculty and person is generalization.
        */

        /*
        7. Apply________ design patterns. Describe situations where you can use them.
        A design patterns are well-proved solution for solving the specific problem/task.
        
        Use Example: Suppose you want to create a class for which only a single instance (or object) should be created and that single object can be used by all other classes.
        Solution: Singleton design pattern is the best solution of above specific problem. 
                  So, every design pattern has some specification or set of rules for solving the problems. 
                  What are those specifications, you will see later in the types of design patterns.
        
        Design Patterns:
            1. Creational
            2. Structural
            3. Behavioral
        
        */

        /*
         * 8. Which collections will you use there and for what? 
         * Ans: Iterator: equentially access the elements of a collection.
         */
    }
}

