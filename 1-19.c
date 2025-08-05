#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void strreverse(char line[], char reverse[], int size);
int getline(char line[], int maxline);

int main(){
    int c;
    char line[MAXLINE];
    char reverse[MAXLINE];

    while((c = getline(line, MAXLINE)) != 0){
        strreverse(line, reverse, c);
        printf("%s\n", reverse);
    }
}

int getline(char s[], int max){
    int c, i;

    for(i = 0; i < max - 1 && (c = getchar()) != '\n' && c != EOF; i++){
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void strreverse(char line[], char reverse[], int size){
    int i;
    for(i = 0; i < size; i++){
        reverse[i] = line[size - 1 - i];
    }
    reverse[size] = '\0';
}