#include <stdio.h>
#include <ctype.h>
/*
 * Write a program that converts a number in the range [0...999] to words, 
 * corresponding to the English pronunciation.
 */
int main() 
{
    char zeroToTen[10][10] = {"zero", "one", "two", "three", "four", "five",
                                "six", "seven", "eight", "nine"};
    char tenToNineteen[10][10] = {"ten", "eleven", "twelve", "thirteen", 
                                "fourteen", "fifteen", "sixteen",
                                "seventeen", "eighteen", "nineteen"};
    char tens[8][8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", 
                        "eighty", "ninty"};
    
    char* numberAsString[30];
    int input, ones, ten, teens, hundreds;
    if (scanf("%d", &input) != 1)
    {
        printf("Invalid input!");
    }
    else
    {
        hundreds = input / 100;
        ten = input / 10;
        ones = input % 10;
        teens = ten % 10;
        
        if (input < 0 || input > 999)
        {
            printf("The number is negative or larger than 999");
        }
        else
        {
            if (hundreds == 0)
            {
                if (ten == 0)
                {
                    zeroToTen[ones][0] = toupper(zeroToTen[ones][0]);
                    printf("%s", zeroToTen[ones]);
                }
                else if (ten == 1)
                {
                    tenToNineteen[ones][0] = toupper(tenToNineteen[ones][0]);
                    printf("%s", tenToNineteen[ones]);
                }
                else if (ten >= 2 && ones == 0)
                {
                    tens[ten - 2][0] = toupper(tens[ten - 2][0]);
                    printf("%s", tens[ten - 2]);
                }
                else
                {
                    tens[ten - 2][0] = toupper(tens[ten - 2][0]);
                    printf("%s %s", tens[ten - 2], zeroToTen[ones]);
                }
            }
            else
            {
                if ((teens == 0) && ones != 0)
                {
                    zeroToTen[hundreds][0] = toupper(zeroToTen[hundreds][0]);
                    printf("%s hunded and %s", 
                            zeroToTen[hundreds], 
                            zeroToTen[ones]);
                }
                else if ((teens == 0) && ones == 0)
                {
                    zeroToTen[hundreds][0] = toupper(zeroToTen[hundreds][0]);
                    printf("%s hundred", zeroToTen[hundreds]);
                }
                else if ((teens > 0) && ones == 0)
                {
                    zeroToTen[hundreds][0] = toupper(zeroToTen[hundreds][0]);
                    printf("%s hunded and %s", 
                            zeroToTen[hundreds], 
                            tens[teens - 2]);
                }
                else if (teens == 1)
                {
                    zeroToTen[hundreds][0] = toupper(zeroToTen[hundreds][0]);
                    printf("%s hunded and %s", 
                            zeroToTen[hundreds], 
                            tenToNineteen[ones]);
                }
                else
                {
                    zeroToTen[hundreds][0] = toupper(zeroToTen[hundreds][0]);
                    printf("%s hunded and %s %s", 
                            zeroToTen[hundreds], 
                            tens[teens - 2], 
                            zeroToTen[ones]);
                }
            }
        }
    }
    
    return 0;
}

