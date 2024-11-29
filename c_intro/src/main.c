#include <stdio.h>
#include "lib.c"

int main(int argc, char **argv) {
  if (argc > 1) {
    printf("Hello, %s!\n", argv[1]);
  } else {
    puts("No greeting for you!");
  }

  // printing();
  // looping();
  // conditionals();
  // data_types();
  // arrays_and_strings();
  // structs();
  fizzbuzzString(20);
}
