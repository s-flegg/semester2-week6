#include <stdio.h>
#include <string.h>

int validate_inputs(int argc, FILE *fp) {
    if (argc!=2) {
        printf("Error: Invalid Inputs\nUsage: ./word_count filename\n");
        return 1;
    }
    else if (fp == NULL) {
        printf("Error: File cannot be found\n");
        return 1;
    }
    return 0;
}

int count_occurances(char str[100], char toCount) {
    int count = 0;
    for (int i=0; i<strlen(str); i++) {
        if (str[i] == toCount) {
            count++;
        }
    }
    return count;
}

int main(int argc, char **argv) {
    
    FILE *fp = fopen(argv[1], "r");
    if (validate_inputs(argc, fp) == 1) {
        return 1;
    }

    char buffer[100];
    int lines, words, chars = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        lines += count_occurances(buffer, '\n');
        words += count_occurances(buffer, ' ');

        for (int i=0; i<strlen(buffer); i++) {
            chars++;

        }
    }
    fclose(fp);

    printf("Lines: %d\nWords: %d\nChars: %d\n", lines, words, chars);
}