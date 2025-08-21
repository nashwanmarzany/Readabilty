#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // prompt a user foe some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index

    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int x = (int) round(index);
    // Print the grade level
    if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (x > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", x);
    }
}

// Count the number of letters, words, and sentences in the text

int count_letters(string text)
{
    int sum = 0;
    int l = strlen(text);

    for (int i = 0; i < l; i++)
    {
        if (isalpha(text[i]))
        {
            sum++;
        }
    }
    return sum;
}

int count_words(string text)
{
    int sum = 1;
    int w = strlen(text);

    for (int i = 0; i < w; i++)
    {
        if (text[i] == ' ')
        {
            sum++;
        }
    }
    return sum;
}

int count_sentences(string text)
{
    int sum = 0;
    int s = strlen(text);

    for (int i = 0; i < s; i++)
    {
        if (text[i] == '.')
        {
            sum++;
        }
        else if (text[i] == '!')
        {
            sum++;
        }
        else if (text[i] == '?')
        {
            sum++;
        }
    }
    return sum;
}
