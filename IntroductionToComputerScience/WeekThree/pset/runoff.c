#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string rank1;
    string rank2;
    string rank3;
} vote;

typedef struct
{
    int alice;
    int bob;
    int charlie;
} results;

results apply_votes(string rank, int point, results result);

int main(void)
{
    int amount = get_int("Number of voters: ");
    
    vote votes[amount];
    results result;
    result.alice = 0;
    result.bob = 0;
    result.charlie = 0;

    for (int i = 0; i < amount; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            string rank = get_string("Rank %i: ", j + 1);
            result = apply_votes(rank, j + 1, result);
        }
        printf("\n");
    }

    if ((result.alice <= result.bob || result.bob <= result.alice) && (result.bob < result.charlie && result.alice < result.charlie))
    {
        printf("%s\n", "Charlie");
        return 0;
    }

    if ((result.alice <= result.charlie || result.charlie <= result.alice) && (result.charlie < result.bob && result.alice < result.bob))
    {
        printf("%s\n", "Bob");
        return 0;
    }

    if ((result.charlie <= result.bob || result.bob <= result.charlie) && (result.bob < result.alice &&  result.charlie < result.alice))
    {
        printf("%s\n", "Alice");
        return 0;
    }
    
    
}

results apply_votes(string rank, int point,  results result)
{
    if (!strcmp(rank, "Alice") && point == 1)
    {
        result.alice += 3;
    } else if (!strcmp(rank, "Alice") && point == 2)
    {
        result.alice += 2;
    } else if (!strcmp(rank, "Alice")  && point == 3) {
        result.alice += 1;
    }

    if (!strcmp(rank, "Bob") && point == 1)
    {
        result.bob += 3;
    } else if (!strcmp(rank, "Bob") && point == 2)
    {
        result.bob += 2;
    } else if (!strcmp(rank, "Bob") && point == 3) {
        result.bob += 1;
    }

    if (!strcmp(rank, "Charlie") && point == 1)
    {
        result.charlie += 3;
    } else if (!strcmp(rank, "Charlie") && point == 2)
    {
        result.charlie += 2;
    } else if (!strcmp(rank, "Charlie") && point == 3) {
        result.charlie += 1;
    }

    return result;
}