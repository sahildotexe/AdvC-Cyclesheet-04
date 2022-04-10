// Write a program to copy one file to another such that every word is reversed before being written to the target file.Assume the maximum size of each word is 10 characters and each word is separated either by new line(s), tab(s) or space(s).For example, if source file contains "I am an Indian", the target file should contain "I ma na naidnl".

#include <stdio.h>
#include <string.h>
int main()
{
    char ch, str[100];
    int i = 0;
    FILE *fp1, *fp2;
    fp1 = fopen("input_7.txt", "r");
    fp2 = fopen("output_7.txt", "w");
    while ((ch = fgetc(fp1)) != EOF)
    {
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            str[i] = '\0';
            strrev(str);
            i = 0;
            fputs(str, fp2);
            fputc(ch, fp2);
        }
        else
        {
            str[i] = ch;
            i++;
        }
    }
    printf("\nFile copied successfully");
    fclose(fp1);
    fclose(fp2);
    return 0;
}