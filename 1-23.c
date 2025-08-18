#include <stdio.h>
#include <stdbool.h>

#define FILENAME "comments.c"
#define LINESIZE 100

void rmv_comments(FILE *fptr);

int main()
{
    int c;
    FILE *fptr;
    bool isQuoted, isComment;

    fptr = fopen(FILENAME, "r+");
    if(fptr == NULL) return -1;

    while((c = fgetc(fptr)) != EOF){
        if(c == '"'){
            isQuoted = !isQuoted;
        }
        if(!isQuoted && c == '/'){
            rmv_comments(fptr);
        }
    }

    fclose(fptr);
}

void rmv_comments(FILE *fptr)
{
    int c;

    fseek(fptr, -1, SEEK_CUR);
    while((c = fgetc(fptr)) != '\n' && c != EOF){
        fseek(fptr, -1, SEEK_CUR);
        fputc(' ',  fptr);
        fflush(fptr);
    }
}