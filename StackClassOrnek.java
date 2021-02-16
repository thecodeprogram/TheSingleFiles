/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 16.02.2021
*/
package javacalisma;

import java.util.Stack;

/**
 *
 * @author burak
 */
public class StackClassOrnek {
    
    public static void main(String[] args) {
        Stack<String> s = new Stack();
        
        //Push ile stack koleksiyonuna verileri ekleyebiliriz
        s.push("Burak");
        s.push("Hamdi");
        s.push("TUFAN");
        s.push("TheCodeProgram");
        
        //Normal bir koleksiyon gibi yazdırılabilir
        System.out.println("Stack koleksiyonu : " + s);
        
        //search ile bir nesnenin koleksiyon içerisindeki konumunu bulabiliriz.
        int pos = s.search("Hamdi");
        System.out.println("Eleman indexi : " + pos);
        
        //peek komutu ile koleksiyon içerisindeki en üstte bulunan eleman, 
        //koleksiyondan kaldırılmadan alınabilir.
        String peekElement = s.peek();
        System.out.println("En üstteki eleman : " + peekElement);
        
        

        //Vector sınıfından kalıtım alınan size komutu ile eleman sayısı alınabilir
        int ilkSize = s.size();
        System.out.println("Pop öncesi eleman sayısı : " + ilkSize);
        
        //empty ile stack koleksiyonunun boş olduğunu kontrol edebiliriz
        //pop ile stack içerisindeki elemanları tersten okuyup, koleksiyondan kaldırabiliriz
        while(s.empty() == false){
            System.out.println(s.pop());
        }
        
        int sonSize = s.size();
        System.out.println("Pop sonrası eleman sayısı : " + sonSize);
        
        //java.util.EmptyStackException oluşacak.
        System.out.println("Pop sonrası eleman sayısı : " + s.peek());
    }
    
}
