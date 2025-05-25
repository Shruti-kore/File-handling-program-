# File-handling-program-
#include <stdio.h>

int main() {
    FILE *file;
    char buffer[100];

    // 1. Create and write to a file
    file = fopen("example.txt", "w"); // "w" creates the file or overwrites if it exists
    if (file == NULL) {
        printf("Error creating file.\n");
        return 1;
    }
    fprintf(file, "Hello, this is a file write example.\n");
    fclose(file);
    printf("File created and data written.\n");

    // 2. Append data to the file
    file = fopen("example.txt", "a"); // "a" opens the file for appending
    if (file == NULL) {
        printf("Error opening file to append.\n");
        return 1;
    }
    fprintf(file, "This line is appended.\n");
    fclose(file);
    printf("Data appended to file.\n");

    // 3. Read data from the file
    file = fopen("example.txt", "r"); // "r" opens the file for reading
    if (file == NULL) {
        printf("Error opening file to read.\n");
        return 1;
    }
    printf("\nContents of the file:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);

    return 0;
}
