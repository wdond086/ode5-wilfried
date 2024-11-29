# C Programming Notes

## Instructions

- An instruction is a symbol representing an operation.
- They are both memory (i.e. they exist in memory) and operate on memory.
- Each instruction has a memory address, and those addresses get interpreted into instructions by the decompiler.
- Each variable in a particular function's frame is positioned relative to the functions frame base pointer, which we can refer to as `rbp`.

## SysCalls

- These are instructions that a programs gives to systems outside itself.
- The easiest example of a syscall is the call to `printf` in the `stdio.h` header file in C.
- You use syscalls to interact with terminals, displays, pretty much all hardware.

## Functions

- Functions describe the world, essentially true.
- A callable unit of code. Takes inputs in the form of parameters, and returns a result while sometimes modifying behaviour in a different section of the code.

## Structure

- The idea that people write programs in a structured pattern, closer to the way they think about the problems they are trying to solve, then have the compiler convert that structured code into assembly instructions.
- In the past, before the idea of structured programs, code was written in assembly instructions directly.
- Structured programs allowed for the ability to incorporate a lot of the concepts of mathematics and they way mathematical expressions were expressed into the world of software engineering.

## Clang Compiler

- Options are `GCC`, `CLANG`, and `CC`.
- I will be using clang for now.
- Options to keep in mind when using clang to compile c code.
  - `-O3` flag: Determines how optimized the compiled code should be, where `0` is the lowest level and `3` is the highest level.
  - `-g` flag: Enables easier debugging and printing of symbols.
  - `-Wall` flag: Enables all the warnings that compiler can find.
  - `-o` flag: Lets the user determine the path of the output executable. If not provided the default is `a.out`. Compilers can also produce object files which are not executable, but can be bundled with other object files to produce executables.

## Syntax and Conventions

- You include existing header files using the `#include <somehing.h>` syntax.
- You include a file you have written using: `#include "something.c"`.
- Conventions is not to include files directly, but header files that you create for your c files. In the header files, you specify things in your c file you want to make available for inclusion and what you do not.
- You cannot return arrays (hence strings also since string is an array of chars) directly. In general, you should no return non-primitive data types directly. You should be returning pointers to them.
- You can print using;
  - `puts`: Automatically adds a newline at the end does not allow for string interpolation.
  - `printf`: Allows for string formatting and interpolation. The format specifiers you can provide are the following
    - `%d`: Signed decimal integer
    - `%f`: Decimal floating point number
    - `%s`: String
    - `%%`: Literal % i.e. The actual percentage sign
    - `%p`: Pointer address
    - `\n`: New line
    - `\t`: Tab
    - `%04X`: The hex equivalent of a value provided
- There is no power operator in C. Use the `pow` function in the `math.h` header file.
- `size_t` means give me a type that is big enough to hold the size of or the address of any object that could fit in memory on this machine. It is basically c's equivalent to Rust's `usize`.
- Arrays are very basic. Hence no utility functions like length, size etc. An array is basically a block of memory that is allocated and allows you to store an given amount of objects of a certain type. You the developer fully manage the size manually. Arrays in C have fixed sizes.
- Strings in C are null terminated. Hence they have to end with a null byte, and that is how C knows that the string is done. `Hence, when instantiating a string array for a string, the size of the string array must always be the size of the actual string plus 1.`
- C does not have classes. It has structs. You access the properties of the struct using the dot operator as in most other languages.
- `sprintf`: Allows you to do string formatting but instead of writing to stdout, it writes to a buffer you provide when calling the functions.
- `snprintf`: Operates similar to `sprintf` but takes an extra parameter representing the length of the buffer. It uses that length to prevent buffer overflows by limiting the amount of data written to the buffer to its maximum length.
- `malloc` allows you to allocate memory on the heap. You determine the size of heap memory you need based on the size of the data you want to store. The developer is responsible for manually managing the size of heap memory allocated and making sure the memory gets deallocated when it is no longer needed. The allocated memory block cannot be reused until it is deallocated.
- `free`: It is the function used to free memory that was allocated on the heap using `malloc`.
-
