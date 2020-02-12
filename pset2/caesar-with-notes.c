#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    int k = 0, klength = 0, plength = 0, kmod = 0;

    //Step 1: Validate there is only one argument entered.
    if (argc != 2)//Effectively, argc is the array length. argv[1] != NULL && argv[2] == NULL)
    {
        //Next check to make sure it's a decimal integer, positive number.
        //int arglength = strlen(argv[1]); //Check length of CL argument for array.
        // OMG can i isdigit on the argv[1] as a whole??
        //use isdigit() ??
        //int keyarray[arglength];
        //for (int i = 0; i < arglength; i++)
        //{
        //    if (isdigit(argv[1][i]))
        //    {
        //        keyarray[i] = argv[1][i];
        //    }
        //    else
        //    {
        //        printf("Usage: ./caesar key\n");
        //        return 1;
        //    }
        //}
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        //Step 2: Validate decimals only have been entered
        // Maybe use isdigit. returns non 0 number if not a digit from what i can find online?
        // Okay testing seems to treat it as bool. 0 is false, other must be true?


        // if (kvalid == 0) Useless. Can just use else

        klength = strlen(argv[1]); //Get key length first
        for (int i = 0; i < klength; i++)
        {
            //Do the IF check for each character
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                // kvalid = 1;  --- This isn't needed after all..
                return 1;
            }
        }
        //Okay so validation appears complete. now we begin asking for the plaintext
        k = atoi(argv[1]); // Convert k to integer.

        string plaintext = get_string("Plaintext: "); //Ask for user plaintext

        //Check key value. If over 26, use modulo
        /*
        if (k > 26)
        {
            k = k % 26;
            printf("Modulo K: %i\n", k);
        }
        */
        // Realise strings are also arrays. So we need the length of the plaintext.
        plength = strlen(plaintext);

        //Maybe bring in the modulo now
        if (k > 26)
        {
            kmod = k % 26;
        }
        else
        {
            kmod = k;
        }
        //Do it this way so we can just remain with kmod for the rest of the code.

        //We'll need to check that upper and lower stay as they are, and ensure there is 'looping' with the key
        //First, implement a test using low numbers and the word hello
        int textnum = 0;
        for (int i = 0; i < plength; i++)
        {
            if (isalpha(plaintext[i]) != 0) //0 should check that it's NOT false..hopefully
            {

                //Okay so next check out upper and lower case chars.
                //ASCII info: A - 65, Z - 90, a - 97, z - 122
                //or maybe, i can use the ascii range to determine what it should be instead...
                //something like get ascii val, if 90 or 122 minus ascii val is more than kmod
                //then work out the difference and add to 65 or 97?
                //maybe use a char variable
                //char asciicheck;
                //nope, make a duplicate string of plaintext instead and convert.
                //since we're already in a loop, i don't need to make another. simply an if should work
                textnum = plaintext[i] + kmod;
                //realised this breaks with a giant key. wait no modulo should fix that
                if ((textnum >= 65 && textnum <= 90) || (textnum >= 97 && textnum <= 122)) //Check ascii value with modulo added. Looks a bit crap
                {
                    plaintext[i] += kmod; //simply add the modulo.
                }
                else //and if it does, find the difference then add it.
                {
                    //Do lowercase first
                    if (textnum > 122)
                    {
                        plaintext[i] = (textnum - 26);//- plaintext[i]);
                    }
                    else if (textnum > 90)
                    {
                        plaintext[i] = (textnum - 26); //plaintext[i]);
                    }
                    else
                    {
                        plaintext[i] += kmod;
                    }
                }

                //plaintext[i] += kmod;
            }
            //Don't need an ELSE here from testing, as it just ignores non alpha chars.
        }
        printf("Ciphertext: %s\n", plaintext);
        //Basic test works. Now to make sure only alphabetic chars get changed. isalpha() should work.
        //Edit above with an IF

        //Reqs:
        //Preserve capitalisation.
        //Ignore non-alphabet chars
        //Return 0 upon success

        printf("Success.\n");
        printf("Kmod Value: %i\n", kmod);
    }


// realised here I'm an idiot. The key will only be a decimal digit, not letters...
// Keeping this because it might be useful for the plaintext later.
/*
    //trying to get the key it's own array
    int length = strlen(argv[1]);

    int key[length];

    for (int i = 0; i < length; i++)
    {
        key[i] = argv[1][i];
    }

    //verify: printf the array
    for (int j = 0; j < length; j++)
    {
        printf("%c", key[j] + 1);
    }
*/


}

//converting the string to integer...
//need to get values for each character from array.
//strlen() ??
/*
int length = strlen(argv[1]);

int key[length];

for (int i = 0; i < length; i++)
{
    key[i] = get_int(argv[1][i]);
}
*/
