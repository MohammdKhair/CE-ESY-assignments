#include <stdio.h>
#include <string.h>

#define CAPACITY 20

typedef struct {
    char arr[CAPACITY];
    int front;
    int rear;
    int count;
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->front = 0;
    cb->rear = 0;
    cb->count = 0;
}

int isEmpty(const CircularBuffer *cb) {
    return cb->count == 0;
}

int isFull(const CircularBuffer *cb) {
    return cb->count == CAPACITY;
}

void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Overflow\n");
        return;
    }
    cb->arr[cb->rear] = data;
    cb->rear = (cb->rear + 1) % CAPACITY;
    cb->count++;
}

char readBuffer(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Underflow\n");
        return '\0';
    }
    char data = cb->arr[cb->front];
    cb->front = (cb->front + 1) % CAPACITY;
    cb->count--;
    return data;
}

int main() {

    CircularBuffer cb;
    init(&cb);

    char name[50];
    printf("Enter your name: ");
    scanf("%49s", name);
    strcat(name, "CE-ESY");

    for (int i = 0; i < (int)strlen(name); i++) {
        write(&cb, name[i]);
    }

    char result[70];
    int i = 0;
    while (!isEmpty(&cb)) {
        result[i] = readBuffer(&cb);
        i++;
    }

    result[i] = '\0'; 
    printf("%s\n", result);

    return 0;
}