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

// Add a index for garbage words
const unsigned int N = (26 * 26) + 1;
unsigned int count = 0;

// Hash table
node *table[N];

void RecurseFree(node *ptr);

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
                char *temp_buffer = malloc(strlen(word));
                for (int i = 0; word[i] != '\0'; i++)
                {
                    temp_buffer[i] = tolower(word[i]);
                }
                while (ptr != NULL)
                {
                    compare = strcmp(ptr->word, temp_buffer);
                    ptr = ptr->next;
                    if (compare == 0)
                    {
                        free(temp_buffer);
                        return true;
                    }
                    
                }
                free(temp_buffer);
                return false;
            }
        }
    }

    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash_value = (toupper(word[0]) - 'A') + (toupper(word[1]) - 'A');
    // TODO: Improve this hash function
    return hash_value < 0 ? N - 1 : hash_value;
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
                buffer[strcspn(buffer, "\r\n")] = '\0';
                strcpy(new_node->word, buffer);
                new_node->next = NULL;
                // Adds node to the hash table
                table[hash_table_index] = new_node;
                count++;
            } else
            {
                // Gets first item
                node *head = table[hash_table_index];

                // Adds item to the front
                node *new_node = malloc(sizeof(node));
                //printf("Got Here\n");
                buffer[ strcspn(buffer, "\r\n") ] = '\0';
                strcpy(new_node->word, buffer);
                new_node->next = head;


                if (new_node->next == NULL)
                {
                    return false;
                }

                table[hash_table_index] = new_node;
                count++;
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
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        RecurseFree(table[i]);
    }

    return true;
}

void RecurseFree(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    
    RecurseFree(ptr->next);
    
    free(ptr);
}
