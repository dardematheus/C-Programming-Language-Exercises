#include <stdio.h>

#define FILENAME "words.txt"

void main(){
    int wordsize[10];
    int wl, other, c;
    wl = other = c = 0;
    FILE *fptr = fopen(FILENAME, "r");

    //Remove garbage memory
    for(int i = 0; i < 10; i++){
        wordsize[i] = 0;
    }

    while((c = fgetc(fptr)) != EOF){
        wl++;
        
        if(c == ' ' || c == '\n' || c == '\t'){
            if(wl > 10){
                other++;
                wl = 0;
            } else {
                wordsize[wl - 1] += 1;
                wl = 0;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        printf("\n Words with %d chars: ", i);
        for(int j = 1; j <= wordsize[i]; j++){
            printf("#");
        }
    }

    printf("\n Other Words: ");
    for(int i = 0; i < other; i++){
        printf("#");
    }
    
    fclose(fptr);
}
