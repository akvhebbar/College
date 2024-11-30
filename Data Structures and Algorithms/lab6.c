/*You have been tasked with implementing a circular queue data structure using linked storage in C language. The queue
should include a header node that stores the number of nodes in the queue, as well as the largest and smallest values
currently present in the queue. Implement the following operations for this circular queue:
1. Initialize Queue: Write a function to initialize an empty circular queue with a header node. The header node should
have its count initialized to 0, and largest and smallest initialized to appropriate values.
2. Enqueue: Write a function to enqueue an integer value into the circular queue. Update the header node's count,
largest, and smallest accordingly.
3. Dequeue: Write a function to dequeue an element from the circular queue. Update the header node's count, largest,
and smallest appropriately.
4. Get Largest Value: Write a function to retrieve the largest value from the circular queue.
5. Get Smallest Value: Write a function to retrieve the smallest value from the circular queue.
6. Display Queue: Write a function to display the elements of the circular queue, starting from the front.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure for a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for the header node
typedef struct {
    Node* front;
    Node* rear;
    int count;
    int largest;
    int smallest;
} CircularQueue;

CircularQueue* initializeQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front = queue->rear = NULL;
    queue->count = 0;
    queue->largest = INT_MIN;
    queue->smallest = INT_MAX;
    return queue;
}

void enqueue(CircularQueue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        newNode->next = queue->front;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
        queue->rear->next = queue->front;
    }

    queue->count++;
    if (value > queue->largest) queue->largest = value;
    if (value < queue->smallest) queue->smallest = value;
}

int dequeue(CircularQueue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return INT_MIN;
    }

    Node* temp = queue->front;
    int data = temp->data;

    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
    }

    free(temp);
    queue->count--;

    // Update largest and smallest values
    if (queue->count == 0) {
        queue->largest = INT_MIN;
        queue->smallest = INT_MAX;
    } else {
        Node* current = queue->front;
        queue->largest = queue->smallest = current->data;
        for (int i = 1; i < queue->count; i++) {
            current = current->next;
            if (current->data > queue->largest) queue->largest = current->data;
            if (current->data < queue->smallest) queue->smallest = current->data;
        }
    }

    return data;
}

int getLargestValue(CircularQueue* queue) {
    return queue->largest;
}

int getSmallestValue(CircularQueue* queue) {
    return queue->smallest;
}

void displayQueue(CircularQueue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* current = queue->front;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

int main() {
    CircularQueue* queue = initializeQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("Queue: ");
    displayQueue(queue);
    printf("Largest: %d\n", getLargestValue(queue));
    printf("Smallest: %d\n", getSmallestValue(queue));

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Queue: ");
    displayQueue(queue);
    printf("Largest: %d\n", getLargestValue(queue));
    printf("Smallest: %d\n", getSmallestValue(queue));

    return 0;
}
