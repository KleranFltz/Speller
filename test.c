/*
// TODO
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    //creating a variable called readword that we will store the value of whichever word we read in this array
    char readword[LENGTH + 1];
    while (fscanf(input, "%s", readword) != EOF) //loop until end of file
    {

        fscanf(input, "%s", readword); //scanning the file and storing the word we are currently viewing in readword

        node *w = malloc(sizeof(node)); //allocate enough space for a new node
        if (w == NULL) //if we could not allocate any space, end the program
        {
            return false;
        }
        strcpy(w->word, readword); //copy the word we are looking at into the new node


        int index = hash(w->word); //call the hash function to determine which bucket (linked list) that this word should go into

        //inserting new node into existing linked list
        w->next = table[index]; //set new node's next pointer to whatever the header was pointing at
        wordCounter++; //counting how many words
        table[index] = w; //set the header to point at the new node
    }
    return true;
    */




   /*
   // For speed, 26*(26+2) (hash table of 2 chars - second character may be nothing in case of i_, a_, or ' in case of i've, etc);
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    // creates the empty nodes for the hashtable
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


    // allocates first node and creates a buffer for the single char being read, and the string being built
    node *n = malloc(sizeof(node));
    char *word = malloc(LENGTH + 1);

    if (n == NULL || word == NULL)
    {
        return false;
    }

    while (fscanf(file, "%s", word) != EOF)
    {
        // copies read string
        strcpy(n->word, word);
        words++;

        // sets the pointer of this node to next in hash (null if none)
        n->next = table[hash(word)]->next;

        // sets the pointer of the hash to this new node
        table[hash(word)]->next = n;

        // creates new node for next word
        node *tmp = malloc(sizeof(node));

        if (tmp == NULL)
        {
            return false;
        }

        n = tmp;
    }
    free(n);
    free(word);
    fclose(file);

    return true;
    */