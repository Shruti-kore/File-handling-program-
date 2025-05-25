#include <stdio.h>
#include <stdlib.h>

// Compress the input file using RLE
void compress(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("File error!\n");
        return;
    }

    char ch, prev;
    int count = 1;

    prev = fgetc(in);
    while ((ch = fgetc(in)) != EOF) {
        if (ch == prev) {
            count++;
        } else {
            fprintf(out, "%d%c", count, prev);
            count = 1;
        }
        prev = ch;
    }
    fprintf(out, "%d%c", count, prev);

    fclose(in);
    fclose(out);
    printf("Compression complete.\n");
}

// Decompress the RLE file
void decompress(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("File error!\n");
        return;
    }

    int count;
    char ch;

    while (fscanf(in, "%d%c", &count, &ch) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
    printf("Decompression complete.\n");
}

int main() {
    int choice;
    printf("1. Compress\n2. Decompress\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        compress("input.txt", "compressed.txt");
    else if (choice == 2)
        decompress("compressed.txt", "output.txt");
    else
        printf("Invalid choice.\n");

    return 0;
}
