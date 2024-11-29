#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b) {
  return a + b;
}

// ===== FUNCTIONS =====
int mul(int a, int b) {
  int result = a * b;
  return result;
  puts("This will not be executed.");
}

int fib(int n) {
  if (n <= 1) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}

// ===== PRINTING =====
void printing() {
  puts("Welcome!");
  printf("3 * 4 = %d\n", mul(3, 4));
  printf("Fibonacci number 10 is %d\n", fib(10));
}

// ===== LOOPING =====
void looping() {
  puts("Counting down from 1000 by 7s:");

  int c = 100;
  while (c > 0) {
    printf("%d\n", c);
    c = c - 7;
  }
  
  puts("Counting up from 0 by 7s:");

  for (int i = 0; i < 100; i += 7) {
    printf("%d\n", i);
  }
}

// ===== CONDITIONALS =====
void conditionals() {
  puts("Fizzbuzzing up to 20:");

  for (int i = 1; i <= 20; i++) {
    if (i % 15 == 0) {
      puts("Fizzbuzz");
    } else if (i % 3 == 0) {
      puts("Fizz");
    } else if (i % 5 == 0) {
      puts("Buzz");
    } else {
      printf("%d\n", i);
    }
  }

  if (1 && !0 || 1) {
    puts("We made it!");
  }

  // And comparison operators:
  if (1 == 1 && 2 != 1 && 2 > 1 && 1 < 2 && 1 <= 1 && 2 >= 1) {
    puts("We made it again!");
  }
}

// === BASIC DATA TYPES ===

void data_types() {
  int integer = 42;
  float decimal = 3.14;
  char character = 'a'; // Typically 8 bits, enough to store an ASCII char
  // There's no boolean type, use integers of 0 and 1 instead

  // You may see these around:
  size_t whatever = 100;
  // This type is essentially "an unsigned integer big enough to store the size
  // of, or reference to, any object in memory on this system".
}


// === ARRAYS & STRINGS ===

void arrays_and_strings() {
  // C arrays & strings are a lot more basic than the lists you may be used to.
  // C strings are arrays of characters, terminated by a null character '�'.

  char string[6] = "hello"; // 6 characters, including the null terminator
  int numbers1[5]; // This allocates the memory for 5 ints but does not clear it.
  int numbers2[] = {1, 2, 3, 4, 5}; // This allocates the memory for 5 ints and
                                    // initialises them.

  // You can't get far using C arrays without learning about pointers and memory.
  // But that's not for this file, so let's move on!
}


// === STRUCTS ===

// Do you like classes and objects? Tough! C doesn't have them. But it does
// have structs, which are a bit like a single database record.

struct Person {
  char name[50];
  int height;
};

void structs() {
  // You can then initialize them like this:
  struct Person me = {"Kay", 176};

  // Or like this:
  struct Person you = {.height = 180, .name = "Someone"};

  // And access the properties using the familiar dot notation:
  printf("Person %s, height %dcm\n", me.name, me.height);
  printf("Person %s, height %dcm\n", you.name, you.height);
}

char* fizzbuzzString(int n) {
  // Allocating with calloc allocates the memory but you to keep track of the size yourself
  int bufferSize = 20;
  char *buffer = calloc(bufferSize, sizeof(char));

  if (buffer == NULL) {
    perror("Error when allocating memory on heap for buffer");
    return NULL;
  }

  int isFirst = 1;

  char fizzOrBuzz[11] = {0};

  // printf("Initial buffer: \"%s\", Size: %d\n", buffer, bufferSize);

  for (int i = 1; i <= n; i++) {

    if (i % 15 == 0) {
      sprintf(fizzOrBuzz, "%s", "FizzBuzz");
    } else if (i % 3 == 0) {
      sprintf(fizzOrBuzz, "%s", "Fizz");
    } else if (i % 5 == 0) {
      sprintf(fizzOrBuzz, "%s", "Buzz");
    } else {
      sprintf(fizzOrBuzz, "%d", i);
    }

    int sizeNeeded;

    if (isFirst) {
      sizeNeeded = snprintf(buffer, bufferSize, "%s", fizzOrBuzz);
      isFirst = 0;
    } else {
      char temp[11] = {0};  
      // I have to create this temp here because sprintf replaces in place.
      // Since the edit I want comes before the original string, I have to move its contents to another buffer so it does not get overwritten.
      sprintf(temp, "%s", fizzOrBuzz);
      sprintf(fizzOrBuzz, ", %s", temp);

      sizeNeeded = snprintf(buffer, bufferSize, "%s%s", buffer, fizzOrBuzz);
      if (sizeNeeded >= 0 && sizeNeeded > bufferSize) {
        // puts("Buffer overflow detected!");
        // printf("Size of FizzOrBuzz: %lu\n", strlen(fizzOrBuzz));
        int startingOverflowIndex = strlen(fizzOrBuzz) - sizeNeeded + bufferSize - 1; // The -1 accounts for the null termination string
        // Pointer arithmetic to determine the starting index of the section of the fizzbuzz string that overflew
        char *overflows = fizzOrBuzz + startingOverflowIndex;
        // printf("Buffer: \"%s\", FizzBuzzStr: \"%s\", Overflows: \"%s\", StartingOverflowIndex: %d\n", buffer, fizzOrBuzz, overflows, startingOverflowIndex);

        // Allocating memory for new buffer, double the size of the original buffer
        char *newBuffer = calloc(bufferSize * 2, sizeof(char));
        if (newBuffer == NULL) {
          perror("Failed to reallocate new buffer on heap");
          return NULL;
        }

        // Copying the contents of the old buffer to the new buffer
        for (int i = 0; i < bufferSize; i++) {
          newBuffer[i] = buffer[i];
        }
        bufferSize *= 2;
        free(buffer);
        buffer = newBuffer;
        sprintf(buffer, "%s%s", buffer, overflows);
        // printf("new buffer: %s, size: %d\n", buffer, bufferSize);
      }
    }

    // printf("%d, \"%s\", sizeNeeded: %d\n", i, buffer, sizeNeeded);
  }
  sprintf(buffer, "%s%s", buffer,".");
  return buffer;
}