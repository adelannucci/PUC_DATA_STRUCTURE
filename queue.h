#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct queue_queue_node
{
    int value;
    struct queue_queue_node* next;
}queue_node;

typedef struct queue
{
    queue_node* start_queue;
    queue_node* end_queue;
}queue_header;

queue_header* new_queue();
queue_node* new_queue_node(int n);
int queue_is_null(queue_header *queue);
int enqueue(queue_header *queue, int n);
int dequeue(queue_header* queue);
int queue_find(queue_header* queue, int n);

#endif // QUEUE_H_INCLUDED
