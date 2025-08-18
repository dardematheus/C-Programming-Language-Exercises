#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000
#define THRESHOLD 20

int my_getline(char s[], int max);
int fold(char s[], int start, int len);

int main()
{
    int c;
    char line[MAXLINE];

    while((c = my_getline(line, MAXLINE)) != 0){
        fold(line, 0, c);
        printf("%s", line);
    }
}

int my_getline(char s[], int max)
{
    int i, c;

    for(i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        s[i] = c;
    }

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

int fold(char s[], int start, int len)
{
    int i, totalsize;
    bool hasblank = false;
    
    totalsize = len - start;
    i = start;

    if(totalsize > THRESHOLD){
        for(; i < start + THRESHOLD && i < len; i++){
            if(s[i] == ' '){
                hasblank = true;
            } 
        }
        if(hasblank){
            s[i] = '\n';
            fold(s, i+1, len);
        }
        if(!hasblank){
            int pos = start + THRESHOLD;
            s[pos] = '\n';
            fold(s, pos+1, len);
        }
    }
}