package javacalisma;

/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 13.07.2021
*/

public class JavaSynchronizedExample {
   
    public static void main(String[] args) {
        LoggerClass w = new LoggerClass();

        DriverThread t1 = new DriverThread(w);
        DriverThread t2 = new DriverThread(w);

        t1.start();
        t2.start();
    }
}

class LoggerClass{
    public void msgLog(String msg){
        System.out.println(msg);
    }
}

class DriverThread extends Thread {
    final LoggerClass w;
    
    DriverThread(LoggerClass _w){
        w=_w;
    }

    @Override
    public void run() {
        synchronized(w) {
            System.out.println("İş parcacigi baslatildi");
            for (int i = 0; i < 5; i++) {
                w.msgLog("Mesaj : " + i);
            }
            System.out.println("İş parcacigi sonlandi");
        }
    }
}
