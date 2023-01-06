#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int main(int argc, string argv[]){
    string guess_word = "games";

    int guesses = 0;
    do
    {
        string guess = get_string("Input your guess: ");

        for (int i = 0; i < strlen(guess); i++)
        {

            bool correct_pos = false;
            bool has_letter = false;
            bool not_found = false;
            for (int j = 0; j < strlen(guess_word); j++)
            {
                if (guess_word[i] == guess[j] && i == j)
                {
                    correct_pos = true;
                    break;
                } else if (guess[i] == guess_word[j])
                {
                    has_letter = true;
                    break;
                } else {
                    not_found = true;
                }
            }
            if (correct_pos)
            {
               printf("%s%c", KGRN, guess_word[i]);
            } else if (has_letter)
            {
                printf("%s%c", KYEL, guess_word[i]);
            } else
            {
                printf("%s%c", KRED, guess_word[i]);
            }
        }
        guesses++;
        printf("%s\n", KWHT);
    } while (guesses < 6);
}