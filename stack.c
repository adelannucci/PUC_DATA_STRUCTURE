#include "stack.h"

stack_header* new_stack()
{
    stack_header *stack = (stack_header*) malloc(sizeof(stack_header));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}


stack_node* new_stack_node(int n)
{
    stack_node *node = (stack_node*) malloc(sizeof(stack_node));
    if(node == NULL)
    {
        return NULL;
    }
    else
    {
        node->next = NULL;
        node->value = n;
    }

    return node;
}

int stack_is_null(stack_header *stack)
{
    if(stack->size == 0)
    {
        return 1;
    }

    return 0;
}

int push(stack_header* stack, int n)
{
    stack_node *new_top = new_stack_node(n);
    if(new_top == NULL)
        return 0;

    if(stack_is_null(stack))
    {
        stack->top = new_top;
    }
    else
    {
        new_top->next = stack->top;
        stack->top = new_top;
    }

    stack->size++;

    return 1;
}

int pop(stack_header* stack)
{
    int out = 0;

    if(stack_is_null(stack))
        return out;

    stack_node *aux = stack->top;
    out = aux->value;
    stack->top = aux->next;
    stack->size--;
    free(aux);
    return out;
}

int peek(stack_header* stack)
{
    int out = 0;
    if(stack_is_null(stack))
        return out;
    out = stack->top->value;
    return out;
}


