#include <cs50.h>
#include <stdio.h>
#include <math.h>

// VISA Rules:
// 13 / 16 Digits
// Begins with 4

// MC Rules:
// 16 Digits
// Begins with 51, 52, 53, 54, or 55

// AMEX Rules:
// 15 Digits
// Begins with 34 or 37

int main(void)
{
    long ccNum, checksum; 
    int ccLength = 0, odd = 0, even = 0;
    //First grab a CC number
    do
    {
        ccNum = get_long("Enter your CC Number: \n");
    }
    while (ccNum < 0);
    printf("Entered Number: %li\n", ccNum);

    //Get Card Length. Loop removes the last digit by dividing by 10 and adding 1 to ccLength each time.
    for (long i = ccNum; i > 0; i /= 10)
    {
        ccLength++;
    }
    printf("Length of card entered: %i\n", ccLength);

    // Quick validation check based on length
    if (ccLength != 13 && ccLength != 15 && ccLength != 16)
    {
        printf("INVALID\n");
        // break; //Okay..so break is for loops...
        return 0; // This ends the function without progressing further.
    }

    //Next, checksum. hint: Use modulo %10.
    // So first we need to double every second number, starting from the second to last on the right..
    // Use %10 to get the first number, then you take the last one. Then /10 to remove and repeat.
    // Add each number to an integer. 
    // For the doubled number, make sure it doesn't go over 10, otherwise have to separate and then add in.
    // So lets make two variables, odd and even and go from there.
    //Created them above. Now lets begin. While loop as long as card number is over 0. Create checksum variable to copy card so that the original card number is preserved.
    checksum = ccNum; //Copy the number to preserve original number.
    while (checksum > 0)
    {
        //Now figure out odd and even..
        //So odd numbers will not be doubled. Simply add these together.
        // This is the first number.
        int first = checksum % 10;
        odd += first;
        checksum /= 10;
        //First part done. Next:
        // Take next number. Then double it. Check if 10 or higher. If it is, separate and add together to 'even'. Then checksum/10.
        int second = checksum % 10;
        second *= 2;
        if (second >= 10)
        {
            //need two more ints
            int seconda = second % 10;
            int secondb = second / 10;
            second = seconda + secondb;
        }
        //Add to even here, after the if check
        even += second;
        checksum /= 10;
    }
    int total = odd + even;
    // printf("Progress check: %i\n", total);
    
    // Count the digits. Divide big number by 10. Remainder is the last digit. Modulo 10.
    // This is to calc the checksum.
    // Then check length and starting digits.
    // Then print either, AMEX, MASTERCARD, VISA, or INVALID.

    // Alright, time to do the CC Type checks. Can I use switch statement? Maybe within an IF that checks the checksum value
    if (total % 10 == 0) //Check the remainder is 0 for validity
    {
        //Now begin switch. I need the first two digits.
        int digits = ccNum / (10 * pow(10, (ccLength - 2))); //shows first digit for VISA validation
        if (digits == 4)
        {
            switch (digits)
            {
                case 4:
                    printf("VISA\n");
                    break;

                default:
                    break;
            }
        }
        else
        {
            digits = ccNum / (10 * pow(10, (ccLength - 3))); //now get the first 2 digits for the other cards
            printf("Hello: %i\n", digits);
            switch (digits)
            {
                case 34:
                    printf("AMEX\n");
                    break;

                case 37:
                    printf("AMEX\n");
                    break;

                case 51:
                    printf("MASTERCARD\n");
                    break;

                case 52:
                    printf("MASTERCARD\n");
                    break;

                case 53:
                    printf("MASTERCARD\n");
                    break;

                case 54:
                    printf("MASTERCARD\n");
                    break;

                case 55:
                    printf("MASTERCARD\n");
                    break;

                default:
                    printf("INVALID\n");
                    break;
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
