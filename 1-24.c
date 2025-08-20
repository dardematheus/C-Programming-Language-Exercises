#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define STACKSIZE 1000

int stackpointer;

typedef struct
{
    int lineno;
    char character;
} Errors;

int stackpush(Errors *stack[], char insert, int lineno);
int stackpop(Errors *stack[]);

//TODO:
// 1 -> Melhorar Brackets e Colchetes, so esta mostrando que ta faltando, nao a linha e nem quantos
// Implementar checagem de comentarios e de quote
// Implementar erros quando ; estiver faltando

int main(int argc, char *argv[])
{
    FILE *fptr;

    Errors *stack[STACKSIZE]; //Declara stack como um array de ponteiros para a Struct, e nao como um array de structs;
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

    linecounter = 0;
    while((c = fgetc(fptr)) != EOF){
        if(c == '\n'){
            linecounter++;
        }
        if(c == '{'){
            stackpush(stack, c, linecounter);
        }
        if(c == '}'){
            stackpop(stack);
        }
    }

    if(stackpointer == 0){
        printf("No errors");
        return 0;
    }
    else {
        printf("Missing Bracket");
    }
    
    return 0;
}


//Nao inserir se for }), mas tirar 1 equivalente
int stackpush(Errors *stack[], char c, int linecounter)
{
    if(stackpointer > STACKSIZE) return -1;

    //Criacao dinamica com Malloc de uma instancia da struct errors;
    //Acesso aos campos com -> para atribuicao de valores, depois guarda no array de structs;
    Errors *errorInstance = malloc(sizeof(Errors));

    errorInstance->lineno = linecounter;
    errorInstance->character = c;

    stack[stackpointer++] = errorInstance;
    return 0;
}

int stackpop(Errors *stack[])
{
    if(stackpointer <= 0){
        return -1;
    }
    stackpointer--;
    return 0;
}