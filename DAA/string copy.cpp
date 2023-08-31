#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, world!";
    char destination[100]; // Make sure the destination array is large enough

    // Copying the string from source to destination
    strcpy(destination, source);

    printf("Source string: %s\n", source);
    printf("Copied string: %s\n", destination);

    return 0;
}

