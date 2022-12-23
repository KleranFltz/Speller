// Implements a dictionary's functionality
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 28;
unsigned int wordcounter = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
     //input is the *word
    //output is true or false boolean
    //case insensitive function
    //hash the word to obtain hash value

    int index = hash(word);
    //access the linked list at that hash value
    node *cursor = table[index]->next;
    //if the word is in dictionary it should be in that list, if the word isn't in that list, it isn't in the dictionary
    //traverse the linked list looking at one node at a time, use strcasecmp to compare two strings case insensitively
    while(!(cursor == NULL))
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    //if the word is found, return true, otherwise return false
    //cursor = cursor->next; traversing the linked list (do this if the word we are looking at isn't the one)
    //in order to stop the traverse loop we will end if we reach a null value for cursor (if cursor->next == NULL) end


    //start with cursor set to the first node in the list, keep moving the cursor checking each word until you reach NULL
    //if you find the word then the function will return true, otherwise you will return false.


    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // (ascii - 'A' * 26) + (ascii - 'A')
    // for example debris would be ((68 - 65)*26) + (69 - 65) --> which equals 78 + 4 or 82
    // therefore debris would be stored in index 82 along with all other words that start with d and e

    // both letters are converted to uppercase so that we don't have to check if the letters are lower case
    int letter1 = toupper(word[0]);

    int letter2 = toupper(word[1]);

    if (letter2 == 39) //if apostrophe
    {
        letter2 = 91; //converted to ascii equivalent of 27th index
    }

    else if (letter2 == 62) //if space
    {
        letter2 = 92; //converted to ascii equivalent of 28th index
    }

    if (letter2 == '\0' || letter2 == '\n')
    {
        return 92;
    }

    int l1 = ((letter1 - 65) * 26);
    int l2 = (letter2 - 65);

    if (l2 < 0)
    {
        letter2 = 92;
    }

    return (((letter1 - 65)*26) + ((letter2 - 65)));
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        node *tmp = malloc(sizeof(node));

        // if cant allocate
        if (tmp == NULL)
        {
            return false;
        }

        tmp->next = NULL;

        table[i] = tmp;
    }

    //allocating space for a new node
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return false;
    }
    //allocate space for a word
    char *word = malloc(LENGTH + 1);
    if (word == NULL)
    {
        return false;
    }

    while (fscanf(input, "%s", word) != EOF) //loop until end of file
    {
        strcpy(n->word, word); //copy the word we are looking at (in the dictionary) into the new node
        wordcounter++; //increments every time we add a word

        //inserting new node into existing linked list
        n->next = table[hash(word)]->next; //set new node's next pointer to whatever the header was pointing at
        table[hash(word)]->next = n; //set the header to point at the new node

        //allocating space for a new node
        node *tmp = malloc(sizeof(node));

        if (tmp == NULL)
        {
            return false;
        }
        //this is giving n a null value so that it can be used for the next iteration as a new node
        n = tmp;
    }
    //free all data and close the input file
    free(n);
    free(word);
    fclose(input);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    
    return wordcounter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    //first loop is to loop over all indexes
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        //second loop is to loop over all links in the linked list
        while (!(cursor == NULL))
        {
            node *tmp = cursor;

            cursor = cursor->next;

            free(tmp);
        }

    }

    return true;
}


//basic words
//min length (1 char words)
//substrings

/* our program hashes the word based on the first two letters
 so in the case of these words: quick, brown, lazy, and fox
 they would be stored in hash values like this
 quick = (81-65) * 26) + (85-65);
 or
 quick = (16 * 26) + (20)

 quick = 436;
 */