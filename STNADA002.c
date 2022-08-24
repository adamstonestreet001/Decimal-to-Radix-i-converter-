// C program to convert a Decimal value to any given base
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

//Definitions for Title, Author and Year:
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Adam Stonestreet"
#define YEAR 2022


//Function to convert decimal to specified base
void Dec2RadixI(int dec,int base){
   int size = ceil(log10f(dec+1)/log10f(base));         //Gets the number of "digits" needed to store the number in the new radix system.
    if (size == 0){                                     //Takes care of scenario for input decimal value of 0
        size = 1;
    }
   int rem = dec;                                       //Initializes first remainder value to dec
   for (int i = size-1; i>=0; i--)                      //Iterates through the decimal value starting at the most significant bit to convert to new specified base
    {                                                   
    int digit = rem/(pow(base,i));                      //Calculates the converted digit for position i starting at the MSB
    if (digit <=9){
        printf("%c",digit+48);                          //Prints out the equivalent digit in ASCII by adding 48 if the digit is less than 9
    }
    else if (digit >9){          
        printf("%c",digit+55);                          //Prints out the equivalent digit in ASCII by adding 55 if the digit is greater than 9
    }                             
    rem = rem -(digit * pow(base,i));                   //Updates the remainder value
    }
}

//Main Function to call the input from the user and then execute the decimal to radix converter
int main ()
{
    int dec = 0, base;
    printf("*****************************\n%s\nWritten by:%s\nDate:%d\n*****************************\n", TITLE, AUTHOR, YEAR);  //Creates the header of the function using the defined definitions

    while (dec >= 0)                                                                //While loop to run while a positive decimal has been entered
    {
        printf("Enter a decimal number: ");                                         //Prompts user to enter a decimal value
        scanf("%d",&dec);                                                           //Captures the decimal input and stores it as an integer in "dec"

        if (dec<0)                                                                  //Exits the program if the decimal is a neagtive number (Will exit the while loop)
        {
            printf("EXIT\n");
        }
        else 
        {
            printf("The number you have entered is %d\n",dec);                      //Displays the entered number if it is a positive integer
            printf("Enter a radix for the converter between 2 and 16: ");           //Prompts the user to enter a base for the radix converter
            scanf("%d",&base);                                                      //Captures the specified radix and stores it as an integer in "base"
            printf("The radix you have entered is %d\n",base);                      //Displays the entered radix
            float log2 =log2f(dec) ;                                                //Initializes the log2 value to store the log2 value of the entered decimal
            printf("The log2 of the number is  %.2f\n",log2);                       //Displays log2 of the decimal number
            int div = dec / base;                                                   //Initializes the variable to store the division of the decimal value by the base
            printf("The integer result of the number divided by %d is %d\n",base ,div );    //Displays the integer result of the decimal number divided by the base
            int remainder = dec%base;                                               //Initializes the variable to store the remainder of the decimal divided by the base
            printf("The remainder is %d\n",remainder);                              //Displays the remainder
            printf("The radix-%d value is ",base);                                  //Displays the specidied radix value
            Dec2RadixI(dec,base);                                                   //Executes the Decimal to Radix converter function which returns the converted form
            printf("\n");
        }
    }
    return 0;
}





