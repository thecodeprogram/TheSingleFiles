/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 14.02.2021
*/
package javacalisma;

/**
 *
 * @author burak
 */


class TheSimpleException extends Exception{
    public TheSimpleException(String exceptionMessage) {
        super(exceptionMessage);
    }
    
    public TheSimpleException(String exceptionMessage, ErrorCodes errorCode) {
        super(exceptionMessage + "" + errorCode);
        System.out.println("Anormal durum log kaydı yapıldı...");
    }
    
    public static enum ErrorCodes{
        LittleException,
        MediumException,
        HardException
    }
}

class TheDetailedException extends RuntimeException{
    public TheDetailedException(String exceptionMessage) {
        super(exceptionMessage);
    }
    public TheDetailedException(String exceptionMessage, Throwable cause) {
        super(exceptionMessage, cause);
        System.out.println("Durum sebepleri : " + cause.getMessage());
    }
}

public class UserDefinedExceptionExample {
    public static void main(String[] args) {
        try 
        { 
            throw new RuntimeException("Temel hata burada belirtilecek");
        } 
        catch(RuntimeException err) {
                throw new TheDetailedException( "Detailed Exception hatası : ", err);
        }
    }
}
