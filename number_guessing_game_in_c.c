/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 05.09.2020
*/

#include <stdio.h>

int main()
{

    //Firstly we need to set the randomise on time base
    //else program will always generate same numbers
    time_t t;
    srand((unsigned) time(&t));

    //Here our digits array and the variable which hold the generated number
    int digits[4];
    int generated_number = 0;

    //At for loop we will select 4 digits
    for(int i = 0 ; i < 4 ; i++ ) {
        //adding_ok flag to control the digit is okay to use
        int adding_ok = 1;
        int digit = rand() % 10;
        //After generaing digit check if exist in the array and being zero.
        for(int j=0; j<i; j++)
        {
                if( (digit == digits[j]) )
                {
                    adding_ok = 0;
                    i--;
                }
                if(adding_ok == 1 && (i == 0 && digit == 0 )) // ilk sayi sifir olamaz diyoruz
                {
                    adding_ok = 0;
                    i--;
                }
        }
        //Lastly if there is no problem add generated digit to array.
        if(adding_ok == 1)
            digits[i] = digit;
    }

    //Generate the number from digits array
    generated_number = (digits[0] * 1000) + (digits[1] * 100) + (digits[2] * 10) + (digits[3] * 1);


    //Here we have essential variables to hold the input data and its integer value
    //Also I have incorrect entry counter variable.
    char * str[100];
    int entered_number = 0;
    int incorrect_counter = 0;

    //Below while loop we are going to ask user to guess a number
    //We are going to control it on equalisation,
    //Than our program is going to help user to find the number
    //Here we set the user can guess 10 times
    while(1)
    {
        printf("Guess Number : ");
        fgets(str, sizeof(str), stdin);
        entered_number = atoi(str);
        if(entered_number == generated_number)
        {
            printf("You guessed Correct...\n");
            break;
        }
        else
        {
            if(entered_number > generated_number)
            {
                printf("Go Down: \n");
                incorrect_counter++;
            }
            else if(entered_number < generated_number)
            {
                printf("Go up : \n");
                incorrect_counter++;
            }
        }

        if( incorrect_counter >=10)
        {
            printf("Failed ...\n");
            printf("Generated Number : %d\n", generated_number);
            printf("Game over ...\n");
            break;
        }
    }

    return 0;
}
