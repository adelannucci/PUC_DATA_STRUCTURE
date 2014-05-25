#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "stack.c"
#include "list.c"


void listing(list_node* node)
{

    if(node != NULL)
    {
        printf("lis value %d\n", node->value);
        listing(node->next);
    }

}

void test_list()
{
    list_header* list_ = new_list();
    list_add(list_, 3);
    list_add(list_, 7);
    list_add(list_, 5);
    list_add(list_, 1);
    list_add(list_, 2);
    list_add(list_, 8);
    list_add(list_, 4);
    list_add(list_, 6);
    list_add(list_, 9);
    list_add(list_, 0);

    listing(list_->header);

    list_remove(list_,0);
    list_remove(list_,9);
    
    printf("\n");
    listing(list_->header);

    list_remove(list_,5);
    list_remove(list_,6);
   
    printf("\n");
    listing(list_->header);

    list_add(list_, 6);
    list_add(list_, 9);
    list_add(list_, 0);

    printf("\n");
    listing(list_->header);

}

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
    test_list();
    test_queue();
    test_stack();
    return 0;
}
