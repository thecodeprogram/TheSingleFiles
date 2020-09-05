/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 05.09.2020
*/


#include <stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{

    //First we request from user to specify the file
    char filePath[1000];
    printf( "Enter file or drag file here to get file path :");
    gets( filePath );

    //Then we load inputted file path to the FILE structure to read.
    char const* const fileName = filePath; // "D:\\try.txt";
    FILE* file = fopen(fileName, "r");
    //also we need a variable to read the text line by line
    char line[1000];
    //Also we can count how many lines do we have in  text file
    char c;
    int lineCount = 0;


    //Now we check the text file is correct and count the newlines
    for (c = getc(file); c != EOF; c = getc(file))
            if (c == '\n')
                lineCount++;

    //Here we clear the related pointer and reload the file
    fclose(file);
    file = fopen(fileName, "r");


    //Here you can make some controls on the characters EOF = end of file
    //You can make this control with different ways
    //you can use ASCII encoding or whatever you want
    //I HAVE COMMENTED HERE TO SHOW YOU EXAMPLE IS WORKING
    /*
    for (c = getc(file); c != EOF; c = getc(file)){
            if (!(c == '0' || c == '1' || c == '2' ||  c == 'a' || c == 'b' || c == 'c' ||c == '\n')){
                printf( "UNRELATED CHARACTERS WAS FOUND...");
                return 0;
            }
    }
    */

    //Here we clear the related pointer and reload the file
    fclose(file);
    file = fopen(fileName, "r");


    //Here we print all text line by line
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        i++;
        printf("Line %d : %s", i, line);
    }
    printf("\n");

    //and close the file when operation is completed
    fclose(file);

    return 0;
}
