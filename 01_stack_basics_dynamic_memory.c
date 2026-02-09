#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentujaca element kolejki
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Struktura reprezentujaca kolejke
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Funkcja tworzaca nowa kolejke
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Funkcja dodajaca element na koniec kolejki
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

// Funkcja usuwajaca element z poczatku kolejki
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Kolejka jest pusta!\n");
        return -1;
    }

    struct QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Funkcja sprawdzajaca, czy kolejka jest pusta
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Funkcja wyswietlajaca zawartosc kolejki
void displayQueue(struct Queue* queue) {
    struct QueueNode* current = queue->front;
    printf("Zawartosc kolejki: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Funkcja usuwajaca wszystkie elementy z kolejki
void clearQueue(struct Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    displayQueue(queue);

    printf("Usunieto element: %d\n", dequeue(queue));

    displayQueue(queue);

    clearQueue(queue);

    return 0;
}
