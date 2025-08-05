#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);

int main()
{
    int c;
    char line[MAXLINE];
    char fmtline[MAXLINE];

    while ((c = getline(line, MAXLINE)) != 0)
    {
        printf("%s", line);
    }
}

int getline(char s[], int max)
{
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; i++)
    {
        if (c == '\t' || c == ' ')
        {
            i--;
            continue;
        }
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}