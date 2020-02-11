#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //First we're getting the height input then verifying it meet the conditions set. Do while let's us do a first run, then verifies to see if it needs to run again or not.
    int height;
    do
    {
        height = get_int("Give me a number between 1 and 8. This is the Height.\n");
    }
    // while (height >= 1 && height <= 8); Whoops, accidentally set this part up wrong...
    while (height < 1 || height > 8); //Another whoops, must use OR, not AND...

    //Now do for loop. Need to nest two of them to do width and height.
    // Each for loop must use a different int name while referncing the height
    for (int i = 0; i < height; i++)
    {
        //this first one was for height. Since rows will place the block, height just needs to place linebreaks
        //Have the next for loop before the line break otherwise this breaks
        for (int space = height - 1 - i; space < height && space > 0; space--)
        {
            printf(" ");
        }
        for (int hash = 0; hash <= i; hash++)
        {
            //Now print the brick(s)
            printf("#"); //No line break because that's handled in the root for loop
        }
        printf("\n");
    }

    //Attempt two, since first one makes a 'square' block...Let's try with just one for loop
    //for (int pyramid = 0; pyramid < height; pyramid++)
    //{
    //    printf("#");
    //}
}
