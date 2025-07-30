#include <stdio.h>

#define FILENAME "words.txt"

void main(){
    int charcount[26];
    int c, index, other;
    FILE *fptr = fopen(FILENAME, "r");

    for(int i = 0; i < 26; i++){
        charcount[i] = 0;
    }

    other = c = 0;
    while((c = fgetc(fptr)) != EOF){
        index = c - 97;
        if (index < 0 || index > 26){
            other++;
        } else {
            charcount[c - 97]++;
        }
    }
    
    for(int i = 0; i < 26; i++){
        printf("\n Letter: %c - Incidence: ", i + 97);
        for(int j = 1; j <= charcount[i]; j++){
            printf("#");
        }
    }
    printf("\n Other: %d", other);
    fclose(fptr);
}