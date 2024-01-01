#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue
{
  int items[MAX_SIZE];
  int front;
  int rear;
};

void enqueue (struct Queue *q, int item)
{
  if (q->rear == MAX_SIZE - 1)
    {
      printf ("Queue overflow\n");
      return;
    }

  if (q->front == -1)
    {
      q->front = 0;
    }

  q->rear++;
  q->items[q->rear] = item;
}

int dequeue (struct Queue *q)
{
  if (q->front == -1)
    {
      printf ("Queue underflow\n");
      return -1;
    }

  int item = q->items[q->front];
  q->front++;

  if (q->front == q->rear)
    {
      q->front = -1;
      q->rear = -1;
    }

  return item;
}

void display (struct Queue *q)
{
  if (q->rear == -1)
    {
      printf ("Queue is empty\n");
      return;
    }

  for (int i = q->front; i <= q->rear; i++)
    {
      printf ("%d ", q->items[i]);
    }

  printf ("\n");
}

void reverse (struct Queue *q)
{
  if (q->front == -1)
    {
      return;
    }

  int item = dequeue (q);

  reverse (q);

  enqueue (q, item);
}

int main ()
{
  struct Queue q;
  q.front = -1;
  q.rear = -1;

  enqueue (&q, 1);
  enqueue (&q, 2);
  enqueue (&q, 3);
  enqueue (&q, 4);

  printf ("Queue before reversing:\n");
  display (&q);

  reverse (&q);

  printf ("Queue after reversing:\n");
  display (&q);

  return 0;
}