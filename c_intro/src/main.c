#include <stdio.h>
#include "lib.c"
#include <errno.h>
#include <string.h>

typedef enum {
    COMMAND_FIZZBUZZ,
    COMMAND_FIZZBUZZNEW,
    COMMAND_UNKNOWN
} COMMAND;

COMMAND getCommandEnum(const char *str) {
    if (strcmp(str, "fizzbuzz") == 0) {
      return COMMAND_FIZZBUZZ;
    } else if (strcmp(str, "fizzbuzzNew") == 0) {
      return COMMAND_FIZZBUZZNEW;
    } else {
      return COMMAND_UNKNOWN;
    }
}

long getNumberFromArgs(char **argv, int index) {
  char* endPointer;
  errno = 0;
  long number = strtol(argv[index], &endPointer, 10);
  // Error handling
  if (errno != 0) {
    perror("Invalid parameter provided to the fizzbuzz command. Unable to parse to an integer.");
  }
  if (*endPointer != '\0') {
    perror("Invalid input provided");
  }
  return number;
}

int main(int argc, char **argv) {
  if (argc > 1) {
    printf("Hello, %s!\n", argv[1]);
  } else {
    puts("No greeting for you!");
  }

  if (argc < 3) {
    printf("Invalid number of arguments provided. At least the user name and command to be run have to be provided\n");
    return 1;
  }

  char *commandInput = argv[2];

  COMMAND command = getCommandEnum(commandInput);

  switch (command) {
    case COMMAND_FIZZBUZZ:
      printf("Fizzbuzz command selected\n");
      if (argc != 4) {
        printf("Invalid number of parameters provided for the fizzbuzz command. Expected 4, got %d\n", argc);
        return 1;
      }

      // char *endPointer;
      // errno = 0;
      // long fizzNumber = getNumberFromArgs(argv, 3);

      // Error handling
      // if (errno != 0) {
      //   puts("Invalid parameter provided to the fizzbuzz command. Unable to parse to an integer.");
      //   return 1;
      // }
      // if (*endPointer != '\0') {
      //   printf("Invalid input: %s is not a valid integer.\n", argv[3]);
      //   return 1;
      // }


      // printing();
      // looping();
      // conditionals();
      // data_types();
      // arrays_and_strings();
      // structs();
      char *result = fizzbuzzString(getNumberFromArgs(argv, 3));
      puts(result);
      break;
    
    case COMMAND_FIZZBUZZNEW:
      printf("FizzbuzzNew command is selected\n");
      if (argc != 4) {
        printf("Invalid number of parameters provided for the fizzbuzzNew command. Expected 4, got %d\n", argc);
        return 1;
      }

      // char *endPointer;
      // errno = 0;
      // long number = getNumberFromArgs(argv, 3);

      // Error handling
      // if (errno != 0) {
      //   puts("Invalid parameter provided to the fizzbuzzNew command. Unable to parse to an integer.");
      //   return 1;
      // }
      // if (*endPointer != '\0') {
      //   printf("Invalid input: %s is not a valid integer.\n", argv[3]);
      //   return 1;
      // }
      
      // Buffer of size 15 should allow for an input of up to a trillion
      char buffer[15] = {0};
      fizzbuzzStringNew(buffer, 15, getNumberFromArgs(argv, 3));
      break;
    default:
      puts("Unknown command selected");
      return 1;
  }
  // if (argc < 2) {
  //   // perror("Invalid number of arguments provided.");
  //   printf("Number of arguments: %d\n", argc);
  //   int i = 0;
  //   while (argv[i] != NULL) { // Assuming the array is NULL-terminated
  //       printf("String %d: %s\n", i, argv[i]);
  //       i++;
  //   }
  //   return 1;
  // }

}
