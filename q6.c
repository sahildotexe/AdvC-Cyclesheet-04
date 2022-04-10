// Write a program to count the vowels in free text given as standard input. Read text one character at a time until you encounter end-of-data. Then print out the number of occurrences of each of these vowels.

#include <stdio.h>
#include <string.h>
int main()
{
    char ch, str[100];
    int i = 0;
    int a[26] = {0};
    FILE *fp1;
    fp1 = fopen("input_6.txt", "r");
    while ((ch = fgetc(fp1)) != EOF)
    {
        // Ch to lowercase
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 32;
        }
        // Count number of occurences of each vowel

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            a[ch - 'a']++;
        }
    }

    // Print the number of occurences of each vowel
    for (i = 0; i < 26; i++)
    {
        if (a[i] != 0)
        {
            printf("%c: %d\n", i + 'a', a[i]);
        }
    }

    fclose(fp1);
    return 0;
}