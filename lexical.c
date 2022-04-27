#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
int ValidKeyword(char words[]){
    char keywords[36][10] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto",
    "if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while",
    "include", "stdioh", "main", "printf"};
    int i, key = 0;
    for(i = 0; i < 36; ++i){
        if(strcmp(keywords[i], words) == 0){
        key = 1;
        break;
        }
    }
return key;
}
 
int main(){
    char ch, words[50]; 
    //char operators[] = "+-*/%=";
    FILE *fp;
    int i,j=0;
    fp = fopen("lexical_input.c","r");
    if(fp == NULL){
        printf("Unable to open file\n");
        exit(0);
    }
    printf("Tokens of following c program are:  \n");
    printf("Lexemes\t : \tToken \n");
    printf("----------------------- \n");
    while((ch = fgetc(fp)) != EOF){     //end of file   //fgetc() is used to obtain input from a file single character at a time
        // for(i = 0; i < 6; ++i){
        //     if(ch == operators[i])
        //     printf("%c : Operators \n", ch);
        // }
        if(isalnum(ch)){   //isalnum() used to check that the character is alphanumeric or not
            words[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n') && (j != 0)){
            words[j] = '\0';
            j = 0;
            
            if(ValidKeyword(words) == 1){
                printf("%s : Keywords \n", words);
            }
            else{
                printf("%s : Identifiers \n", words);
            }   
        }
    }
    fclose(fp);
    return 0;
}


