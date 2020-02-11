#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Alright. Similar to the last one, but this time have two for loops BEFORE new line...
    //Again, enter number to determine height.

    int height;
    do
    {
        height = get_int("Height: \n");
    }
    while (height < 1 || height > 8);
    //This works for height. Next, start placing the pyramids.

    for (int i = 0; i < height; i++)
    {

        printf("  "); //Two spaces between the two pyramids.
        for (int right = 0; right <= i; right++)
        {
            printf("#"{})
        }
        printf("\n"); //New line at the end of other loops
    }
}
