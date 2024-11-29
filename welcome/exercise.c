#include <stdio.h>

int getUserChar() {
    char userInput;

    // Doing this to consume any leftover newline characters in the input buffer
    // getchar();

    // Prompt the user for input
    printf("Enter a character: ");

    // Read a single character using scanf
    userInput = getchar();


    // Display the character that was inputed by the user
    printf("You entered: %c\n", userInput);

    if (userInput == 'Q') {
        puts("Welcome to ODE5!");
    }

    return 0;
}