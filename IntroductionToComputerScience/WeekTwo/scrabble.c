#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int compute_score(string word, char alphabet[], int point[]);

int main(void)
{
    
    string player_words[2];
    int points[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    for (int i = 0; i < 2; i++)
    {
        player_words[i] = get_string("Player %i: ", i+1);
    }
    
    int score[2];
    for (int i = 0; i < 2; i++)
    {
        score[i] = compute_score(player_words[i], alphabet, points);
    }

    if (score[0] < score[1])
    {
        printf("Player 2 Wins!");
    } else if(score[0] > score[1])
    {
        printf("Player 1 Wins!"); 
    } else {
        printf("Draw!");
    }
    printf("\n");
}

int compute_score(string word, char alphabet[], int point[])
{
    int total_score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (tolower(word[i]) == alphabet[j])
            {
                total_score += point[j];
            }
        }
        
    }
    return total_score;
}