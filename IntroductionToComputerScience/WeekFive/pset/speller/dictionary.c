// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = (26 * 26);

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    if (strcmp(word, " "))
    {
        int hash_index = hash(word);
        if (hash_index >= 0)
        {
            node *ptr = table[hash_index];
            if (ptr == NULL)
            {
                return true;
            } else
            {
                int compare = 0;
                while (ptr != NULL)
                {
                    compare = strcmp(ptr->word, word);
                    ptr = ptr->next;
                }
                return compare == 0;
            }
        }
    }
    
    //printf("%i\n", word[0]);
    
    
    // while (ptr->next != NULL)
    // {
    //     printf("%s\n", ptr->word);
    //     ptr = ptr->next;
    // }
    

    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return (toupper(word[0]) - 'A') + (toupper(word[1]) - 'A');
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *chosen_dictionary = fopen(dictionary, "r");
    if (chosen_dictionary == NULL)
    {
        return false;
    }

    fseek(chosen_dictionary, 0, SEEK_END); // seek to end of file
    int size = ftell(chosen_dictionary); // get current file pointer
    fseek(chosen_dictionary, 0, SEEK_SET);

    //Holds word temporarily in memory
    char buffer[LENGTH + 1];
    
    for (int i = 0, buffer_i = 0; i < size; i++)
    {
        //Holds word temporaroly
        fread(&buffer[buffer_i], sizeof(char), sizeof(char), chosen_dictionary);
        

        if (buffer[buffer_i] == 10)
        {
            int hash_table_index = hash(buffer);
            if (table[hash_table_index] == 0)
            {
                // Adds a new node to the hash table is there isn't a value
                // Allocates memory for a word
                node *new_node = malloc(sizeof(node));
                buffer[ strcspn(buffer, "\r\n") ] = '\0';
                strcpy(new_node->word, buffer);
                new_node->next = NULL;

                // Adds node to the hash table
                table[hash_table_index] = new_node;
            } else
            {
                // Gets first item
                node *head = table[hash_table_index];

                // Adds item to the front
                node *new_node = malloc(sizeof(node));
                buffer[ strcspn(buffer, "\r\n") ] = '\0';
                strcpy(new_node->word, buffer);
                new_node->next = head;


                if (new_node->next == NULL)
                {
                    return false;
                }

                table[hash_table_index] = new_node;
            }

            buffer_i = 0;

            // Continue to next word
            continue;
        }

        buffer_i++;
    }
    
    
    fclose(chosen_dictionary);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
