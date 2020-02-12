//Includes
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Declare variables for later
    int k = 0, klength = 0, plength = 0, kmod = 0;

    //Check that only one additional argument was entered
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else //And if so, everything else happens in here
    {
        klength = strlen(argv[1]); //Key Length

        //Check that only digits have been entered as the key
        for (int i = 0; i < klength; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        //convert key string to integer
        k = atoi(argv[1]);

        //ask for plaintext
        string plaintext = get_string("Plaintext: ");

        //get length of plaintext
        plength = strlen(plaintext);

        // Check is key is larger value than 26. If so, reduce iwth modulo
        if (k > 26)
        {
            kmod = k % 26;
        }
        else
        {
            kmod = k;
        }
        //now working key value is in kmod, regardless of original value.

        int textnum = 0; //declaring this variable for the total 'value' of plaintext character PLUS kmod value. Using this to help with preserving case.

        for (int i = 0; i < plength; i++) //Rest of everything goes within this loop
        {
            if (isalpha(plaintext[i]) != 0) //check if character in plaintext is alphabetical. If so, continue, otherwise ignore.
            {
                textnum = plaintext[i] + kmod;  //Giving the value to textnum here

                if ((textnum >= 65 && textnum <= 90) || (textnum >= 97 && textnum <= 122)) //Hacky upper and lowercase check. Did this way to use ASCII values and not double-up with isupper and islower.
                {
                    plaintext[i] += kmod; //simply add the kmod value if the total is within range set above.
                }
                else //If textnum goes out of range, then figure out how to loop back.
                {

                    if (textnum > 122) //check highest value first. If higher than 122, make it continue the count from 97
                    {
                        plaintext[i] = (textnum - 26);
                    }
                    else if (textnum > 90) //uppercase check. if higher than 90, make it continue the count from 65
                    {
                        plaintext[i] = (textnum - 26);
                    }
                    else //not really sure if this does anything or not, but i figure it can't hurt.
                    {
                        plaintext[i] += kmod;
                    }

                }
            }
        }
        //aaaand complete!
        printf("ciphertext: %s\n", plaintext);
        return 0;
    }
}