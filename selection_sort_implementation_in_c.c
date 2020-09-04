/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 04.09.2020
*/

#include <stdio.h>

int main()
{

    //We have to generate numbers based on time. Because time is always changing , if we do not do this, program will always generate same numbers
    time_t t;
    srand((unsigned) time(&t));

    //And the array which hold the generated random numbers.
    int numbers[6];

    //Here we are going to generate 6 numbers and they will be between 0 - 100
    for(int i = 0 ; i < 6 ; i++ ) {
        int adding_ok = 1;
        int temp_rand = rand() % 100;
        //Then we control the generated number if added the array before. If not then go
        for(int j=0; j<i; j++)
        {
            //If generated number is exist in the array then we are setting the flag as bit-0 to prevent adding again.
            if(temp_rand == numbers[j])
            {
                adding_ok = 0;
                i--;
            }
        }
        //And last if there is no problem we are adding the number at specified index
        if(adding_ok == 1)
            numbers[i] = temp_rand;
    }


    //Until here our array is ready and we can implement selection sort method,
    //Below variable will keep the minimum values' index
    int min_index;

    //Here we are going to controll all values in the array.
    //At the begining we have selected the first value so our last kontrol index is 1 lack of array size
    for (int i = 0; i < 5; i++)
    {
        // Here we are going to find the minimum number in the index
        min_index = i;
        for (int j = i+1; j < 6; j++)// we need to control the indexes after our selected index. Because we assume the little indexes have been ordered from small to bigger.
          if (numbers[j] < numbers[min_index])// and we are selecting the index according to being small around rest of numbers
            min_index = j;

        // And lastly we are replacing the numbers to prevent deleting them with new order.
        int temp = numbers[min_index];
        numbers[min_index] = numbers[i];
        numbers[i] = temp;

    }


    //en son ekrana yazdiriyoruz
    for(int i = 0 ; i < 6 ; i++ ) {
        printf("%d\n", numbers[i] );
    }

    return 0;
}
