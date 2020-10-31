
/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 31.10.2020
*/


import java.util.ArrayList;
import java.util.LinkedList;


public class LinkedListExample {
    
    public static void main(String[] args) {
        
        //We can add the data with add method.
        LinkedList<String> list = new LinkedList<>();
        list.add("Burak");
        list.add("Hamdi");
        list.add("TUFAN");
        System.out.println(list);
        
        //You can clear all objects in it with clear method
        list.clear();
        System.out.println(list);
        
        //You can also add data start and end of list
        list.add("Code");
        list.addFirst("The");
        list.addLast("Program");
        list.add(1, "Clean");
        System.out.println(list);
        
        //you can remove the data from specified index
        list.remove(1);
        System.out.println("Removed from index : " + list);
        
        //and specified object
        list.remove("Program");
        System.out.println("Removed object : " + list);
        
        
        list.clear();
        System.out.println(list);
        
        //You can initialize a linkedlist from arraylist with its elements
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i=0; i<10; i++){
            arr.add(i);
        }
        
        LinkedList intList = new LinkedList(arr);
        System.out.println(intList);
        
        //you can get the data from index, first or last data
        System.out.println(intList.get(5));
        System.out.println(intList.getFirst());
        System.out.println(intList.getLast());
        
    }
    
}
