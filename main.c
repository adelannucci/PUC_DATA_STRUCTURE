#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "stack.c"

void test_queue()
{
    queue_header* queue_ = new_queue();
    int value = 1;

    while(value != 5)
    {
        if(enqueue(queue_, value) == 1)
        {
            printf("value %d, enqueue\n", value);
        }
        else
        {
            printf("value %d, not enqueue\n", value);
        }

        value++;
    }

    int out = 0;

    do
    {
        out = dequeue(queue_);
        if(out != 0)
            printf("dequeue value %d\n", out);
        else
            printf("queue is empty\n");

    }while(out != 0);

}

void test_stack()
{
    stack_header *stack = new_stack();

    push(stack, 5);
    push(stack, 4);
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);

    printf("look top %d\n",peek(stack));
    printf("remove top %d\n",pop(stack));
    printf("remove top %d\n",pop(stack));
    printf("remove top %d\n",pop(stack));
    printf("remove top %d\n",pop(stack));
    printf("look top %d\n",peek(stack));

}

int main()
{
    test_queue();
    test_stack();
    return 0;
}
