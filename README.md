# TinyMemLeakTester

This is a simple c-based testing tool to detecting memory leaks for target program.

---
## Useage:

Including the header file **tiny_mem_leak_tester.h** to which file you using any memory allocating functions.
Copy the source code and header files into your projects.

> The files you needs to copies:
>> tiny_mem_leak_tester.c
>> tiny_mem_leak_tester.h

---
## Outputs:

While you using this tester, it will print some result to your **STDOUT**:

### void* malloc (size_t size);

When you call the malloc function, the STDOUT will print:

> | alloc   | File name | Line number | Function name | Pointer address | Size of memory allocated |

### void* realloc (void* ptr, size_t size);

When you call the realloc function, the STDOUT will print:

> | realloc | File name | Line number | Function name | Pointer address | Size of memory reallocated |

### void* malloc (size_t size);

When you call the malloc function, the STDOUT will print:

> | free    | File name | Line number | Function name | Pointer address | 0 |

---
## Result function:

Here we implemented a simple result function, to shown the list of leak memories:

### void Get_Result();

You can call this function in the end of your program, and the result will print to your STDOUT:
**Note: This function will destroy all the record for the list of memory leak.**

> ```
> ----The list of the memory location doesn't free----
> | File name | Line number | Function name | Pointer address | Size of alloced |
> | --------- | ----------- | ------------- | --------------- | --------------- |
> | test_main.c | 14 | main | 00C904A0 | 100 |
> | test_main.c | 9 | main | 00C939D8 | 100 |
> | test_main.c | 15 | main | 00C976D0 | 100 |
> | test_main.c | 16 | main | 00C97740 | 100 |
> | test_main.c | 17 | main | 00C977B0 | 100 |
> | test_main.c | 18 | main | 00C97820 | 100 |
> | test_main.c | 19 | main | 00C984A0 | 100 |
> | test_main.c | 20 | main | 00C98918 | 100 |
> | test_main.c | 21 | main | 00C98988 | 100 |
> | test_main.c | 22 | main | 00C989F8 | 100 |
> Number of node in list: 10
> ------------------End of the list-------------------
> ```

---
## Design of the *tiny_mem_leak_tester*