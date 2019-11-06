import java.util.*;
import java.io.*;

class functions {
    public void mystery(HashMap<String, String> map) {
        ArrayList<String> List = new ArrayList<String>();
        for(String key : map.keySet()) {
            if(map.get(key).length() > key.length()) {
                List.add(map.get(key));
            }
            else {
                List.add(0, key);
                List.remove(map.get(key));
            }
        }
        System.out.println(List);
    }
}

public class Main {
    public static void main(String args[]) {
        HashMap<String, String> map1 = new HashMap<String, String>();
        map1.put("horse", "cow"); 
        map1.put("cow", "horse"); 
        map1.put("dog", "cat"); 
        map1.put("ok", "yo");

        HashMap<String, String> map2 = new HashMap<String, String>();
        map2.put("bye", "hello"); 
        map2.put("bird", "dog"); 
        map2.put("hi", "hello"); 
        map2.put("hyena", "hello");
        map2.put("fruit", "meat");

        HashMap<String, String> map3 = new HashMap<String, String>();
        map3.put("a", "b"); 
        map3.put("c", "d"); 
        map3.put("e", "a"); 
        map3.put("ff", "a");
        map3.put("gg", "c");
        map3.put("hhh", "ff");

        functions object = new functions();
        System.out.print("Output for {'horse'='cow','cow'='horse','dog'='cat','ok'='yo'} is : ");
        object.mystery(map1);
        System.out.print("\n\nOutput for {'bye'='hello','bird'='dog','hi'='hello','hyena'='hello','fruit'='meat'} is : ");
        object.mystery(map2);
        System.out.print("\n\nOutput for {'a'='b','c'='d','e'='a','gg'='c','hhh'='ff'} is : ");
        object.mystery(map3);
    }
}