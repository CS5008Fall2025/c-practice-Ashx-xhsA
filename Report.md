# Homework - C Practice Report

Completely answer the report questions below. Make sure to double check the final version to make sure it is easily readable on your github repository.

1.  What is the difference between a standard numeric type (int, float, double) and a pointer?

    > A pointer is an address of other data stored on heap. "\*" can be used for a pointer to get the data stored in that address. While numeric types are the value itself.

2.  In your test file, we had the following code:

    ```c
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    ```

    Later in the code we only `free(arr)` but not expected. Why is this? What is the difference in where they are stored in memory?

    > Because expected is stored on stack, once the function ends it frees automatically.

    > Data stored on heap needs to be freed manually.

3.  What is the difference between the heap and stack when related to memory allocation and management?

    > Heap:
    > Allocated and managed automatic by compiler instructions.[1].

    > Stack:
    > Allocated and managed manual by the programmer.[1].

4.  Take the following code:

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct {
      int x, y;
    } Point;

    Point * new_point(int x, int y) {
      Point pt = {x, y};
      return &pt;
    }

    int main() {
       Point* point = new_point(10, 10);
       printf("x: %d, y: %d", point->x, point->y);
       return 0;
    }
    ```

    Would the code run correctly? Even if it does compile, what would be some potential runtime issues? After answering your thoughts, put the output of a run below (you may need to run it a few times).

    > No it wont. Even if it does compiles, it resigns NULL to point in main. And NULL does not point to any address which will lead to runtime issues.

    ```text
    output here
    test.c:10:14: warning: address of stack memory associated with local variable 'pt' returned [-Wreturn-stack-address]
    10 |      return &pt;
       |              ^~
    1 warning generated.

    ```

    Fix the code in the following block:

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct {
      int x, y;
    } Point;

    Point * new_point(int x, int y) {
      Point *p = (Point*)malloc(sizeof(Point));
      p->x = x;
      p->y = y;
      return p;
    }

    int main() {
       Point* point = new_point(10, 10);
       printf("x: %d, y: %d", point->x, point->y);
       return 0;
    }
    ```

5.  When you use `malloc`, where are you storing the information?

    > On heap.

6.  Speaking about `malloc` and `calloc`, what is the difference between the two (you may need to research it!)?

    > Initialization:

    > malloc() allocates a memory block of given size (in bytes) and returns a pointer to the beginning of the block. malloc() doesn't initialize the allocated memory. If you try to read from the allocated memory without first initializing it, then you will invoke undefined behavior, which usually means the values you read will be garbage values.
    > calloc() allocates the memory and also initializes every byte in the allocated memory to 0. If you try to read the value of the allocated memory without initializing it, you'll get 0 as it has already been initialized to 0 by calloc().

    > Parameters:

    > malloc() takes a single argument, which is the number of bytes to allocate. Unlike malloc(), calloc() takes two arguments:Number of blocks to be allocated. Size of each block in bytes.[2]

7.  What are some common built in libraries used for C, list at least 3 and explain each one in your own words. Name a few (at least 3) functions in those libraries (hint: we used two of the most common ones in this assignment. There are many resources online that tell you functions in each library - you need to include at least 1 reference, but ideally for every library, you should have a reference to it)?

    - Example: stdlib.h - provides functions for general-purpose operations including
      memory management and random numbers [1].
      - void \* malloc(size_t) - allocates memory specified in size on the heap and returns a pointer to that location
      - void \* calloc(size_t num_elements, size_t element_size) - contiguous allocation for allocating arrays with the default value of 0. Slower than malloc.
      - int rand(void) - returns a random integer between 0 and RAND_MAX. Seed should be set before hand.

    1. stdio.h - The <stdio.h> header provides a variety of functions for input, output and file handling[3].

       - int printf(const char \*format, ...)- Sends formatted output to stdout.
       - int scanf(const char \*format, ...)- Reads formatted input from stdin.
       - int getchar(void) - Gets a character (an unsigned char) from stdin.

    2. string.h - defines one variable type, one macro, and various functions for manipulating arrays of characters[4].

       - char *strchr(const char *str, int c) - Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.
       - char *strstr(const char *haystack, const char \*needle) - Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack.
       - char *strtok(char *str, const char \*delim) - Breaks string str into a series of tokens separated by delim.

    3. time.h - The time.h header defines four variable types, two macro and various functions for manipulating date and time[5].

       - char *ctime(const time_t *timer) - Returns a string representing the localtime based on the argument timer.
       - double difftime(time_t time1, time_t time2) - Returns the difference of seconds between time1 and time2 (time1-time2).
       - time_t time(time_t \*timer) - Calculates the current calender time and encodes it into time_t format.

8.  Looking at the struct Point and Polygon, we have a mix of values on the heap, and we make ample use of pointers. Take a moment to draw out how you think that looks after `create_triangle(2,3)` is called (see an example below). The important part of the drawing it to see that not everything is stored together in memory, but in different locations! Store the image file in your github repo and link it here. You can use any program to draw it such as [drawIO](https://app.diagrams.net/), or even draw it by hand and take a picture of it.

## Technical Interview Practice Questions

For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

   > What is the difference between git add and git commit?

   > git add is a method of preparing your changes, git commit is finalizing them into a checkpoint in your project’s history[6].

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others.

   ```c
   int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
      int *twonumber = malloc(2 * sizeof(int));
      for(int i = 0; i < numsSize -1; i++){
         for (int j = i + 1; j < numsSize; j ++){
               if(nums[i] + nums[j] == target){
                  twonumber[0] = i;
                  twonumber[1] =j;
                  *returnSize = 2;
                  return twonumber;
               }
         }

      }
      return twonumber;
   }
   ```

## Deeper Thinking

In Java and Python, do you think new objects are stored on the stack or the heap? Feel free to work through your thoughts as to why it would be better to store them on the stack or heap. You should consider pass by reference, and how that is similar to pointer in your answer. Feel free to use resources, but make sure to cite them, and include the citation below using ACM format. You will note LLMs are not valid references, but they can give you directions to valid references. Make sure to use your own words.

Answer here using a paragraph (not just bullet points).

## References

Add any references you use here. Use ACM style formatting, adding to the numbers as you add the reference.

1. GeeksforGeeks. 2025. Stack vs Heap Memory Allocation. (February 26, 2025). Retrieved September 30, 2025 from <https://www.geeksforgeeks.org/dsa/stack-vs-heap-memory-allocation/>
2. GeeksforGeeks. 2025. Difference Between malloc() and calloc() with Examples. (July 23, 2025). Retrieved September 30, 2025 from <https://www.geeksforgeeks.org/c/difference-between-malloc-and-calloc-with-examples/>
3. W3Schools. 2025. C stdio (stdio.h) Library. Retrieved September 30, 2025 from <https://www.w3schools.com/c/c_ref_stdio.php>
4. TutorialsPoint. 2025. C Library - <string.h>. Retrieved September 30, 2025 from <https://www.tutorialspoint.com/c_standard_library/string_h.htm>
5. TutorialsPoint. 2025. C Library - <time.h>. Retrieved September 30, 2025 from <https://www.tutorialspoint.com/c_standard_library/time_h.htm>
6. Graphite. 2024. Git add, commit, and push. Retrieved September 30, 2025 from <https://graphite.dev/guides/git-add-commit-push>

## Resource/Help: Linking to images?

To link an image, you use the following code

```markdown
![alt text](path / link to image)
```

for example

```markdown
![my memory drawing](instructions/rectangle_points.png)
```

Here is a sample using:

```c
void my_func() {
    Polygon* r = create_rectangle(5,5);
    printf("The area of the rectangle is %d\n", area(r));
}
```

![my memory drawing](instructions/rectangle_points.png)

Note: This is a simplified version. However, it helps illustrate why we need to use `free` on the pointers in the struct. If we do not, we will have memory leaks! (memory that is allocated, but not freed, and thus cannot be used by other programs). In the above example code, `r` is created, and then the variable is destroyed when the function ends. However, the memory allocated for the struct is not freed, and thus we have a memory leak.

When you work on your version for `create_triangle(2, 3)`, you do not have to be exact on the memory structure (the locations on the heap were randomly chosen). The idea is more to show how the memory is stored, and the pointers to different memory addresses.
