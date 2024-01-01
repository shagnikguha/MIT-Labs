#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure for a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return -1;

    int data = queue->front->data;
    struct QueueNode* temp = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return data;
}

// Function to check if Vignesh and Lata can get money securely
char* can_get_money(int N, int K) {
    struct Queue* queue = createQueue();

    // Enqueue the positions of people in the queue
    for (int i = 1; i <= N; i++) {
        enqueue(queue, i);
    }

    // Dequeue K elements to simulate Vignesh's position
    for (int i = 0; i < K; i++) {
        dequeue(queue);
    }

    int lataPosition = dequeue(queue);  // Dequeue Lata's position

    char* result;
    if (lataPosition == K + 1) {
        result = "Yes";
    } else {
        result = "No";
    }

    free(queue);
    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N, K;
        scanf("%d %d", &N, &K);

        char* result = can_get_money(N, K);
        printf("%s\n", result);
    }

    return 0;
}
