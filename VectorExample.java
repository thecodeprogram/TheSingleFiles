/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 13.02.2021
*/

package javacalisma;

import java.util.ArrayList;
import java.util.Vector;

/**
 *
 * @author burak
 */
public class VectorExample {
    
    public static void main(String[] args){
        
        int size = 33;
        int capIncrement = 55;
        
        Vector v1 = new Vector();
        Vector v2 = new Vector(size);
        Vector v3 = new Vector(size, capIncrement);
        
        ArrayList ar = new ArrayList();
        Vector v4 = new Vector(ar);
        
        //vectorExample1();
        //vectorExample2();
        vectorCapacityIncrement();
        
    }

    public static void vectorExample1(){
        
        //String sınıfı ile bir vector başlatılıyor
        Vector<String> names = new Vector<String>();
        
        //Oluşturulan vector sınıfına String eleman ekleniyor
        names.add("Burak");
        names.add("Hamdi");
        names.add("Tufan");
        names.add("The");
        names.add("Code");
        names.add("Program");
        
        //Eklemeden sonra vector dizisi içerikleri
        System.out.println("Vector içeriği : " + names);
        System.out.println("Vector boyutu : " + names.size() );
        
        //Vektörden eleman silme
        names.remove(1);
        names.remove(3);
        
        //Vektörden eleman silme işleminden sonra vektör bilgileri
        System.out.println("Vector içeriği : " + names);
        System.out.println("Vector boyutu : " + names.size() );     
    }
    
    public static void vectorCapacityIncrement(){
        //Size 2 ve capacity increment 5 olan bir vector başlattık
        Vector vec = new Vector(2, 5);
        //For döngüsü içeirsinde değer ekleme esnasında size değeri capacity i geçerse
        //increment değeri kadar arttırılması beklenmektedir.
        for(int i=0; i<4; i++){
            vec.add(i);
            System.out.println("Vector size : " + vec.size() + " / Vector Capacity : " + vec.capacity());
        }
    }
    
    public static void vectorExample2(){
        
        //Bir sınıf belirtmeden vector başlattık
        Vector vec = new Vector();
        
        //String bazı değerler ekledik
        vec.add("Burak");
        vec.add("Hamdi");
        vec.add("TUFAN");
        
        //Integer bazı değerler ekledik
        vec.add(33);
        vec.add(41);
        vec.add(54);
        
        //Boolean bazı değerler ekledik
        vec.add(true);
        vec.add(false);
        vec.add(true);
        
        System.out.println("Vector içeriği : " + vec);
        System.out.println("Vector boyutu : " + vec.size() );   
        
        //Vector içerisindeki elemanların değerlerini değiştirelim
        vec.set(0, "The");
        vec.set(1, "Code");
        vec.set(2, "Program");
        
        System.out.println("Vector içeriği : " + vec);
        System.out.println("Vector boyutu : " + vec.size() );   
 
    }
    
    public static void forLoopsWithVector(){
        
        Vector<String> v = new Vector<>();
        v.add("Burak");
        v.add("Hamdi");
        v.add("Tufan");
        
        for(int i=0; i<v.size(); i++){
            System.out.println(v.get(i));
        }
        
        for(Object o : v){
            System.out.println(o);
        }
    }
 
}
