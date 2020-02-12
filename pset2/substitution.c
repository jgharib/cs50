#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    int keylength = 0;
    //First check key exists
    if (argc != 2)
    {
        printf("Error: No command-line argument. Use ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    keylength = strlen(key);
    //Check key meets requirements. First keylength since doing isalpha gave segmentation fault.
    if (keylength != 26)
    {
        printf("Error: Invalid key. 26 characters only. Use ./substitution key\n");
        return 1;
    }
    else
    {
        // Attempt to check for alpha chars here using loop.
        for (int i = 0; i < keylength; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Error: Invalid key. Alphabetical characters only. Use ./substitution key\n");
                return 1;
            }
        }
    }

    //Now figure out how the hell to check for unique chars...
    //for loop in a for loop??

    //Attempting duplication check:
    for (int i = 0; i < keylength; i++)
    {
        //originally had j = 0, then j = 1. it's gotta be i + 1 so that it never matches i and gives a fale duplicate.
        for (int j = i + 1; j < keylength; j++)
        {
            if (key[i] == key[j])
            {
                printf("Error: Must use unique letters\n");
                return 1;
            }
        }
    }

    //Ask for plaintext from user

    string plaintext = get_string("plaintext: ");
    /*
    seriously now...how do i do this convert...
    could i use a switch statement? Thats a LOT of lines though... Maybe if I make a separate function.
    could i do it like caesar with modulo but for each individual letter??

    Alright think this through.
    The key is case insensitive. The plaintext converts to the key letter in it's original case.
    Should I convert the key to the same case first?

    I feel like a for loop..again..seems to be the best way. but how?

    What if i convert both plain and key to upper or lower, then do the substitute, then convert back
    to original case with a loop. preserve the original text in plaintext and convert in another var?

    */

    //Conversion strings
    //string lowertext = tolower(plaintext);
    //string lowerkey = tolower(key);

    //LOL not that simple. Googling shows tolower() works on chars. Alright. Let's do some loops..again
    int textlength = strlen(plaintext);
    string lowertext = 0;
    char capscheck[textlength];
    lowertext = plaintext; //[textlength + 1]; //add one to account for NULL char at the end ofarray.
    string lowerkey = key; //[keylength + 1]; //not sure why exactly it's here and not in the earlier one, but whatever.
    //first for key value
    for (int i = 0; i < keylength; i++)
    {
        lowerkey[i] = tolower(key[i]);
    }
    //next for plaintext value
    for (int i = 0; i < textlength; i++)
    {
        if (!isupper(plaintext[i]))
        {
            lowertext[i] = plaintext[i];
            capscheck[i] = 0;
        }
        else
        {
            lowertext[i] = tolower(plaintext[i]);
            capscheck[i] = 1;
        }
    }

    //Now, use lowerkey to alter lowertext, then convert back to original case with plaintext.
    //switch statement within a for loop? I feel like I'm overusing for loops though..
    //But it might be easier. Compare with ascii vals and might work?

    //a = 97. lowerkey[0] should be 97. So loop with that in mind.

    for (int i = 0; i < textlength; i++)
    {

        if (!isalpha(lowertext[i]))
        {
            lowertext[i] = lowertext[i];
        }
        else
        {
            lowertext[i] = lowerkey[(lowertext[i] - 97)];
        }
    }

    //wtf that actually works??

    //alright then let's convert it back to original case.
    //compare plaintext and lowertext. convert lowertext to original and use that as ciphertext
    //one last for loop should do it

    for (int i = 0; i < textlength; i++)
    {
        if (capscheck[i] == 1)
        {
            lowertext[i] = toupper(lowertext[i]);
        }

    }
    //ok so plaintext is changing with lowertext for some reason

    /*
    Checks:
    printf("Lowered Vars:\nText: %s\nKey: %s\nTextlength: %i\n", lowertext, lowerkey, textlength);
    printf("Original plaintext: %s\n", plaintext);
    printf("Success! Key: %s\n", key);
    */
    printf("ciphertext: %s", lowertext);
    printf("\n");
    return 0;

}