/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 29.10.2020
*/

package javacalisma;

/**
 *
 * @author burak
 */
public class SummarizeHugeNumbers {
    
    public static void main(String[] args) {
        String no1 = "12452452452452452452452452425245245245254245245243252234356546765536456785673578568468452452452452"; 
        String no2 = "3454543245454545245452453245453453245454837827245245234524524524545242452452455242452452424524524532453245245245245234532453245345324";
        summarizeHugeNumbers(no1, no2);
    }
    
    public static void summarizeHugeNumbers(String _no1, String _no2){
    
        String output = "";
        
        //reversed number variables
        String rno1, rno2;
        //if summarized digits more than 10 it will move one next
        boolean hasDecimal = false;
                
        //firstly we need to reverse
        rno1 = reverseString(_no1);
        rno2 = reverseString(_no2);
        
        //find the for loop size according to number character count
        int loopSize = rno1.length() >= rno2.length() ? rno1.length() : rno2.length();
        
        //Fill with 0 rest of decimal areas and make them equal lenght
        while(rno1.length() != rno2.length() ){
            if(rno1.length() < rno2.length()) rno1 += "0";
            else if(rno1.length() > rno2.length()) rno2 += "0";
        }

        for(int i=0; i<loopSize; i++){
            //summarize the decimals first
            int res = Integer.parseInt(rno1.charAt(i) + "") + Integer.parseInt( rno2.charAt(i)+ "" ); 
            res += hasDecimal ? 1 : 0; //add 1 if hasDecimal
            hasDecimal = (res > 9);//set the decimal if bigger than 10
            //calculate and add the decimal to output variable
            int decimal = res % 10;
            output += decimal + "";
        }
        
        output = reverseString(output);
        
        System.out.println(output);
        
    }
        
    public static String reverseString(String word){
        //First define the output variable
        String output = "";
        //then start to add char by char to output variable
        for(int i=word.length()-1; i>=0; i--){
            output += word.charAt(i);
        }
        return output;
    }
    
}
