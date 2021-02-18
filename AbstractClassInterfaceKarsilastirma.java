/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 18.02.2021
*/

package javacalisma;

/**
 *
 * @author burak
 */

interface ikiTekerlek{
    int getWheelCount();
}

interface aracDavranislari{

}

abstract class Araclar implements aracDavranislari{
    abstract void calistir();
    void ureticiyiGetir(){ 
        System.out.println("Thecodeprogram"); 
    };
    
    final public int finalDegisken = 4;
    final public static double finalStaticDegisken = 33;
    static boolean staticDegisken = true;
    
    public int publicDegisken = 5;
    private int privateDegisken = 6;
    protected float protectedDegisken = 7;
}


class Kamyon extends Araclar implements ikiTekerlek{
    
    @Override
    void calistir(){
        System.out.println("Truck sınıfı başlatıldı"); 
    }

    @Override
    public int getWheelCount() {
        int tekerlekSayisi = 2;
        return tekerlekSayisi;
    }
    
    public void herseyiYazdır(){
        ureticiyiGetir();
        calistir();
        
        System.out.println("tekerlek sayısı : " + getWheelCount());
        System.out.println("finalDegisken : " + finalDegisken);
        System.out.println("finalStaticDegisken : " + finalStaticDegisken);
        System.out.println("staticDegisken : " + staticDegisken);
        System.out.println("publicDegisken : " + publicDegisken);
        System.out.println("privateDegisken : " + "Private yazdırılamaz :))");
        System.out.println("protectedDegisken : " + protectedDegisken);
    }
}



//Interface örneği
abstract class Arac{
    abstract String getMarka();
    abstract String getModel();
}

interface AracSahip{
    String getSahip();
}

interface AracKimlik extends AracSahip {
    final static int koltukSayisi = 4;
    String getSasiNo();
}

interface AracIslemler{
    void calistir();
    void durdur();
}



class Murat124 extends Arac implements AracKimlik, AracIslemler{
    
    public int getkoltukSayisi(){ return koltukSayisi; }

    @Override
    public String getSasiNo(){return "33AASASDGSG41545A"; }
    
    @Override
    public String getSahip(){return "Burak Hamdi TUFAN"; }
    
    
    @Override
    public void calistir(){ System.out.println("Araba Çalıştırıldı"); }
    
    @Override
    public void durdur(){ System.out.println("Araba Durduruldu"); }

    @Override
    String getMarka(){return "Murat124"; }
    
    @Override
    String getModel(){return "1995"; }
    
    public void butunOzellikleriYazdır(){
        System.out.println( "Marka : " + getMarka() );
        System.out.println( "Model : " +  getModel() );
        System.out.println( "Sahibi : " +  getSahip() );
        System.out.println( "Sasi No : " +  getSasiNo() );
        System.out.println( "Koltuk Sayisi : " +  getkoltukSayisi() );
    }
}


public class AbstractClassInterfaceKarsilastirma {
    public static void main(String[] args) {
        //Kamyon kamyon = new Kamyon();
        //kamyon.herseyiYazdır();
        
        Murat124 murat124 = new Murat124();
        murat124.butunOzellikleriYazdır();
        murat124.calistir();
        murat124.durdur();
    }
}
