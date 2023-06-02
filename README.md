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

## VARIABLE AND CONSTANTANS
A variable is defined as a meaningful name given to a data storage location in the computer
memory. When using a variable, we actually refer to the address of the memory where the data
is stored. C language supports two basic kinds of variables.

### Numeric Variables
Numeric variables can be used to store either integer values or floating point values. Modifiers like
`short`, `long`, `signed`, and `unsigned` can also be used with numeric variables. The difference between
`signed` and `unsigned` numeric variables is that `signed` variables can be either negative or positive
but `unsigned` variables can only be positive.

When we omit the `signed/unsigned `modifier, C language
automatically makes it a `signed` variable. To declare an `unsigned` variable, the `unsigned` modifier
must be explicitly added during the declaration of the variable.

### DECLARATION OF VARIABLE 
To declare a variable, specify the data type of the variable followed by its name. The data type
indicates the kind of values that the variable can store. Variable names should always be meaningful
and must reflect the purpose of their usage in the program
```C
int emp_num;
float salary;
char grade;
double balance_amount;
unsigned short int acc_no;
```
In C, variables can be declared at any place in the program but two things must be kept in mind.
First, variables should be declared before using them

### Initializing Variables
While declaring the variables, we can also initialize them with some value
```C
int emp_num = 7;
float salary = 9800.99
char grade = ‘A’;
double balance_amount = 100000000;
```

### Constants
Constants are identifiers whose values do not change. While values of variables can be changed at
any time, values of constants can never be changed. Constants are used to define fixed values
like pi or the charge on an electron so that their value does not get changed in the program even
by mistake.

```C
const float pi = 3.14;
```


## C POINTERS 
pointer is a variable that stores the memory address of another variable. Pointers are used to indirectly access and manipulate the data stored in memory.

- pointer  are declared `*` sysmbol in a vairiable declaration
- `&` in C/C++ refers to address of, and is use to get the address of a variable.

```c
#include <stdio.h>

int main(void){
    int age = 23;
    int *ptr = &age;
    return 0;
}
```

- `*ptr` dereference the pointer allowing us to get the value

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

### STRUCT IN C
A struct is C's and C++'s notion of a composite type, a datatype that composes a fixed set of labeled fields or members. It is so called because of the struct keyword used in declaring them, which is short for structure or, more precisely, user-defined data structure.

In C, a struct is a user-defined composite data type that allows you to group together multiple variables of different types into a single entity. It provides a way to create a custom data structure that can hold related data elements.


```c
#include <stdio.h>
#include <string.h>

struct User {
    char email[100];
    char password[100];
};

int main(void) {
    struct User johndoe;
    strncpy(johndoe.email, "johndoe@fake.com", sizeof(johndoe.email) - 1);
    strncpy(johndoe.password, "123@", sizeof(johndoe.password) - 1);

    johndoe.email[sizeof(johndoe.email) - 1] = '\0';       // Ensure null termination
    johndoe.password[sizeof(johndoe.password) - 1] = '\0'; // Ensure null termination

    printf("Email: %s\n", johndoe.email);
    printf("Password: %s\n", johndoe.password);

    return 0;
}

```


- The `strncpy` function is used to safely copy the email and password strings into the 


## COMMAND LINE ARGUMENTS IN C
It is possible to pass some values from the command line to your C programs when they are executed. These values are called command line arguments and many times they are important for your program especially when you want to control your program from outside instead of hard coding those values inside the code.

The command line arguments are handled using `main()` function arguments where argc refers to the number of arguments passed, and `argv[]` is a pointer array which points to each argument passed to the program

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    } else {
        printf("No argument provided!\n");
    }
    return 0;
}

```