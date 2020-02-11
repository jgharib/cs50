#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("How much change is owed?\n$");
    }
    while (change < 0);
    printf("\n$%.2f? Coming up!\n", change);
    int cents = round(change * 100);
    printf("This many cents: %i\n", cents);
    // US based coins: .25, .1, .05, .01.
    //Now figure out the coins...one int for each coin type and change (cents) remainins? Periodically update cents?
    //modulo?
    //Work big to small.
    int fifty = 0, twentyfive = 0, ten = 0, five = 0, one = 0;
    //I guess use While loops and modulo
//    while (cents >= 50)
//    {
//        fifty = cents / 50;
//        cents = cents - (fifty * 50);
//    }
    while (cents >= 25)
    {
        twentyfive = cents / 25;
        cents = cents - (twentyfive * 25);
    }
    while (cents >= 10 && cents < 25)
    {
        ten = cents / 10;
        cents = cents - (ten * 10);
    }
    while (cents >= 5 && cents < 10)
    {
        five = cents / 5;
        cents = cents - (five * 5);
    }
    while (cents >= 1 && cents < 5)
    {
        one = cents / 1;
        cents = cents - one;
    }
    int coins = fifty + twentyfive + ten + five + one;
    printf("Current remaining: %i\n", cents);
    printf("Total number of coins: %i\n", coins);
}
