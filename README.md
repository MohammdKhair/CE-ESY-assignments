# Circular Buffer

##  Project Description
This project demonstrates the implementation of a **Circular Buffer (Ring Buffer)** in the C programming language. It includes a practical example of storing, processing, and reconstructing a string using a fixed-size buffer.

---

##  Program Idea
The program performs the following steps:

1. Creates a circular buffer with a fixed size (10 elements).
2. Reads a name from the user.
3. Appends a fixed string `"CE-ESY"` to the input name.
4. Stores all characters into the circular buffer.
5. Reads characters back from the buffer.
6. Stores the output in a separate string variable.
7. Prints the final result at once.

---

##  Key Concepts Used

- **Circular Buffer**
  - A FIFO (First In First Out) data structure
  - When the end of the array is reached, it wraps around to the beginning

- **Overflow**
  - Happens when inserting data into a full buffer

- **Underflow**
  - Happens when reading data from an empty buffer

- **String Handling in C**
  - Uses character arrays (`char[]`)
  - Must be null-terminated using `'\0'`

---

##  Data Structure

```c
typedef struct {
    char arr[CAPACITY];
    int front;
    int rear;
    int count;
} CircularBuffer;
