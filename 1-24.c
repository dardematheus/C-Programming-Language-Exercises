#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define STACKSIZE 1000

int stackpointer;

typedef struct
{
    int lineno;
    char chartoken;
} closurestack;

int stackpush(closurestack *stack[], char insert, int lineno);
int stackpop(closurestack *stack[], int c);

//TODO:
// Implementar checagem de comentarios e de quote
// Implementar erros quando ; estiver faltando

int main(int argc, char *argv[])
{
    FILE *fptr;

    closurestack *stack[STACKSIZE]; //Declara stack como um array de ponteiros para a Struct, e nao como um array de structs;
    int linecounter, c;
    bool isQuoted, isComment;

    //Initialize stack with 0/NULL instead of garbage
    memset(stack, 0, sizeof(stack));

    if(argc != 2){
        printf("Incorrect Usage:\nMust contain only <FileName>");
        return -1;
    } 

    fptr = fopen(argv[1], "r");
    if (fptr == NULL){
        printf("Could not open File");
        return -1;
    }

    printf("Checking %s for Common Syntax Errors\n", argv[1]);
    printf("------------------------------------\n");

    linecounter = 1;
    while((c = fgetc(fptr)) != EOF){
        if(c == '\n'){
            linecounter++;
        }
        if(c == '"'){
            isQuoted = !isQuoted;
        }
        if(!isQuoted && c == '{' || c == '[' || c == '('){
            stackpush(stack, c, linecounter);
        }
        if(c == '}' || c == ']'){
            stackpop(stack, c - 2);
        }
        if(c == ')'){
            stackpop(stack, c - 1);
        }
    }

    if(stackpointer == 0){
        printf("Program has no Syntax Errors");
        return 0;
    }
    for(int i = 0; i < stackpointer; i++){
        printf("Unclosed %c at line %d\n---\n", stack[i]->chartoken, stack[i]->lineno);
    }
    return 0;
}

int stackpush(closurestack *stack[], char c, int linecounter)
{
    if(stackpointer > STACKSIZE) return -1;

    //Criacao dinamica com Malloc de uma instancia da struct errors;
    //Acesso aos campos com -> para atribuicao de valores, depois guarda no array de structs;
    closurestack *closureInstance = malloc(sizeof(closurestack));

    closureInstance->lineno = linecounter;
    closureInstance->chartoken = c;

    stack[stackpointer++] = closureInstance;
    return 0;
}

int stackpop(closurestack *stack[], int c)
{
    if(stack[stackpointer - 1]->chartoken == c){
        stackpointer--;
        return 0;
    }
    
    for(int i = 0; i < stackpointer; i++){
        if(stack[i]->chartoken == c){
            stack[i] = stack[i+1];
        }
    }
    stackpointer--;
    return 0;
}