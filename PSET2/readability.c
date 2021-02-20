#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Prototype
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int readability_index(int letters, int words, int sentences);

int main(void)
{
    //Prompt the user to enter the text
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index = readability_index(letters, words, sentences);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//Counting Letters
int count_letters(string text)
{
    //Setting initial value to 0
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
        if (isalpha(text[i]))
        {
            letters ++;
        }
    return letters;
}
//Counting Words
int count_words(string text)
{
    //Setting initial value to 0
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '-' && isalpha(text[i - 1])) {}

        else if (text[i] == 39 && isalpha(text[i - 1])) {}

        else if (!isalpha(text[i]) && isalpha(text[i - 1]))
        {
            words ++;
        }

    }
    return words;
}
//Counting Sentences
int count_sentences(string text)
{
    //Setting initial value to 0
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int character = text[i];
        if (character == 46 || character == 33 || character == 63)
        {
            sentences ++;
        }
    }
    return sentences;
}
//Calculation
int readability_index(int letters, int words, int sentences)
{
    //Converting int to float
    float words_per_100 = words / 100.0;
    float L = letters / words_per_100;
    float S = sentences / words_per_100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}
