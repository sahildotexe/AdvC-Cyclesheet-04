// Write a program to extract words form any text file and store in another file. Sort the words in alphabetical order and store them in the same file. Read the sorted file and print the frequency of each word.

#include <stdio.h>
#include <string.h>

#define MAXW 100
#define MAXC 32

int main()
{

    /* initialize variables & open file or stdin for reading */
    char seen[MAXW][MAXC] = {{0}};
    char word[MAXC] = {0};
    size_t freq[MAXW] = {0};
    size_t i, idx = 0;
    FILE *fp = fopen("input_4.txt", "r");
    if (!fp)
    {
        fprintf(stderr, "error: file open failed.\n");
        return 1;
    }

    /* seen 1st word into 'seen' array, update index 'idx' */
    if (fscanf(fp, " %32[^ ,.\t\n]%*c", word) == 1)
    {
        strcpy(seen[idx], word);
        freq[idx]++;
        idx++;
    }
    else
    {
        fprintf(stderr, "error: file read error.\n");
        return 1;
    }

    /* read each word in file */
    while (fscanf(fp, " %32[^ ,.\t\n]%*c", word) == 1)
    {
        /* check against all words in seen */
        for (i = 0; i < idx; i++)
        {
            /* if word already in 'seen', update 'freq' count */
            if (strcmp(seen[i], word) == 0)
            {
                freq[i]++;
                goto skipdup; /* skip adding word to 'seen' */
            }
        } /* add word to 'seen', update freq & 'idx' */
        strcpy(seen[idx], word);
        freq[idx]++;
        idx++;

    skipdup:

        if (idx == MAXW)
        { /* check 'idx' against MAXW */
            fprintf(stderr, "warning: MAXW words exceeded.\n");
            break;
        }
    }
    if (fp != stdin)
        fclose(fp);

    printf("\nthe occurrence of words are:\n\n");
    for (i = 0; i < idx; i++)
        printf("  %-28s : %zu\n", seen[i], freq[i]);
    // Sort the words in alphabetical order and store them in the same file.
    FILE *fp1 = fopen("input_4.txt", "w");
    if (!fp1)
    {
        fprintf(stderr, "error: file open failed.\n");
        return 1;
    }
    for (i = 0; i < idx; i++)
    {
        for (int j = i + 1; j < idx; j++)
        {
            if (strcmp(seen[i], seen[j]) > 0)
            {
                char temp[MAXC];
                strcpy(temp, seen[i]);
                strcpy(seen[i], seen[j]);
                strcpy(seen[j], temp);
            }
        }
    }
    for (i = 0; i < idx; i++)
    {
        fprintf(fp1, "%s\n", seen[i]);
    }
    fclose(fp1);
    fclose(fp);
    return 0;
}