/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 27.02.2021
*/
package javacalisma;


import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.NavigableMap;
import java.util.SortedMap;
import java.util.TreeMap;




/**
 *
 * @author burak
 */
public class TreeMapOrnek {
    
    
    public static void main(String[] args) {
        
        //Initialize treemap and put items in it
        //Treemap nesnesi başlat ve içerisine eleman ekle
        TreeMap<Integer, String> treeMap = new TreeMap<>();
        treeMap.put(1, "Burak");
        treeMap.put(2, "Hamdi");
        treeMap.put(3, "Tufan");
        
        //Initialize HashMap from a Map and put elements in it.
        //Map oluştur ve içine eleman ekle
        Map<Integer,String> map = new HashMap<>();
        map.put(1, "The");
        map.put(2, "Code");
        map.put(3, "Program");
        
        //Initialize a treemap with above Hashmap
        //yukarıdaki Hashmap ile bir treemap başlat
        TreeMap treeMap2 = new TreeMap(map);
        
        System.out.println(treeMap);
        System.out.println(treeMap2);
        
        //Get element with specified key
        //Belirtilen anahtar değer ile eleman bulma
        System.out.println(treeMap.get(2));
        System.out.println(treeMap2.get(2));
        
        
        System.out.println(treeMap.containsKey(1));
        System.out.println(treeMap.containsValue("Hamdi"));
        System.out.println(treeMap.containsValue("harici"));
        //--------------------------------------------------
        
        
        TreeMap<Integer, String> treeMap3 = new TreeMap<>();
        treeMap3.put(3, "Tufan"); 
        treeMap3.put(2, "Hamdi");
        treeMap3.put(1, "Burak");
        
        System.out.println(treeMap3);
        

        NavigableMap<Integer, String> m = Collections.synchronizedNavigableMap(new TreeMap());
        Map<Integer, String> smap = Collections.synchronizedMap(new TreeMap());
        SortedMap<Integer, String> sm = Collections.synchronizedSortedMap(new TreeMap());
        
        
        //Bazı TreeMap metodları
        TreeMap<Integer, String> treeMap4 = new TreeMap<>();
        treeMap4.put(1, "Burak");
        treeMap4.put(2, "Hamdi");
        treeMap4.put(3, "Tufan"); 
        treeMap4.put(4, "The");
        treeMap4.put(5, "Code");
        treeMap4.put(6, "Program");
        
        System.out.println( "KeySet : " + treeMap4.keySet());
        System.out.println( "Values : " + treeMap4.values() );
        System.out.println( "EntrySet : " + treeMap4.entrySet() );
        System.out.println( "SubMap : " + treeMap4.subMap(2, 5));
        System.out.println( "firstKey : " + treeMap4.firstKey());
        System.out.println( "lastKey : " + treeMap4.lastKey());
        
        
        TreeMap shallowClone = (TreeMap)treeMap4.clone();
        System.out.println( "Clone : " + shallowClone);   
        
        shallowClone.remove(2);
        System.out.println( "remove : " + shallowClone);   
        
        shallowClone.clear();
        System.out.println( "clear : " + shallowClone);   
        

    }
    
}



