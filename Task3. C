#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[][10] = {"int", "float", "return", "if", "else", "while", "for"};
char operators[] = "+-*/=<>";

int isKeyword(char *word) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, word[50];
    int i = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    printf("Lexical Tokens:\n");

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            word[i++] = ch;
        } else if (isdigit(ch)) {
            word[i++] = ch;
        } else if (ch == ' ' || ch == '\n' || isOperator(ch)) {
            if (i > 0) {
                word[i] = '\0';
                if (isKeyword(word))
                    printf("[Keyword: %s]\n", word);
                else
                    printf("[Identifier: %s]\n", word);
                i = 0;
            }
            if (isOperator(ch))
                printf("[Operator: %c]\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
