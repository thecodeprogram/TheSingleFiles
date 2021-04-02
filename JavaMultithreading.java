/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 02.04.2021
*/
package javacalisma;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author burak
 */
public class JavaMultithreading {
    
    public static void main(String[] args) {
        String[] arr = { "Burak" ,"Hamdi" ,"TUFAN" ,"The" ,"Code" ,"Program" };
        for(int i=0; i<arr.length; i++){
            new TheMultiCounter(arr[i]).start();
        }
    }
    
}

class TheMultiCounter extends Thread{
    
    int counter = 0;
    String threadName = "";
    
    public TheMultiCounter(String threadName){
        this.threadName = "Thread " + threadName;
    }
    
    public void run(){
        while(true){
            counter++;
            System.out.println(threadName + " : " +counter);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(TheCounterWithThread.class.getName())
                        .log(Level.SEVERE, null, ex);
            }
        }
    
    }
}

class TheCounterWithThread extends Thread{
    
    int counter = 0;
    
    public TheCounterWithThread(int startFrom){
        this.counter = startFrom;
    }
    
    public void run(){
        while(true){
            counter++;
            System.out.println(counter);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(TheCounterWithThread.class.getName())
                        .log(Level.SEVERE, null, ex);
            }
        }
    
    }
}

class TheCounterWithRunnable implements Runnable{
    
     int counter = 0;
    
    public TheCounterWithRunnable(int startFrom){
        this.counter = startFrom;
    }

    @Override
    public void run() {
        while(true){
            counter++;
            System.out.println(counter);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(TheCounterWithRunnable.class.getName())
                        .log(Level.SEVERE, null, ex);
            }
        }
    }

}
