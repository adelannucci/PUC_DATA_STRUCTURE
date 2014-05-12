#include "queue.h"

queue_header* new_queue()
{
    queue_header *queue = (queue_header*)malloc(sizeof(queue_header));
    queue->start_queue = NULL;
    queue->end_queue = NULL;
    return queue;
}

queue_node* new_queue_node(int n)
{
    queue_node* data = (queue_node*)malloc(sizeof(queue_node));
    if(data == NULL)
       return NULL;

    data->value = n;
    data->next = NULL;
    return data;
}

int queue_is_null(queue_header *queue)
{
    if((queue->end_queue == NULL) && (queue->start_queue == NULL))
        return 1;
    return 0;
}

int enqueue(queue_header *queue, int n)
{
    queue_node * aux = new_queue_node(n);
    if(aux == NULL)
        return 0;

    if(queue_is_null(queue))
    {
        queue->start_queue = aux;
    }
    else
    {
        queue->end_queue->next = aux;
    }

    queue->end_queue = aux;
    return 1;
}

int dequeue(queue_header* queue)
{
    int out;
    if(queue_is_null(queue))
        return 0;
    if(queue->end_queue == queue->start_queue)
        queue->end_queue = NULL;

    out = queue->start_queue->value;
    queue_node* aux = queue->start_queue;
    queue->start_queue = aux->next;
    free(aux);
    return out;

}

int queue_find(queue_header* queue, int n)
{
    queue_node* aux = queue->start_queue;
    do
    {
        if(aux->value == n)
            return 1;
        aux = aux->next;
    }while(aux != queue->end_queue);

    return 0;
}


