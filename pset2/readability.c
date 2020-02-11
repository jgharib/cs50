// Includes
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    string text = get_string("Text: ");
    //int i = strlen(text); <-- This works, yay
    //printf("Characters: %i", i);

    //omg so simple. use for loop combined with other stuff...

    float letters = 0, words = 1, sentences = 0;
    // set words to 1 because there should theoretically be one less space than words, unless there's a double space then crap
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        //To find letters, use isalpha
        if (isalpha(text[i]))
        {
            letters++;
        }
        //for words, count number of spaces
        if (isblank(text[i]))
        {
            words++;
        }
        //for sentences, count punct?? ..only looking for the three...
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') //maybe without ispunct?
        {
            sentences++;
        }
        //else if (letters >= 1) OKAY SOMEHOW THIS BREAKS EVERYTHING!!!
        //{
        //    sentences = 1;
        //}
    }
    //testing
    //printf("Letters: %f\nWords: %f\nSentences: %f\n", letters, words, sentences);
    //test grade
    float L = letters / words * 100;
    float S = sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    if (grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
    //printf("Grade: %f\n", grade);
    //printf("Grade Int: %i\n", gradeint);

}

// formula: index = 0.0588 * L - 0.296 * S - 15.8
// L = letters per 100 words
// S = sentences per 100 words

//isalpha() checks for alphabetic character
// isupper() and islower() for upper and lowercase
//isblank() for space
//ispunct() for punctuation
//ASCII for . is 46. for ! is 33. for ? is 63

//so let's figure out how to count letters, words, and punc for sectences.
