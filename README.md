# Simple C program
C is a programming language, a general-purpose, procedural, compiled programming
language. C language was created by Dennis Ritchie in the late 1960s and early 1970s.

## What is c used for 
C is often used for so-called systems programming, which is operating systems
programming, application programming, and embedded systems programming, to
name a few.

## C compilers
To compile and run a C program, we need a C compiler. A compiler compiles a C
program and turns the source code into an object file. The linker then links the object
files together and produces an executable file or a library, depending on our intention.

```c
#include <stdio.h>

int main(void){
    printf("Hello World");
}
```


* The main function is the application entry point


---
## C POINTERS 
pointer is a variable that stores the memory address of another variable. Pointers are used to indirectly access and manipulate the data stored in memory.

- pointer  are declared `*` sysmbol in a vairiable declaration
- `&` in C/C++ refers to address of, and is us to get the address of a variable.

```c
#include <stdio.h>

int main(void){
    int age = 23;
    int *ptr = &age;
    return 0;
}
```

- `*ptr` dereference the pointer allowing use to get the value

### WHY POINTERS ARE IMPORTANT
* **Dynamic memory allocation:** Pointers allow you to dynamically allocate memory at runtime using functions like `malloc`, `calloc`, and `realloc`. Dynamic memory allocation enables you to create data structures of arbitrary size, such as arrays and linked lists.

* **Efficient memory management:** Pointers provide a way to efficiently manage memory by allowing you to allocate and deallocate memory as needed. This helps optimize memory usage and can prevent unnecessary memory consumption.

* **Passing parameters by reference:** In C, parameters are typically passed by value, which means a copy of the value is made and passed to a function. However, by passing a pointer to a variable, you can modify the original variable within a function, effectively achieving pass-by-reference behavior.

* **Array manipulation:** Pointers and arrays are closely related in C. Arrays are represented as a contiguous block of memory, and pointers can be used to iterate over the elements of an array. Pointers allow efficient access and manipulation of array elements.

* **Data structures and algorithms:** Pointers are essential when working with complex data structures and implementing algorithms. Data structures like linked lists, trees, and graphs heavily rely on pointers to establish relationships between different elements and nodes.


* **Efficient memory access:** Pointers can enable faster and more efficient memory access compared to other methods. By directly accessing memory locations, you can bypass the overhead associated with copying or retrieving data from variables.

* **Interfacing with low-level code:** Pointers are crucial when interacting with low-level code, such as system APIs or hardware interfaces. Many low-level operations require passing or manipulating memory addresses, making pointers essential for such scenarios

```c
#include <stdio.h>

int main(void){

    int age = 1003;
    int *ptr; // declare a pointer 
    ptr  = &age; // assign an address
    *ptr = 200; // updating value through pointer 
    printf("%d \n", *ptr); // Dereferencing the array to get the value


    return 0;
}
```