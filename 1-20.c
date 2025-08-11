#include <stdio.h>

#define MAXLINE 1000
#define TABSIZE 8

//In POSIX Systems (C99 ONWARD), getline should be replaced by my_getline, since it is now included in the lib

int getline(char line[], int max);
int detab(char s[], int pos);

int main()
{
    int c;
    char line[MAXLINE];

    while((c = getline(line, MAXLINE)) != 0){
        printf("%s", line);
    }
}

int getline(char s[], int max)
{
    int i, c;

    for(i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        if(c == '\t'){
            i = detab(s, i) - 1;
            continue;
        } else {
            s[i] = c;
        }
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int detab(char s[], int pos){
    int detab = TABSIZE - (pos % TABSIZE);

    int i;
    for(i = 0; i < detab; i++){
        s[pos++] = ' ';
    }
    return pos;
}