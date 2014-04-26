//
//  main.c
//  targil2
//
//  Created by Ronen Kondratovsky on 3/12/14.
//  Copyright (c) 2014 Ronen. All rights reserved.
//

#include <stdio.h>
int isWhiteSpace(char);
int isNewWord(char, char);
int isLetter(char);
int isDigit(char);

int isWhiteSpace(char ch){
    if (ch == ' ' || ch == '\t'||ch=='\n' ) {
        return 1;
    }
    return 0;
}
int isNewWord(char last, char current){
    if ((last == ' ' || last == '\t' || last=='\n' )&&(current != ' ' && current != '\t' && current!='\n')) {
        return 1;
    }
    return 0;
}
int isLetter(char c){
    if( ( c>='A' && c<='Z' ) || ( c>='a' && c<='z' ) ){
        return 1;
    }
    return 0;
}
int isDigit(char c){
    if(c>='0'&&c<='9'){
        return 1;
    }
    return 0;
}
int main(int argc, const char * argv[])
{
    int numberOfChars=0,numberOfLine=0,sumWhiteSpace=0,sumWords=0,sumletter=0,sumdigit=0;

    char last=' ';
    printf("Running: \n");
    while (1>0)
    {
        char c=getchar();
        if (c=='\n') {
            numberOfLine++;
        }
        if(isWhiteSpace(c)==1){
            sumWhiteSpace++;
        }
        if(isNewWord(last, c)==1){
            sumWords++;
        }
        if(isLetter(c)==1){
            sumletter++;
        }
        if(isDigit(c)==1){
            sumdigit++;
        }
        last=c;
        if (c==EOF){
            printf("%s%d\n","number of chars = ",numberOfChars);
            printf("%s%d\n","number of line = ",numberOfLine);
            printf("%s%d\n","number of whiteSpace = ",sumWhiteSpace);
            printf("%s%d\n","number of words = ",sumWords-1);
            printf("%s%d\n","number of letters = ",sumletter);
            printf("%s%d\n","number of digits = ",sumdigit);
        break;
        }
        numberOfChars++;
        last=c;

    }


}

